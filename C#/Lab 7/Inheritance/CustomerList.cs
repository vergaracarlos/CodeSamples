using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CustomerMaintenanceClasses
{
    public class CustomerList
    {
        private List<Customer> customers;

        public CustomerList()
        {
            customers = new List<Customer>();
        }

        public static CustomerList operator +(CustomerList list, Customer c)
        {
            list.Add(c);
            return list;
        }

        public static CustomerList operator +(Customer c, CustomerList list)
        {
            list.InsertAt(0, c);
            return list;
        }

        public void InsertAt(int index, Customer c)
        {
            customers.Insert(index, c);
        }

        public static CustomerList operator -(CustomerList list, Customer c)
        {
            list.Remove(c);
            return list;
        }

        public Customer this[int i]
        {
            get
            {
                return customers[i];
            }
            set
            {
                customers[i] = value;
            }
        }

        public int Count
        {
            get
            {
                return customers.Count;
            }
        }

        public void Add(Customer c)
        {
            customers.Add(c);
        }

        public void Remove(Customer c)
        {
            customers.Remove(c);
        }

        public override string ToString()
        {
            string output = "";
            foreach (Customer c in customers)
            {
                output += c.ToString() + "\n";
            }
            return output;
        }

        public void Add(string fName, string lName, string email)
        {
            Customer c = new Customer(fName, lName, email);
            customers.Add(c);
        }
    }
}
