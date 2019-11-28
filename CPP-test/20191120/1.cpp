#include<iostream>
using namespace std;

class Complex//复数Complex类
{
    protected:
        int real, image;//保护数据成员：int类型的real、image，分别代表实部、虚部

    public:
        Complex(int r=0, int i=0): real(r), image(i) {}//带有两个参数的构造函数，参数默认值均为0；在初始化列表中将形参赋给对应的数据成员

        void Show() const {
            cout << real;
            if(image != 0) {
                if(image > 0)
                    cout << "+" << image << "i" << endl;
                else
                    cout << image << "i" << endl;  
            }
        }//输出Show()常成员函数，注意保持合理的复数输出格式

        Complex operator+(const Complex &c) const {
            Complex temp;
            temp.real = real + c.real;
            temp.image = image + c.image;
            return temp;
        }//双目+运算符重载常成员函数，有一个参数（Complex类型对象z2的常引用）

        Complex operator-(const Complex &c) const {
            Complex temp;
            temp.real = real - c.real;
            temp.image = image - c.image;
            return temp;
        }//双目-运算符重载常成员函数，有一个参数（Complex类型对象z2的常引用）

        Complex operator*(const Complex &c) const{
            Complex temp;
            temp.real = real * c.real - image * c.image;
            temp.image = image * c.real + real * c.image;
            return temp;
        }//双目*运算符重载常成员函数，有一个参数（Complex类型对象z2的常引用）

        Complex operator-() const{
            Complex temp;
            temp.real = -real;
            temp.image = -image;
            return temp;
        }//单目-运算符重载常成员函数，无参数
};
int main()
{
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   Complex z1(a, b), z2(c, d), z3; //定义复数对象
   z1.Show(); //输出z1
   z2.Show(); //输出z2

   z3 = z1 + z2 - (-z1); //进行复数运算
   z3.Show(); //输出z3

   z3 = z3 * z1; //进行复数运算
   z3.Show(); //输出z3
   return 0;
}