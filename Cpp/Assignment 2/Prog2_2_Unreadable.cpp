#include <stdlib.h>
#include <iostream.h>
char a[6], b[6];
bool valid1 = true, valid2 = true;
int main(){while (valid1){cout << "Enter manufacturer code: ";
cin.getline(a, 6);
valid1 = false;
for (int i = 0; i<5; i++) !isdigit(a[i]) ? valid1 = true : cout << "";
(valid1) ? cout << "Please, check the correctness of input data and try again" << endl : cout << "";}
while (valid2){cout << "Enter product code: ";
cin.getline(b, 6);
valid2 = false;
for (int i = 0; i<5; i++) !isdigit(b[i]) ? valid2 = true : cout << "";
(valid2) ? cout << "Please, check the correctness of input data and try again" << endl : cout << "";}
int checkVal;
cout << endl << "Enter check digit: ";
cin >> checkVal;
10-((((((a[1]*1)+(a[3]*1))+((b[0]*1)+(b[2]*1)+(b[4]*1)))*3)+((a[0]*1)+(a[2]*1)+(a[4]*1))+((b[1]*1)+(b[3]*1)))%10==checkVal) ? cout << endl << endl << "Code is valid" << endl : cout << endl << endl << "Code is invalid" << endl;
system("PAUSE");
return 0;}
