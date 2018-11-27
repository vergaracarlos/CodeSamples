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

            TestProductConstructors();
            TestProductPropertyGetters();
            TestProductPropertySetters();

            Console.WriteLine();
            Console.ReadLine();
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
    }
}
