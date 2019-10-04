#include<iostream>
#include<string>
using namespace std;

struct Node {
	Node* next = NULL;
	int n = 0;
};
struct Queue {
	Node* head = NULL;
	Node* tail = NULL;
	int QS = -1;
	int si = 0;
	void enqueue(int x) {
		Node* newN = new Node;
		newN->n = x;
		if (head == NULL)
		{
			head = tail = newN;
			si++;
		}
		else if (si == QS)
		{
			cout << "Full\n";
			delete newN;
		}
		else
		{
			tail->next = newN;
			tail = newN;
			si++;
		}
	}
	void dequeue() {
		if (si == 0)
			cout << "Empty\n";
		else if (si == 1)
		{
			Node* temp = head;
			int t = temp->n;
			head = tail = NULL;
			cout << t << endl;
			delete temp;
			si--;
		}
		else
		{
			Node* temp = head;
			int t = temp->n;
			head = head->next;
			cout << t << endl;
			delete temp;
			si--;
		}
	}
	void size() {
		cout << si << endl;
	}
	void isEmpty() {
		if (si == 0)
			cout << "1\n";
		else
			cout << "0\n";
	}
	void front() {
		if (si == 0)
			cout << "Empty\n";
		else
			cout << head->n << endl;
	}
	void rear() {
		if (si == 0)
			cout << "Empty\n";
		else
			cout << tail->n << endl;
	}
	
};
int main() {
	int s;
	cin >> s;
	Queue* Q = new Queue;
	Q->QS = s;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "enqueue") {
			int t;
			cin >> t;
			Q->enqueue(t);
		}
		else if (s == "dequeue")
			Q->dequeue();
		else if (s == "size")
			Q->size();
		else if (s == "isEmpty")
			Q->isEmpty();
		else if (s == "front")
			Q->front();
		else if (s == "rear")
			Q->rear();
	}
	return 0;
}