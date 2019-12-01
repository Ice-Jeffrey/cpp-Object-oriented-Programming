
#include"Jeffrey's_vector.hpp"
//#include<vector>
#include<iostream>
using namespace std;

int main() {
    //对第一种拷贝构造函数以及vector.size(), vector.empty(), vector.push_back()函数的测试
    int n;
    cout << "Please input the size of the vector: "; 
    cin >> n;
    vector<int> a(n);
    cout << "Please input elements of the vector: ";
    for(int i=0; i<n; i++) 
        cin >> a[i];
    a.push_back(6);
    a.push_back(7);

    if(a.empty())
        cout << "The vector is empty!" << endl; 
    else {
        cout << "The vector is not empty." << endl;
        cout << "Traverse the vector: ";
        for(int i=0; i< a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
        
    //对于vector.size(), vector.front(), vector.back()函数的测试
    cout << "The size of the vector is: " << a.size() << endl; 
    cout << "The first and last element of the vector is: " << a.front()<< ", " << a.back() << endl;
    
    //对于第二种构造函数的测试
    vector<int> b(5, 1);
    if(b.empty())
        cout << "The vector is empty!" << endl; 
    else {
        cout << "The vector is not empty." << endl;
        cout << "Traverse the vector: ";
        for(int i=0; i< b.size(); i++)
            cout << b[i] << " ";
        cout << endl;
    }

    //对于拷贝构造函数的测试
    vector<int> c(a);
    if(c.empty())
        cout << "The vector is empty!" << endl; 
    else {
        cout << "The vector is not empty." << endl;
        cout << "Traverse the vector: ";
        c.pop_back();   //对于vector.pop_back()函数的测试
        for(int i=0; i< c.size(); i++)
            cout << c[i] << " ";
        cout << endl;
    }

    c = b;
    if(c.empty())
        cout << "The vector is empty!" << endl; 
    else {
        cout << "The vector is not empty." << endl;
        cout << "Traverse the vector: ";
        for(int i=0; i< c.size(); i++)
            cout << c[i] << " ";
        cout << endl;
    }
    return 0;
}