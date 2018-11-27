#include <iostream>
#include <utility> //Included library to pair function results.

using namespace std;

//Functions are declared
int Verify(int num);
pair<int,int> Rectangle(int length,int with);
pair<double,double> Circle(double diameter);

//Pi is declared as a global constant
const double Pi = 3.14159;

int main()
{
    //Local variables are declared
    int length, with;
    double diameter;

    //Ask for user to input length and wide of the rectangle and verify that the numbers are positive
    cout << "Please enter length and with of your rectangle as positive numbers: " << endl;
    cin >> length; length = Verify(length);
    cin >> with; with = Verify(with);

    //Receive 2 values from the function Rectangle and stores them in x then display out the answers
    pair<int,int> x = Rectangle(length, with);
    cout << "\nYour rectangle has an area of " << x.first << " and a perimeter of " << x.second << endl;

    //Ask for user to input diameter of the circle and verify that the number entered is positive
    cout << "\nPlease enter diameter of your circle as a positive number: ";
    cin >> diameter; diameter = Verify(diameter);

    //Receive 2 values from the function Rectangle and stores them in y then display out the answers
    pair<double,double> y = Circle(diameter);
    cout << "\nYour circle has an area of " << y.first << " and a circumference of " << y.second << endl;

    return 0;
}

// Function Verify makes sure the numbers entered are positive
int Verify(int num)
{
    while(num <= 0)
    {
        cout << "\nERROR, invalid value. Please enter a positive number: ";
        cin >> num;
        return num;
    }
}

// Function Rectangle calculates the area and perimeter of a rectangle
// from the values entered by the user and returns them to be displayed
pair<int,int> Rectangle(int length, int with)
{
    int Area = length * with;
    int Perimeter = (2 * length) + (2 * with);
    return make_pair(Area, Perimeter);
}

// Function Circle calculates the area and circumference of a circle
// from the value entered by the user and returns them to be displayed
pair<double,double> Circle(double diameter)
{
    double radius = diameter / 2;

    double Area = Pi * radius * radius;
    double Circumference = Pi * diameter;
    return make_pair(Area, Circumference);
}
