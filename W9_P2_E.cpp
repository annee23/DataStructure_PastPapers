#include<vector>
#include<iostream>
using namespace std;
vector<int>v;
void insert(int t) {
	v.push_back(t);
	int s = 0;
	for (int i = v.size() - 1; i > 0; i /= 2) {
		if (v[i] < v[i / 2]) {
			s = v[i];
			v[i] = v[i / 2];
			v[i / 2] = s;
		}
		else break;
	}
}
void dele() {
	v[1] = v[v.size() - 1];
	v.pop_back();
	int s = 0;
	for (int i = 1; i * 2 < v.size();) {
		if (i * 2 + 1 == v.size() && v[i] > v[i * 2])
		{
			s = v[i];
			v[i] = v[i * 2];
			v[i * 2] = s;
			i = i * 2;
		}
		else if (v[i * 2] <= v[i * 2 + 1] && v[i] > v[i * 2])
		{
			s = v[i];
			v[i] = v[i * 2];
			v[i * 2] = s;
			i = i * 2;
		}
		else if (v[i * 2] > v[i * 2 + 1] && v[i] > v[i * 2 + 1])
		{
			s = v[i];
			v[i] = v[i * 2 + 1];
			v[i * 2 + 1] = s;
			i = i * 2 + 1;
		}
		else break;
	}
}
int main() {
	int T, N, p, t;
	cin >> T;
	while (T--) {
		
		v.push_back(0);
		cin >> N >> p;
		while (N--) {
			cin >> t;
			insert(t);
		}
		cout << v[p] << endl;
		p--;
		while (p--)
			dele();
		cout << v[1] << endl;
		
	}
	return 0;
}