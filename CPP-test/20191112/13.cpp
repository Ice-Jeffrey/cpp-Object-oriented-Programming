#include<iostream>
#include<iomanip>
using namespace std;

template <typename T>
void Exchange (T &a, T &b) { 
    T temp;
    temp = a;
    a = b;
    b = temp; 
} 

class Date {
    protected:
        int year, month, day;
    public:
        Date(int y=0, int m=0, int d=0) {
            year = y;
            month = m;
            day = d;
        }
        int getYear() {return year;}
        int getMonth() {return month;}
        int getDay() {return day;}
        friend ostream &operator<<( ostream &output, Date &D ){ 
            output << D.getYear() << "年" << D.getMonth() << "月" << D.getDay() << "日";
            return output;            
        }
};

int main()
{
    int a, b; //定义整型变量
    double c, d; //定义浮点型变量
    int y1, m1, d1, y2, m2, d2;
    cin >> a >> b >> c >> d >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    Date day1(y1, m1, d1), day2(y2, m2, d2); //定义Date型变量

    cout << "互换前a与b为：" << setiosflags(ios::fixed) << setprecision(2) << a << ", " << setiosflags(ios::fixed) << setprecision(2) << b << endl;//参照输出示例，输出互换前a与b的值
    Exchange(a, b); //调用模板函数void Exchange(int,int)
    cout << "互换后a与b为：" << setiosflags(ios::fixed) << setprecision(2) << a << ", " << setiosflags(ios::fixed) << setprecision(2) << b << endl;//参照输出示例，输出互换后a与b的值

    cout << "互换前c与d为：" << setiosflags(ios::fixed) << setprecision(2) << c << ", " << setiosflags(ios::fixed) << setprecision(2) << d << endl; //参照输出示例，输出互换前c与d的值，要求小数点后必须保留2位有效数字（四舍五入），不足补零
    Exchange(c, d); //调用模板函数void Exchange(double,double)
    cout << "互换后c与d为：" << setiosflags(ios::fixed) << setprecision(2) << c << ", " << setiosflags(ios::fixed) << setprecision(2) << d << endl; //参照输出示例，输出互换后c与d的值，要求小数点后必须保留2位有效数字（四舍五入），不足补零

    cout << "互换前day1与day2为：" << day1 << ", " << day2 << endl; //参照输出示例，输出互换前day1与day2的值
    Exchange(day1, day2); //调用模板函数void Exchange(Date,Date)
    cout << "互换后day1与day2为：" << day1 << ", " << day2 << endl; //参照输出示例，输出互换后day1与day2的值
    return 0;
}