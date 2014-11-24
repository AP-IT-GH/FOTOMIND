using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FotomindUI
{
    public class ArduinoCommandsList : ObservableCollection<ArduinoCommands>
    {
        public ArduinoCommandsList() : base()
        {
            Add(new ArduinoCommands()
            {
                Title = "Take Picture",
                Command = "Cmd for taking picture with arduino"
            });
            Add(new ArduinoCommands()
            {
                Title = "Do something else",
                Command = "Blablibloebla"
            });
        }
    }
}
