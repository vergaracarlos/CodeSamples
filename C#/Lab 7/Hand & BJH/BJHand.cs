using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardClassLibrary
{
    public class BJHand : Hand
    {
        public BJHand() : base() { }

        public bool HasAce()
        {
            return HasCard(1);
        }

        public int Score
        {
            get
            {
                int score = 0;

                foreach (Card c in cards)
                {
                    if (c.IsFaceCard())
                        score += 10;
                    else if (c.IsAce())
                        score += 1;
                    else
                        score += c.Value;
                }

                if (HasAce() && score <= 11)
                    score += 10;

                return score;
            }
        }

        public bool IsBusted
        {
            get
            {
                if (Score > 21)
                    return true;
                else
                    return false;
            }
        }
    }
}
