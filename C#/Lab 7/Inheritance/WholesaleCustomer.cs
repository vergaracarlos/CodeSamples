using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CustomerMaintenanceClasses
{
    public class WholesaleCustomer : Customer
    {
        private string company;

        public WholesaleCustomer() : base()
        {
            company = "Company name goes here";
        }

        public WholesaleCustomer(string fn, string ln, string em, string c) : base(fn, ln, em)
        {
            company = c;
        }

        public string Company
        {
            get
            {
                return company;
            }
            set
            {
                company = value;
            }
        }

        public override string ToString()
        {
            return base.ToString() + " " + company;
        }
    }
}
