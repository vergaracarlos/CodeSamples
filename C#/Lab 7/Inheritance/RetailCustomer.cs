using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CustomerMaintenanceClasses
{
    public class RetailCustomer : Customer
    {
         private string phone;

        public RetailCustomer() : base()
        {
            phone = "Phone number goes here";
        }

        public RetailCustomer(string fn, string ln, string em, string ph) : base(fn, ln, em)
        {
            phone = ph;
        }

        public string Phone
        {
            get
            {
                return phone;
            }
            set
            {
                phone = value;
            }
        }

        public override string ToString()
        {
            return base.ToString() + " " + phone;
        }
    }
}
