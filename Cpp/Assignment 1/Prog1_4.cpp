//Dmitrii Kondratev
//COSC-1337
//Programming Assignment 1, problem 4

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

long long int var1;
int extrNum(int, int);
//function extracts one digit from number
//first int - input number, second int - number of digit from the right side
//starting with 1 (example: 54321)
int powerTen(int);
//power of ten
int extractProd(long long int);
int extractManu(long long int);
//pretty self-explanatory
int checkVal = 0;
int checkSum = 0;
int calculateCheckSum(long long int);

int main(){
    
    cout << "Enter BarCode: ";
    cin >> var1;    
    cout << endl << "Enter check digit: ";
    cin >> checkVal;
    
    checkSum = calculateCheckSum(var1);
    //function calculateCheckSum separates the barcode into manufacturer
    //and produck code, then performes a lot of operations to calculate the
    //value which is supposed to be equal to the check digit, and returns
    //that value
    //I really feel like I've overcomplicated this code.
    //I just love using functions. They allow fast code rewriting 
    //without a need to change every operation over and over again    
    bool var10 = (checkSum==checkVal);
    
    var10 ? cout << endl << endl << "Code is valid" : cout << endl << endl << "Code is invalid";
    cout << endl << endl;
    
    system("PAUSE");
    
    
    return 0;   
}
int extrNum(int par1, int par2)
{
    return (par1/powerTen(par2-1))-((par1/powerTen(par2))*10);    
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

int extractProd(long long int par1)
{
    return par1-((par1/100000)*100000);
}
int extractManu(long long int par1)
{
    return par1/100000;
}

int calculateCheckSum(long long int par1)
{
    int prodCode = extractProd(par1);
    int manuCode = extractManu(par1);
    int var2 = extrNum(manuCode, 2) + extrNum(manuCode, 4);
    int var3 = extrNum(prodCode, 1) + extrNum(prodCode, 3) + extrNum(prodCode, 5);
    int var4 = (var2 + var3) * 3;
    int var5 = extrNum(manuCode, 1) + extrNum(manuCode, 3) + extrNum(manuCode, 5);
    int var6 = extrNum(prodCode, 2) + extrNum(prodCode, 4);   
    int var7 = var4 + var5 + var6;
    int var8 = var7%10; 
    int var9 = 10-var8;
    return var9;
    // I can write it all in Return statement,
    //but code is already unreadable enough
}

