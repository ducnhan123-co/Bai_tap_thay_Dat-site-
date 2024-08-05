#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
char *tachtutrai(char *s);// cau a
char *tachtuphai(char *s);// cau a
char *chuanhoatu(char *s);// cau b
int demsotu(char *s);//cau c
int demtubatdaunguyenam(char s[]); // cau d
void demkytucuamoitu (char *s);// cau e
void sapxepkytutang (char *s);//cau f
void tansocackytu (char *s);//cau g
 // bai lam
char *tachtutrai(char *s)
{
	return strrev(strrchr(strrev(s),' ')+1);
}
//tach tu phai
char *tachtuphai(char *s)
{
	return strrchr(s,' ')+1;
}
//chuan hoa tu 
char *chuanhoatu(char *s) {
    // Chuyển toàn bộ chuỗi thành chữ thường
    strlwr(s);
if (s[0] != '\0') {
        s[0] = toupper(s[0]);
    }
    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < strlen(s); i++) {
        // Nếu ký tự là dấu cách và ký tự tiếp theo không phải là dấu cách
        if (s[i] == ' ' && s[i + 1] != ' ') {
            // Chuyển ký tự tiếp theo thành chữ hoa
            s[i + 1] = toupper(s[i + 1]);
        }
    }

    // Nếu ký tự đầu tiên là dấu cách, chuyển nó thành chữ hoa
    if (s[0] == ' ') {
        s[0] = toupper(s[0]);
    }

    // Trả về chuỗi đã chuẩn hóa
    return s;
}

//dem so tu 
int demsotu(char *s)
{
	int l=strlen(s);
	int d=1;
	for(int i=0;i<l;i++)
	{
		if(s[i]==' ' && s[i+1] != ' ')
		d++;
	}
	return d;
}
// demtubatdaubangnguyen am 
int demtubatdaunguyenam(char s[])
{
	int l=strlen(s);
	int d=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]== ' ' && (s[i+1]=='a' || s[i+1]=='u' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='e'))
		{
			d++;
		}
	}
	if (s[0]=='a' || s[0]=='u' || s[0]=='i' || s[0]=='o' || s[0]=='e')
	{
		d++;
	}
	return d;
}
//dem ky tu moi tu
void demkytucuamoitu(char *s) {
    int sokytumoitu = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != ' ') {
            sokytumoitu++;
        } else {
            cout<<sokytumoitu<<" ";
            sokytumoitu=0;
        }
    }
    cout << sokytumoitu << endl;
}

// sap xep cac ky tu tang
void xapsepkytutang(char *s)
{
	for(int i=0;i<strlen(s)-1;i++)
	{
		for(int j=i+1;j<strlen(s);j++)
		{
			if(*(s+i)>*(s+j) && *(s+i)!= ' ' && *(s+j) !=' ' )
			{
				char temp=*(s+i);
				*(s+i)=*(s+j);
				*(s+j)=temp;
			}
		}
	}
}
// tansocackytu
void tansocackytu(char *s) {
    int l = strlen(s);
    int d[256] = {0}; // Khởi tạo mảng d với giá trị 0 cho tất cả các phần tử
    for (int i = 0; i < l; i++) {
        d[s[i]]++; // Tăng số lần xuất hiện của ký tự tại vị trí s[i]
    }
    for (int i = 0; i < l; i++) {
        if (d[s[i]] != 0) { // muon bo ky tu khoang trang thi s[i] !=' ' ;
            cout << s[i] << " xuat hien " << d[s[i]] << " lan" << endl;
            d[s[i]] = 0; // Đặt lại số lần xuất hiện của ký tự về 0 sau khi in ra
        }
    }
}
//demchuoicon
int demchuoicon (char *s,char *y)
{
	int d=0;
	while(strstr(s,y)!=NULL)
	{
		d=d+1;
		strcpy(s,strstr(s,y)+1);
	}
	return d;
}

//ham main
int main()
{
	char *s;
	s=new char[1000];
	cout<<"moi ban nhap chuoi : ";
	cin.getline(s,1000);
	cout <<"chuoi moi nhap la : "<< s<<endl;
	
    /*
    
	 char *s1=tachtutrai(s);
	cout<<"chuoi sau khi tach tu ben trai la : "<<s1<<endl;
	*/ 
	/*
	chuanhoatu(s);
	cout<<"chuoi sau khi chuan hoa la : " << s<<endl;
    */	
	int sotu=demsotu(s);
	cout<<"Chuoi tren co : "<< sotu <<" tu "<< endl;
	
	
	//
	int demnguyenam=demtubatdaunguyenam(s);
	cout<<"Chuoi tren co : "<< demnguyenam <<" tu bat dau tu nguyen am " <<endl;
	//
	demkytucuamoitu(s);
	//
	cout<<endl;
	//
	tansocackytu(s);
	//
	xapsepkytutang(s);
	cout<<"Chuoi tren sap khi sap xep ky tu tang la : "<< s<<endl;
	//
	
	delete s;
}


