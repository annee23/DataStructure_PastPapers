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
			head = head->next;
			delete temp;
			size--;
		}
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
	int k;
	while (n--) {
		LL* ml = new LL;
		k = 10;
		while (k--) {
			int l;
			cin >> l;
			ml->addBack(l);
		}
		ml->tail->next = ml->head;

		k = 3;		//변수 그냥 재사용
		while (k--) {
			string s;
			cin >> s;
			int del = 0;
			if (s == "Delete")
				cin >> del;
			Node* it = ml->head;
			if (del == 0)				//head예외처리
			{
				ml->removeFront();
				ml->tail->next = ml->head;
			}
			else {
				while (--del) {				//move함수 따로 안만들어도 됨
					it = it->next;
				}
				Node* itnx = it->next;
				if (itnx == ml->tail)		//tail예외처리
					ml->tail = it;
				if (itnx == ml->head)		//재순회시 head예외처리
					ml->head = itnx->next;
				it->next = it->next->next;
				delete itnx;
			}
		}
		Node* it = ml->head;
		while (1)
		{
			cout << it->n << " ";
			if (it == ml->tail)
				break;
			it = it->next;
		}
		cout << endl;
		delete ml;
	}
	return 0;
}