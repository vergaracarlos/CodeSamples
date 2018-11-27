using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomerMaintenanceClasses
{
    public class Customer
    {
        protected string fName;
        protected string lName;
        protected string eMail;

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
                if (value.Length <= 20)
                    fName = value;
                else
                    throw new ArgumentOutOfRangeException("First Name", "First name must be no longer than 20 characters.");
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
                if (value.Length <= 20)
                    lName = value;
                else
                    throw new ArgumentOutOfRangeException("Last Name", "Last name must be no longer than 20 characters.");
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
                if (value.Contains("@"))
                    eMail = value;
                else
                    throw new ArgumentOutOfRangeException("Email", "Email must contain @.");
            }
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            Customer c = (Customer)obj;

            if (this.FirstName == c.FirstName && this.LastName == c.LastName && this.Email == c.Email)
                return true;
            else
                return false;
        }

        public static bool operator ==(Customer c1, Customer c2)
        {
            if (Object.Equals(c1, null))
                if (Object.Equals(c2, null))
                    return true;
                else
                    return false;
            else
                return c1.Equals(c2);
        }

        public static bool operator !=(Customer c1, Customer c2)
        {
            return !(c1 == c2);
        }

        public override string ToString()
        {
            return fName + " " + lName + " - " + eMail;
        }
    }
}
