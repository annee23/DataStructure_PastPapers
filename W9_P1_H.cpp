#include<iostream>
#include<vector>
#include <string>
using namespace std;
vector<int>heap;
void insert(int e) {
	heap.push_back(e);
	int swap = 0;
	for (int i = heap.size()-1; i > 0; i /= 2)
	{
		if (heap[i] < heap[i / 2])
		{
			swap = heap[i];
			heap[i] = heap[i / 2];
			heap[i / 2] = swap;
		}
		else break;
	}
}
int size() {
	return heap.size() - 1;
}
bool isEmpty() {
	return !size();
}
void pop() {
	if (isEmpty())
		cout << -1 << endl;
	else {
		cout << heap[1] << endl;
		heap[1] = heap[heap.size()-1];
		heap.pop_back();
		int swap = 0;
		for (int i = 1; i * 2 < heap.size();) {
			if (i * 2 + 1 == heap.size() && heap[i] > heap[i * 2])
			{
				swap = heap[i];
				heap[i] = heap[i * 2];
				heap[i * 2] = swap;
				i = i * 2;
			}
			else if (heap[i * 2] <= heap[i * 2 + 1] && heap[i] > heap[i * 2]) {
				swap = heap[i];
				heap[i] = heap[i * 2];
				heap[i * 2] = swap;
				i = i * 2;
			}
			else if (heap[i * 2] > heap[i * 2 + 1] && heap[i] > heap[i * 2 + 1]) {
				swap = heap[i];
				heap[i] = heap[i * 2 + 1];
				heap[i * 2 + 1] = swap;
				i = i * 2 + 1;
			}
			else break;
		}
	}
}
void top() {
	if (isEmpty())
		cout << -1 << endl;
	else
		cout << heap[1] << endl;
}
void print() {
	if (isEmpty())
		cout << -1 << endl;
	else {
		for (int i = 1; i < heap.size(); i++)
			cout << heap[i] << " ";
		cout << endl;
	}
}
int main() {
	heap.push_back(0);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int e;
			cin >> e;
			insert(e);
		}
		else if (s == "size")
			cout << size() << "\n";
		else if (s == "isEmpty")
			cout << isEmpty() << "\n";
		else if (s == "pop")
			pop();
		else if (s == "top")
			top();
		else if (s == "print")
			print();
	}
	return 0;
}