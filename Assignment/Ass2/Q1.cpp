#include<iostream>
using namespace std;
class vector{
	int x,y,z;
	public:
		void create(){
			cout<<" Enter value in\n x-direction: ";
			cin>>x;
			cout<<"\n y-direction: ";
			cin>>y;
			cout<<"\n z-direction: ";
			cin>>z;
			display();
		}
		void modify(){
			int n;
			cout<<"\n Choose direction value you wanna modify \n 1. x-direction\n 2. y-direction\n 3. z-direction:\n 4. NONE!"<<endl;
		A:    cout<<" Enter your choice: ";
			cin>>n;
			switch(n){
				case 1:
					cout<<" Enter new value of x: ";
					cin>>x;
					goto A;
				case 2:
					cout<<" Enter new value of y: ";
					cin>>y;
					goto A;
				case 3:
					cout<<" Enter new value of z: ";
					cin>>z;
					goto A;
				case 4:
					exit;
			}
			display();
		}
		void multiply(){
			int s;
			cout<<"\n Enter scalar quantity to multiply: ";
			cin>>s;
			x=x*s;
			y=y*s;
			z=z*s;
			display();
		}
		void display(){
			cout<<"\n Vector is: "<<x<<"i + "<<y<<"j + "<<z<<"k";
     		}
};
int main(){
	vector v;
	v.create();
	v.modify();
	v.multiply();
}
