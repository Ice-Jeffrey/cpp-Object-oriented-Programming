#include<iostream>
#include "Jeffrey's_sort.hpp"
using namespace std;

int main() {
    cout << "请输入数组元素的个数：";
    int n;
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    cout << "请输入数组的各个元素：" << endl;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    Quicksort(a, n);
    HeapSort(b, n);

    cout << "快速排序的结果为：" << endl;
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "堆排序的结果为：" << endl;
    for(int i=0; i<n; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}