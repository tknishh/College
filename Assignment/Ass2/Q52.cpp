#include<iostream>
using namespace std;
class student{
	int rollnumber;
	public:
		char studentname[100];
		void display(){
			cout<<"\n\nStudent Name: "<<studentname<<endl;
			cout<<"Roll Number: "<<rollnumber<<endl;
		}
	friend class Administration;
};
class T1T2T3: public student{
	int t1,t2,t3;
	public:
		void display(){
			cout<<"Marks in T1: "<<t1<<endl;
			cout<<"Marks in T2: "<<t2<<endl;
			cout<<"Marks in T3: "<<t3<<endl;
		}
	friend class Faculty;
	friend class Administration;
};
class P1P2: public student{
		int p1,p2;
	public:
		void display(){
			cout<<"Marks in P1: "<<p1<<endl;
			cout<<"Marks in P2: "<<p2<<endl;
		}
	friend class Faculty;
	friend class Administration;
};
class attendance: public student{
	float att;
	public:
		void display(){
			cout<<"Attendance: "<<att<<endl;
		}
	friend class Faculty;
	friend class Administration;	
};
class Total: public T1T2T3, public P1P2, public attendance{
	int total;
	public:
		char grade;
		void display(){
			cout<<"Total marks: "<<total<<endl;
			cout<<"Grade secured: "<<grade<<endl;
		}
	friend class Administration;
	friend void searching();
};
class Faculty{
	public:
		void marks(attendance& a, T1T2T3& t, P1P2& p){
			cout<<"Enter marks obtained in T1: ";
			cin>>t.t1;
			cout<<"Enter marks obtained in T2: ";
			cin>>t.t2;
			cout<<"Enter marks obtained in T3: ";
			cin>>t.t3;
			cout<<"Enter marks obtained in P1: ";
			cin>>p.p1;
			cout<<"Enter marks obtained in P2: ";
			cin>>p.p2;
			cout<<"Attendance(%): ";
			cin>>a.att;
		}
};
class Administration{
	public:
		void stuinfo(student& s){
			cout<<"\n Enter student name: ";
			fflush(stdin);
			cin.getline(s.studentname,100);
			cout<<"Enter student roll number: ";
			cin>>s.rollnumber;
		}
		void result(Total& tl, T1T2T3& t, P1P2& p){
			float per;
			tl.total = t.t1 + t.t2 + t.t3 + p.p1 + p.p2;
			per = (tl.total/500.0) * 100;
			if(per>=80)
				tl.grade = 'A';
			else if(per>=70 && per<80)
				tl.grade = 'B';
			else if(per>=60 && per<70)
				tl.grade = 'C';
			else if(per>=50 && per<60)
				tl.grade = 'D';
			else
				tl.grade = 'F';
		}
};
void sort(Total* tl, student* s, int num){ 
	for(int i=0;i<num;i++){ 
		for(int j= i+1 ; j<num ;j++){   
            	if(tl[i].grade>tl[j].grade){
				student temp ;
                  	temp = s[i] ;
                  	s[i] = s[j] ;
                        s[j] = temp ;
                  }
            }
      }  
      for (int i=0;i<num;i++){ 
		s[i].display();
      	tl[i].display();
    	}
}
void searching (Total* tl, student* s, int num, string search){ 
	int k=0;
	int length=search.length();
      for(int i=0;i<num;i++){   
      	if(s[i].studentname[length] == ' '){ 
            	for(int j=0;j<length;j++){ 
				int l=0;
            		if(search[j] != s[i].studentname[j])
            			break ;
            			if(j==length-1){
                  			k++ ;
                        		if(l=0){
					   		s[i].display();
							tl[i].display();
   			                  	l=1;
            				}
      				}
          			}
      	}
		else if(k==0)
          		cout<<"\n No result found."<<endl;
     	}
}
int main(){
	int x,y;
	student s[100];
	T1T2T3 t[100];
	P1P2 p[100];
	attendance a[100];
	Total tl[100];
	Faculty f[100];
	Administration ad[100];
   A: cout<<"Choose \n1. Enter student details \n2. View all student's info \n3. Sort by Grade \n4. Search through Name \nEnter your choice: ";
	cin>>y;
	switch(y){
		case 1:
			cout<<"\nNumber of entries: ";
			cin>>x;
			for(int i=0;i<x;i++){
			ad[i].stuinfo(s[i]);
			f[i].marks(a[i],t[i],p[i]);
			ad[i].result(tl[i],t[i],p[i]);
		}
			goto A;
		case 2:
			for(int i=0;i<x;i++){
			s[i].display();
			t[i].display();
			p[i].display();
			a[i].display();
			tl[i].display();
		}
			goto A;
		case 3:
			cout<<"Sorting by order of Grade..."<<endl;
			sort(&tl[0], &s[0], x);	
			goto A;
		case 4:
			cout<<"Enter the name you want to see grade of: "<<endl;
			string a;
			fflush(stdin);
      		getline(cin,a);
    			searching(&tl[0], &s[0], x, a);
    			goto A;
	}		
}		
