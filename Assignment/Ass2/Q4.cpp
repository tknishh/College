#include<iostream>
using namespace std; 
class student{
	public:
	char name[30];
	int Branch_Number;
};
class CSE: public student{
	int CSE_sub1_marks;
	int CSE_sub2_marks;
	int CSE_sub3_marks;
	public:
		void getdata(){
			cout<<" Enter name: ";
			fflush(stdin);
			cin.getline(name,30);
			cout<<" Enter marks of sub1: ";
			cin>>CSE_sub1_marks;
			cout<<" Enter marks of sub2: ";
			cin>>CSE_sub2_marks;
			cout<<" Enter marks of sub3: ";
			cin>>CSE_sub3_marks;
		}
		void display(){
			cout<<" Name: "<<name<<endl;
			cout<<" Branchno: 1"<<endl;
			cout<<" Sub1: "<<CSE_sub1_marks<<endl;
			cout<<" Sub2: "<<CSE_sub2_marks<<endl;
			cout<<" Sub3: "<<CSE_sub3_marks<<endl;
		}
};
class ECE: public student{
	int ECE_sub1_marks;
	int ECE_sub2_marks;
	int ECE_sub3_marks;
	public:
		void getdata(){
			cout<<" Enter name: ";
			fflush(stdin);
			cin.getline(name,30);
			cout<<" Enter marks of sub1: ";
			cin>>ECE_sub1_marks;
			cout<<" Enter marks of sub2: ";
			cin>>ECE_sub2_marks;
			cout<<" Enter marks of sub3: ";
			cin>>ECE_sub3_marks;
		}
		void display(){
			cout<<" Name: "<<name<<endl;
			cout<<" Branchno: 2"<<endl;
			cout<<" Sub1: "<<ECE_sub1_marks<<endl;
			cout<<" Sub2: "<<ECE_sub2_marks<<endl;
			cout<<" Sub3: "<<ECE_sub3_marks<<endl;
		}
};
int main(){
	student s;
	CSE c1,c2;
	ECE e1,e2,e3;
	cout<<" 1.CSE\n Enter marks of 1st student:"<<endl;
	c1.getdata();
	cout<<"\n Enter marks of 2nd student:"<<endl;
	c2.getdata();
	cout<<" 2.ECE\n Enter marks of 1st student:"<<endl;
	e1.getdata();
	cout<<"\n Enter marks of 2nd student:"<<endl;
	e2.getdata();
	cout<<"\n Enter marks of 3rd student:"<<endl;
	e3.getdata();
	cout<<"\n Marks are as follow: \n 1.CSE"<<endl;
	cout<<"\n Marks of 1st student:"<<endl;
	c1.display();
	cout<<"\n Marks of 2nd student:"<<endl;
	c2.display();
	cout<<"\n 2.ECE"<<endl;
	cout<<"\n Marks of 1st student:"<<endl;
	e1.display();
	cout<<"\n Marks of 2nd student:"<<endl;
	e2.display();
	cout<<"\n Marks of 3rd student:"<<endl;
	e3.display();
}
