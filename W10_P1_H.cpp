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
		int max = 0;
		Node* it = NULL;
		for (int i = 0; i < N; i++)
		{
			int c = 0;
			if (v[i]->ch[0] == NULL && v[i]->ch[1]==NULL)
			{
				it = v[i];
				while (it->pa != NULL)
				{
					it = it->pa;
					c++;
				}
				if (c > max)
					max = c;
			}
		}
		cout << max << endl;
		for (int i = N - 1; i >= 0; i--)
		{
			delete v[i];
			v.pop_back();
		}
	}
	return 0;
}
