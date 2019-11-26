#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Vrt {
	int idx = -1;
	int data = -1;
};
struct Edg {
	Vrt* S = NULL;
	Vrt* D = NULL;
	string str;
};
int main() {
	int N, M, K, I, S, D, L;
	cin >> N >> M >> K;
	vector<vector<Edg*>> Matrix(N, vector<Edg*>(N, NULL));
	vector<Edg*>E;
	vector<Vrt*> V;
	for(int i=0;i<N;i++) {
		cin >> I;
		Vrt* newV = new Vrt;
		newV->data = I;
		V.push_back(newV);
		newV->idx = i;
	}
	while (M--) {

	}
}