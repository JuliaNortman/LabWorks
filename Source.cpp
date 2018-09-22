#include <iostream>
#include <fstream>
#include "stack"

using namespace std;

/*√рафи на основ≥ списку сум≥жност≥, матриц≥ сум≥жност≥. ѕерев≥рка на
звТ€зн≥сть графу. ¬изначенн€ в≥дстан≥ м≥ж двома вершинами графу.*/

typedef struct Node
{
	int n;
	Node *next;
}listn, *listp;

class Graph
{
private:
	const int MaxN; // max number of vetexes
	listp beg = nullptr; // head of the adj list
	/*
	// объ€вление двумерного динамического массива на 10 элементов:
float **ptrarray = new float* [2]; // две строки в массиве
    for (int count = 0; count < 2; count++)
        ptrarray[count] = new float [5]; // и п€ть столбцов
//  где ptrarray  Ц массив указателей на выделенный участок пам€ти под массив вещественных чисел  типа float*/

public:
	void ListDfs(int);
	void ArrDfs(int);
	bool connected(); //check if graph is connected
	int arrDistance(int, int);

};

//bool visited[] - visited array
//adj[] - adj list
// arr[] - matrix
// MaxN - maximum number of vertexes
void Graph::ListDfs(int u)
{
	visited[u] = true;
	for (listp p = adj[u]->next; p; p = p->next)
	{
		if (!visited[p->n]) ListDfs(p->n);
	}
}

//arr[] - adj array
void Graph::ArrDfs(int u)
{
	visited[u] = true;
	for (int i = 0; i < MaxN; ++i)
	{
		if (arr[u][i] == 1 && !visited[i]) ArrDfs(i);
	}
}

bool Graph::connected()
{
	bool *visited = new bool[MaxN];
	for (int i = 0; i < MaxN; ++i) visited[i] = false;
	int c = 0;
	for (int i = 0; i < MaxN; ++i)
	{
		if (!visited[i])
		{
			c++;
			if (beg) ListDfs(i);
			else ArrDfs(i);
		}
	}
	if (c > 1) return false;
	return true;
}

int Graph::arrDistance(int u, int v)
{
	stack <int> s;
	bool visited[MaxN];
	int prev[MaxN];
	for (int i = 0; i < MaxN; ++i)
	{
		visited[i] = false;
		prev[i] = -1;
	}
	while (!s.empty() &&)
	{

	}
}

int main() 
{

	system("pause");
	return 0;
}
