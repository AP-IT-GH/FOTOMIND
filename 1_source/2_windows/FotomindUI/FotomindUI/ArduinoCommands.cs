using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FotomindUI
{
    public class ArduinoCommands
    {
        private string _title;
        private string _command;

        
        public string Title
        {
            get { return _title; }
            set
            {
                if (!string.IsNullOrEmpty(value))
                {
                    _title = value;
                }
            }
        }
        public string Command
        {
            get { return _command; }
            set {
                    if (!string.IsNullOrEmpty(value))
                    {
                        _command = value;
                    }
                 }
        }
    }
}
