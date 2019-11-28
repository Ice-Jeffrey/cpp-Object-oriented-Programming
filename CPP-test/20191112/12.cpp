#include<iostream>
using namespace std;

class Complex {
    protected:
        int real, image;
    public:
        Complex(int r = 0, int i = 0): real(r), image(i) {}
        friend ostream &operator<<( ostream &output, const Complex &c) { 
            if(c.image < 0) {
                output << c.real << c.image << "i" << endl;
            }
            else if (c.image == 0)
            {
                output << c.real << endl;
            }
            else if (c.image > 0)
            {
                output << c.real << "+" << c.image << "i" << endl;
            }            
            return output;            
        }
};

int main()
{
    int a, b;//输入两个整数a和b，再使用这两个整数创建复数对象z1
    cin >> a >> b;
    Complex z1(a, b);  

    cout << z1 << endl; //输出z1对象
    return 0;
}