/*
Cho một file văn bản chứa các số nguyên dương có cấu trúc như sau:
Dòng 1: ghi 2 số nguyên dương m, n 
m dòng còn lại, mỗi dòng  ghi n số nguyên dương . Các số cách nhau ít nhất một khoảng trắng
a) Đọc dữ liệu từ file, lưu vào mảng 2 chiều A (yêu cầu dùng cấp phát động/mảng động). 
b) Tính tổng các phần tử trên mỗi dòng
c) Tạo mảng C từ mảng A sao cho  cij = aij * ki với ki là số lớn nhất trong dòng i.
d)  Gọi sij là số lượng các số nguyên tố trên dòng i và cột j. Tạo mảng D từ mảng A sao cho 
e) Yêu cầu ghi kết quả ra file output.txt. 
* Lưu ý: Viết đầy đủ chương trình có hàm main(). Kết thúc chương trình phải thu hồi vùng nhớ.
*/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void doc_file(int **&a, int &m, int &n) {
    ifstream inputfile("input.txt");
    if (!inputfile.is_open()) {
        cerr << "Khong the mo file input.txt" << endl;
        return;
    }
    inputfile >> m >> n;
    a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            inputfile >> a[i][j];
        }
    }

    inputfile.close();
}


int max_dong(int **a,int m,int n,int dong)
{
	int maxd=a[dong][0];
	for(int i=1;i<n;i++)
	{
		if(a[dong][i]>maxd)
		{
			maxd=a[dong][i];
		}
	}
	return maxd;
}
void tao_mang_c(int **a,int m,int n,int **&c,ofstream &outputfile)
{
	c=new int*[m];
	for(int i=0;i<m;i++)
	{
		c[i]=new int[n];
	}
	for(int i=0;i<m;i++)
	{
		int max_dong_c=max_dong(a,m,n,i);
		for(int j=0;j<n;j++)
		{
			c[i][j]=a[i][j]*max_dong_c;
		}
	}
	for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outputfile << c[i][j] << " ";
        }
        outputfile << endl;
    }
}
bool isPrime(int n) {
    if (n < 2) return false;
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int tong_nguyen_to_dong_cot(int **a, int m, int n, int dong2, int cot2) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[dong2][i])) {
            dem++;
        }
    }
    for (int j = 0; j < m; j++) {
        if (j != dong2 && isPrime(a[j][cot2])) {  // Tránh đếm trùng
            dem++;
        }
    }
    return dem;
}

void tao_mang_d(int **a, int m, int n, int **&d, ofstream &outputfile) {
    d = new int*[m];
    for (int i = 0; i < m; i++) {
        d[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tong_ngto = tong_nguyen_to_dong_cot(a, m, n, i, j);
            if (isPrime(a[i][j])) {
                d[i][j] = a[i][j] * tong_ngto;
            } else {
                d[i][j] = a[i][j] * tong_ngto - 1;
            }
        }
    }

    // Xuất mảng d ra file
    outputfile << "Mang D:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outputfile << d[i][j] << " ";
        }
        outputfile << endl;
    }
}


void tong_phan_tu_tung_dong(int **a, int m, int n, ofstream &outputfile) {
    for (int i = 0; i < m; i++) {
        int tong_dong = 0;
        for (int j = 0; j < n; j++) {
            tong_dong += a[i][j];
        }
        outputfile << "Tong dong " << i + 1 << " la: " << tong_dong << endl;
    }
}



void ghi_file(int **a, int m, int n) {
    ofstream outputfile("output.txt");
    if (!outputfile.is_open()) {
        cerr << "Khong the mo file output.txt" << endl;
        return;
    }

    tong_phan_tu_tung_dong(a, m, n, outputfile);

    int **d;
    tao_mang_d(a, m, n, d, outputfile);

    outputfile.close();

    // Giải phóng bộ nhớ đã cấp phát cho mảng d
    for (int i = 0; i < m; i++) {
        delete[] d[i];
    }
    delete[] d;
}

int main() {
    int **a;
    int m, n;
    doc_file(a, m, n);

    if (a != nullptr) {
        ghi_file(a, m, n);

        // Giải phóng bộ nhớ đã cấp phát cho mảng a
        for (int i = 0; i < m; i++) {
            delete[] a[i];
        }
        delete[] a;
    }

    return 0;
}
