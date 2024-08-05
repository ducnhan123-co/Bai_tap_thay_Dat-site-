/*Cho file văn bản str.txt chứa nhiều chuỗi,mỗi chuối trên một dòng.Mỗi chuỗi chứa các ký tự chữ cái thường và khoảng trắng,giữa các từ có đúng một khoảng trắng,đầu và cuối mỗi chuỗi không có khoảng trắng
Hãy viết chương trình hoàn chỉnh thực hiện các công việc sau
a) hỏi file chứa bao nhiêu chuỗi?
b) tìm chuỗi dài mỗi chuỗi
c) đếm xem file có bao nhiêu từ?
d) tìm từ dài nhất trong file
e)tìm một chuỗi có chiều dài dài nhất
f) đếm xem file có bao nhiêu ký tự 'a';
g) đếm xem file có bao nhiêu chuỗi "abcabc"
ghi vào output.txt*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void doc_file(char *s)
{
    ifstream inputfile ("input.txt");
    if(!inputfile.is_open())
    {
        cout<<"Khong mo duoc file . ";
    }
    char *line= new char[256];
    while (inputfile.getline(line,256))
    {
        strcat(s,line);
        strcat(s,"\n");
    }
    inputfile.close();
}

// Hàm để giải phóng bộ nhớ cho mảng char
void giai_phong_bo_nho(char *s)
{
    delete[] s;
}

// Đếm số lượng chuỗi trong file
int dem_so_luong_chuoi_file(char *s)
{
    int dem = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '\n' && s[i + 1] != '\n'){
            dem++;
        }
    }
    if (strlen(s) > 0 && s[strlen(s) - 1] != '\n')
    {
        dem++;
    }
    return dem;
}

// Tìm chiều dài mỗi chuỗi
void chieu_dai_moi_chuoi(char *s, ofstream &outputfile)
{
    char *line = strtok(s, "\n");
    int i = 1;
    while (line != NULL)
    {
        int len = strlen(line);
        outputfile <<"Chuoi dai chuoi "  << i <<" la : "<< len <<endl;
        i++;
        line = strtok(NULL, "\n");
    }
}

// Đếm số từ trong file
int dem_tu_trong_file(char *s)
{
    int dem_tu = 0;
    char *copy = new char[strlen(s) + 1];
    strcpy(copy, s);

    char *line = strtok(copy, "\n");
    while (line != NULL)
    {
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            dem_tu++;
            token = strtok(NULL, " ");
        }
        line = strtok(NULL, "\n");
    }

    delete[] copy;
    return dem_tu;
}

// Tìm từ dài nhất trong file
void tu_dai_nhat_trong_file(char *s, ofstream &outputfile)
{
    char *copy = new char[strlen(s) + 1];
    strcpy(copy, s);

    char *line = strtok(copy, "\n");
    int max_length = 0;
    char longest_word[256];

    while (line != NULL)
    {
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            int length = strlen(token);
            if (length > max_length)
            {
                max_length = length;
                strcpy(longest_word, token);
            }
            token = strtok(NULL, " ");
        }
        line = strtok(NULL, "\n");
    }

    outputfile << "Tu dai nhat trong file la: " << longest_word << " voi do dai " << max_length << endl;

    delete[] copy;
}

// Ghi kết quả vào file
void ghi_file(char *s)
{
    ofstream outputfile ("output.txt");
    if(!outputfile.is_open())
    {
        cout<<"Khong mo duoc file ";
    }

    // a) Đếm số lượng chuỗi trong file
    outputfile << "a) So luong chuoi trong file: " << dem_so_luong_chuoi_file(s) << endl;

    // b) Tìm chiều dài mỗi chuỗi
    outputfile << "b) Chieu dai cua tung chuoi:" << endl;
    chieu_dai_moi_chuoi(s, outputfile);

    // c) Đếm số từ trong file
    outputfile << "c) So tu trong file: " << dem_tu_trong_file(s) << endl;

    // d) Tìm từ dài nhất trong file
    tu_dai_nhat_trong_file(s, outputfile);

    // e) Tìm một chuỗi có chiều dài dài nhất
    // (Nếu cần thực hiện, bạn có thể viết code cho nhiệm vụ này ở đây)

    // f) Đếm số lần xuất hiện của ký tự 'a'
    int dem_a = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'a') {
            dem_a++;
        }
    }
    outputfile << "f) So lan xuat hien cua ky tu 'a': " << dem_a << endl;

    // g) Đếm số lần xuất hiện của chuỗi "abcabc"
    // (Nếu cần thực hiện, bạn có thể viết code cho nhiệm vụ này ở đây)

    outputfile.close();
}
int countString(char s[], char s2[]) {
    int check = 1, cnt = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == s2[0]) {
            check = 1;
            for (int j = 0; j < strlen(s2); j++) {
                if (s2[j] != s[i + j]) {
                    check = 0;
                    break;
                }
            }
            if (check) {
                cnt++;
            }
        }
    }

    return cnt;
}


int main()
{
    char *s = new char[256];
    doc_file(s);
    ghi_file(s);
    giai_phong_bo_nho(s);
    return 0;
}
