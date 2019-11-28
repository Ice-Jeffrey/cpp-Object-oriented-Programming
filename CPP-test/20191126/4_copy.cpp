#include<iostream>
using namespace std;

class Gather {
protected:
	int m_data[100];  
	int m_count;  

public:
	Gather() {
		Clear();
	}

	void Clear() {
		m_count = 0;
	} 

	int GetCount() {
		return m_count;
	}

	int Find(int e) const {
		for (int i = 0; i < m_count; i++) {
			if (m_data[i] == e)
				return i;
		}
		return -1;
	} 

	bool Add(int e) {
		int loc = Find(e);
		if (loc == -1) {
			m_data[m_count] = e;
			m_count++;
			return true;
		}
		return false;
	} 

	bool Remove(int e) {
		int loc = Find(e);
		if (loc != -1) {
			for (int i = loc; i < m_count; i++) {
				m_data[i] = m_data[i + 1];
			}
			m_count--;
			return true;
		}
		return false;
	} 

	Gather operator+(const Gather& g2) {
		Gather g3 = *this;
		for (int i = 0; i < m_count; i++) {
			int element = g2.m_data[i];
			int loc = g3.Add(element);
		}
		return g3;
	}

	Gather operator-(const Gather& g2) {
		Gather g3;
		for (int i = 0; i < m_count; i++) {
			int element = m_data[i];
			int loc = g2.Find(element);
			if (loc == -1)
				g3.Add(element);
		}
		return g3;
	} 

	friend ostream& operator<<(ostream& dout,const Gather& g) {
		dout << "(";
		for (int i = 0; i < g.m_count - 1; i++) {
			dout << g.m_data[i] << ", ";
		}
		dout << g.m_data[g.m_count - 1] << ")";
		return dout;
	}
};

int main()
{
	Gather g1, g2;
	int x, y, a, b;
	cin >> x >> y;
	for (int i = x; i <= y; i++)
		g1.Add(i);

	g2 = g1;
	cout << "集合g2内容如下：" << g2 << endl; 

	Gather g3(g1);

	cin >> x >> y >> a >> b;
	g3.Remove(x);
	g3.Remove(y);
	g3.Add(a);
	g3.Add(b);

	cout << "集合g3内容如下：" << g3 << endl;
	cout << "集合g2与g3的差：" << (g2 - g3) << endl;
	cout << "集合g2与g3的和：" << (g2 + g3) << endl;
	return 0;
}