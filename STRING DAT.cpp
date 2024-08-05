#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int count =1;
	int k=s.length();
	for(int i=0;i<k;i++)
	{
		if(s[i]==' ') count++;
	}
	cout<<count;
}