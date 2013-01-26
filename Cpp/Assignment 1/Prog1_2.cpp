//Dmitrii Kondratev
//COSC-1337
//Programming Assignment 1, problem 2

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
//import all the necessary header files
//and declaring variables
void inpstart();
int nums[3];
int sum = 0;
int avg = 0;
int prod = 1;
int min = 0;
int max = 0;

int main()
{
    //i've used to do all the stuff in the separate functions.
    //sorry about that
    //start this function
    inpstart(); 
    //holds a screen for output readability
    cout << endl;
    system("PAUSE");
    return 0;
}

void inpstart()
{
     cout << "Input three different integers: ";
     //inputting 3 numbers in array
     cin >> nums[0] >> nums[1] >> nums[2];
     //init assignment of min and max variables for further comparisson
     min = nums[0];
     max = nums[0];
     //starting loop to perform some crazy calculations with
     //those three variables
     for (int i = 0; i <= 2; i++)
     {
         //cout << " " << nums[i];
         //^unnecessary line. used it to test to inputs.
         //used to leave all that I wrote in the program as comments
         //even if I'm not using it anymore
         sum += nums[i];
         //^adding number to dum
         prod = prod*nums[i];
         //^multiplying product by number
         if (min>nums[i])
         {
            min = nums[i];
         }
         //^comparing with minimal value, and replacing it if necessary
         if (max<nums[i])
         {
            max = nums[i];
         }
         //^comparing with max value and replacing max value if necessary
     }
     avg = sum/3;
     //^calculating the average
     cout << "Sum is: " << sum;
     cout << endl << "Average is: " << avg;
     cout << endl << "Product is: " << prod;
     cout << endl << "Smallest is: " << min;
     cout << endl << "Largest is: " << max;
     //^output everything
     
}
