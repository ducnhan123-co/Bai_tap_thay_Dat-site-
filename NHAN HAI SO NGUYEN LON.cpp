/*Bài toán: Nhân 2 số nguyên lớn ==>ý tưởng của bài này là :ta sẽ nhân như phép nhân bình thường 2 số với nhau với mỗi số ở đây ta sẽ cho nó thành một chuỗi 
==>đảo ngược 2 chuỗi lại với nhau rồi thực hiện tính toán sau đó ta lại đảo ngược kết quả để thu được kết quả cuối cùng

ví dụ 4235 x 759 = 								Chỉ số		0123
 Cách làm thông thường		A		4236   -->		A		6324		A		6324	
 							B		 759	    	B		957			B		957	
 							C	3215124   					4218		C		42151233 \0 
 															 08112
															  25692	
													C		4215123  ==>đổi ngược chuỗi ta được chuỗi cần tìm
==> Dạng tổng quát (string)
                                  B			A			C           
                                  0			0			0
                                  0			1			1
                                  0			2			2
                                  0			3			3
                                  1			0			1
                                  1			1			2
                                ...			...			...
                                  iB		iA			iB+iA
                                  
*/
#include <bits/stdc++.h>
#include <sys/time.h>
#include <string>
#pragma GCC optimize ({options})
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
//hàm đảo 1 chuỗi string
string reverseString(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}
// Hàm tính tích của hai số nguyên lớn
string tinhTich(string A, string B) {
    A = reverseString(A);
    B = reverseString(B);
     // Lấy độ dài của hai chuỗi
    int lenA = A.length();
    int lenB = B.length();
    string C(lenA + lenB, '0');//Khởi tạo một chuỗi C để lưu kết quả cuối cùng với độ dài là tổng độ dài 2 chuổi cần tính và các phần tử được khởi tạo bằng 0(tránh lấy số rác)
    for (int iB = 0; iB < lenB; iB++) { 
        int nho = 0;// số "nhớ" ==>ví dụ 9*5=45 (nhớ 4)
        for (int iA = 0; iA < lenA; iA++) {
            int x = (B[iB] - '0') * (A[iA] - '0') + nho + (C[iA + iB] - '0');// (B[iB]-'0' ; A[iA]-'0' ; C[iA+iB]-'0'--> dùng để đưa các kí từ về các số để tính toán 
            C[iA + iB] = x % 10 + '0';//Phần tử C[iA+iB] ở đây là sẽ phần từ đầu được ghi vào (Lưu phần đơn vị vào chuỗi C)

            nho = x / 10;// Cập nhật số "nhớ" cho lần tính toán tiếp theo 
        }
        if (nho > 0) // nếu hết vòng lặp rồi mà vẫn còn nhớ thì ta đưa số nhớ đó vào cuối của dãy kết quả
		{
            C[iB + lenA] = nho + '0';
        }
    }
    if (C[lenA+lenB-1]!='0') //Nếu phần tử cuối ta tính ra đã là 1 số khác '0' thì ta lấy kết thúc chuỗi tại vị trí cuối cùng 
        C[lenA+lenB]='\0';
    else{
    	C[lenA+lenB-1]='\0';
	}
    return reverseString(C); // Đảo ngược chuỗi C để thu được kết quả cuối cùng
}

int main() {
	/*
	Họ Tên:Phan Đức Nhân
	MSSV:3123410243
	Lớp:DCT1236
	*/
    string A, B;
    cout <<"Nhap vao 1 so A :";
    cin >> A ;
    cout <<"Nhap vao 1 so B: ";
    cin>>B;
    cout << "Tich 2 so nguyen tren la : "<<endl;
    cout << tinhTich(A, B);
    return 0;
}

//Việc chuyển số lớn sang chuỗi để tính toán có một số lý do:
//==>xử lý các số nguyên lớn với độ dài tùy ý mà không cần quan tâm đến giới hạn của kiểu dữ liệu số nguyên, không bị giới hạn bởi kiểu dữ liệu
//==>hi số được biểu diễn dưới dạng chuỗi, chúng ta có thể dễ dàng truy cập từng chữ số của số đó và thực hiện các phép toán cơ bản như cộng, trừ, nhân, chia một cách dễ dàng và linh hoạt
//==>Khả năng xử lý số lớn một cách hiệu quả,Đơn giản hóa việc xử lý dữ liệu