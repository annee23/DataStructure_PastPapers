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
			
			delete temp;
			si--;
		}
		else
		{
			Node* temp = head;
			int t = temp->n;
			head = head->next;
			
			delete temp;
			si--;
		}
	}
	
};
int main() {
	Queue* P1 = new Queue;
	Queue* P2 = new Queue;

	int n;
	cin >> n;
	while (n--) {
		int playturn;
		int num;
		cin >> playturn;
		int t = playturn;
		while (t--) {
			cin >> num;
			P1->enqueue(num);
		}
		t = playturn;
		while (t--) {
			cin >> num;
			P2->enqueue(num);
		}							
		//플레이어 카드들 큐에 받기완료
		t = playturn;
		int pp1 = 0, pp2 = 0;	//plus point
		int po1 = 0, po2 = 0;	//point of winning
		while (t--) {
			if (P1->head->n + pp1 > P2->head->n + pp2)
			{
				pp1 = P1->head->n + pp1 - (P2->head->n + pp2) - 1;
				pp2 = 0;
				po1++;
			}
			else if (P1->head->n + pp1 < P2->head->n + pp2)
			{
				pp2 = P2->head->n + pp2 -( P1->head->n + pp1) - 1;
				pp1 = 0;
				po2++;
			}
			else
				pp1 = pp2 = 0;
			P1->dequeue();
			P2->dequeue();
		}
		if (po1 < po2)
			cout << 2 << endl;
		else if (po1 == po2)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	delete P1, P2;
	return 0;
}