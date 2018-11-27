using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CardClassLibrary;

namespace CardTests
{
    class Program
    {
        static void Main(string[] args)
        {
            Card c1 = new Card(1, 1);
            Card c2 = new Card(12, 2);
            Card c3 = new Card(13, 3);
            Card c4 = new Card(1, 4);

            TestCardConstructors();
            TestProductPropertyGetters();
            TestProductPropertySetters();

            TestCardIs(c1);
            TestCardIs(c2);
            TestCardIs(c3);
            TestCardIs(c4);

            Console.ReadLine();
        }

        static void TestCardConstructors()
        {
            Card c1 = new Card();
            Card c2 = new Card(3,4);

            Console.WriteLine("Testing both constructors");
            Console.WriteLine("Default constructor.  Expecting Ace of Clubs. " + "\n" + c1);
            Console.WriteLine("Overloaded constructor.  Expecting 3 of Spades. " + "\n" + c2);
            Console.WriteLine();
        }

        static void TestProductPropertyGetters()
        {
            Card c1 = new Card(3,4);

            Console.WriteLine("Testing getters");
            Console.WriteLine("Value.  Expecting 3. " + "\n" + c1.Value);
            Console.WriteLine("Suit.  Expecting 4. " + "\n" + c1.Suit);
            Console.WriteLine();
        }

        static void TestProductPropertySetters()
        {
            Card c1 = new Card(1,1);

            Console.WriteLine("Testing setters");
            c1.Value= 3;
            c1.Suit = 4;
            Console.WriteLine("Expecting 3 of Spades. " + "\n" + c1);
            Console.WriteLine();
        }

        static void TestCardIs(Card c)
        {
            Console.WriteLine("Testing Is Method with " + c);
            Console.WriteLine("Is Red " + c.IsRed());
            Console.WriteLine("Is Black " + c.IsBlack());
            Console.WriteLine("Is Clubs " + c.IsClub());
            Console.WriteLine("Is Diamond " + c.IsDiamond());
            Console.WriteLine("Is Hearts " + c.IsHeart());
            Console.WriteLine("Is Spades " + c.IsSpade());
            Console.WriteLine("Is Ace " + c.IsAce());
            Console.WriteLine("Is Face Card " + c.IsFaceCard());
            Console.WriteLine();
        }
    }
}
