#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int userChoice;     // To hold the user's choice
int compChoice; // To hold the computer's choice
int choice;



//function prototypes
int getUserChoice(int);
int getCompChoice();
void determineWinner(int,int);
void displayChoice (int userChoice, int compChoice);

//*************************************************
//Function main
//*************************************************
int main()
{

    // Get the computer's choice.
    compChoice = getCompChoice();

    // Get the user's choice.
    userChoice = getUserChoice(choice);

    while (userChoice != 4)
    {
        //Displays selections
        displayChoice (userChoice,compChoice);

        // Determine the winner.
        determineWinner(userChoice, compChoice);

        // Get the computer's choice.
        compChoice = getCompChoice();

        // Get the user's choice.
        userChoice = getUserChoice(choice);
    }//end while

    return 0;
}
//end main






// The getUserChoice function displays a menu allowing
// the user to select rock, paper, or scissors. The
// function then returns 1 for rock (via the ROCK
// constant), or 2 for paper (via the PAPER constant),
// or 3 for scissors (via the SCISSORS constant).
int getUserChoice(int choice)
{
    cout<<"\n\nROCK PAPER SCISSORS!!!";
    cout<<"\n---------\n1) Rock\n2) Paper\n3) Scissors\n4) Quit\n\n";
    cout<<"Enter your choice:";
    cin>>choice;
    return choice;
}//end getUserChoice




// The getComputerChoice function returns the computer's
// game choice. It returns 1 for rock (via the ROCK
// constant), or 2 for paper (via the PAPER constant),
// or 3 for scissors (via the SCISSORS constant).
int getCompChoice()
{
    int number;
    int seed = time(0);//gets system time
    srand(seed);//seed the random number

    number = 1 + rand() % 3;//generate random # 1-3
    return number;
}//end getComputerChoice






// The displayChoice function accepts an integer
// argument and displays rock, paper, or scissors.
void displayChoice(int userChoice, int computerChoice)
{

//displays what you&the comp selected
    if(userChoice == 1)
    {
        cout<<"You selected: Rock\n";
    }//end if

    else if(userChoice == 2)
    {
        cout<<"You selected: Paper\n";
    }//end else if

    else if(userChoice == 3)
    {
        cout<<"You selected: Scissors\n";
    }//end else if #2


    if(compChoice == 1)
    {
        cout<<"The computer selected: Rock\n";
    }//end if

    else if(compChoice == 2)
    {
        cout<<"The computer selected: Paper\n";
    }//end else if

    else if(compChoice == 3)
    {
        cout<<"The computer selected: Scissors\n";
    }//end else if #2

}






// The determineWinner function accepts the user's
// game choice and the computer's game choice as
// arguments and displays a message indicating
// the winner.
void determineWinner(int userChoice, int compChoice)
{
//determines winner
    if (userChoice == compChoice)
    {
        cout <<"Tie. NO WINNER.\n\n"<<endl;
    }

    if ( userChoice == 1 && compChoice == 2)
    {
        cout << "Paper wraps rock, COMPUTER WINS\n\n";
    }
    else if (userChoice == 1 && compChoice == 3)
    {
        cout << "Rock smashes scissors. YOU WON!\n\n";
    }

    if (userChoice == 2 && compChoice == 1)
    {
        cout <<"Paper wraps rock. YOU WON!\n\n";
    }
    else if ( userChoice == 2 && compChoice == 3)
    {
        cout <<"Scissors cut paper, COMPUTER WINS\n\n";
    }

    if ( userChoice == 3 && compChoice == 1)
    {
        cout <<"Scissors cut paper, COMPUTER WINS\n\n";
    }
    else if (userChoice == 3 && compChoice == 2)
    {
        cout <<"Rock smashes scissors. YOU WON!\n\n";
    }

}//end determindWinner




/*
Proof




ROCK PAPER SCISSORS!!!
---------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice:1
You selected: Rock
The computer selected: Paper
Paper wraps rock, COMPUTER WINS



ROCK PAPER SCISSORS!!!
---------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice:2
You selected: Paper
The computer selected: Paper
Tie. NO WINNER.




ROCK PAPER SCISSORS!!!
---------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice:3
You selected: Scissors
The computer selected: Paper
Rock smashes scissors. YOU WON!



ROCK PAPER SCISSORS!!!
---------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice:4
Press any key to continue . . .
*/
