#include <iostream.h>
char a[6],b[6];
bool c=true;
int d;
int main(){while(c){cout<<"Enter manufacturer code: ";
cin.getline(a,6);
c=false;
for(d=0;d<5;d++)!isdigit(a[d])?c=true:cout<<"";
c?cout<<"Please, check the correctness of input data and try again"<<endl:cout<<"";}
c=true;
while(c){cout<<"Enter product code: ";
cin.getline(b,6);
c=false;
for(d=0;d<5;d++)!isdigit(b[d])?c=true:cout<<"";
c?cout<<"Please, check the correctness of input data and try again"<<endl:cout<<"";}
cout<<endl<<"Enter check digit: ";
cin>>d;
10-((((((a[1]*1)+(a[3]*1))+((b[0]*1)+(b[2]*1)+(b[4]*1)))*3)+((a[0]*1)+(a[2]*1)+(a[4]*1))+((b[1]*1)+(b[3]*1)))%10==d)?cout<<endl<<endl<<"Code is valid"<<endl:cout<<endl<<endl<<"Code is invalid"<<endl;
system("PAUSE");
return 0;}
