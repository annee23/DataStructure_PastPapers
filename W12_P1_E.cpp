#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAX 353333
struct item {
	int key = 0, value = 0;
};
int HashArr[MAX];
int sz = 0;
int hashfunc(int idx) {
	return idx % MAX;
}
void insert(int t) {
	int temp = hashfunc(t);
	while (1) {
		if (HashArr[temp] == 0)
		{
			HashArr[temp] = t; break;
		}
		else temp++;
	}
}
void prob(int t) {
	int temp = hashfunc(t);
	int rt = 1;
	while (1) {
		if (HashArr[temp] == t)
		{
			cout << 1 << " " << rt << endl;
			break;
		}
		else if (HashArr[temp] == 0)
		{
			cout << 0 << " " << rt << endl;
			break;
		}
		else
			temp++; rt++;
		
	}
}
int main() {
	int T, N, M, t;
	cin >> T;
	while (T--) {
		cin >> N;
		while (N--) {
			cin >> t;
			insert(t);
		}
		cin >> M;
		while (M--) {
			cin >> t;
			prob(t);
		}
		for (int i = 0; i < MAX; i++)
			if (HashArr[i] != 0)
				HashArr[i] = 0;
	}
	return 0;
}