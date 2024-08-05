/*File và dữ liệu cấu trúc
Cho mảng n phân số ; trong đó tử số và mẫu số là các số nguyên dương.Hãy viết chương trình thực hiện các công việc sau
-Hãy sắp xếp các phân số của mảng theo chiều tăng dần
-Hãy tính tổng các phân số của mảng;kết quả là một phân số tối giản
Dữ liệu vào được cho từ file văn bản input.txt ;trong đó
+Dòng đầu chứa số nguyên dương n.
+Trong n dòng tiếp theo mỗi dòng chứa 2 số nguyên dương là tử số và mẫu số của một phân số.
Kết quả ghi vào file văn bản output.txt gồm 2 dòng;mỗi dòng ghi kết quả của mỗi bài tương ướng 
ví dụ
input.txt
4
3 7
2 5
17 6
16 21

output.txt
Bai 24: 2/5 3/7 16/21 17/6
Bai 25: 929/210
*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
struct ps
{
	int tuso;
	int mauso;
};

void doc_file(ps ps_arr[], int &n)
{
    ifstream inputfile("input.txt");
    if (!inputfile.is_open())
    {
        cout << "Khong mo duoc file : ";
    }
       inputfile >>n;
    for (int i = 0; i < n; i++)
    {
        inputfile >> ps_arr[i].tuso >> ps_arr[i].mauso;
    }

    inputfile.close(); // Đóng file sau khi đã đọc xong.
}


void sap_xep_cac_phan_so_tang_dan(ps ps_arr[], int n, ofstream &outputfile)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Tính giá trị thực của phân số thứ nhất và thứ hai
            float value1 = (float)ps_arr[i].tuso / ps_arr[i].mauso;
            float value2 = (float)ps_arr[j].tuso / ps_arr[j].mauso;

            // So sánh giá trị thực của hai phân số
            if (value1 > value2)
            {
                // Hoán đổi vị trí của hai phân số
                swap(ps_arr[i], ps_arr[j]);
            }
        }
    }
 outputfile << "Bai 24: ";
    for (int i = 0; i < n; i++)
    {
        outputfile << ps_arr[i].tuso << "/" << ps_arr[i].mauso << " ";
    }
}
int ucln (int a,int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int bcnn(int a, int b) {
    return (a * b) / ucln(a, b);
}
void toi_gian_ps(int &tuso, int &mauso) {
    int ucln_val = ucln(tuso, mauso);
    tuso /= ucln_val;
    mauso /= ucln_val;

}
void tong_cac_phan_so(ps ps_arr[], int n, ofstream &outputfile) {
    int tuso_tong = 0;
    int mauso_chung = 1;

    // Tính mẫu số chung
    for (int i = 0; i < n; i++) {
        mauso_chung = bcnn(mauso_chung, ps_arr[i].mauso);
    }

    // Tính tổng các tử số
    for (int i = 0; i < n; i++) {
        tuso_tong += ps_arr[i].tuso * (mauso_chung / ps_arr[i].mauso);
    }

    // Rút gọn phân số tổng
    toi_gian_ps(tuso_tong, mauso_chung);

    outputfile << "\nBai 25: " << tuso_tong << "/" << mauso_chung << endl;
}
void ghi_file(ps ps_arr[],int n)
{
	ofstream outputfile("output.txt");
		if(!outputfile.is_open())
		{
			cout << "Khong mo duoc file : ";
    }
    
    sap_xep_cac_phan_so_tang_dan(ps_arr,n,outputfile);
    tong_cac_phan_so(ps_arr,n,outputfile);
    
    
outputfile.close();		
}


int main()
{
    const int MAX_SIZE = 100; // Số lượng phân số tối đa có thể đọc từ file.
    ps ps_arr[MAX_SIZE]; // Khai báo mảng chứa các phân số.
int n;
    doc_file(ps_arr, n); // Đọc dữ liệu từ file vào mảng
    ghi_file(ps_arr, n);

    return 0;
}
