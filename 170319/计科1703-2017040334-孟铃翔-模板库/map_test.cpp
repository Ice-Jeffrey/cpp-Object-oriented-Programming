#include<iostream>
#include"Jeffrey's_map.hpp"
//#include<map>
using namespace std;

int main() {
	map<int, int> m;
	m.insert(make_pair(23, 3));
	cout << m[23] << endl;
	cout << "Number of elements in map: " << m.size() << endl;
	m.erase(23);
	cout << "If map is empty? " << m.empty() << endl;
	for(int i=0; i<12; i++) {
		int n;
		cin >> n;
		m.insert(make_pair(i, n));
	}
	for(int i=0; i<12; i++)
		cout << m[i] << " ";
	cout << endl;
	return 0;
}