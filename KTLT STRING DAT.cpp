#include <bits/stdc++.h>
using namespace std;

string tachtubentrai(string s) {
    string result;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            result += s[i];
        } else {
            break;
        }
    }
    return result;
}
string tachtubenphai(string s) {
    string result;
    int i = s.size() - 1;
    // Bắt đầu từ ký tự cuối cùng của chuỗi s
    // Bỏ qua các khoảng trắng ở phía bên phải
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    // Tiếp tục thêm các ký tự vào chuỗi kết quả cho đến khi gặp khoảng trắng hoặc hết chuỗi
    while (i >= 0 && s[i] != ' ') {
        result = s[i] + result;
        i--;
    }
    // Không đảo ngược chuỗi kết quả
    return result;
}

void kytudauhoa(string s)
{
	int l=s.size();
	bool inhoa=true;
	for(int i=0;i<l;i++)
	{
		if(s[i]!=' ' && inhoa)
		{
			s[i]=toupper(s[i]);
			inhoa=false;
		}
		else if(s[i]==' ')
		 inhoa=true;
		}
	for(int i=0;i<l;i++)
	{
		cout<<s[i];
	}
}

int demXuatHien(string s, string y) 
{
    int count = 0;
    int lenS = s.length();
    int lenY = y.length();

    // Duyệt qua từng ký tự trong chuỗi s
    for (int i = 0; i <= lenS - lenY; i++) {
        // Kiểm tra chuỗi con y từ vị trí i của chuỗi s
        if (s.substr(i, lenY) == y ) {
            count++; // Tăng biến đếm lên 1
        }
    }

    return count;
}
int demkytuthuongtrongchuoi(string s)
{
	int dem=0;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='a' && s[i]<='z')
		dem++;
	}
	return dem;
}
string chuoicon2tudaucuoi(string s,string m)
{
	string tu_dau=tachtubentrai(s);
	string tu_cuoi=tachtubenphai(s);
	
	m=tu_dau+" "+ tu_cuoi;

	return m;
}
void hoanvi(char &x, char &y) {
    char temp = x;
    x = y;
    y = temp;
}

// Hàm đảo ngược chuỗi ký tự
void daonguockytu(string &s) {
    int dodai = s.size();
    for (int i = 0; i < dodai / 2; i++) {
        hoanvi(s[i], s[dodai - 1 - i]);
    }
    for(int i=0;i<dodai;i++)
    {
    	cout<<s[i];
	}
}
void sapxepcackitutangdan(string &s) {
    int l = s.size();
    for (int i = 0; i < l - 1; i++) {
        for (int j = i + 1; j < l; j++) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                if (s[i] > s[j]) {
                    hoanvi(s[i], s[j]);
                }
            }
        }
        
    }
    for(int i=0;i<l;i++)
    {
    	cout<<s[i];
	}
}
//6 nguyên âm là a, e, i, o, u, y
//18 phụ âm là b, c, d, f, g, h, k, l, m, n, p, q, r, s, t, v, x, z.
int demnguyenam(string s)
{
	int dem=0;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y')
		dem++;
	}
	return dem;
}
int demphuam(string s)
{
	int dem=0;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		
		if(s[i]=='b' || s[i]=='c' || s[i]=='d' || s[i]=='f' || s[i]=='g' || s[i]=='h' || s[i]=='k' || s[i]=='l' || s[i]=='m' || s[i]=='n' || s[i]=='p'  || s[i]=='q' || s[i]=='r' || s[i]=='s' || s[i]=='t' || s[i]=='v' || s[i]=='x' || s[i]=='z' )
		dem++;
	}
	return dem;
}
void loaiBoDauCach(string &s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
}
bool kiemtrachuoidoixung(string s)
{
	loaiBoDauCach(s);
	int dodai=s.size();
	for(int i=0;i<dodai/2;i++)
	{
		if(s[i] != s[dodai-1-i])
		return false;
	}
	return true;
}
int demcobaonhieutu(string s)
{
	int dem=1;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]==' ' & s[i+1] !=' ')
		{
			dem++;
		}
	}
	return dem;
}
void demKyTuMoiTu(string s) {
    stringstream ss(s);
    string token;
    int max_length = 0;
    string longest_word;
    
    while (ss >> token) {
        int length = token.length();
        cout << "So ky tu trong tu '" << token << "': " << length << endl;
        if (length > max_length) {
            max_length = length;
            longest_word = token;
        }
    }
    
    cout << "Tu dai nhat trong chuoi co " << max_length << " ky tu la: " << longest_word << endl;
}

int demtucokkytu(string s,int k)
{
	int demkytu=0;
	int demkkytu=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] !=' ') demkytu++;
		else
		{
			if(demkytu==k)
			{
				demkkytu++;
			}
			demkytu=0;
		}
	}
	return demkkytu;
}
int main()
{
	
	string s;
	cout <<"Nhap vao mot chuoi ki tu : ";
	getline(cin,s);
	
	cout<<"Chuoi vua nhap la : "<< s << endl;

int demtu=demcobaonhieutu(s);
cout<<"Chuoi tren co : "<< demtu <<" tu "<<endl;

demKyTuMoiTu(s);

int k;
cout<<"Nhap so luong k ki tu can dem : ";
cin>>k;
int demk_kytu=demtucokkytu(s,k);
cout<<"Chuoi tren co " << demk_kytu << " tu k "<<endl;
fflush(stdin);
string tachtutrai;
tachtutrai=tachtubentrai(s);
   cout<< tachtutrai<<endl;
string tachtuphai;
tachtuphai=tachtubenphai(s);
cout<<tachtuphai<<endl;
	
	kytudauhoa(s);
	cout<<endl;
string y;
cout<<"Nhap chuoi y can dem : ";
getline(cin,y);
int dem=demXuatHien(s,y);
cout<<dem<<endl;

int demthuong=demkytuthuongtrongchuoi(s);
cout<<"Co " << demthuong <<" ky tu thuong trong chuoi " <<endl;
string m;
 string hop= chuoicon2tudaucuoi(s,m);
cout<<hop<<endl;


daonguockytu(s);
cout<<endl;

sapxepcackitutangdan(s);
cout<<endl;

int dem_nguyenam=demnguyenam(s);
cout<<"Chuoi tren co "<< dem_nguyenam <<" chu nguyen am "<<endl;

int dem_phuam=demphuam(s);
cout<<"Chuoi tren co "<< dem_phuam <<" chu phu am "<<endl;

if (kiemtrachuoidoixung(s)){
	cout<<"Chuoi tren co doi xung "<<endl;
}
else 
{
	cout<<"Chuoi tren khong doi xung "<<endl;
}
	fflush(stdin);
	return 0;
}