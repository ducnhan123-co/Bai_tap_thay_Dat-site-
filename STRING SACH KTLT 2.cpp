#include<iostream>
#include<string.h>
using namespace std;
int demsotukkytu(char *s,int k);
void demtuloaik(char *s);
char *daonguocchuoi (char *s);
char *daonguoctu(char *s);
char *sapxep(char *s);
char *dainhat(char *s);

//dem tu loai k
int demsotukkytu(char *s, int k) {
    int demkytu = 0; // Đếm số ký tự trong mỗi từ
    int demtukkytu = 0; // Đếm số từ có độ dài k
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != ' ') {
            demkytu++; // Tăng biến đếm nếu gặp ký tự không phải khoảng trắng
        } else {
            // Nếu gặp khoảng trắng
            if (demkytu == k) {
                demtukkytu++; // Nếu số ký tự của từ hiện tại bằng k, tăng biến đếm số từ có độ dài k
            }
            demkytu = 0; // Reset biến đếm số ký tự trong từ để đếm từ tiếp theo
        }
    }
    return demtukkytu;
}
void demtuloaik(char *s)
{
	for(int i=0;i<=7;i++)
	cout<<demsotukkytu(s,i)<< " ";
}
char *gheptu(char *s)
{
	char stemp[256];
	strcpy(stemp,s);
	int k=strchr(s,' ')-s;
	s[k]='\0';
	return strcat(s,strrchr(stemp,' '));
}
char *daonguocchuoi(char *s)
{
	strcat(strrev(s)," ");
	int i=0;
	while (i<strlen(s))
	{
		int j=i;
		while(s[j]!=' ')
		j++;
		{
			int u=i,v=j-1;
			while(u<v)
			{
				char ch=s[u];
				s[u]=s[v];
				s[v]=ch;
				u++;
				v--;
			}
		}
		i=j+1;
	}
	s[strlen(s)-1]='\0';
	return s;
}
char *daonguoctu(char *s)
{
	strcat(s," ");
	int i=0;
	while (i<strlen(s))
	{
		int j=i;
		while (s[j]!=' ')
		j++;{
		int u=i,v=j-1;
		while (u<v)
		{
			char ch=s[u];
			s[u]=s[v];
			s[v]=ch;
			u++;
			v--;
		}
		}
	i=j+1;
	}
	s[strlen(s)-1]='\0';
  return s;
}
char *tutrai(char *s)
{
	int k=strchr(s,' ')-s;
	s[k]='\0';
	return s;
}
int main()
{
	char s[1000];
	int k;
		cout<<"moi ban nhap chuoi : ";
	cin.getline(s,1000);
	cout <<"chuoi moi nhap la : "<< s<<endl;
	cout<<"Nhap vao k ,so luong tu can dem : ";
	cin>>k;
	int demk=demsotukkytu(s,k);
	cout<<demk<<endl;
	
	char *result = gheptu(s);
    cout << "Chuoi sau khi ghep: " << result << endl;
	
}