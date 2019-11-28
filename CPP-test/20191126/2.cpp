#include<iostream>
using namespace std;

class A //����A 
{ 
	private: 
	  int a; 
	public:
	  void Set(int i) //�����ݳ�Աa��ֵ 
	  { 
	    a = i; 
	  } 
	  int Get() //�������ݳ�Աa��ֵ 
	  { 
	    return a; 
	  } 
}; 

class B: public A //��A�๫������B�� 
{ 
   private: 
      int b; 
    public:
      void Set(int i) //�����ݳ�Աb��ֵ 
      { 
        b = i; 
      } 
      int Get() //�������ݳ�Աb��ֵ 
      { 
        return b; 
      } 
      void Show() //������ݳ�Աa��b��ֵ 
      { 
        cout << "A::a=" << A::Get() << ", B::b=" << B::Get() << endl; 
      } 
}; 
int main() 
{ 
   B bb; //������B�Ķ���bb 
   int x, y; 
   cin >> x >> y; 
   bb.A::Set(x); //�����ݳ�Աa��ֵ 
   bb.B::Set(y); //�����ݳ�Աb��ֵ 
   bb.Show(); 
   return 0; 
}