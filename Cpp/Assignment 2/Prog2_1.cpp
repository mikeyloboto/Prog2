//Assignment 2, program 1
//Dmitrii Kondratev
//
#include <iostream>
#include <string>
using namespace std;


const int EMPLOYEESNUMBER = 5;

struct Employee
{
	int ID;
	string FirstName;
	string LastName;
	float PayRate;
};

Employee EmplArr[EMPLOYEESNUMBER];

void initEmployeesAll();
void initEmployee(int, int, string, string, float);

char var1 = 'y';
bool var2 = (var1=='y');
int var3;

void startSearch(int);
void searchByID();
void searchByLastName();
void searchByHourlyPay();

void outputResult(int, int);

int main()
{
	initEmployeesAll();
	while (var2)
	{
          cout << "Choose your search method:" << endl << "(1) - Search by ID" << endl << "(2) - Search by last name" << endl << "(3) - Search by hourly pay" << endl;
          cin >> var3;
          startSearch(var3);
          cout << "Do you want to search for another employee? (y/n)" << endl;
          cin >> var1;
          var2 = (var1=='y') || (var1=='Y');
    }
    system("PAUSE");
	return 0;
}

void initEmployee(int par1, int par2, string par3, string par4, float par5)
{
	EmplArr[par1-1].ID = par2;
	EmplArr[par1-1].FirstName = par3;
	EmplArr[par1-1].LastName = par4;
	EmplArr[par1-1].PayRate = par5;
}

void initEmployeesAll()
{
     initEmployee(1, 216, "William", "Fullerton", 13.50);
     initEmployee(2, 150, "Ashley", "Ross", 14.00);
     initEmployee(3, 78, "Sharon", "Webb", 17.20);
     initEmployee(4, 180, "George", "Ross", 16.80);
     initEmployee(5, 10, "Eli", "Manning", 35.00);
     
}

void startSearch(int par1)
{
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
         }         
     }
     if (emptyResult)
     {cout << "No employees matching criteria found" << endl;}
}

void outputResult(int par1, int par2)
{
     cout << par1 << ") " << EmplArr[par2].ID << " - " <<
              EmplArr[par2].FirstName << " " << EmplArr[par2].LastName << " - " <<
              EmplArr[par2].PayRate << "$/hour" << endl;
}
