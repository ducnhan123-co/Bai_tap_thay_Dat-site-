#include <iostream>
#include <cmath>
#include <fstream>
#include <limits.h>
#include <algorithm>

using namespace std;

void doc_file(int **&a, int &m, int &n) {
    ifstream inputfile("table.in");
    if (!inputfile.is_open()) {
        cerr << "Khong the mo file input." << endl;
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

void gia_tri_lon_nhat_mang(int **a, int m, int n, ofstream &outputfile) {
    int max = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    outputfile << "Gia tri lon nhat: " << max << endl;
}

void gia_tri_nho_nhat_mang(int **a, int m, int n, ofstream &outputfile) {
    int min = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }
    outputfile << "Gia tri nho nhat: " << min << endl;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void dem_so_nguyen_to_mang(int **a, int m, int n, ofstream &outputfile) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j])) {
                dem++;
            }
        }
    }
    outputfile << "So luong so nguyen to: " << dem << endl;
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

void tong_phan_tu_tung_cot(int **a, int m, int n, ofstream &outputfile) {
    for (int j = 0; j < n; j++) {
        int tong_cot = 0;
        for (int i = 0; i < m; i++) {
            tong_cot += a[i][j];
        }
        outputfile << "Tong cot " << j + 1 << " la: " << tong_cot << endl;
    }
}

void cac_phan_tu_tang_dan_tren_dong_cot(int **a, int m, int n, ofstream &outputfile) {
  int k=m*n;
  for(int i=0;i<k-1;i++)
  {
      for(int j=i+1;j<k;j++)
      {
          if(a[i/n][i%n]>a[j/n][j%n])
          {
              int temp=a[i/n][i%n];
              a[i/n][i%n]=a[j/n][j%n];
              a[j/n][j%n]=temp;
          }
      }
  }
  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outputfile << a[i][j] << " ";
        }
        outputfile << endl;
    }
}

void sap_xep_tang_dan_tren_dong_2(int **a, int m, int n, ofstream &outputfile) {
    for (int i = 0; i < m; i++) {
        // Sắp xếp từng dòng sử dụng thuật toán sắp xếp đơn giản như Bubble Sort
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    swap(a[i][j], a[i][k]);
                }
            }
        }
    }

    outputfile << "Mang sau khi sap xep tang dan tren tung dong:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outputfile << a[i][j] << " ";
        }
        outputfile << endl;
    }
}
void sap_xep_tang_dan_tren_cot_2(int **a, int m, int n, ofstream &outputfile) {
    for (int j = 0; j < n; j++) {
        // Sắp xếp từng cột sử dụng thuật toán sắp xếp đơn giản như Bubble Sort
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if (a[i][j] > a[k][j]) {
                    swap(a[i][j], a[k][j]);
                }
            }
        }
    }

    outputfile << "Mang sau khi sap xep tang dan tren tung cot:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            outputfile << a[i][j] << " ";
        }
        outputfile << endl;
    }
}

void ghi_file(int **a, int m, int n) {
    ofstream outputfile("table.out");
    if (!outputfile.is_open()) {
        cerr << "Khong the mo file output." << endl;
        return;
    }

    gia_tri_lon_nhat_mang(a, m, n, outputfile);
    gia_tri_nho_nhat_mang(a, m, n, outputfile);
    dem_so_nguyen_to_mang(a, m, n, outputfile);
    tong_phan_tu_tung_dong(a, m, n, outputfile);
    tong_phan_tu_tung_cot(a, m, n, outputfile);
    outputfile << "Mang sau khi sap xep tang dan tren tung dong va cot :" << endl;
     sap_xep_tang_dan_tren_dong_2(a,m,n,outputfile);
     
     sap_xep_tang_dan_tren_cot_2(a,m,n,outputfile);
  //  cac_phan_tu_tang_dan_tren_dong_cot(a, m, n, outputfile);

    outputfile.close();
}

int main() {
    int **a;
    int m, n;
    doc_file(a, m, n);
    ghi_file(a, m, n);

    // Giải phóng bộ nhớ đã cấp phát cho mảng a
    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
