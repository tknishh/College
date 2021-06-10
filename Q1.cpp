#include<iostream>
#include<cmath>
using namespace std;
class Polar{
    int radius,angle;
    public:
    Polar(){
        cout<<"Enter radius: "<<endl;
        cin>>radius;
        cout<<"Enter angle: "<<endl;
        cin>>angle;
    }
    void display_polar(){
        cout<<"Radius of polar class: "<<radius<<endl;
        cout<<"Angle of polar class: "<<angle<<endl;
    }
    Polar(int a,int b){
      radius=sqrt(a*a + b*b);
      angle=atan(b/a);
	cout<<"Radius after conversion from polar to rectangle: "<<radius<<endl;
	cout<<"Angle after conversion from polar to rectangle: "<<angle<<endl;
    }
    int get_Radius(){
        return radius;
    }
    int get_Angle(){
        return angle;
    }
};
class Rectangle
{
    int x,y;
    public:
    Rectangle(){
      cout<<"Enter the length of rectangle: "<<endl;
      cin>>x;
      cout<<"Enter the breadth of rectangle: "<<endl;
      cin>>y;
    }
    void display_Rectangle(){
      cout<<"Length of rectangle: "<<x<<endl;
      cout<<"Breadgth of rectangle: "<<y<<endl;
    }
    Rectangle(Polar p)
    {
        x=p.get_Radius() * cos(p.get_Angle());
        y=p.get_Radius() * sin(p.get_Angle());
cout<<"Length after conversion in polar coordinates: "<<x<<endl;
cout<<"Breadth after conversion in polar coordinates: "<<y<<endl;
    }
    operator Polar()
    {
        Polar obj(x,y);
        return obj;
    }
};
int main()
{
    Polar p1;
    Rectangle r1;
    r1=p1;
    Polar p2;
    Rectangle r2;
    p2=r2;
    return 0;
}
