#include<iostream>
using namespace std;
const float PI = 3.141592628;

class Ball {
    public:
        //获取球的表面积的函数
        float get_Area() {
            return 4 * PI * radius * radius;
        }
        //获取球的体积的函数
        float get_Volume() {
            return 4 * PI * radius * radius * radius / 3;
        }
        //有参构造函数
        Ball(float r) {
            radius = r;
        }
        //拷贝构造函数
        Ball(Ball &B) {
            radius = B.radius;
        }
        //输入倍数来改变球的半径的函数
        int modify_radius(float times) {
            radius *= times;
            return 0;
        }
    private:
        float radius;
};

int main() {
    //输入球A的半径
    float r; 
    cout << "Please input the radius of ball A: ";
    cin >> r;
    //调用有参构造函数初始化球A
    Ball A(r);
    //输出球A的表面积和体积
    cout << "The surface area of ball A is " << A.get_Area() << endl;
    cout << "The volume of ball A is " << A.get_Volume() << endl;
    //调用拷贝构造函数拷贝构造球B
    Ball B(A);
    //将球B的半径扩大两倍
    B.modify_radius(2);
    //输出球B的表面积与体积
    cout << "The surface area of ball B is " << B.get_Area() << endl;
    cout << "The volume of ball B is " << B.get_Volume() << endl;
    return 0;
}