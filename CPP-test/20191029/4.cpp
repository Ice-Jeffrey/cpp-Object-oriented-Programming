#include<iostream>
using namespace std;//必要的头文件等，可能为多条语句

class A1 {
    protected://保护成员
        int a1;
    public://公有成员
    A1(int a = 0) : a1(a) {
        cout << "执行基类A1的构造函数" << endl;
    }
    ~A1() {
        cout << "执行基类A1的析构函数" << endl;
    }
    void ShowA1() const {
        cout << "A1::a1=" << a1 << endl;
    }
};

class A2 {
    protected://保护成员
        int a2;
    public://公有成员
        A2(int a = 0) : a2(a) {
            cout << "执行基类A2的构造函数" << endl;
        }
        ~A2() {
            cout << "执行基类A2的析构函数" << endl;
        }
        void ShowA2() const {
            cout << "A2::a2=" << a2 << endl;
        }
};

class B : public A1, private A2//派生类B从A1公有继承，从A2私有继承
{
    public://公有成员
        B(int a1 = 0, int a2 = 0): A1(a1), A2(a2) {
            cout << "执行派生类B的构造函数" << endl;
        }
        ~B() {
            cout << "执行派生类B的析构函数" << endl;
        }
        void Show() const {
            A1::ShowA1();//调用基类函数ShowA1()
            A2::ShowA2();//调用基类函数ShowA2()
        }
};

int main() {
   int x, y;
   cin >> x >> y;
   B obj(x, y); //创建派生类B对象obj
   obj.Show();
   obj.ShowA1();
   return 0;
}