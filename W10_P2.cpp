#include<iostream>
#include<vector>
using namespace std;
struct Node {
	Node* pa = NULL;
	Node* ch[2] = { NULL, };
	int n = 0;
};
vector<Node*>v;
Node* root = NULL;
void nodeexchange(Node* M, Node* K) {
	if (M == root)
		root = K;
	else if (M->pa->ch[0] == M)
		M->pa->ch[0] = K;
	else
		M->pa->ch[1] = K;
	if (K != NULL)
		K->pa = M->pa;
}
void dele(Node* N) {
	if (N->ch[0] == NULL) {
		nodeexchange(N, N->ch[1]);
	}
	else if (N->ch[1] == NULL) {
		nodeexchange(N, N->ch[0]);
	}
	else {
		Node* change = N->ch[1];
		while (change->ch[0] != NULL)
			change = change->ch[0];
		if (change->pa != N) {
			nodeexchange(change, change->ch[1]);
			change->ch[1] = N->ch[1];
			change->ch[1]->pa = change;
		}
		nodeexchange(N, change);
		change->ch[0] = N->ch[0];
		change->ch[0]->pa = change;
	}
}
void pre(Node* N) {
	cout << N->n << " ";
	if (N->ch[0] != NULL)
		pre(N->ch[0]);
	if (N->ch[1] != NULL)
		pre(N->ch[1]);
}
void insert(int x, Node* N) {
	if (N->n < x)
	{
		if (N->ch[1] == NULL)
		{
			Node* newN = new Node;
			newN->pa = N;
			N->ch[1] = newN;
			newN->n = x;
			v.push_back(newN);
		}
		else
			insert(x, N->ch[1]);
	}
	else {
		if (N->ch[0] == NULL)
		{
			Node* newN = new Node;
			newN->pa = N;
			N->ch[0] = newN;
			newN->n = x;
			v.push_back(newN);
		}
		else
			insert(x, N->ch[0]);
	}
}
int main() {
	int T, N, M, t;
	cin >> T;
	while (T--) {
		cin >> N;
		cin >> t;
		root = new Node;
		root->n = t;
		v.push_back(root);
		for (int i = 1; i < N; i++) {
			cin >> t;
			insert(t, root);
		}
		cin >> M;
		while (M--) {
			cin >> t;
			Node* it = root;
			bool noo = false;
			while (it->n != t)
			{
				if (it->n > t) {
					if (it->ch[0] == NULL)
					{
						noo = true;
						break;
					}
					it = it->ch[0];
				}
				else
				{
					if (it->ch[1] == NULL)
					{
						noo = true;
						break;
					}
					it = it->ch[1];
				}
			}
			if (noo)
				cout << 0 << endl;
			else {
				dele(it);
			}
		}
		pre(root);
		for (int i = N - 1; i >= 0; i--)
		{
			delete v[i];
			v.pop_back();
		}
	}
	return 0;
}
