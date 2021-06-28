#include<iostream>
#include<fstream>
using namespace std;
void delete_line(const char *file_name, int n){
    ifstream is(file_name);
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);
    char c;
    int line_no = 1;
    while (is.get(c)){
        if (c == '\n')
        line_no++;
        if (line_no != n)
            ofs << c;
    }
    ofs.close();
    is.close();
    remove(file_name);
    rename("temp.txt", file_name);
}
int main(){
	char a[100];
	cout<<"Input the file name: ";
	cin.getline(a,100);
	ofstream MyFile(a);
	MyFile<<"test line 1\ntest line 2\ntest line 3\ntest line 4";
	MyFile.close();
	int x;
	cout<<"Input the line you want to remove: ";
	cin>>x;
	delete_line(a, x);
	string myText;
	ifstream MyReadFile(a);
	while (getline (MyReadFile, myText)) {
		cout << myText<<endl;
	}
	MyReadFile.close();   
}
