#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char userChoice, choice; // Holds the user's choice
int compChoice; // Holds the computer's choice

//Functions are declared
char getUserChoice(char);
int getCompChoice();
void dispCompChoice (int);
void dispWinner(int,int);
bool playAgain();

//Main program. Will continue to run as long as user wants.
int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    do
    {
        userChoice = getUserChoice(choice);
        compChoice = getCompChoice();

        dispCompChoice(compChoice);

        dispWinner(userChoice, compChoice);

    } while (playAgain());

    return 0;
}

/**
* getUserChoice
* -------
* Function gets user choice. R for rock, P for paper and s for Scissors.
* If user selects invalid choice, an error message will display until
* user enters a valid choice.
**/
char getUserChoice(char choice)
{
    cout << "ROCK, PAPER, SCISSORS" << endl;
    cout << "R for Rock\nP for Paper\nS for Scissors\n\nEnter your choice: ";
    cin >> choice;
    while (choice != 'r' && choice != 'p' && choice != 's' && choice != 'R' && choice != 'P' && choice != 'S')
    {
        cout << "\nERROR: Please enter a valid choice (R, P or S): ";
        cin >> choice;
    }
    return choice;
}

/**
* getCompChoice
* -------
* Function gets computer's choice in the form of a number between 1 and 3.
* 1 means computer chose rock.
* 2 means computer chose paper.
* 3 means computer chose scissors.
**/
int getCompChoice()
{
     return compChoice = (rand() % 3 + 1);
}

/**
* dispCompChoice
* -------
* Function displays the computer choice in text form.
**/
void dispCompChoice(int compChoice)
{
    switch(compChoice)
    {
        case 1:
            cout << "\nComputer chose Rock" << endl; break;
        case 2:
            cout << "\nComputer chose Paper" << endl; break;
        case 3:
            cout << "\nComputer chose Scissors" << endl; break;
    }
}

/**
* dispWinner
* -------
* Function will compare the choice from the user and
* from the computer and will indicate the winner or
* in case both choices are the same will indicate a tie.
**/
void dispWinner(int userChoice, int compChoice)
{
    if (((userChoice == 'r' || userChoice == 'R') && compChoice == 1) ||
        ((userChoice == 'p' || userChoice == 'P') && compChoice == 2) ||
        ((userChoice == 's' || userChoice == 'S') && compChoice == 3))
        cout << "\nTie! NO WINNER!" << endl;
    if ((userChoice == 'r' || userChoice == 'R') && compChoice == 2)
        cout << "\nPaper wraps rock! THE COMPUTER WINS!" << endl;
    else if ((userChoice == 'r' || userChoice == 'R') && compChoice == 3)
        cout << "\nRock beats scissors! YOU WIN!" << endl;
    else if ((userChoice == 'p' || userChoice == 'P') && compChoice == 1)
        cout << "\nPaper wraps rock! YOU WIN!" << endl;
    else if ((userChoice == 'p' || userChoice == 'P') && compChoice == 3)
        cout << "\nScissors cut paper! THE COMPUTER WINS!" << endl;
    else if ((userChoice == 's' || userChoice == 'S') && compChoice == 1)
        cout << "\nRock beats scissors! THE COMPUTER WINS!" << endl;
    else if ((userChoice == 's' || userChoice == 'S') && compChoice == 2)
        cout << "\nScissors cut paper! YOU WIN!" << endl;
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
