/*Chuỗi ký tự
Cho một chuỗi s chứa các ký tự chữ hoa,chữ thường và ký tự khoảng trắng.Giả sư s không có khoảng trắng đầu chuổi,
không có khoảng trắng cuối chuổi,giữa các từ chỉ có một khoảng trắng.Các ký tự liền nhau gọi là một từ
Hãy viết các hàm thực hiện công việc sau(ví dụ một số dạng)
a)Tìm một từ đầu tiên bên trái 
b) tìm một từ đầu tiên bên phải
c)đếm số lượng từ của chuỗi s 
d) đếm số ký tự mỗi từ trong chuỗi s
e)chuyển các ký tự đầu từ thành chữ hoa còn các ký tự khác thành thường
f)kiểm tra xem chuổi x có thuộc về chuỗi s hay không?Nếu không trả về -1,nếu có trả về vị trí đầu tiên mà chuỗi x xuất hiện trong chuốix s
g)Đếm xem chuỗi x xuất hiện bao nhiêu lần trong chuối s
*/
#include<iostream>
#include<cstring>
using namespace std;
//cau a
void tim_tu_dau_tien_ben_trai(char *s)
{
	char *temp=new char[255];
	int n=strlen(s);
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='\0' && s[i]!=' ')
		{
		while(i<n && s[i]!=' ')
		{
			temp[j++]=s[i++];
		}
		break;
			
		}
	}
	temp[j]='\0';
	
	cout <<temp<<endl;
	delete[] temp;
}
void tim_tu_dau_tien_ben_phai(char *s)
{
	char *temp1=new char[255];
	int n=strlen(s);
	int j=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]!='\0' && s[i]!=' ')
		{
			int k=i;
			while (k>=0 && s[k]!=' ')
			{
				k--;
			}
			for(int l=k+1;l<=i;l++)
			{
				temp1[j++]=s[l];
			}
			break;
			
			
			
			
			
			
		}
	}
	temp1[j]='\0';
	cout <<temp1<<endl;
	delete[] temp1;
	
}
void dem_so_luong_tu_chuoi(string s,  string *&tu, int &n)
{
    tu = new string [20];
    for (int i = 0; i < 20; i++)
    {
        tu[i] = new char[255];
    }

    string delim  = " ";
    string temp = new string[s.size() + 1]; // Tạo một biến tạm để sao chép nội dung của chuỗi s
    strcpy(temp, s); // Sao chép nội dung của chuỗi s vào biến tạm

    char *ptr = strtok(temp, delim);
    n = 0;
    while (ptr != NULL)
    {
        strcpy(tu[n], ptr);
        ptr = strtok(NULL, delim);
        n++;
    }
    cout << "Chuoi tren co : " << n << " tu " << endl;

    delete[] temp; // Giải phóng bộ nhớ của biến tạm
}
void dem_so_luong_ky_tu_moi_tu_1_tu(char *s, char **&tu, int &n)
{
	 tu = new char *[20];
    for (int i = 0; i < 20; i++)
    {
        tu[i] = new char[255];
    }

    char delim[] = " ";
    char *temp = new char[strlen(s) + 1]; // Tạo một biến tạm để sao chép nội dung của chuỗi s
    strcpy(temp, s); // Sao chép nội dung của chuỗi s vào biến tạm

    char *ptr = strtok(temp, delim);
    n = 0;
    while (ptr != NULL)
    {
        strcpy(tu[n], ptr);
        ptr = strtok(NULL, delim);
        n++;
    }
    for(int i=0;i<n;i++)
    {
    	cout<<tu[i]<<" " << strlen(tu[i])<<endl;
	}
	delete[] temp; 
}
void chuyen_ki_tu_dau_thanh_chu_hoa(char *s,char **&tu,int &n)
{
	tu=new char *[20];
	for(int i=0;i<20;i++)
	{
		tu[i]=new char[255];
	}
	char *temp=new char[strlen(s)+1];
	char delim[]=" ";
	strcpy(temp,s);
	char *ptr=strtok(temp,delim);
	n=0;
	while(ptr!=NULL)
	{
		strcpy(tu[n],ptr);
		ptr=strtok(NULL,delim);
		n++;
	}
	for(int i=0;i<n;i++)
	{
		tu[i][0]=toupper(tu[i][0]);
	}
	for(int i=0;i<n;i++)
	{
		cout <<tu[i]<<" ";
	}
	
}
int kiem_tra_chuoi_x_co_thuoc_chuoi_s_khong(char *s, char *x)
{
    int len_s = strlen(s);
    int len_x = strlen(x); // Độ dài của chuỗi x

    for (int i = 0; i <= len_s - len_x; i++) // Lặp qua từng vị trí trong chuỗi s
    {
        if (strncmp(s + i, x, len_x) == 0) // So sánh các ký tự từ vị trí i của chuỗi s với chuỗi x
        {
            return i; // Trả về vị trí đầu tiên mà chuỗi x xuất hiện trong chuỗi s
        }
    }
    
    return -1; // Trả về -1 nếu chuỗi x không xuất hiện trong chuỗi s
}
int dem_chuoi_x_xuat_hien_bao_nhieu_lan_trong_chuoi_s(char *s, char *x)
{
    int len_s = strlen(s);
    int len_x = strlen(x);
    int dem = 0;

    for (int i = 0; i <= len_s - len_x; i++) // Duyệt qua từng vị trí trong chuỗi s
    {
        bool match = true; // Biến để kiểm tra xem chuỗi s từ vị trí i có giống với chuỗi x không

        for (int j = 0; j < len_x; j++) // Duyệt qua từng ký tự của chuỗi x
        {
            if (s[i + j] != x[j]) // So sánh ký tự tương ứng của chuỗi s và chuỗi x
            {
                match = false; // Nếu có ký tự nào không giống nhau thì match sẽ là false
                break; // Thoát khỏi vòng lặp trong trường hợp không cần kiểm tra tiếp
            }
        }

        if (match) // Nếu match vẫn là true sau khi so sánh hết các ký tự của chuỗi x
        {
            dem++; // Tăng biến đếm lên
        }
    }

    return dem; // Trả về số lần xuất hiện của chuỗi x trong chuỗi s
}


int main()
{
	char *s=new char[255];
	char **tu;
	
	cout <<"Nhap vao chuoi s : ";
	cin.getline(s,255);
	tim_tu_dau_tien_ben_trai(s);
	tim_tu_dau_tien_ben_phai(s);
	
	
	int n;
	dem_so_luong_tu_chuoi(s,tu,n);
//		dem_so_luong_ky_tu_moi_tu(s);
dem_so_luong_ky_tu_moi_tu_1_tu(s,tu,n);
chuyen_ki_tu_dau_thanh_chu_hoa(s,tu,n);

char *x=new char[255];
cout <<"Nhap vao chuoi x : ";
cin.getline(x,255);
int check=kiem_tra_chuoi_x_co_thuoc_chuoi_s_khong(s,x);
cout <<"Vi tri xuat hien dau tien la : "<< check<<endl;

int demxs=dem_chuoi_x_xuat_hien_bao_nhieu_lan_trong_chuoi_s(s,x);
cout <<"Chuoi x xuat hien : "<<demxs <<" lan trong chuoi s "<<endl;
	return 0;
}

void dem_so_luong_ky_tu_moi_tu(char *s)
{
    int dem = 0;
    int i = 0;
    bool inWord = false;
    while (s[i] != '\0')
    {
        if (s[i] != ' ')
        {
            dem++;
            inWord = true;
        }
        else if (inWord)
        {
            cout << "So ky tu trong tu: " << dem << endl;
            dem = 0;
            inWord = false;
        }
        i++;
    }
    if (inWord) // Nếu cuối chuỗi là một từ và không có dấu cách kết thúc
    {
        cout << "So ky tu trong tu: " << dem << endl; // In ra số ký tự của từ cuối cùng
    }
} 