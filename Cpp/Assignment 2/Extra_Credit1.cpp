//COSC 1337.51 Spring 2013
//Dmitrii Kondratev
//1/29/2013
//Assignment 2, Extra Credit
//Program to search employee from the list by ID, last name or pay rate.
//Also it can sort and output list of employeeeees sorted by ID, last name or pay rate.

//You may remove next line to run it in DevCpp
//VS12 needs this import.
//And DevCpp doesn't have a normal debugger.
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//I highly recommend you to use Notepad++
//As it is free and easy to use. It has synthax highlighting for many major programming languages
//It also allows you to collapse functions, and leave just function headers and comments between them, which will ease
//the analysing of code

const int EMPLOYEESNUMBER = 5;
//number of employees used in all loops for easier modifications

struct Employee
{
	int ID;
	char FirstName[20];
	char LastName[20];
	float PayRate;
};

//Employee array declaration
Employee EmplArr[EMPLOYEESNUMBER];
Employee Temp;
void initEmployeesAll();
void initEmployee(int, int, string, string, float);

char var1 = 'y';
bool var2 = (var1=='y');
int var3;
int var4;

void startSearch(int);

void searchByID();
void searchByLastName();
void searchByHourlyPay();
//those three functions are starting the searach and choice between three functions comes form user inputed choice

void userInput();
void searchPromt();
void outAll();
void sortAll();
void startSort(int);
void outputResult(int, int);

//main function - 4 lines of code. Me gusta. Could have made 2;
int main()
{
	initEmployeesAll();
	//assignment of all employees in array in function initEmployeesAll();
	userInput();
    system("PAUSE");
	return 0;
}

//User option select until user decides to quit (Main menu)
void userInput()
{
	while (var2)
	{
        cout << "Select one option:" << endl << "1) Search for employee" << endl << "2) Show all employees" << endl << "3) Sort employee list" << endl;
		cin >> var4;
		switch (var4)
		{
		case 1:
			searchPromt();
			break;
		case 2:
			outAll();
			break;
		case 3:
			sortAll();
			break;
		}
        cout << "Do you want to perform another operation? (y/n)" << endl;
        cin >> var1;
        var2 = (var1=='y') || (var1=='Y');
		//loops for multiple searches in one program run
    }
}

//gives user choice of search method
void searchPromt()
{
	cout << "Choose your search method:" << endl << "(1) - Search by ID" << endl << "(2) - Search by last name" << endl << "(3) - Search by hourly pay" << endl;
        cin >> var3;
        startSearch(var3);
}

//outputs list of all employees
void outAll()
{
	for (int i = 0; i < EMPLOYEESNUMBER; i++)
	{
		outputResult(i+1, i);
	}
}

//giver user choice to sort all employees
void sortAll()
{
	cout << "Choose your sort method:" << endl << "(1) - Sort by ID" << endl << "(2) - Sort by last name" << endl << "(3) - Sort by hourly pay" << endl;
        cin >> var3;
        startSort(var3);
}

//Fuction startSort start buuble sorting of employees array, based on user input
//1 - By ID
//2 - By LastName
//3 - By PayRate
void startSort(int par1)
{
	switch (par1)
	{
	case 1:
		for (int j = 1; j < EMPLOYEESNUMBER; j++)
			for (int i = 1; i < EMPLOYEESNUMBER; i++)
			{
				if (EmplArr[i-1].ID > EmplArr[i].ID)
				{
					Temp = EmplArr[i-1];
					EmplArr[i-1] = EmplArr[i];
					EmplArr[i] = Temp;
				}
			}
		cout << "Done" << endl;
		outAll();
		break;
		case 2:
		for (int j = 1; j < EMPLOYEESNUMBER; j++)
			for (int i = 1; i < EMPLOYEESNUMBER; i++)
			{
				int cmp = strcmp(EmplArr[i-1]).LastName, EmplArr[i].LastName);
				bool var1 = (cmp>0);
				var1 ? 
				{
					Temp = EmplArr[i-1];
					EmplArr[i-1] = EmplArr[i];
					EmplArr[i] = Temp;
				} : cout << "";
				
			}
		cout << "Done" << endl;
		outAll();
        break;
		case 3:
		for (int j = 1; j < EMPLOYEESNUMBER; j++)
			for (int i = 1; i < EMPLOYEESNUMBER; i++)
			{
				if (EmplArr[i-1].PayRate > EmplArr[i].PayRate)
				{
					Temp = EmplArr[i-1];
					EmplArr[i-1] = EmplArr[i];
					EmplArr[i] = Temp;
				}
			}
		cout << "Done" << endl;
		outAll();
		break;

	}
}
//Adds employee to array
void initEmployee(int par1, int par2, char par3[], char par4[], float par5)
{
//par1 - number of employee in array + 1, so they start with 1
//par2 - Employee ID
//par3 - First Name
//par4 - Last Name
//par5 - hourly pay rate
	EmplArr[par1-1].ID = par2;
	EmplArr[par1-1].FirstName = par3;
	EmplArr[par1-1].LastName = par4;
	EmplArr[par1-1].PayRate = par5;
}
//Sends command to initEmployee function.
//One line of code - one employee.
//Really easy to add new ones
void initEmployeesAll()
{
	//when more employees needed just add lines here
	//initEmployee(number, ID, "FirstName", "LastName", payRate);
    initEmployee(1, 216, "William", "Fullerton", 13.50);
    initEmployee(2, 150, "Ashley", "Ross", 14.00);
    initEmployee(3, 78, "Sharon", "Webb", 17.20);
    initEmployee(4, 180, "George", "Ross", 16.80);
    initEmployee(5, 10, "Eli", "Manning", 35.00);
    
}

void startSearch(int par1)
{
//choose search method, and start different functions based of user input
	switch (par1)
    {
    case 1:          
        searchByID();
        break;
    case 2:          
        searchByLastName();
        break;
    case 3:
        searchByHourlyPay();
        break;
    default:
        //Handler for invalid input data
        cout << "Please choose one of the option above!" << endl;
        break;
        }
}
void searchByID()
{
    int Id;
    bool emptyResult = true;
    int extraCounter = 1;
    cout << "Please enter employee ID: ";
    cin >> Id;
    cout << "Employees found:" << endl;
    for (int i = 0; i < EMPLOYEESNUMBER; i++)
    {
        if (EmplArr[i].ID == Id)
        {
            outputResult(extraCounter, i);
            emptyResult = false;
			extraCounter++;
        }         
    }
    if (emptyResult)
    {cout << "No employees matching criteria found" << endl;}
     
}

void searchByLastName()
{
    string nam;
    bool emptyResult = true;
    int extraCounter = 1;
    cout << "Please enter employee Last Name: ";
    cin >> nam;
    cout << "Employees found:" << endl;
    for (int i = 0; i < EMPLOYEESNUMBER; i++)
    {
        if (EmplArr[i].LastName == nam)
        {
            outputResult(extraCounter, i);
            emptyResult = false;
			extraCounter++;
        }         
    }
    if (emptyResult)
    {cout << "No employees matching criteria found" << endl;}
}

void searchByHourlyPay()
{
    float rate;
    bool emptyResult = true;
    int extraCounter = 1;
    cout << "Please enter employee hourly pay rate: ";
    cin >> rate;
    cout << "Employees found:" << endl;
    for (int i = 0; i < EMPLOYEESNUMBER; i++)
    {
        if (EmplArr[i].PayRate == rate)
        {
            outputResult(extraCounter, i);
            emptyResult = false;
			extraCounter++;
        }         
    }
    if (emptyResult)
    {cout << "No employees matching criteria found" << endl;}
}

void outputResult(int par1, int par2)
{
//function takes:
//par1 - number of search result for numbering several search results
//par2 - number of employee in array
//Function formats the string and outputs it
    cout << par1 << ") " << EmplArr[par2].ID << " - " <<
        EmplArr[par2].FirstName << " " << EmplArr[par2].LastName << " - " <<
        EmplArr[par2].PayRate << "$/hour" << endl;
}
