using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CustomerMaintenanceClasses;

namespace CustomerTests
{
    class Program
    {
        static void Main(string[] args)
        {

            //TestProductConstructors();
            //TestProductPropertyGetters();
            //TestProductPropertySetters();

            //CustomerListIndexer();
            //TestInvalidFirstName();
            //TestInvalidLastName();
            //TestInvalidEmail();

            //CustomerListAdd();

            TestInheritance();

            Console.WriteLine();
            Console.ReadLine();
        }

        static void CustomerListIndexer()
        {
            CustomerList cList = new CustomerList();
            Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");
            Customer c2 = new Customer("Donald", "Duck", "duckd@disney.com");

            cList.Add(c1);
            cList.Add(c2);

            Console.WriteLine("Testing indexer");
            Console.WriteLine("Get customer with index 0.");

            Customer c3 = cList[0];

            Console.WriteLine("Expecting Mickey. " + c3);
            Console.WriteLine("Shouldn't alter the list. Expecting count of 2. " + cList.Count);
            Console.WriteLine("Expecting list of 2 customers. Mickey is the first element in list:\n" + cList);

            Console.WriteLine("Set product with index 0");
            cList[0] = c2;
            Console.WriteLine("Shouldn't alter the length of the list. Expecting count of 2. " + cList.Count);
            Console.WriteLine("Expecting list of 2 products. Donald is the first element in list as well as the last:\n" + cList);
        }

        static void CustomerListAdd()
        {
            CustomerList cList = new CustomerList();
            Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");
            Customer c2 = new Customer("Donald", "Duck", "duckd@disney.com");
            Customer c3 = new Customer("Minnie", "Mouse", "minnie@disney.com");
            Customer c4 = new Customer("Goofy", "Dog", "goofy@disney.com");

            cList.Add(c1);
            cList.Add(c2);

            Console.WriteLine("Testing Add");
            Console.WriteLine("Expecting count of 2. " + cList.Count);
            Console.WriteLine("Expecting list of 2 customers. Mickey is the first element in list:\n" + cList);

            cList = cList + c3;
            Console.WriteLine("Testing +");
            Console.WriteLine("Expecting count of 3. " + cList.Count);
            Console.WriteLine("Expecting list of 3 customers. Minnie is the third element in list:\n" + cList);

            cList = c4 + cList;
            Console.WriteLine("Testing InsertAt");
            Console.WriteLine("Expecting count of 4. " + cList.Count);
            Console.WriteLine("Expecting list of 4 customers. Goofy is the first element in list:\n" + cList);

            Customer c5 = new Customer("Mickey", "Mouse", "mousem@disney.com");

            if (c1 == c5)
                Console.WriteLine("They are equal");
            else
                Console.WriteLine("They are not equal");

            Customer c6 = c1;

            if (c1 == c6)
                Console.WriteLine("They are equal");
            else
                Console.WriteLine("They are not equal");
        }

        static void TestInvalidFirstName()
        {
            try
            {
                Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");
                c1.FirstName = "123456789101234567891012";
                Console.WriteLine("If I see this message my exception didn't work.");
            }
            catch (ArgumentOutOfRangeException ae)
            {
                Console.WriteLine("Testing invalid first name.");
                Console.WriteLine("Should throw an exception");
                Console.WriteLine(ae.Message);
                Console.WriteLine();
            }
        }

        static void TestInvalidLastName()
        {
            try
            {
                Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");
                c1.LastName = "123456789101234567891012";
                Console.WriteLine("If I see this message my exception didn't work.");
            }
            catch (ArgumentOutOfRangeException ae)
            {
                Console.WriteLine("Testing invalid last name.");
                Console.WriteLine("Should throw an exception");
                Console.WriteLine(ae.Message);
                Console.WriteLine();
            }
        }

        static void TestInvalidEmail()
        {
            try
            {
                Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");
                c1.Email = "123456789101234567891012";
                Console.WriteLine("If I see this message my exception didn't work.");
            }
            catch (ArgumentOutOfRangeException ae)
            {
                Console.WriteLine("Testing invalid email.");
                Console.WriteLine("Should throw an exception");
                Console.WriteLine(ae.Message);
                Console.WriteLine();
            }
        }

        static void TestProductConstructors()
        {
            Customer c1 = new Customer();
            Customer c2 = new Customer("Mickey", "Mouse", "mousem@disney.com");

            Console.WriteLine("Testing both constructors");
            Console.WriteLine("Default constructor.  Expecting default values. " + "\n" + c1);
            Console.WriteLine("Overloaded constructor.  Expecting Mickey Mouse - mousem@disney.com " + "\n" + c2);
            Console.WriteLine();
        }
        
        static void TestProductPropertyGetters()
        {
            Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");

            Console.WriteLine("Testing getters");
            Console.WriteLine("First name.  Expecting Mickey. " + "\n" + c1.FirstName);
            Console.WriteLine("Last name.  Expecting Mouse. " + "\n" + c1.LastName);
            Console.WriteLine("Email.  Expecting mousem@disney.com. " + "\n" + c1.Email);
            Console.WriteLine();
        }
        
        static void TestProductPropertySetters()
        {
            Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");

            Console.WriteLine("Testing setters");
            c1.FirstName = "Donald";
            c1.LastName = "Duck";
            c1.Email = "duckd@disney.com";
            Console.WriteLine("Expecting Donald Duck - duckd@disney.com. " + "\n" + c1);
            Console.WriteLine();
        }

        static void TestInheritance()
        {
            Customer c1 = new Customer("Mickey", "Mouse", "mousem@disney.com");
            WholesaleCustomer w1 = new WholesaleCustomer("Minnie", "Mouse", "minnie@disney.com", "Disney Studios");
            RetailCustomer r1 = new RetailCustomer("Donald", "Duck", "duckd@disney.com", "555-555-5555");

            Console.WriteLine(c1);
            Console.WriteLine(w1);
            Console.WriteLine(r1);

            CustomerList list = new CustomerList();
            list.Add(c1);
            list.Add(w1);
            list.Add(r1);

            Console.WriteLine(list);
        }
    }
}
