//COSC 1337.51 Spring 2013
//Dmitrii Kondratev
//1/29/2013
//Assignment 2, Program 2
//Program to check validity of the barcode.
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

long long int var1;
int extrNum(char[], int);
//function extracts one digit from number
//first int - input number, second int - number of digit from the right side
//starting with 1 (example: 54321)
int powerTen(int);
//power of ten
int checkVal = 0;
int checkSum = 0;
int calculateCheckSum(long long int);

int manCod;
int prodCod;

char ManufactCode[6];
char ProductCode[6];

bool valid1 = true;
bool valid2 = true;

int main(){
    while (valid1)
    {
        cout << "Enter manufacturer code: ";
        cin.getline(ManufactCode, 6);
        valid1 = false;
        for (int i = 0; i<5; i++)
        {
            if (!isdigit(ManufactCode[i]))
            {
                valid1 = true;                                           
            }              
        }
        if (valid1)
        {
            cout << "Please, check the correctness of input data and try again" << endl;
        }
    }
    while (valid2)
    {
        cout << "Enter product code: ";
        cin.getline(ProductCode, 6);
        valid2 = false;
        for (int i = 0; i<5; i++)
        {
            if (!isdigit(ProductCode[i]))
            {
                valid2 = true;                                           
            }              
        }
        if (valid2)
        {
            cout << "Please, check the correctness of input data and try again" << endl;                      
        }
    }
    
    cout << endl << "Enter check digit: ";
    cin >> checkVal;
    
    checkSum = calculateCheckSum(var1);   
    bool var10 = (checkSum==checkVal);
    
    var10 ? cout << endl << endl << "Code is valid" : cout << endl << endl << "Code is invalid";
    cout << endl << endl;
    
    system("PAUSE");
    
    
    return 0;   
}
int extrNum(char par1[], int par2)
{
    return (par1[par2-1]*1);    
}
int powerTen(int par1)
{
    int varFP1 = 1;
    for (int i = 1; i <=par1; i++)
    {
        varFP1 = varFP1*10; 
    }
    return varFP1;
}

int calculateCheckSum(long long int par1)
{
    int var2 = extrNum(ManufactCode, 2) + extrNum(ManufactCode, 4);
    int var3 = extrNum(ProductCode, 1) + extrNum(ProductCode, 3) + extrNum(ProductCode, 5);
    int var4 = (var2 + var3) * 3;
    int var5 = extrNum(ManufactCode, 1) + extrNum(ManufactCode, 3) + extrNum(ManufactCode, 5);
    int var6 = extrNum(ProductCode, 2) + extrNum(ProductCode, 4);   
    int var7 = var4 + var5 + var6;
    int var8 = var7%10; 
    int var9 = 10-var8;
    return var9;
    // I can write it all in Return statement,
    //but code is already unreadable enough
}

