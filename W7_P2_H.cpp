#include<iostream>
#include<vector>
using namespace std;

struct Node {
	Node* pa = NULL;
	vector<Node*> ch;
	int n = 0;
};
void pre(vector<Node*>tree, Node* np) {
	cout << np->n << " ";
	for (int j = 0; j < np->ch.size(); j++)
		pre(tree, np->ch[j]);
}
void post(vector<Node*>tree, Node* np) {
	for (int j = 0; j < np->ch.size(); j++)
		post(tree, np->ch[j]);
	cout << np->n << " ";
}
int depth(Node* np) {
	Node* it = np;
	int countd = 0;
	if (np->ch.size() == 0)
	{
		while (it->pa!=NULL) {
			countd++;
			it = it->pa;
		}
		return countd;
	}
	else
		return 0;
}
int main() {
	int N, M;
	cin >> N;
	while (N--) {
		vector<Node*>tree;
		Node* root = new Node;
		root->n = 1;
		tree.push_back(root);
		cin >> M;
		while (M--) {
			int a, b;
			cin >> a >> b;
			for (int i = 0; i < tree.size(); i++) {
				if (tree[i]->n == a)
				{
					Node* newN = new Node;
					newN->n = b;
					newN->pa = tree[i];
					tree[i]->ch.push_back(newN);
					tree.push_back(newN);
				}
			}
		}
		pre(tree, root);
		cout << endl;
		post(tree, root);
		cout << endl;
		int max = 0;
		for (int i = 0; i < tree.size(); i++)
		{
			if (depth(tree[i]) > max)
				max = depth(tree[i]);
		}
		cout << max << endl;
	}
	return 0;
}