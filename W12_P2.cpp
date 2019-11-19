#include<iostream>
#define Max 353333
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;
struct item {
	int flag = 0;
	int key = 0;
	//int data = 0;
};
item arr[Max];
int pro = 1;
int hashfunc(int key)
{
	return key % Max;
}
int hashfunc2(int key) {
	return (17 - (key % 17));
}
void insert(int key) {
	int temp = hashfunc(key);
	int hash = hashfunc2(key);
	while (1) {
		if (arr[temp].flag == 1)
			temp += hash;
		else
		{
			arr[temp].flag = ISITEM;
			arr[temp].key = key;
			break;
		}
	}
}
bool prob(int key) {
	int temp = hashfunc(key);
	int hash = hashfunc2(key);
	pro = 1;
	bool noex = false;
	while (1) {
		if (arr[temp].key == key)
			break;
		else if (arr[temp].flag == 0)
		{
			noex = true;
			break;
		}
		else
		{
			temp += hash;	//+=로 써야하는것 +로 써서 오류났었음.
			pro++;
		}
	}
	return noex;
}
int main() {
	int N, M, T, t;
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
			cout << !prob(t) << " " << pro << endl;
		}
		for (int i = 0; i < Max; i++) {
			if (arr[i].flag == 1 || arr[i].flag == 2)
			{
				arr[i].key = 0;
				arr[i].flag = 0;
			}
		}
	}
	return 0;
}