#include<iostream>
using namespace std;
class FLOAT{
	float x;
	public:
		void getdata(float a){
			x = a; 	
		}
		void display(){
			cout<<"\n Number: "<<x<<endl;
		}
		FLOAT operator+(FLOAT f){
			FLOAT t;
			t.x = x + f.x;
 			return t;
		}
		FLOAT operator-(FLOAT f){
			FLOAT t;
			t.x = x - f.x;
 			return t;
		}
		FLOAT operator*(FLOAT f){
			FLOAT t;
			t.x = x * f.x;
 			return t;
		}
		FLOAT operator/(FLOAT f){
			FLOAT t;
			t.x = x / f.x;
 			return t;
		}
};
int main(){
	int x;
	float y,z;
	FLOAT f,f1,f2;
	cout<<" Enter 1st number: ";
	cin>>y;
	cout<<" Enter 2nd number: ";
	cin>>z;
	f1.getdata(y);
	f1.display();
	f2.getdata(z);
	f2.display();
   A: cout<<"\n 1.ADD \n 2.SUBTRACT \n 3.MULTIPLY \n 4.DIVIDE \n 5.EXIT"<<endl;
	cout<<" Enter your choice: ";
	cin>>x;
	switch(x){
		case 1: 
			f = f1 + f2;
			f.display();
			goto A;
	      case 2: 
			f = f1 - f2;
			f.display();
			goto A;
		case 3:
			f = f1 * f2;
			f.display();
			goto A;
		case 4:
			f = f1 / f2;
			f.display();
			goto A;
		case 5:
			cout<<"\n \n Program Terminated!!";	              
	}
}
