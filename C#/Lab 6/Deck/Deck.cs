using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardClassLibrary
{
    public class Deck
    {
        private List<Card> cards;

        public Deck()
        {
            cards = new List<Card>();

            for (int suit = 1; suit <= 4; suit++)
            {
                for (int value = 1; value <= 13; value++)
                {
                    cards.Add(new Card(value, suit));
                }
            }
        }

        public int NumCards
        {
            get
            {
                return cards.Count;
            }
        }

        public Card Deal()
        {
            Card c = cards[0];
            cards.RemoveAt(0);
            return c;
        }

        public bool IsEmpty()
        {
            if (cards.Count() == 0)
                return true;
            else
                return false;
        }

        public void Shuffle()
        {
            Random generator = new Random();
            for (int i = 0; i <= 51; i++)
            {
                int randomIndex = generator.Next(0, 52);
                Card temp = cards[randomIndex];
                cards[randomIndex] = cards[i];
                cards[i] = temp;
            }
        }

        public override string ToString()
        {
            string output = "";
            foreach (Card c in cards)
            {
                output += c.ToString() + "\n";
            }
            return output;
        }

    }
}
