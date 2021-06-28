#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class levels
{
	int a,b,c,d=9;
	float p;
	public:
		void level(){
		C:	cout<<"Hello mate!"<<endl<<"Let's start!";
		B:	int r=0,w=0;
			for(int i=0; i<10;i++){
			srand(time(0));
			a= rand() % d +1;
			b= rand() % d +1;
			cout<<"\nHow much is "<<a<<" times "<<b<<"?"<<endl;
		A:	cin>>c;
			if(c==(a*b)){
				int x;
			srand(time(0));
			x= rand() % 4 +1;
			switch(x){
				case 1: cout<<"Very good!"<<endl; break;
				case 2: cout<<"Nice work!"<<endl; break;
				case 3: cout<<"Keep up the good work!"<<endl; break;
				case 4: cout<<"Excellent!"<<endl; break;
			}
				r++;
			}
			else{
				int y;
			srand(time(0));
			y= rand() % 4 +1;
			switch(y){
				case 1: cout<<"No. Please try again."<<endl; break;
				case 2: cout<<"Wrong. Try once more."<<endl; break;
				case 3: cout<<"Don't give up!"<<endl; break;
				case 4: cout<<"No. Keep trying."<<endl; break;
			}
				w++;
				goto A;
			}
		}
		cout<<"\nCorrect:"<<r<<" Incorrect:"<<w<<endl;
		p= (r/((r+w)*1.0))*100;
		if (p>75){
			cout<<"Congratulations, you are ready to go to the next level!"<<endl;
			cout<<"You may Proceed to next level"<<endl;
			d= d*10 +9;
			goto B;
		}
		else{
			cout<<"Please ask your teacher for extra help.\n"<<endl;
			goto C;
		}
		cout<<"Thank You for being with us!\n\n"<<endl;
	}
};
int main()
{
	levels l;
	l.level();		
}
