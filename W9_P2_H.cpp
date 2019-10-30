#include<iostream>
#include<vector>
#include <string>
using namespace std;
vector<int>heap;
vector<int>heapmax;
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
void insertmax(int e) {
	heapmax.push_back(e);
	int swap = 0;
	for (int i = heapmax.size() - 1; i > 1; i /= 2)	//min-heap이랑 조건다르게 해줘야함.
	{
		if (heapmax[i] > heapmax[i / 2])
		{
			swap = heapmax[i];
			heapmax[i] = heapmax[i / 2];
			heapmax[i / 2] = swap;
		}
		else break;
	}
}
void pop() {
	heap[1] = heap[heap.size() - 1];
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
void popmax() {
	heapmax[1] = heapmax[heapmax.size() - 1];
	heapmax.pop_back();
	int swap = 0;
	for (int i = 1; i * 2 < heapmax.size();) {
		if (i * 2 + 1 == heapmax.size() && heapmax[i] < heapmax[i * 2])
		{
			swap = heapmax[i];
			heapmax[i] = heapmax[i * 2];
			heapmax[i * 2] = swap;
			i = i * 2;
		}
		else if (heapmax[i * 2] >= heapmax[i * 2 + 1] && heapmax[i] < heapmax[i * 2]) {
			swap = heapmax[i];
			heapmax[i] = heapmax[i * 2];
			heapmax[i * 2] = swap;
			i = i * 2;
		}
		else if (heapmax[i * 2] < heapmax[i * 2 + 1] && heapmax[i] < heapmax[i * 2 + 1]) {
			swap = heapmax[i];
			heapmax[i] = heapmax[i * 2 + 1];
			heapmax[i * 2 + 1] = swap;
			i = i * 2 + 1;
		}
		else break;
	}
}
int main() {
	heap.push_back(0);
	heapmax.push_back(0);
	int N, T, p, t;
	cin >> T;
	while (T--) {
		cin >> N >> p;
		while (N--) {
			cin >> t;
			insert(t);
			insertmax(t);
		}
		cout << heap[p] << endl;
		for (int i = 1; i < p; i++)
			pop();
		cout << heap[1] << endl;

		cout << heapmax[p] << endl;
		for (int i = 1; i < p; i++)
			popmax();
		cout << heapmax[1] << endl;
		while (heap.size() != 1)
		{
			heap.pop_back();
			heapmax.pop_back();
		}
	}
	return 0;
}