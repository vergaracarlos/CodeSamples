#include <iostream>

using namespace std;

char choice;

void drawRect(char outChar, int row, int col);
void drawTriangle(char outChar, int dimension);
void drawSquare(char outChar, int dimension);
void drawDiamond(char outChar, int dimension);
char getUserChoice(char);

int main()
{
    int row, col, dimension;
    char value, userChoice;

    while(1)
    {
        userChoice = getUserChoice(choice);

        switch(userChoice)
        {
            case 'D': case 'd':
                cout << "\nPlease enter a character and size (size needs to be an odd number): " << endl;
                cin >> value >> dimension;
                while(dimension % 2 == 0)
                {
                    cout << "\nERROR: Size needs to be an odd number." << endl;
                    cout << "\nPlease enter the diamond size: ";
                    cin >> dimension;
                }
                    drawDiamond(value, dimension); cout << endl; break;
            case 'R': case 'r':
                cout << "\nPlease enter a character and dimensions (row and column size): " << endl;
                cin >> value >> row >> col;
                drawRect(value, row, col); cout << endl; break;
            case 'S': case 's':
                cout << "\nPlease enter a character and size: " << endl;
                cin >> value >> dimension;
                drawSquare(value, dimension); cout << endl; break;
            case 'T': case 't':
                cout << "\nPlease enter a character and size: " << endl;
                cin >> value >> dimension;
                drawTriangle(value, dimension); cout << endl; break;
            case 'E': case 'e':
                return 2;
        }
    }
    return 0;
}

void drawRect(char outChar, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << outChar;
        }
        cout << endl;
    }
}

void drawTriangle(char outChar, int dimension)
{
    for(int i = 0; i <= dimension; i++)
    {
        for(int j = 0; j < i; j++)
        {
           cout << outChar;
        }
        cout << endl;
    }
}

void drawSquare(char outChar, int dimension)
{
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
           cout << outChar;
        }
        cout << endl;
    }
}

void drawDiamond(char outChar, int dimension)
{
    int k = 0;
    for(int i = 1; i <= (dimension/2)+1; i++)
    {
        for(int j = 1; j <= (dimension - i); j++)
        {
            cout << " ";
        }
        while(k != (2*i-1))
        {
            cout << outChar;
            k++;
        }
        k = 0;
        cout << endl;
    }

    for(int m = (dimension/2); m >= 1; m--)
    {
        for(int n = (dimension - m); n > 0; n--)
        {
            cout << " ";
        }
        while(k != (2*m-1))
        {
            cout << outChar;
            k++;
        }
        k = 0;
        cout << endl;
    }
}

char getUserChoice(char choice)
{
    cout << "Select a shape: " << endl
         << "D for Diamond" << endl
         << "R for Rectangle" << endl
         << "S for Square" << endl
         << "T for Triangle" << endl
         << "E to end program" << endl << endl
         << "Enter your choice: ";
    cin >> choice;
    while(choice != 'D' && choice != 'R' && choice != 'S' && choice != 'T' && choice != 'E' && choice != 'd' && choice != 'r' && choice != 's' && choice != 't' && choice != 'e')
    {
        cout << "ERROR: Invalid choice, please select a valid option (D, R, S, T or E): ";
        cin >> choice;
    }
    return choice;
}
