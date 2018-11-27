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
            /*Card c1 = new Card(1, 1);
            Card c2 = new Card(12, 2);
            Card c3 = new Card(13, 3);
            Card c4 = new Card(1, 4);*/

            Deck d = new Deck();

            //TestProductPropertyGetters();
            //TestProductPropertySetters();
            TestConstructor();
            TestPropertyCount(d);
            TestShuffle(d);
            TestDeal(d);
            TestIsEmty(d);
            //TestHasCard();

            /*TestCardIs(c1);
            TestCardIs(c2);
            TestCardIs(c3);
            TestCardIs(c4);*/

            Console.ReadLine();
        }

        static void TestConstructor()
        {
            /*Card c1 = new Card();
            Card c2 = new Card(3,4);

            Console.WriteLine("Testing both constructors");
            Console.WriteLine("Default constructor.  Expecting Ace of Clubs. " + "\n" + c1);
            Console.WriteLine("Overloaded constructor.  Expecting 3 of Spades. " + "\n" + c2);
            Console.WriteLine();*/

            Deck d = new Deck();

            Console.WriteLine("Testing deck constructor");
            Console.WriteLine("Default constructor. Expecting 52 cards. " + "\n" + d);
            Console.WriteLine();
        }

        static void TestProductPropertyGetters()
        {
            /*Card c1 = new Card(3,4);

            Console.WriteLine("Testing getters");
            Console.WriteLine("Value.  Expecting 3. " + "\n" + c1.Value);
            Console.WriteLine("Suit.  Expecting 4. " + "\n" + c1.Suit);
            Console.WriteLine();*/
        }

        static void TestProductPropertySetters()
        {
            /*Card c1 = new Card(1,1);

            Console.WriteLine("Testing setters");
            c1.Value= 3;
            c1.Suit = 4;
            Console.WriteLine("Expecting 3 of Spades. " + "\n" + c1);
            Console.WriteLine();*/
        }

        static void TestCardIs(Card c)
        {
            /*Console.WriteLine("Testing Is Method with " + c);
            Console.WriteLine("Is Red " + c.IsRed());
            Console.WriteLine("Is Black " + c.IsBlack());
            Console.WriteLine("Is Clubs " + c.IsClub());
            Console.WriteLine("Is Diamond " + c.IsDiamond());
            Console.WriteLine("Is Hearts " + c.IsHeart());
            Console.WriteLine("Is Spades " + c.IsSpade());
            Console.WriteLine("Is Ace " + c.IsAce());
            Console.WriteLine("Is Face Card " + c.IsFaceCard());
            Console.WriteLine();*/
        }

        static void TestPropertyCount(Deck d)
        {
            Console.WriteLine("Testing count");
            Console.WriteLine("Count. Expecting 52. " + "\n" + d.NumCards);
            Console.WriteLine();
        }

        static void TestShuffle(Deck d)
        {
            d.Shuffle();
            Console.WriteLine("Testing Shuffle");
            Console.WriteLine("Shuffle. Expecting shuffled deck. " + "\n" + d);
            Console.WriteLine();
        }

        static void TestDeal(Deck d)
        {
            Console.WriteLine("Testing Deal");
            Console.WriteLine("Deal. Expecting the 52 cards on deck. " + "\n");
            for (int i = 0; i < 52; i++)
                Console.WriteLine(d.Deal());
            Console.WriteLine();
        }

        static void TestIsEmty(Deck d)
        {
            Console.WriteLine("Testing IsEmpty");
            Console.WriteLine("IsEmpty. Expecting True. " + "\n" + d.IsEmpty());
            Console.WriteLine();
        }

        static void TestHasCard()
        {
            Hand h = new Hand();
            Card c1 = new Card();
            Card c2 = new Card(3, 4);
            Card c3 = new Card(3, 4);

            h.Add(c1);
            h.Add(c2);

            Console.WriteLine("Testing HasCard");
            Console.WriteLine("The hand is: \n" + h);
            if (h.HasCard(3))
                Console.WriteLine(3 + " is in the hand.");
            else
                Console.WriteLine(3 + " is NOT in the hand");
        }
    }
}
