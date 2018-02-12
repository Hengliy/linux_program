#include<iostream>
using namespace std;
#include<fcntl.h>

//int fun(int a,int b,...)
//{
//	a++;
//}

int main()
{
	int f;
	f=open("test.txt",O_WRONLY|O_TRUNC);
	if(f==-1){
		cout<<"error"<<endl;
		return -1;
	}
	cout<<"**********"<<endl;
	return 0;
}