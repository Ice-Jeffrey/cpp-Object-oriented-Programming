#include<iostream>
#include<iomanip>
using namespace std;

template <class T>
class Stack { 
  protected: 
    T* m_data;     // 元素 
    int m_count;
    int capacity;
 
  public: 
    void Clear() {m_count = 0;}
    Stack(int capacity) {
        m_data = new T[capacity];
        Clear();
    }
    ~Stack() {
        delete[] T;
    }
    void push(T a){
        for(int i=0; i<capacity-1; i++)
            m_data[i+1] = m_data[i];
        m_data[0] = a; 
        m_count++;
    }  // 入栈
    void pop(T &t){
        for(int i=0; i<capacity-1; i++)
            m_data[i] = m_data[i+1]; 
        m_count--;
        return true;
    }               // 出栈
}; 

int main()
{
   Stack <int, 100> stk1; //创建对象
   Stack <double, 100> stk2; //创建对象
   int n, m;
   cin >> n >> m;
   …… //输入n个整数，并压入堆栈stk1中

   …… //输入m个浮点数，并压入堆栈stk2中

   int a;
   if (stk1.Pop(a))
      cout << a << endl;
   if (stk1.Pop(a))
      cout << a << endl;
   double x;
   if (stk2.Pop(x))
      cout << x << endl;
   if (stk2.Pop(x))
      cout << x << endl;
   return 0;
}