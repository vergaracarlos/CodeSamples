#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

// Struct is declared
struct playerMove
{
    int One;
    int Two;
}play;

// Constant variables are declared
const int MAX = 16;
const char EMPTY = ' ';
const char HIDE = 'X';

// Function prototypes are declared
char *createBoard1(int length);
char *createBoard2(int length);
void *displayBoard(char *arr, int length);
void *getMove(struct playerMove *play);
void *checkMove(char *arr, char *arr2, int length, int pos1);
void *checkMove(char *arr, char *arr2, int length, int &pos1, int &pos2);
bool checkWin(char *arr, int length);
bool playAgain();

int main()
{
    // Randomizer gets seeded
    srand(static_cast<int>(time(NULL)));

    // Local variables are declared
    char *board1;
    char *board2;
    int pos1, pos2;

    board1 = createBoard1(MAX);
    board2 = createBoard2(MAX);

    do // Loop until player don't want to play again
    {
        do // Loop until player wins
        {
            displayBoard(board1, MAX);

            getMove(&play);
            pos1 = play.One * (MAX/4) + play.Two;
            checkMove(board1, board2, MAX, pos1);

            getMove(&play);
            pos2 = play.One * (MAX/4) + play.Two;
            checkMove(board1, board2, MAX, pos1, pos2);

        } while(!checkWin(board1, MAX));

        cout << "You WIN!" << endl;
    } while(playAgain());

    delete[] board1;
    delete[] board2;

    return 0;
}

/*
    Function createBoard1
    A board size 4 by 4 is created and filled with X's.
*/
char *createBoard1(int length)
{
    char *theBoard1 = new char[length];

    for(int i = 0; i < length; i++)
    {
        theBoard1[i] = HIDE;
    }

    return theBoard1;
}

/*
    Function createBoard2
    A board size 4 by 4 is created and filled with 8 pair
    of symbols. Then the symbols get placed in random order.
*/
char *createBoard2(int length)
{
    char *theBoard2 = new char[length] {'@','@','#','#','&','&','%','%','?','?','!','!','+','+','*','*'};
    int x;

    for(int a = 0; a < 100; a++)
    {
        for(int i = 0; i < length; i++)
        {
            x = rand() % length;
            swap(theBoard2[i], theBoard2[x]);
        }
    }

    return theBoard2;
}

/*
    Function displayBoard
    Displays the board filled with X's.
*/
void *displayBoard(char *arr, int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << setw(3) << *(arr+i);
        if ( (i+1) % 4 == 0 )
            cout << endl;
    }
}

/*
    Function getMove
    Ask's the user for a row and a column to uncover.
    Check's if user's entry is within bound (0-3).
*/
void *getMove(struct playerMove *play)
{
    cout << "\n - Enter your move - " << endl;
    cout << "Row: ";
    cin >> play->One;

    while(play->One < 0 || play->One > 3)
    {
        cout << "ERROR: Invalid input!" << endl;
        cout << "Row: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> play->One;
    }

    cout << "Column: ";
    cin >> play->Two;

    while(play->Two < 0 || play->Two > 3)
    {
        cout << "ERROR: Invalid input!" << endl;
        cout << "Column: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> play->Two;
    }
}

/*
    Function checkMove
    Display's the board uncovering the position entered by the user.
*/
void *checkMove(char *arr, char *arr2, int length, int pos1)
{
    for(int i = 0; i < length; i++)
    {
        if(i != pos1)
            cout << setw(3) << *(arr+i);
        else
            cout << setw(3) << *(arr2+pos1);
        if ( (i+1) % 4 == 0 )
            cout << endl;
    }
}

/*
    Function checkMove
    Display's the board uncovering both positions entered by the user.
    If the symbols match they are replaced by an empty space.
*/
void *checkMove(char *arr, char *arr2, int length, int &pos1, int &pos2)
{
    for(int i = 0; i < length; i++)
    {
        if(i == pos1)
            cout << setw(3) << *(arr2+pos1);
        else if(i == pos2)
            cout << setw(3) << *(arr2+pos2);
        else
            cout << setw(3) << *(arr+i);
        if ( (i+1) % 4 == 0 )
            cout << endl;
    }
    cout << endl << endl;

    if(*(arr2+pos1) == *(arr2+pos2))
    {
        *(arr+pos1) = EMPTY;
        *(arr+pos2) = EMPTY;
    }
}

/*
    Function checkWin
    Check's if the user matched the 8 pair of symbols in the board.
*/
bool checkWin(char *arr, int length)
{
    int counter = 0;
    for(int i = 0; i < length; i++)
    {
        if(*(arr+i) == EMPTY)
            counter++;
        if(counter == 16)
            return true;
    }
    return false;
}

/*
    Function playAgain
    Ask's the user if he would like to play again.
*/
bool playAgain()
{
    char answer;
    cout << "\nDo you want to go again? (Y/N) ";
    cin >> answer;
    answer = tolower(answer);

    do {
        if (answer != 'y' && answer != 'n')
        {
            cout << "\nERROR: Invalid input, need a 'Y' or 'N'" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> answer;
            answer = tolower(answer);
        }
    } while(answer != 'y' && answer != 'n');

    return answer == 'y';
}
