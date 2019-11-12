#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int n = 0;
	Node* pa = NULL;
	vector<Node*> ch;
};
Node* root = NULL;
vector<Node*>v;
void pre(Node* N) {
	cout << N->n << " ";
	for (int i = 0; i < N->ch.size(); i++)
		pre(N->ch[i]);
}
void post(Node* N) {
	
	for (int i = 0; i < N->ch.size(); i++)
		post(N->ch[i]);
	cout << N->n << " ";
}
int cd(Node* N) {
	int c = 0;
	Node* it = N;
	while (it->pa != NULL)
	{
		c++;
		it = it->pa;
	}
	return c;
}
int main() {
	int N, M, t,k;
	cin >> N;
	while (N--) {
		root = new Node;
		root->n = 1;
		v.push_back(root);
		cin >> M;
		while (M--) {
			cin >> t>>k;
			Node* it = NULL;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i]->n == t)
				{
					it = v[i];
					break;
				}
			}
			Node* newN = new Node;
			newN->n = k;
			newN->pa = it;
			it->ch.push_back(newN);
			v.push_back(newN);
		}
		pre(root);
		cout << endl;
		post(root);
		cout << endl;
		int m = 0, temp = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->ch.size() == 0)
			{
				temp = cd(v[i]);
				if (m < temp)
					m = temp;
			}
		
		}
		cout << m << endl;
		for (int i = v.size() - 1; i >= 0;i--) {
			delete(v[i]);
			v.pop_back();
		}
	}
}
