/*
Cho file văn bản input.txt có cấu trúc như sau:
- Dòng đầu tiên ghi một số nguyên dương n.
- Dòng tiếp theo ghi n số nguyên dương, mỗi số cách nhau ít nhất một khoảng trắng.
Hãy viết chương trình đọc dữ liệu từ file input.txt lưu vào mảng một chiều và thực hiện các yêu cầu sau đây: 
a. Tìm giá trị lớn nhất trong mảng.
b. Tìm số nguyên tố nhỏ nhất thỏa điều kiện lớn hơn mọi giá trị trong mảng.
Ghi các kết quả vào file output.txt gồm hai dòng:
- Dòng thứ nhất ghi giá trị lớn nhất
- Dòng thứ hai ghi số nguyên tổ thỏa điều kiện tìm được

*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <limits.h>
#include <algorithm>

using namespace std;
void doc_file(int *&a,int &n)
{
	ifstream inputfile("input.txt");
	if(!inputfile.is_open())
	{
		cerr<<"Khong the mo file input. "<<endl;
	}
	
	inputfile>>n;
	a=new int[n];
	int i=0;
     while (!inputfile.eof())
{
	inputfile >>a[i];
	i++;
}



	inputfile.close();
	
}
void gia_tri_lon_nhat(int *a,int n,ofstream &outputfile)
{
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
			if(a[i]>max)
			{
				max=a[i];
			}
	}
	outputfile <<"Gia tri lon nhat: "<<max<<endl;
}


bool isPrime(int n)
{
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

void so_nguyen_to_nho_nhat_max(int *a,int n,ofstream &outputfile)
{
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	int k=max;
	while (!isPrime(k))
	{
		k++;
	}
	
	outputfile << k << endl;
}


void ghi_file(int *a,int n)
{
	ofstream outputfile("output.txt");
	if(!outputfile.is_open())
	{
		cerr<<"Khong the mo file output "<<endl;
		return;
	}
	gia_tri_lon_nhat(a,n,outputfile);
	
}

int main()
{
	int *a;
	int n;
	doc_file(a,n);
	ghi_file(a,n);
	
	delete a;
	return 0;
	
}