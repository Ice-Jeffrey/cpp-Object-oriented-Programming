#include<iostream>
using namespace std;

template<typename T>
class vector {
    private:
        int s = 0;
        int c = 0;
        T *buffer;  //vector对应的缓冲区
    public:
        //对应的多种构造函数
        vector() {  }
        vector(vector<T>& c2) {
            buffer = new T[c2.size()];
            s = c2.size();
            c = s;
            for(int i=0; i<s; i++) 
                buffer[i] = c2[i];
        }
        vector(int n) {
            s = n;
            c = 0;
            buffer = new T[n];
        }
        vector(int n, T elem) {
            buffer = new T[n];
            s = n;
            c = n;
            for(int i=0; i<n; i++)
                buffer[i] = elem;
        }
        //vector的析构函数
        ~vector() {
            delete[] buffer;
            s = 0;
            c = 0;
        }
        int size() {    //返回数组的大小
            return s;
        }
        int capacity() {
            return c;
        }
        int max_size() {
            return s;
        }   //返回容器中最大数据的数量。
        bool empty() {  //返回数组是否为空
            return s == 0;
        }
        T front() {
            return buffer[0];
        }
        T back() {
            return buffer[s - 1];
        }
        T at(int index) {   //返回数组中index下标的数据
            return buffer[index];
        }
        void assign(int n, T elem) {
            buffer = new T[n];
            s = n;
            c = n;
            for(int i=0; i<n; i++)
                buffer[i] = elem;
        }
        void reserve(int n) {
            T* temp = new T[s];
            for(int i=0; i<s; i++) 
                temp[i] = buffer[i];
            delete[] buffer;
            buffer = new T[n];
            for(int i=0; i<s; i++)
                buffer[i] = temp[i];
            s = n;
        }
        void insert(int index, T element) {
            T* temp = new T[s];
            for(int i=0; i<s; i++) 
                temp[i] = buffer[i];
            delete[] buffer;
            buffer = new T[s + 1];
            for(int i=0; i<s; i++)
                buffer[i] = temp[i];
            s++;
            for(int i=c-1; i>=index; i--) 
                buffer[i+1] = buffer[i];
            buffer[index] = element;
        }
        void insert(int index, int n, int element) {
            T* temp = new T[s];
            for(int i=0; i<s; i++) 
                temp[i] = buffer[i];
            delete[] buffer;
            buffer = new T[s + n];
            for(int i=0; i<s; i++)
                buffer[i] = temp[i];
            s += n;
            for(int i=c-1; i>=index; i--) 
                buffer[i+n] = buffer[i];
            for(int i=0; i<n; i++)
                buffer[index + i] = element;
        }
        void pop_back() {
            //将已有数据进行拷贝
            T* temp;
            temp = new T[s-1];
            for(int i=0; i<s-1; i++) 
                temp[i] = buffer[i];
            //删除旧的缓冲区并重新申请新的缓冲区
            s--;
            c--;
            delete[] buffer;
            buffer = new T[s];
            //将原有数据写会并添加新数据
            for(int i=0; i<s; i++)
                buffer[i] = temp[i];
        }   //删除最后一个数据。
        void push_back(T elem) {
            //将已有数据进行拷贝
            T* temp;
            temp = new T[s];
            for(int i=0; i<s; i++) 
                temp[i] = buffer[i];
            //删除旧的缓冲区并重新申请新的缓冲区
            s++;
            c++;
            delete[] buffer;
            buffer = new T[s];
            //将原有数据写会并添加新数据
            for(int i=0; i<s; i++)
                buffer[i] = temp[i];
            buffer[s - 1] = elem;
        }// 在尾部加入一个数据。
        void clear() {
            delete[] buffer;
            s = 0;
            c = 0;
        }
        void resize(int n) {
            if(n >= s) {
                T* temp = new T[s];
                for(int i=0; i<s; i++) 
                    temp[i] = buffer[i];
                delete[] buffer;
                buffer = new T[n];
                for(int i=0; i<s; i++)
                    buffer[i] = temp[i];
                s = n;
            } 
            else {
                T *temp = new T[s];
                for(int i=0; i<n; i++) 
                    temp[i] = buffer[i];
                delete[] buffer;
                buffer = new T[n];
                s = n;
                for (int i=0; i<n; i++) 
                    buffer[i] = temp[i];
            }
        }
        void resize(int n, T element) {
            if(n >= s) {
                T* temp = new T[s];
                for(int i=0; i<s; i++) 
                    temp[i] = buffer[i];
                delete[] buffer;
                buffer = new T[n];
                for(int i=0; i<n; i++) {
                    if(i <= s)
                        buffer[i] = temp[i];
                    else
                        buffer[i] = element;                   
                }                   
                s = n;
            } 
            else {
                T *temp = new T[n];
                for(int i=0; i<n; i++) 
                    temp[i] = buffer[i];
                delete[] buffer;
                buffer = new T[n];
                s = n;
                for (int i=0; i<n; i++) 
                    buffer[i] = temp[i];
            }
        }
        //对下标运算符进行重载
        T& operator[](int i)
        {
            if( i > s )
            {
                cout << "索引超过最大值" <<endl; 
                // 返回第一个元素
                return buffer[0];
            }
            return buffer[i];
        }
        //对逻辑相等运算符进行重载
        bool operator==(vector<T> v) {
            for(int i=0; i<v.size(); i++)
                if(buffer[i] != v[i])
                    return false;
            return true;
        }
        //对!=运算符进行重载
        bool operator!=(vector<T> v) {
            for(int i=0; i<v.size(); i++)
                if(buffer[i] != v[i])
                    return true;
            return false;
        }
        //对<=运算符进行重载
        bool operator<=(vector<T> v) {
            for(int i=0; i<v.size(); i++)
                if(buffer[i] > v[i])
                    return false;
            return true;
        }
        //对<运算符进行重载
        bool operator<(vector<T> v) {
            for(int i=0; i<v.size(); i++)
                if(buffer[i] >= v[i])
                    return false;
            return true;
        }
        //对>=运算符进行重载
        bool operator>=(vector<T> v) {
            for(int i=0; i<v.size(); i++)
                if(buffer[i] < v[i])
                    return false;
            return true;
        }
        //对>运算符进行重载
        bool operator>(vector<T> v) {
            for(int i=0; i<v.size(); i++)
                if(buffer[i] <= v[i])
                    return false;
            return true;
        }
};