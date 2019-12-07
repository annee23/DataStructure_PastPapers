#include<iostream>
#include<vector>
#include<string>
#define NO_VER -1
#define VISITED 1
#define UNVISITED 3
#define BACK 2
using namespace std;
vector<vector<int>>graph(20001);
vector<int> vertices;
int edge[20001][20001];
int visit[20001];
void DFS(int V) {
	cout << V << " ";
	visit[V] = VISITED;
	for (int i = 0; i < graph[V].size(); i++)
	{
		if (edge[V][graph[V][i]] == UNVISITED)
		{
			if (visit[graph[V][i]] == UNVISITED)
			{
				edge[V][graph[V][i]]= edge[graph[V][i]][V] = VISITED;
				DFS(graph[V][i]);
			}
			else edge[V][graph[V][i]]=edge[graph[V][i]][V] = BACK;
		}
	}
}
int main() {
	int N, M, A, temp, S, D;
	cin >> N >> M >> A;
	while (N--) {
		cin >> temp;
		vertices.push_back(temp);
		visit[temp] = UNVISITED;
	}
	while (M--) {
		cin >> S >> D;
		if (edge[S][D] != 0)
			cout << -1 << endl;
		else {
			edge[S][D] = edge[D][S] = UNVISITED;
			graph[S].push_back(D);
			graph[D].push_back(S);
		}
	}
	/*for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i] == A)
			temp = i;
	}
	for (int i = temp; i < vertices.size(); i++) {
		if (visit[vertices[i]] == 0)*/
			DFS(A);
	//}
	return 0;
}