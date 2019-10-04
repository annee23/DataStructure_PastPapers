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
	int pop() {
		if (Ssize == 0)
			return -1;
		else
		{
			Node* temp = head;
			head = head->next;
			int t = temp->n;
			delete temp;
			Ssize--;
			return t;
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
		Stack* S = new Stack;

		for(auto a:s) {
			if (a =='+')
			{
				int a, b;
				b = S->pop();
				a = S->pop();
				S->push(a + b);
			}
			else if (a == '*')
			{
				int a, b;
				b = S->pop();
				a = S->pop();
				S->push(a * b);
			}
			else if (a == '-')
			{
				int a, b;
				b = S->pop();
				a = S->pop();
				S->push(a - b);
			}
			else if (a == '/')
			{
				int a, b;
				b = S->pop();
				a = S->pop();
				S->push(a / b);
			}
			else
				S->push(a-'0');
		}
		cout << S->head->n << endl;
		delete S;
	}
	return 0;
}