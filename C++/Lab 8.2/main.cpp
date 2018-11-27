#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Global variables are declared.
int num, guess, userGuess, counter;

//Functions are declared
int randNum();
int getUserGuess(int);
void validate(int, int);
int tries();
bool playAgain();

//Main program. Will continue to run as long as user wants.
int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    do
    {
        num = randNum();
        userGuess = getUserGuess(guess);
        validate(num, userGuess);

    }while (playAgain());

    return 0;
}

/**
* randNum
* -------
* Function gets random number that user will try to guess.
**/
int randNum()
{
    return num = (rand() % 100 + 1);
}

/**
* getUserGuess
* -------
* Function gets user guess.
**/
int getUserGuess(int guess)
{
    cout << "Enter your guess: ";
    cin >> guess;
    return guess;
}

/**
* validate
* -------
* Function validates user guess and displays message
* according to comparison with randNum. Too high if the
* guessed number is greater than the randNum, too low
* if the guessed number is lower than the randNum and
* correct with the number of tries when user guess is correct.
**/
void validate(int num, int userGuess)
{
    do
    {
        if (userGuess > num)
        {
            cout << "\nToo high, try again: ";
            tries();
            cin >> userGuess;
        } else if (userGuess < num)
            {
                cout << "\nToo low, try again: ";
                tries();
                cin >> userGuess;
            }
    } while (userGuess != num);

    if (userGuess == num)
    {
        cout << "\nCORRECT! You guessed the number in " << tries() << " tries!" << endl;
        counter = 0;
    }
}

/**
* tries
* -------
* Function counts the number of guesses from the user.
**/
int tries()
{
    counter++;
    return counter;
}

/**
* playAgain
* -------
* Function will ask if user wants to play again.
* Y: Code will run again.
* N: Will exit program.
**/
bool playAgain()
{
    char answer;

    cout << "\nDo you wish to play again? (Y/N): ";
    cin >> answer; cout << endl;

    if (answer == 'y' || answer == 'Y')
        return true;
    else
        return false;
}
