/* Ví dụ: Cho mảng 1  chiều n số nguyên dương. Viết hàm đệ quy thực hiện các yêu cầu sau:
a) tính tổng các phần tử trong mảng
b) tìm giá trị lớn nhất (/nhỏ nhất) trong mảng.
c) đếm số lượng các số lẻ (/chẵn, / dương,/ âm) trong mảng
d) in mảng 2 màn hình.

*/
#include<iostream>
#include<cmath>
using namespace std;
void nhap_mang(int *&a,int n)
{
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]= ";
		cin>>a[i];
	}
}

int tong_phan_tu_de_quy(int *a,int n)
{
	if(n==0) return 0;
	// if(n==1) return a[0];
	return a[n-1]+tong_phan_tu_de_quy(a,n-1);
}
int gia_tri_lon_nhat(int *a,int n)
{
	if(n==1) return a[0];
	int max_mang=gia_tri_lon_nhat(a,n-1);
	return max(a[n-1],max_mang);
}

int gia_tri_nho_nhat(int *a,int n)
{
	if(n==1) return a[0];
	int min_mang=gia_tri_nho_nhat(a,n-1);
	return min(a[n-1],min_mang);
}

int dem_so_luong_so_chan(int *a,int n)
{
    if(n==0) return 0;
    
    int so_luong_chan=0;
    if(a[n-1]%2==0)
    so_luong_chan=1;
    
    return so_luong_chan+dem_so_luong_so_chan(a,n-1);
}
int dem_so_luong_le(int *a,int n)
{
	if(n==0) return 0;
	int so_luong_le=0;
	if(a[n-1]%2!=0)
	so_luong_le=1;
	return so_luong_le+dem_so_luong_le(a,n-1);
	
}
int dem_so_duong(int *a,int n)
{
	if(n==0) return 0;
	int so_luong_duong=0;
	if(a[n-1]>0) 
	so_luong_duong=1;
	return so_luong_duong + dem_so_duong(a,n-1);
}

int dem_so_am(int *a,int n)
{
	if(n==0) return 0;
	int so_luong_am=0;
	if(a[n-1]<0)
	so_luong_am=1;
	return so_luong_am+ dem_so_am(a,n-1);
}

void in_mang_ra_man_hinh(int *a, int n) {
    if (n == 0) return; // Kiểm tra nếu mảng rỗng thì thoát
    in_mang_ra_man_hinh(a, n - 1);
    cout << a[n - 1] << " ";
}

int main()
{
   int *a;
   int n;
   cout <<"Nhap so luong phan tu n : ";
   cin>>n;
   nhap_mang(a,n);
    int tong = tong_phan_tu_de_quy(a,n);
    cout <<"Tong la : "<< tong<<endl;
    int caub=gia_tri_lon_nhat(a,n);
    cout <<"Max la : "<< caub<<endl;
     
	 int caubb=gia_tri_nho_nhat(a,n);
	 cout<<"Min la : "<< caubb<<endl;  
     
     int dem_chan=dem_so_luong_so_chan(a,n);
     cout <<"So so chan la : "<< dem_chan<<endl;
     
     int dem_le=dem_so_luong_le(a,n);
     cout <<"So so le la : "<< dem_le<<endl;
     
     int dem_duong=dem_so_duong(a,n);
     cout <<"So so duong la : "<<dem_duong<<endl;
     
     int dem_am=dem_so_am(a,n);
     cout <<"So so am la : "<<dem_am<<endl;
     in_mang_ra_man_hinh(a,n);
     return 0;
}