#include<iostream>
#include<cstdlib>
using namespace std;
int flip()
{
	return rand() % 2;
}
int main()
{
	int coin,t=0,h=0;
	for(int i=0;i<100;i++){
		coin= flip();
		
		if(coin==0){
			cout<<"Tails \t"<<endl;
			t= t+1;
		}
		else if(coin==1){
			cout<<"Heads \t"<<endl;
			h= h+1;
		}
	}
	cout<<t<<" times Tails was result."<<endl;
	cout<<h<<" times Heads was result."<<endl;
	return 0;
}
