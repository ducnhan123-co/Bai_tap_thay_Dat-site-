/*Nhập vào một chuỗi s chứa các ký tự gồm các chữ cái in thường và ký tự khoảng trắng. Giả sử đầu và cuối chuỗi s không có khoảng trắng, giữa các từ trong chuỗi s chỉ có đúng một khoảng trắng. Hãy viết các hàm thực hiện các yêu cầu sau đây:
a. Đếm xem trong chuỗi có bao nhiêu ký tự là nguyên âm? (các ký tự nguyên âm là: a, e, i, o, u)
b. Chuyển tất cả các ký tự trong chuỗi s thành ký tự in hoa.
c. Đếm xem chuỗi s có bao nhiêu từ và mỗi từ có bao nhiêu ký tự?
Ví dụ: chuỗi s được nhập là "lap trinh web" 
Kết quả câu a: 3 nguyên âm.
Kết quả câu b: chuỗi s trở thành "LAP TRINH WEB".
Kết quả câu c: chuỗi s có 3 từ. Từ LAP có 3 ký tự, từ TRINH có 5 ký tự, từ WEB có 3 ký tự.
*/
#include<iostream>
#include<cstring>
using namespace std;

int do_dai_chuoi(char *s)
{
	int i=0;
	while(s[i]!='\0')
	{
		i++;
	}
	return i;
}

void dem_nguyen_am(char *s)
{
	int l=strlen(s);
	int dem=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
		{
			dem++;
		}
	}
	cout << dem <<" nguyen am."<<endl;
}

void chuyen_thanh_in_hoa(char *s)
{
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		s[i]=toupper(s[i]);
	}
    
    cout <<s<<endl;
}
void chuyen_thanh_in_hoa_2(char *s)
{
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			s[i]=s[i]-32;
		}
	}
	cout <<s<<endl;
}
void dem_tu_chuoi_va_so_ky_tu_moi_tu(char *s,char **&tu,int &n)
{
	tu = new char *[20];
	for(int i=0;i<20;i++)
	{
		tu[i]=new char[255];
	}
	
	
	char *temp=new char(strlen(s)+1);
	strcpy(temp,s);
	char delim[]=" ";
	char *ptr=strtok(temp,delim);
	n=0;
	while(ptr!=NULL)
	{
		strcpy(tu[n],ptr);
		ptr=strtok(NULL,delim);
		n++;
	}
	cout <<"chuoi s co "<<n <<" tu. "<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout <<"tu "<< tu[i] <<" co "<< do_dai_chuoi(tu[i]) <<" ky tu " << " ";
	}

	
}
int main()
{
	char *s=new char[255];
	char **tu;
	int n;
	cout <<"Nhap vao chuoi s : ";
	cin.getline(s,255);
	
	int do_dai=do_dai_chuoi(s);
	cout <<do_dai<<endl;
	cout <<strlen(s)<<endl;
	
	dem_nguyen_am(s);
	chuyen_thanh_in_hoa(s);
	chuyen_thanh_in_hoa_2(s);
	dem_tu_chuoi_va_so_ky_tu_moi_tu(s,tu,n);
	
	for (int i = 0; i < 20; i++) {
        delete[] tu[i];
    }
    delete[] tu;
	return 0;
}