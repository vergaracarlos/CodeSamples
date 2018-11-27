using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardClassLibrary
{
    public class Hand
    {
        protected List<Card> cards;

        public Hand()
        {
            cards = new List<Card>();
        }

        public void Add(Card c)
        {
            cards.Add(c);
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

        public bool HasCard(Card c)
        {
            return cards.Contains(c);
        }

        public bool HasCard(int value, int suit)
        {
            return HasCard(new Card(value,suit));
        }

        public bool HasCard(int value)
        {
            if (HasCard(value, 1) || HasCard(value, 2) || HasCard(value, 3) || HasCard(value, 4))
                return true;
            else
                return false;
        }

        public int IndexOf(Card c)
        {
            return cards.IndexOf(c);
        }

        public int IndexOf(int value, int suit)
        {
            return IndexOf(new Card(value, suit));
        }

        public int IndexOf(int value)
        {
            return IndexOf(new Card(value));
        }

        public int NumCards
        {
            get
            {
                return cards.Count;
            }
        }

        public Card this[int i]
        {
            get
            {
                return cards[i];
            }
        }

        public Card Discard(int index)
        {
            Card c = cards[index];
            cards.RemoveAt(index);
            return c;
        }


    }
}
