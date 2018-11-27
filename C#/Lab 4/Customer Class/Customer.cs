using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomerMaintenanceClasses
{
    public class Customer
    {
        private string fName;
        private string lName;
        private string eMail;

        public Customer()
        {
            fName = "First name unknown";
            lName = "Last name unknown";
            eMail = "Email unknown";
        }

        public Customer(string fn, string ln, string em)
        {
            fName = fn;
            lName = ln;
            eMail = em;
        }

        public string FirstName
        {
            get
            {
                return fName;
            }
            set
            {
                fName = value;
            }
        }

        public string LastName
        {
            get
            {
                return lName;
            }
            set
            {
                lName = value;
            }
        }

        public string Email
        {
            get
            {
                return eMail;
            }
            set
            {
                eMail = value;
            }
        }

        public override string ToString()
        {
            return fName + " " + lName + " - " + eMail;
        }
    }
}
