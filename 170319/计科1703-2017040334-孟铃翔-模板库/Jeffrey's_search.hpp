#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
int InOrderSearch(T* a, T e, int n) {
    for(int i=0; i<n; i++)
        if(a[i] == e) {
            return i;
        }
    return -1;
}

template<class T>
int BiSearch(T* a, T e, int s, int t) {
    if(s > t)
        return -1;
    sort(a+s, a+t);
    int mid = (t - s) / 2 + s;
    if(a[mid] == e) 
        return mid;
    else if(a[mid] > e)
        return BiSearch(a, e, s, mid);
    else if(a[mid] < e)
        return BiSearch(a, e, mid+1, t);
    
}

template<class T>
int BinarySearch(T* a, T e, int n) {
    BiSearch(a, e, 0, n);
}