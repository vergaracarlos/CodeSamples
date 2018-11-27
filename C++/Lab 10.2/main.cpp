#include <iostream>
#include <fstream>

using namespace std;

//Function prototypes
void drawRectangle(char outChar, int row, int col);
void drawTriangle(char outChar, int dimension);
void drawSquare(char outChar, int dimension);
void drawDiamond(char outChar, int dimension);

int main()
{
    //Variables declared
    int row, col, dimension;
    char value, userChoice;

    //Open input
    ifstream infile;
    infile.open("infile.txt");

    //Error in case file is not found or invalid
    if ( !infile.good() )
	{
		cout << "ERROR: Failed to open file!\n";
		return 1;
	}

	//Program loops until
	while(1)
    {
        //Variable that stores the shape
        infile >> userChoice;

        //After shape is selected, character and size are entered to draw proper figure
        switch(userChoice)
        {
            case 'D': case 'd':
                infile >> value >> dimension;
                drawDiamond(value, dimension); break;
            case 'R': case 'r':
                infile >> value >> row >> col;
                drawRectangle(value, row, col); break;
            case 'S': case 's':
                infile >> value >> dimension;
                drawSquare(value, dimension); break;
            case 'T': case 't':
                infile >> value >> dimension;
                drawTriangle(value, dimension); break;
            case 'E': case 'e':
                return 2;
            default:
                cout << "ERROR: Invalid input found." << endl;
                return 3;
        }
    }

    //close input
    infile.close();

    return 0;
}

/**
* drawDiamond uses outChar and dimension to draw a diamond shape in the output file.
**/
void drawDiamond(char outChar, int dimension)
{
    ofstream outfile;

    outfile.open("append.txt", ios::app);

    int k = 0;
    for(int i = 1; i <= (dimension/2)+1; i++)
    {
        for(int j = 1; j <= (dimension - i); j++)
        {
            outfile << " ";
        }
        while(k != (2*i-1))
        {
            outfile << outChar;
            k++;
        }
        k = 0;
        outfile << endl;
    }

    for(int m = (dimension/2); m >= 1; m--)
    {
        for(int n = (dimension - m); n > 0; n--)
        {
            outfile << " ";
        }
        while(k != (2*m-1))
        {
            outfile << outChar;
            k++;
        }
        k = 0;
        outfile << endl;
    }
    outfile.close();
}

/**
* drawRectangle uses outChar, row and col to draw a rectangle shape in the output file.
**/
void drawRectangle(char outChar, int row, int col)
{
    ofstream outfile;

    outfile.open("append.txt", ios::app);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            outfile << outChar;
        }
        outfile << endl;
    }
    outfile.close();
}

/**
* drawSquare uses outChar and dimension to draw a square shape in the output file.
**/
void drawSquare(char outChar, int dimension)
{
    ofstream outfile;

    outfile.open("append.txt", ios::app);

    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
           outfile << outChar;
        }
        outfile << endl;
    }
    outfile.close();
}

/**
* drawDiamond uses outChar and dimension to draw a triangle shape in the output file.
**/
void drawTriangle(char outChar, int dimension)
{
    ofstream outfile;

    outfile.open("append.txt", ios::app);

    for(int i = 0; i <= dimension; i++)
    {
        for(int j = 0; j < i; j++)
        {
           outfile << outChar;
        }
        outfile << endl;
    }
    outfile.close();
}
