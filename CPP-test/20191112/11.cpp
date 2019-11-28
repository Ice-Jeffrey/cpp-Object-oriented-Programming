#include<iostream>
using namespace std;

class Fun {
    public:
        bool Neighbor(int a, int b) {
            if(a - b == 1 || a - b == -1)
                return true;
            return false;
        }
        bool Neighbor(int a, int b, int c) {
            if(a > b && b > c) {
                if(a - b == 1 && b - c == 1)
                    return true;
            }
            else if(a > c && c > b) {
                if (a - c == 1 && c - b == 1)
                    return true;
            }
            else if(b > a && a > c) {
                if (b - a == 1 && a - c == 1)
                    return true;
            }
            else if(b > c && c > a) {
                if (b - c == 1 && c - a == 1)
                    return true;
            }
            else if(c > a && a > b) {
                if (c - a == 1 && a - b == 1)
                    return true;
            }
            else if(c > b && b > a) {
                if (c - b == 1 && b - a == 1)
                    return true;
            }
            return false;
        }
};

int main()
{
    Fun fun;
   int a, b, c, d, e;
   cin >> a >> b >> c >> d >> e;
   if (fun.Neighbor(a, b)) //调用重载函数Neighbor()
      cout << "true" << endl;
   else
      cout << "false" << endl;
   if (fun.Neighbor(c, d, e)) //调用重载函数Neighbor()
      cout << "true" << endl;
   else
      cout << "false" << endl;
   return 0;
}