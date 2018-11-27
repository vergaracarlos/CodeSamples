/************Author: Carlos Vergara************
********Lab 7: Areas of geometric shapes******/

#include <iostream>

using namespace std;

//Functions are declared.
float circleArea(float);
float squareArea(float);
float rectangleArea(float, float);
float triangleArea(float,float);
string shapeName(int);

int main(){
    //Variables are declared.
    int shape;
    float radius, side, heightRectangle, heightTriangle, withRectangle, withTriangle, totalArea;

        cout << "Please enter the shape (circle: 1, square: 2, rectangle: 3, triangle: 4): ";
        cin >> shape;

        //Validates a correct input has been entered by the user.
        while (shape < 1 || shape > 4){
            cout << "\nPlease enter a valid input (circle: 1, square: 2, rectangle: 3, triangle: 4): ";
            cin >> shape;
        }

        //If correct input is entered by user, code proceeds with specific option to calculate the area of the shape.
        if (shape >= 1 && shape <= 4){
            shapeName(shape);
            switch (shape){
                case 1:
                    cout << "\nPlease enter the radius of the circle: ";
                    cin >> radius;
                    totalArea = circleArea(radius); break;
                case 2:
                    cout << "\nPlease enter the length of one of the sides of the square: ";
                    cin >> side;
                    totalArea = squareArea(side); break;
                case 3:
                    cout << "\nPlease enter the height and with of the rectangle: " << endl;
                    cin >> heightRectangle; cin >> withRectangle;
                    totalArea = rectangleArea(heightRectangle, withRectangle); break;
                case 4:
                    cout << "\nPlease enter the height and with of the triangle: " << endl;
                    cin >> heightTriangle; cin >> withTriangle;
                    totalArea = triangleArea(heightTriangle, withTriangle); break;
                default:
                    cout << "\nYou entered an invalid value" << endl; break;
            }
            cout << "\nThe area of the " << shapeName(shape) << " is " << totalArea << endl;
        }
}

/*circleArea Function:
Calculates the area of a circle based on the radius entered by the user.*/
float circleArea(float radius) {
    const float PI = 3.1416;
    return (PI*radius*radius);
}
/*squareArea Function:
Calculates the area of a square based on one of the sides entered by the user.*/
float squareArea(float side) {
    return (side*side);
}
/*rectangleArea Function:
Calculates the area of a rectangle based on height and with entered by the user.*/
float rectangleArea(float heightR, float withR) {
    return (heightR*withR);
}
/*triangleArea Function:
Calculates the area of a triangle based on the height and with entered by the user.*/
float triangleArea(float heightT,float withT) {
    return ((heightT*withT)*0.5);
}

string shapeName(int shape){
    switch(shape){
        case 1: return "circle";
        case 2: return "square";
        case 3: return "rectangle";
        case 4: return "triangle";
    }
}
