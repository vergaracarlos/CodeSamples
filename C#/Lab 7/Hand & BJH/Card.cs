using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardClassLibrary
{
    public class Card
    {
        private int suit;
        private int value;

        private static string[] suits = { "", "Clubs", "Diamonds", "Hearts", "Spades" };
        private static string[] values = { "", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "Ten", "Jack", "Queen", "King" };

        public Card()
        {
            suit = 1;
            value = 1;
        }

        public Card(int v)
        {
            value = v;
        }

        public Card(int v, int s)
        {
            value = v;
            suit = s;
        }

        public string FileName
        {
            get
            {
                return "card" + values[value].Substring(0, 1) + suits[suit].Substring(0, 1) + ".jpg";
            }
        }

        public int Suit
        {
            get
            {
                return suit;
            }
            set
            {
                suit = value;
            }
        }

        public int Value
        {
            get
            {
                return value;
            }
            set
            {
                this.value = value;
            }
        }

        public bool IsAce()
        {
            if (value == 1)
                return true;
            else
                return false;
        }

        public bool IsBlack()
        {
            if (suit == 1 || suit == 4)
                return true;
            else
                return false;
        }

        public bool IsClub()
        {
            if (suit == 1)
                return true;
            else
                return false;
        }

        public bool IsDiamond()
        {
            if (suit == 2)
                return true;
            else
                return false;
        }

        public bool IsFaceCard()
        {
            if (value == 11 || value == 12 || value == 13)
                return true;
            else
                return false;
        }

        public bool IsHeart()
        {
            if (suit == 3)
                return true;
            else
                return false;
        }

        public bool IsRed()
        {
            if (suit == 2 || suit == 3)
                return true;
            else
                return false;
        }

        public bool IsSpade()
        {
            if (suit == 4)
                return true;
            else
                return false;
        }

        public override string ToString()
        {
            return values[value] + " of " + suits[suit];
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            Card c = (Card)obj;

            if (this.Value == c.Value && this.Suit == c.Suit)
                return true;
            else
                return false;
        }

        public static bool operator ==(Card c1, Card c2)
        {
            if (Object.Equals(c1, null))
                if (Object.Equals(c2, null))
                    return true;
                else
                    return false;
            else
                return c1.Equals(c2);
        }

        public static bool operator !=(Card c1, Card c2)
        {
            return !(c1 == c2);
        }
    }
}
