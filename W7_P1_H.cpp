#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Node {
	Node* pa = NULL;
	vector<Node*> ch;
	int n = 0;
};
vector<Node*>tree;
//Node* root = NULL;
bool ex = false;
void insert(int x, int y) {
	ex = false;
	Node* parentpointer = NULL;
	for (int i=0;i<tree.size();i++)
		if (tree[i]->n == x)
		{
			ex = true;
			parentpointer = tree[i];
		}
	if (!ex)
		cout << -1 << endl;
	else {
		Node* newN = new Node;
		newN->n = y;
		parentpointer->ch.push_back(newN);
		newN->pa = parentpointer;
		tree.push_back(newN);
	}
}
void printChild(int x) {
	ex = false;
	Node* parentpointer = NULL;
	for (int i=0; i < tree.size(); i++)
		if (tree[i]->n == x)
		{
			ex= true;
			parentpointer = tree[i];
		}
	if (!ex)
		cout << -1 << endl;
	else {
		if (parentpointer->ch.size() == 0)
			cout << 0;
		else
			for (int j=0;j<parentpointer->ch.size();j++)
				cout << parentpointer->ch[j]->n << " ";
		cout << endl;
	}
}
void printDepth(int x) {
	ex = false;
	Node* pointer = NULL;
	for (int i=0; i < tree.size(); i++)
		if (tree[i]->n == x)
		{
			ex = true;
			pointer = tree[i];
		}
	if (!ex)
		cout << -1 << endl;
	else {
		int count = 0;
		while (pointer->pa != NULL)
		{
			pointer = pointer->pa;
			count++;
		}
		cout << count << endl;
	}
}
int main() {
	int n;
	cin >> n;
	//vector<Node*>tree;		//전역으로 선언 안하면 오버로딩 생김. 왜인지 모름.
	Node* root = new Node;
	root->n = 1;
	tree.push_back(root);
	while (n--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int a, b;
			cin >> a >> b;
			insert(a, b);
		}
		else if(s=="printChild") {
			int a;
			cin >> a;
			printChild(a);
		}
		else if (s == "printDepth") {
			int a;
			cin >> a;
			printDepth(a);
		}
	}
	return 0;
}