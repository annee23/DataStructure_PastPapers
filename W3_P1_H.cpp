#include<iostream>
#include<string>
using namespace std;

struct Node {
	Node* next = NULL;
	int n = 0;
};
struct LL {
	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;
	void addFront(int x) {
		Node* newN = new Node;
		newN->n = x;
		if (size==0) 
			head = tail = newN;
		else {
			newN->next = head;
			head = newN;
		}
		size++;
	}
	void removeFront() {
		if (size == 0)
			cout << -1 << endl;
		else
		{
			Node* temp = head;
			int t = temp->n;
			head = head->next;
			delete temp;
			cout << t << endl;
			size--;
		}
	}
	void front() {
		if (size == 0)
			cout << -1 << endl;
		else
			cout << head->n << endl;
	}
	void empty() {
		if (size == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	void showList(){
		if (size == 0)
			cout << -1 ;
		else
		{
			Node* it = head;
			int si = size;
			while (si--) {
				cout << it->n << " ";
				it = it->next;
			}
		}
		cout << endl;
	}
	void addBack(int x) {
		Node* newN = new Node;
		newN->n = x;
		if (size == 0)
			head = tail = newN;
		else {
			tail->next = newN;
			tail = newN;
		}
		size++;
	}
};
int main() {
	int n;
	cin >> n;
	LL ml;
	while (n--) {
		string s;
		cin >> s;
		if (s == "addFront") {
			int t;
			cin >> t;
			ml.addFront(t);
		}
		else if (s == "addBack") {
			int t;
			cin >> t;
			ml.addBack(t);
		}
		else if (s == "removeFront")
			ml.removeFront();
		else if (s == "front")
			ml.front();
		else if (s == "empty")
			ml.empty();
		else if (s == "showList")
			ml.showList();
	}
	return 0;
}