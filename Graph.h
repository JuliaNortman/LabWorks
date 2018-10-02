#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "stack"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "figures.h"
#include "pentagon.h"
#include "quadrangle.h"
#include "triangle.h"

using namespace std;



typedef struct Node
{
	int n;
	Node *next;
}listn, *listp;


template <typename T>class Graph
{
private:
	int MaxN; // max number of vetexes
	listp *adj = nullptr; // head of the adj list
	int **arr;
	FILE *f = nullptr;
	T *data;

public:
	void ListDfs(int, bool*);
	void ArrDfs(int, bool*);
	bool connected(); //check if graph is connected
	int arrDistance(int, int);
	int listDistance(int, int);
	void print();
	Graph(string, T*); // constructor
	~Graph(); //destructor

};



template <typename T>
Graph<T>::Graph(string fname, T* d)
{
	errno_t err = fopen_s(&f, fname.c_str(), "r+b");
	fread(&MaxN, sizeof(int), 1, f);
	data = new T[MaxN];
	arr = new int*[MaxN];
	adj = new listp[MaxN];
	for (int i = 0; i < MaxN; ++i)
	{
		arr[i] = new int[MaxN];
		adj[i] = nullptr;
		data[i] = d[i];
	}
	int k = 0;
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < MaxN; j++)
		{
			fread(&k, sizeof(int), 1, f);
			arr[i][j] = k;
			if (k == 1)
			{
				listp p = new listn;
				p->n = j;
				p->next = adj[i];
				adj[i] = p;
			}
		}
	}
	fclose(f);
}

template <typename T>
int Graph<T>::listDistance(int u, int v)
{
	if (u == v) return 0;
	if (u < 0 || u>MaxN || v < 0 || v > MaxN) return -1;
	stack <int> s;
	bool *visited = new bool[MaxN];
	int *prev = new int[MaxN];
	for (int i = 0; i < MaxN; ++i)
	{
		visited[i] = false;
		prev[i] = -1;
	}

	s.push(u);
	int w = 0; //vertex from the stack
	listp p = nullptr;
	while (!s.empty())
	{
		w = s.top();
		s.pop();
		visited[w] = true;
		p = adj[w];
		while (p)
		{
			if (!visited[p->n])
			{
				s.push(p->n);
				prev[p->n] = w;
			}
			if (p->n == v) break;
			p = p->next;
		}
		if (p) break;
	}
	if (s.empty()) return -1;
	int n = 0;
	w = v;
	while (w != u)
	{
		++n;
		w = prev[w];
	}
	return n;
}

template <typename T>
void Graph<T>::ListDfs(int u, bool *visited)
{
	visited[u] = true;
	for (listp p = adj[u]->next; p; p = p->next)
	{
		if (!visited[p->n]) ListDfs(p->n, visited);
	}
}


template <typename T>
void Graph<T>::ArrDfs(int u, bool *visited)
{
	visited[u] = true;
	for (int i = 0; i < MaxN; ++i)
	{
		if (arr[u][i] == 1 && !visited[i]) ArrDfs(i, visited);
	}
}

template <typename T>
bool Graph<T>::connected()
{
	bool *visited = new bool[MaxN];
	for (int i = 0; i < MaxN; ++i) visited[i] = false;
	int c = 0;
	for (int i = 0; i < MaxN; ++i)
	{
		if (!visited[i])
		{
			c++;
			ArrDfs(i, visited);
		}
	}
	if (c > 1) return false;
	return true;
}

template <typename T>
int Graph<T>::arrDistance(int u, int v)
{
	if (u == v) return 0;
	if (u < 0 || u >= MaxN || v < 0 || v >= MaxN) return -1;
	stack <int> s;
	bool *visited = new bool[MaxN];
	int *prev = new int[MaxN];
	for (int i = 0; i < MaxN; ++i)
	{
		visited[i] = false;
		prev[i] = -1;
	}
	s.push(u);
	int w = 0; //vertex from the stack
	while (!s.empty())
	{
		w = s.top();
		s.pop();
		visited[w] = true;
		int i = 0; // matrix index
		for (i = 0; i < MaxN; ++i)
		{
			if (arr[w][i] == 1 && !visited[i])
			{
				s.push(i);
				prev[i] = w;
			}
			if (i == v && arr[w][i] == 1) break;
		}
		if (i != MaxN) break;
	}
	if (s.empty())
	{
		return -1;
	}
	int n = 0;
	w = v;
	while (w != u)
	{
		++n;
		w = prev[w];
	}
	return n;
}

template<typename T>
Graph<T>:: ~Graph()
{
	listp p, t;
	for (int i = 0; i < MaxN; ++i)
	{
		delete arr[i];
		p = adj[i];
		while (p)
		{
			t = p;
			p = p->next;
			delete t;
		}
	}
	delete[] arr;
	delete[] adj;
}


template<typename T>
void Graph<T>::print()
{
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < MaxN; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < MaxN; ++i)
	{
		cout << "Data: ";
		cout << data[i] << endl;
	}
	
}

