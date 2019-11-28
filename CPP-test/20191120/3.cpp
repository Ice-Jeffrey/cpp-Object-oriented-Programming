#include<iostream>
using namespace std;

class Rectangle{
    protected:
        int r_long, r_width;
    public:
        Rectangle() {
            r_long = 10;
            r_width = 10;
        }
        Rectangle(int a, int b) {
            r_long = a;
            r_width = b;
        }
        int comp_area() {
            return r_long * r_width;
        }
        int comp_perimeter() {
            return 2 * (r_long + r_width);
        }
        int get_long() {
            return r_long;
        }
        int get_width() {
            return r_width;
        }
};

int main()
{
   int a, b;
   cin >> a >> b;
   Rectangle rect1, rect2(a, b); //分别调用不同的构造函数，创建两个对象
   cout << "(" << rect1.get_long() << "," << rect1.get_width() << ")" << endl;
   cout << "(" << rect2.get_long() << "," << rect2.get_width() << ")" << endl;
   cout << rect2.comp_area() << endl;
   cout << rect2.comp_perimeter() << endl;
   return 0;
}