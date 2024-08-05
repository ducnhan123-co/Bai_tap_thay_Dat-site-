#include<iostream>
using namespace std;
int x[100];
int n,count;

void result ()
{
	cout << ++count <<": ";
	for(int i=1;i<=n;i++)
	{
		cout<<x[i]<< " ";
	}
	cout<<endl;
}
void binary_browser(int i)
{ 

	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if (i==n)
		result(1);
		else 
		binary_browser(i+1);
	}
}
int main()
{
cout<<"n= ";
cin>>n;
count=0;
binary_browser(1);	
	
	
}