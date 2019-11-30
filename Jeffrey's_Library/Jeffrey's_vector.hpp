#pragma once
#include<iostream>
using namespace std;

template<class T>
class vector {
    private:
        int s;
        int c;
        T *buffer;  //vector对应的缓冲区
    public:
        //对应的多种构造函数
        vector() {
            c = 0;
            s = 0;
        }
        vector(vector<T>& c2) {
            buffer = new T[c2.size()];
            s = c2.size();
            c = c2.capacity();
            for(int i=0; i<s; i++) 
                buffer[i] = c2[i];
        }
        vector(int n, T elem = 0) {
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
        //各个成员函数
        int size() {    //返回数组的大小
            return s;
        }
        int capacity() {
            return c;
        }
        int max_size() {
            return c;
        }   //返回容器中最大数据的数量。
        bool empty() {  //返回数组是否为空
            return s == 0;
        }
        //返回某些特定的值
        T front() {
            return buffer[0];
        }
        T back() {
            return buffer[s - 1];
        }
        T at(int index) {   //返回数组中index下标的数据
            return buffer[index];
        }
        //其他操作
        void reserve(int n) {
            //为vector申请多余的内存空间
            if(n > c) {
                T* temp = new T[s];
                for(int i=0; i<s; i++)
                    temp[i] = buffer[i];
                delete buffer;
                buffer = new int[n];
                for(int i=0; i<s; i++)
                    buffer[i] = temp[i];
                c = n;
            }
        }
        void resize(int n, T element = 0) {
            if(n < s) 
                s = n;
            else if(n > s && n <= c) {
                for(int i=s; i<n; i++)
                    buffer[i] = element;
                s = n;
            }
            else if(n > c) {
                reserve(c + c / 2);
                for(int i=s; i<n; i++)
                    buffer[i] = element;
            }
        }
        void assign(int n, T elem) {
            resize(n, elem);
            for(int i=0; i<n; i++)
                buffer[i] = elem;
        }
        void insert(int index, T element) {
            s++;
            resize(s);
            for(int i=index; i<s-1; i++)
                buffer[index+1] = buffer[index];
            buffer[index] = element;
        }
        void insert(int index, int n, T element) {
            for(int i=0; i<n; i++)
                insert(index, element);
        }
        void pop_back() {
            buffer[s-1] = 0;
            s--;
        }   //删除最后一个数据。
        void push_back(T elem) {
            s++;
            resize(s);
            buffer[s-1] = elem;
        }// 在尾部加入一个数据。
        void clear() {
            delete[] buffer;
            s = 0;
            c = 0;
        }
        //对下标运算符进行重载
        T& operator[](int i) {
            return buffer[i];
        }
        //对赋值运算符进行重载
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