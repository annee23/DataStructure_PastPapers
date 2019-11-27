#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Vrt {
	int idx = -1;
	int data = -1;
};
struct Edg {
	Vrt* S = NULL;
	Vrt* D = NULL;
	string str;
};
vector<Edg*>E;
vector<Vrt*> V;
Vrt* find(int F) {
	bool boo = false;
	for (int i = 0; i < V.size(); i++)
	{
		if (V[i]->data == F)
		{
			boo = true;
			return V[i];
		}
	}
	if (!boo)
		return NULL;

}
int main() {
	int N, M, K, I, S, D, L;
	string U;
	cin >> N >> M >> K;
	int vc = N, ec = 0;
	vector<vector<Edg*>> Matrix(N, vector<Edg*>(N, NULL));
	for(int i=0;i<N;i++) {
		cin >> I;
		Vrt* newV = new Vrt;
		newV->data = I;
		V.push_back(newV);
		newV->idx = i;
	}
	while (M--) {
		cin >> S >> D >> U;
		Vrt* Sv = find(S);
		Vrt* Dv = find(D);
		if (Matrix[Sv->idx][Dv->idx] != NULL|| Matrix[Dv->idx][Sv->idx] !=NULL)
			cout << -1 << endl;
		else
		{
			ec++;
			Edg* newE = new Edg;
			newE->S = Sv;
			newE->D = Dv;
			newE->str = U;
			E.push_back(newE);
			Matrix[Sv->idx][Dv->idx] = newE;
			Matrix[Dv->idx][Sv->idx] = newE;
		}
	}
	cout << vc << " " << ec << endl;
	while (K--) {
		cin >> L;
		if (find(L) == NULL)
			cout << -1 << endl;
		else {
			Vrt* tmp = find(L);
			V.erase(V.begin() + tmp->idx);
			vc--;
			for(int i=0;i<E.size();i++)
			{
				if (E[i]->D == tmp || E[i]->S == tmp)
				{
					ec--;
					delete E[i];
					E.erase(E.begin() + i);
					if(i!=E.size()-1)
						i--;
				}
			}
			cout << ec << " ";
			for (int i = 0; i < E.size(); i++)
			{
				cout << E[i]->str << " ";
			}
			cout << endl;
		}
	}
	return 0;
}