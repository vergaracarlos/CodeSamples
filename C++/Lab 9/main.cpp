#include <iostream>
#include <fstream>

using namespace std;

void drawRectangle(char out, int rows, int col)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
            {
                cout << out;
            }
       cout << endl;
    }
}

void drawTriangle(char out, int height)
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<=i;j++)
            {
                cout << out;
            }
       cout << endl;
    }
    return;
}

void drawSquare(char out, int sides)
{
    for(int i=0;i<sides;i++)
    {
        for(int j=0;j<sides;j++)
            {
                cout << out;
            }
       cout << endl;
    }
}

void drawDiamond(char out, int dmnd)
{
    for(int i=0;i<(dmnd+1)/2;i++,printf("\n"))
    {
        for(int j=0;j<(dmnd+1)/2-i-1;j++)
        cout << ' ';
        for(int j=0;j<2*i+1;j++)
        cout << out;
    }
    for(int i=(dmnd-1)/2-1;i>=0;i--,printf("\n"))
    {
        for(int j=0;j<=(dmnd)/2-i-1;j++)
        cout << ' ';
        for(int j=0;j<2*i+1;j++)
        cout << out;
    }
}

int main()
{
    int row, col, height, sides, dmnd;
    char value;

    ifstream infile;
	infile.open("input.txt");

	ofstream outfile;
	outfile.open("output.txt");

	if (!infile.good()) // make sure it works properly
	{
		cout << "ERROR: Failed to open\n";
	}
	else // all is good, continue with rest of program
	{
		//char c,a,b,d,e,f,g,h,k,l; // define a variable to read the data into

		while (!infile.eof())
		{
		    /*infile.get(c);
		    switch(c)
		    {
                case 'D': infile.get(a);
                        infile.get(b);//cin >> c >> c;
                        drawDiamond(a, b);
                case 'R': infile.get(d);
                        infile.get(e);
                        infile.get(f);//cin >> c >> c >> c;
                        drawRectangle(d, e, f);
                case 'T': infile.get(g);
                        //cout << a;
                        infile.get(h);
                        //cout << b;//cin >> c >> c;
                        drawTriangle(g, h);
                case 'S': infile.get(k);
                        infile.get(l);//cin >> c >> c;
                        drawSquare(k, l);
		    }*/
			//cout << c << endl; // write out what you just read to the console, one line at a time
		}

        infile.close(); //close file
	}

    /*cout <<	"Enter your character, row and column values" << endl;
    cin	>> value >> dmnd;
    drawDiamond(value, dmnd);*/

    return 0;
}
