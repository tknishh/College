#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char fileName[30], ch;
    fstream fps, fpt;
    int x;
A:  cout<<"Choose \n1. Encrypt a file \n2. Decrypt a file \n3. EXIT!"<<endl;
    cout<<"Your choice: ";
    cin>>x;
    switch(x){
    case 1:
    cout<<"Enter the Name of File: ";
    fflush(stdin);
    gets(fileName);
    fps.open(fileName, fstream::in);
    if(!fps)
    {
        cout<<"\nError Occurred, Opening the Source File (to Read)!";
        return 0;
    }
    fpt.open("tmp.txt", fstream::out);
    if(!fpt)
    {
        cout<<"\nError Occurred, Opening/Creating the tmp File!";
        return 0;
    }
    while(fps>>noskipws>>ch)
    {
        ch = ch+100;
        fpt<<ch;
    }
    fps.close();
    fpt.close();
    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout<<"\nError Occurred, Opening the Source File (to write)!";
        return 0;
    }
    fpt.open("tmp.txt", fstream::in);
    if(!fpt)
    {
        cout<<"\nError Occurred, Opening the tmp File!";
        return 0;
    }
    while(fpt>>noskipws>>ch)
        fps<<ch;
    fps.close();
    fpt.close();
    cout<<"\nFile '"<<fileName<<"' Encrypted Successfully!"<<endl;
    goto A;
    
    case 2:
    cout<<"Enter the Name of File: ";
    fflush(stdin);
    gets(fileName);
    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout<<"\nError Occurred while Opening the Source File!";
        return 0;
    }
    fpt.open("tmp.txt", fstream::in);
    if(!fpt)
    {
        cout<<"\nError Occurred while Opening/Creating tmp File!";
        return 0;
    }
    while(fpt>>noskipws>>ch)
    {
        ch = ch-100;
        fps<<ch;
    }
    fps.close();
    fpt.close();
    cout<<"\nFile '"<<fileName<<"' Decrypted Successfully!";
    cout<<endl;
    goto A;
    case 3:
    	exit;
}
    return 0;
}
