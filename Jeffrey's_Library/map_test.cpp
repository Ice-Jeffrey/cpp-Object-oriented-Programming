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
	return 0;
}