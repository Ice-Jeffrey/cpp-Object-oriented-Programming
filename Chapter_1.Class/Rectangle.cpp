#include<iostream>
using namespace std;

class Rectangle {
    public: 
        //无参构造函数
        Rectangle() {

        }
        //输入参数时的构造函数
        Rectangle(int a, int b) {
            r_long = a;
            r_width = b;    
        }
        //获取矩形面积的函数
        int comp_area() {
            return r_long * r_width;
        }
        //获取矩形周长的函数
        int comp_perimeters() {
            return 2 * (r_long + r_width);
        }
        //获取矩形长的函数
        int get_long() {
            return r_long;
        }
        //获取矩形宽的函数
        int get_width() {
            return r_width;
        }
    private:
        //开始时为矩形的长和宽设置默认值，当调用无参构造函数时保证输出的正确
        int r_long = 5, r_width = 4;
};

int main() {
    int a, b;
    //提示用户输入矩形B的长和宽
    cout << "Please input the length and width of rectangle B: ";
    cin >> a >> b;
    //调用无参构造函数初始化矩形A
    Rectangle A;
    //调用有参数的构造函数初始化矩形B
    Rectangle B(a, b);
    //输出矩形A的长和宽
    cout << "The length and width of rectangle A is " << A.get_long() << " and " << A.get_width() << endl;
    //输出矩形B的长和宽
    cout << "The length and width of rectangle B is " << B.get_long() << " and " << B.get_width() << endl;
    //输出矩形A所占的面积
    cout << "Rectangle A covers an area of " << A.comp_area() << endl;
    //输出矩形B所占的面积
    cout << "The perimeter of rectangle B is " << B.comp_perimeters() << endl;
    return 0;
}