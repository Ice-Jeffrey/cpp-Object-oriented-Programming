#pragma once
#include <iostream>
using namespace std;

template <class T>
int Partition(T* l, int s, int t)
{
	int low, high;
	low = s;
	high = t;
	int temp = l[low];
	while (low < high)
	{
		while (low < high && l[high] >= temp)
			high--;
		l[low] = l[high];
		while (low < high && l[low] <= temp)
			low++;
		l[high] = l[low];
	}
	l[low] = temp;
	return low;
}

template <class T>
int Qsort(T* a, int s, int t)
{
	if (s >= t)
		return 1;
	int k;
	k = Partition(a, s, t);
	Qsort(a, s, k - 1);
	Qsort(a, k + 1, t);
	return 0;
}

template <class T>
int Quicksort(T* a, int n)
{
	return Qsort(a, 0, n - 1);
}

template <class T>
int Heapadjust(T* a, int n, int s)
{
	int i = s;
	while (2 * i + 1 < n)
	{
		int temp;
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int max = lchild;
		if (rchild < n && a[lchild] < a[rchild])
			max = rchild;
		if (a[i] < a[max])
		{
			temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
		i = max;
	}
	return 0;
}

template <class T>
int CreateHeap(T* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapadjust(a, n, i);
	}
	return 0;
}

template <class T>
int HeapSort(T* a, int n)
{
	CreateHeap(a, n);
	for (int i = 1; i <= n; i++)
	{
		int temp;
		temp = a[0];
		a[0] = a[n - i];
		a[n - i] = temp;
		Heapadjust(a, n - i, 0);
	}
	return 0;
}