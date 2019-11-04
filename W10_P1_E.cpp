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
void insert(int x,Node* N) {
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
		int a = 0, b = 0;
		while (M--)
		{
			a = 0, b = 0;
			cin >> t;
			Node* it = root;
			bool noo = false;
			while (it->n != t)
			{
				if (it->n < t) {
					if (it->ch[1] == NULL)
					{
						noo = true;
						break;
					}
					it = it->ch[1];
					b++;
				}
				else {
					if (it->ch[0] == NULL)
					{
						noo = true;
						break;
					}
					it = it->ch[0];
					b++;
				}
			}
			if (noo)
				cout << 0 << "\n";
			else
			{
				if (it->ch[0] != NULL)
					a++;
				if (it->ch[1] != NULL)
					a++;
				cout << a << " " << b << "\n";
			}
		}
		for (int i = N-1; i >=0; i--)
		{
			delete v[i];
			v.pop_back();
		}
	}
	return 0;
}
