//Dmitrii Kondratev
//COSC-1337
//Programming Assignment 2, problem 3

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

char input[7];

bool checkValidity(char[]);
bool isNumInRange(int, int, int);

int main()
{
    cout << "Enter detail code to order: ";
    cin.getline(input, 7);
    bool res = checkValidity(input);
    res ? cout << "Detail code is valid" << endl : cout << "Detail code is invalid" << endl;
    system("PAUSE");
    return 0;    
}

bool checkValidity(char par1[])
{
    bool var1 = (par1[0]=='A') || (par1[0]=='B') || (par1[0]=='C');
    bool var2 = isdigit(par1[1]) && isdigit (par1[2]);
    bool var3 = false;
    if (var2){var3 = isNumInRange(((par1[1]-48)*10) + ((par1[2]-48)*1), 10, 49);}
    bool var4 = islower(par1[3]);
    bool var5 = isdigit(par1[4]) && isdigit (par1[5]);
    bool var6 = false;
    if (var5){var6 = isNumInRange(((par1[4]-48)*10) + ((par1[5]-48)*1), 22, 66);}
    return (var1 && var2 && var3 && var4 && var5 && var6);
}

bool isNumInRange(int par1, int par2, int par3)
{
    bool ret = false;
    if ((par1 <= par3) && (par1 >= par2)) {ret = true;}
    return ret;
}
