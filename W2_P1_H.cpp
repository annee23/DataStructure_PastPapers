#include<iostream>
using namespace std;

struct Array {
	int arr[10000] = { 0, };
	int n = 0;
	
	void at(int idx) {
		cout << arr[idx] << "\n";
	}
	void set(int idx, int x) {
		if (!arr[idx])
			cout << 0 << "\n";
		else
			arr[idx] = x;
	}
	void add(int idx, int x) {
		if (!arr[idx])
			arr[n] = x;
		else
		{
			for (int j = n - 1; j >= idx; j--)
				arr[j + 1] = arr[j];
			arr[idx] = x;
		}
		n++;
	}
	void remove(int idx) {
		if (arr[idx] == 0)
			cout << "0\n";
		else
		{
			int t = arr[idx];
			for (int j = idx; j < n-1; j++)
				arr[j] = arr[j+ 1];
			arr[n - 1] = 0;
			n--;
			cout << t << "\n";
		}
	}
	void printArray() {
		if (n == 0)
			cout << "0\n";
		else
		{
			for (int j = 0; j < n; j++)
				cout << arr[j] << " ";
			cout << endl;
		}
	}
};
int main() {
	int m;
	cin >> m;
	Array a;
	while (m--) {
		string s;
		cin >> s;
		if (s == "remove") {
			int n;
			cin >> n;
			a.remove(n);
		}
		else if (s == "printArray")
			a.printArray();
		else if (s == "add") {
			int i, n;
			cin >> i >> n;
			a.add(i, n);
		}
		else if (s == "at")
		{
			int n;
			cin >> n;
			a.at(n);
		}
		else if (s == "set") {
			int i,n;
			cin >> i>>n;
			a.set(i, n);
		}
	}
	return 0;
}