#include<iostream>
#include<string>
using namespace std;
struct Node {
	Node* next = NULL;
	int n = 0;
 };
struct Stack {
	Node* head = NULL;
	Node* tail = NULL;
	int Ssize = 0;

	void empty() {
		if (Ssize == 0)
			cout << "1\n";
		else
			cout << "0\n";
	}
	void top() {
		if (Ssize == 0)
			cout << "-1\n";
		else
			cout << head->n << endl;
	}
	void push(int o) {
		Node* newN = new Node;
		newN->n = o;
		if (Ssize == 0)
			head = tail = newN;
		else {
			newN->next = head;
			head = newN;
		}
		Ssize++;
	}
	void pop() {
		if (Ssize == 0)
			cout << "-1\n";
		else
		{
			Node* temp = head;
			head = head->next;
			int t = temp->n;
			delete temp;
			cout << t << endl;
			Ssize--;
		}
	}
	void size() {
		cout << Ssize << endl;
	}

};
int main() {
	int n;
	cin >> n;
	Stack S;
	while (n--) {
		string s;
		cin >> s;
		if (s == "empty")
			S.empty();
		else if (s == "top")
			S.top();
		else if (s == "pop")
			S.pop();
		else if (s == "size")
			S.size();
		else if (s == "push")
		{
			int t;
			cin >> t;
			S.push(t);
		}
	}
	return 0;
}