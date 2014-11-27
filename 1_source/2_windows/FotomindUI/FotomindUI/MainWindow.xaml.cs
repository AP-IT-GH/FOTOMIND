using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;
using System.Xml;
using System.Xml.Serialization;

namespace FotomindUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public SerialPortInterface SerialPort1 = new SerialPortInterface();
        public ObservableCollection<ArduinoCommands> ArdCmds { get; set; }
        public MainWindow()
        {
            InitializeComponent();
            listCommands.DataContext = ArdCmds = new ObservableCollection<ArduinoCommands>();
            var entree = LoadFromXml<ObservableCollection<ArduinoCommands>>("CmdXml.xml");
            foreach (var c in entree)
            {
                ArdCmds.Add(c);
            }
            #region hardcode aanmaken commando's
            /*
            ArdCmds = new ObservableCollection<ArduinoCommands>
            {
                new ArduinoCommands
                {
                    Title = "Turn Off Led",
                    Command = "9"
                },
                new ArduinoCommands
                {
                    Title = "Turn On Led",
                    Command = "8"
                },
                new ArduinoCommands
                {
                    Title = "Take picture",
                    Command = "A"
                }
            };
             * */
            #endregion
            
        }

         private void SerializeCommands(ObservableCollection<ArduinoCommands> p) //To XML
        {
            var serializer = new XmlSerializer(p.GetType(), new XmlRootAttribute("Commands"));
            using (var writer = XmlWriter.Create("CmdXml.xml"))
            {
                serializer.Serialize(writer, p);
            }
        }

         public static T LoadFromXml<T>(string filepath) // get commands from xml
         {
             var serializer = new XmlSerializer(typeof(T), new XmlRootAttribute("Commands"));
             using (var reader = XmlReader.Create(filepath))
             {
                 return (T)serializer.Deserialize(reader);
             }
         }

        private void btnComPortRefresh_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                cboComPort.Items.Clear();
                addComs();
                lblStatus.Content = "Refreshed ComPorts";
            }
            catch (Exception)
            {
                
                lblStatus.Content = "Could not refresh ComPorts";
            }
            
        }

        private void btnOpenPort_Click(object sender, RoutedEventArgs e)
        {
            if (cboComPort.SelectedItem.ToString() != "No Ports")
            {
                SerialPort1.PortName = cboComPort.SelectedItem.ToString();
                SerialPort1.BaudRate = Convert.ToInt32(cboBaudRate.SelectedItem);
                bool verify = SerialPort1.Open();
                if (verify == true)
                {
                    lblStatus.Content = "Port opened";
                }
                else
                {
                    lblStatus.Content = "Could not open port";
                }
            }
        }

        private void btnClosePort_Click(object sender, RoutedEventArgs e)
        {
            SerialPort1.Close();
            lblStatus.Content = "Port Closed";
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            addComs();
            listCommands.DataContext = ArdCmds;
            listCommands.ItemsSource = ArdCmds;
        }

        private void addComs()
        {
            // read avaiable COM Ports: 
            string[] Portnames = SerialPort.GetPortNames();
            if (!Portnames.Any())
            {
                MessageBox.Show("There are no Com Ports detected!");
                //this.Close();
            }

            foreach (string portname in Portnames)
            {
                cboComPort.Items.Add(portname);
                
            }
            try
            {
                cboComPort.Text = Portnames[0];
                btnOpenPort.IsEnabled = true;
                btnClosePort.IsEnabled = true;
            }
            catch (IndexOutOfRangeException)
            {
                cboComPort.Items.Add("No Ports");
                btnOpenPort.IsEnabled = false;
                btnClosePort.IsEnabled = false;
            }
            if (cboBaudRate.Items.Count == 0)
            {
                foreach (int BR in SerialPortInterface.BaudRates)
                {
                    cboBaudRate.Items.Add(BR);
                }
            }
            cboBaudRate.Text = "57600";
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            SerialPort1.Close();
        }

        private void cboComPort_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cboComPort.SelectedItem != null)
            {
                SerialPort1.PortName = cboComPort.SelectedItem.ToString();
            }
        }

        private void cboBaudRate_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SerialPort1.BaudRate = Convert.ToInt32(cboBaudRate.SelectedItem);
        }

        private void btnShow_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                ArduinoCommands temp = new ArduinoCommands();
                temp = (ArduinoCommands) listCommands.SelectedItem;
                MessageBox.Show(temp.ToStringDetailed());
            }
            catch (Exception)
            {
                
                MessageBox.Show("No command was selected");
            }

        }

        private void listCommands_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void listCommands_DataContextChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            listCommands.SelectedItem = 0;
        }

        private void btnSend_Click(object sender, RoutedEventArgs e)
        {
            ArduinoCommands tempCmd = new ArduinoCommands();
            tempCmd = (ArduinoCommands) listCommands.SelectedItem;
            bool verify;
            verify = SerialPort1.Send(tempCmd.Command);
            if (verify)
            {
                lblStatus.Content = "Command sent to Arduino";
            }
            else
            {
                lblStatus.Content = "Could not send command";
            }          
        }

        private void btnAdd_Click(object sender, RoutedEventArgs e)
        {
            if (tbNewCmdTitle.Text != "" && tbNewCmd.Text != "")
            {
                ArduinoCommands newCmd = new ArduinoCommands();
                newCmd.Title = tbNewCmdTitle.Text;
                newCmd.Command = tbNewCmd.Text;
                ArdCmds.Add(newCmd);
                listCommands.ItemsSource = ArdCmds;
                SerializeCommands(ArdCmds);
                tbNewCmd.Clear();
                tbNewCmdTitle.Clear();
            }
        }

        private void btnDelete_Click(object sender, RoutedEventArgs e)
        {
            ArdCmds.Remove((ArduinoCommands)listCommands.SelectedItem);
            SerializeCommands(ArdCmds);
        }
    }
}
