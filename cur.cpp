#include <bits/stdc++.h>
#define PI 3.141592653
#define d(c, v) data[c] = v                             //กำหนดรูปแบบการเขียน
#define f(a) sqrt(pow((a + 32 + PI), 3) - a + 1) + PI   //กำหนดสมการ
using namespace std;
map<char, float> data = {};

void Conf()                                             //ฟังก์ชันกำหนดค่า
{
    int e = -1;
    for (int i = 0; i <= 26; i++)                       //กำหนดค่า 
    {
        e *= -1;
        d('A' + i, f((i + 10) * e));
        e *= -1;                                        
        d('a' + i, f((i + 10) * e));
        e *= -1;
    }
    for (int i = 0; i < 5; i++)                         //กำหนดค่า
    {
        e *= -1;
        d('9' - i, f((i - 5) * e));
        e *= -1;                                        
        d('0' + i, f((i - 5) * e));
        e *= -1;
    }
}

int main()
{
    Conf();                                             //เรียกใช้ฟังก์ชัน
    char pass[1001] = {};                                 //กำหนดความยาวสูงสุด
    cin >> pass;                                        //รับรหัส
    int size = strlen(pass);                            //เก็บความยาวของรหัส
    float var1 = 0, var2 = 0;                           //กำหนดตัวแปรเก็บค่า
    for (int i = 1; i <= size; i++)                     //เข้ารหัสขั้นที่ 1
    {
        var1 += data[pass[i - 1]] / i;                  
    }
    int Z = int(var1);                                  //เข้ารหัสขั้นที่ 2
    for (int i = Z; i < Z * Z; i++)                     //เข้ารหัสขั้นที่ 3
    {
        var2 += 1.00 / i;                               
    }
/*     fstream fout;
    fout.open("value.txt", ios::app);
    if (fout.is_open())                                 //เก็บข้อมูล
    {
        fout << fixed << setprecision(7) << var1 + var2 << endl;
        fout.close();                                   
    }
 */    
  cout<<fixed << setprecision(7) << var1 + var2 << endl;
  return 0;
}