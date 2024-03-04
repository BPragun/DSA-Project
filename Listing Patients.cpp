#include<iostream>
using namespace std;
class Patient
{
	public:
	int age;
	string name;
	Patient *next;
	double number;
};
class List
{
	public:
	Patient*head=NULL;	
	void InsertBeg(string n,int a,double num)
	{
		if(head==NULL)
		{
			Patient*newpatient;
			newpatient=new Patient;
			newpatient->age=a;
			newpatient->name=n;
			newpatient->number=num;
			newpatient->next=NULL;
			head=newpatient;
		}
		else
		{
			Patient*newpatient;
			newpatient=new Patient;
			newpatient->age=a;
			newpatient->name=n;
			newpatient->number=num;
			newpatient->next=head;
			head=newpatient;	
		}
	}

   void DeleteBeg()
   {
   	Patient*temp;
   	temp=head;
   	head=temp->next;
   	cout<<"The details of patient is:"<<endl;
   	cout<<"------------------------------------------------------------------------------------------------------"<<endl;
   	cout<<"The name of patient is:  "<<temp->name<<endl;
   	cout<<"The age of patient is:  "<<temp->age<<endl;
   	cout<<"The number of patient is:  "<<temp->number<<endl;
   	delete temp;
    }	
   void InsertEnd(string n,int a,double num) 
   {
   	Patient*newpatient;
   	newpatient=new Patient;
   	Patient*temp;
   	temp=head;
   	while(temp->next!=NULL)
   	{
   	 temp=temp->next;	
	}
	newpatient->age=a;
	newpatient->name=n;
	newpatient->number=num;
	temp->next=newpatient;
	newpatient->next=NULL;
   }
  void Empty()
  {
  	cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
  	if(head==NULL)
  	cout<<"There are no Patients."<<endl;
  	cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
  }
};
int main()
{
List O,C,N;
int option,age;
string name;
double number;
do
{
cout<<"Enter the option you want to select::"<<endl;
cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"Press 1 for entering patient details , Press 2 for exiting patients details, Press 3 for Emergency, Press 0 to end."<<endl;
cin>>option;
switch(option)
{
case 1:
 cout<<"Enter the patients name: ";
 cin>>name;
 cout<<"Enter patients contact number: ";
 cin>>number;
 cout<<"Enter patients age: ";
 cin>>age;
 cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
 if(age>=75)
 {
 	if(O.head==NULL)
 	O.InsertBeg(name,age,number);
 	else
 	O.InsertEnd(name,age,number);
 }
 
 else if(age<=4)
 {
 	if(C.head==NULL)
 	C.InsertBeg(name,age,number);
 	else
 	C.InsertEnd(name,age,number);
 }
 else
 {
 	if(N.head==NULL)
 	N.InsertBeg(name,age,number);
 	else
 	 N.InsertEnd(name,age,number);
 }
 break;	
 
case 2:
 if(O.head==NULL)
 {
 	if(C.head==NULL)
 	{
 		if(N.head==NULL)
 		N.Empty();
 		else
 		N.DeleteBeg();
    }
	else
	{
	 C.DeleteBeg();	
    } 
 }	
 else
 {
 	O.DeleteBeg();
 } 
break;

case 3:
 cout<<"Enter the patients name: ";
 cin>>name;
 cout<<"Enter patients contact number: ";
 cin>>number;
 cout<<"Enter patients age: ";
 cin>>age;	
 O.InsertBeg(name,age,number);
 break;

default:
cout<<"You are requested to enter a valid option"<<endl;
break;	
}
}while(option!=0);
return 0;
}
