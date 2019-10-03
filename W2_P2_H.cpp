#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int m, n;
	cin >> m;
	while (m--) {
		cin >> n;
		int arr[101];
		int people[3] = { 0,0,0 };
		int money[3] = { 0,0,0 };
		for(int i=0;i<n;i++) {
			cin >> arr[i];
			if (arr[i] != 0)		//계좌가 0인 사람은 세지 않게 예외처리
			{
				money[i % 3] += arr[i];
				people[i % 3]++;
			}
		}
		for (int i = 0; i < 3; i++)		//0으로 나누지 않게 예외처리
			if (people[i] == 0)
				people[i] = 1;
		cout << money[0] << " "<<money[1] <<" "<< money[2] << endl;
		cout << floor(money[0]/people[0]) << " "<<floor(money[1] / people[1]) <<" "<< floor(money[2] / people[2]) << endl;
	}
	return 0;
}