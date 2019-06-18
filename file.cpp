#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char arr[10]="abcdefghi";
	
	//for(int i=0;i<10;i++)
	//arr[i]=i;
	
	char a;
	fstream fin;
	fin.open("arr",ios::in);
	fin>>a;
	
	cout<<a;
	
}
