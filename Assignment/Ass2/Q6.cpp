#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class landline{
	string subname[50];
	long long int number;
	public:
		void call (long long int number){
			cout<<"Calling... "<<number<<endl;
		}
		void receive(){
			cout<<"Receiveing call..."<<endl;
		}
};
class mobile: public landline{
	string sub_name[60];
	long long int sub_num[50];
	int y,d_count=0,index;
	long long int d_numbers[20];
	public:
		void save(){	
			cout<<"Number of contacts to be saved: ";
			cin>>y;
			for(int i=0;i<y;i++){
				cout<<"Enter Subscriber name: ";
				fflush(stdin);
				getline(cin,sub_name[i]);
				cout<<"Enter subscriber Number: ";
				cin>>sub_num[i];
			}
		}
		void Phonebook(){
			cout<<"Contacts...\n";
			for(int i=0;i<y;i++){
				cout<<sub_name[i]<<"\t\t"<<sub_num[i]<<endl;	
			}
		}
		void Dialed(){
		long long int d_num;
		if(d_count==0){
			cout<<" There are no dailed numbers.."<<endl;
      		cout<<" Enter number you want to call: ";
      		cin>>d_num;
		}
		else{
      		cout<<"\n list of Dailed numbers : "<<endl;
      		int i=0;
      		for(i=0;i<d_count;i++){
      			cout<<i+1<<". "<<d_numbers[i]<<endl;
			}	
       		cout<<" Enter your choice: ";
      		cin>>index;
	      	d_num=d_numbers[index-1];
   		}
   		Landline:call(d_num);
   		if(d_count<20){
      		d_numbers[d_count]=d_num;
       		d_count++;
   		}
   		else if(d_count=20){
      		d_numbers[0]=d_numbers[index-1];
   		}	
		}
		void callNum(landline l){
			Phonebook();
			long long int search;
			cout<<"\n Enter number: ";
			cin>>search;
			for (int i=0;i<y;i++){
				if (sub_num[i]==search){
					l.call(sub_num[i]);
					if(d_count<20){
      					d_numbers[d_count]=sub_num[i];
       					d_count++;
   					}
   					else if(d_count=20){
      					d_numbers[0]=d_numbers[index-1];
   					}
				}
				else
					continue;
			} 
		}
		void callName(landline l){
			string search;
			cout<<"Enter name: ";
			fflush(stdin);
			getline(cin,search);
			for (int i=0;i<y;i++){
				if (sub_name[i]==search){
					l.call(sub_num[i]);
					if(d_count<20){
      					d_numbers[d_count]=sub_num[i];
       					d_count++;
   					}
   					else if(d_count=20){
      					d_numbers[0]=d_numbers[index-1];
   					}
				}
				else
					continue;
			} 
		}
};
int main(){
	int x;
	landline l;
	mobile m;
   A: cout<<"\n Choose\n 1.Save Contact\n 2.Show Phonebook\n 3.Make Call by Number\n 4.Call via Name\n 5.Call from recent calls \n 6.EXIT";
	cout<<"\n Enter your choice: ";
	cin>>x;
	switch(x){
		case 1:
			m.save();
			goto A;	
		case 2:
			m.Phonebook();
			goto A;
		case 3:
			m.callNum(l);
			goto A;
		case 4:
			m.callName(l);
			goto A;
		case 5:
			m.Dialed();
			goto A;
		case 6:
			exit;					
	}
}
