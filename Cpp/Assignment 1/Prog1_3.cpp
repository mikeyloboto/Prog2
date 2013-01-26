//Dmitrii Kondratev
//COSC-1337
//Programming Assignment 1, problem 3

#include <stdlib.h>
#include <iostream.h>
//define the constatnt
#define PI 3.14159

float input = 0;
float diameter = 0;
float circumference = 0;
float area = 0;

int main()
{
    cout << "Input the circle radius: ";
    //input radius:
    cin >> input;
    //calculate and out put everything
    //name of variable is pretty self-explanatory.
    diameter = input * 2;
    cout << endl << "Diameter is: " << diameter << endl;
    circumference = 2 * PI * input;
    cout << "Circumference is: " << circumference << endl;
    area = PI * input * input;
    cout << "Area is: " << area << endl;
    //hold the screen, allowing user to see the output
    system("PAUSE"); 
    return 0;   
}
