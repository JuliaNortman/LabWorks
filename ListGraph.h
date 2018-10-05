#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstdlib>

struct Node
{
	int n;
	Node *next;
};

template <typename T>class ListGraph 
{
private:
	Node **adj = nullptr; // head of the adj list
	int MaxN;
	T* data;
public:
	void ListDfs(int, bool*);
	int listDistance(int, int);
	ListGraph(std::string, T*); // constructor
	~ListGraph(); //destructor
	bool connected(); //check if graph is connected
	void print();
};


template<typename T>
void ListGraph<T>::print()
{
	Node *p;
	for (int i = 0; i < MaxN; ++i)
	{
		p = adj[i];
		std::cout << i << ": ";
		while (p)
		{
			std::cout << p->n << "  ";
			p = p->next;
		}
		std::cout << endl;
	}
	for (int i = 0; i < MaxN; ++i)
	{
		std::cout << "Data: " << data[i] << endl;
	}

}

template <typename T>
ListGraph<T>::ListGraph(std::string fname, T* dat)
{
	ifstream in(fname, ios::binary);
	in.read((char*)&MaxN, sizeof(int));
	data = new T[MaxN];
	adj = new Node*[MaxN];
	for (int i = 0; i < MaxN; ++i)
	{
		adj[i] = nullptr;
		data[i] = dat[i];
	}
	int k = 0;
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < MaxN; j++)
		{
			in.read((char*)&k, sizeof(int));
			if (k == 1)
			{
				Node* p = new Node;
				p->n = j;
				p->next = adj[i];
				adj[i] = p;
			}
		}
	}
	in.close();
}

template <typename T>
int ListGraph<T>::listDistance(int u, int v)
{
	if (u == v) return 0;
	if (u < 0 || u>MaxN || v < 0 || v > MaxN) { return -1; } //wrong value of vertex
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
	Node* p = nullptr;
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
	if (s.empty()) { return -1; }// vertexes are not connected
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
void ListGraph<T>::ListDfs(int u, bool *visited)
{
	visited[u] = true;
	for (Node* p = adj[u]; p; p = p->next)
	{
		if (!visited[p->n]) { ListDfs(p->n, visited); }
	}
}


template <typename T>
bool ListGraph<T>::connected()
{
	bool *visited = new bool[MaxN];
	for (int i = 0; i < MaxN; ++i) { visited[i] = false; }
	int c = 0;
	for (int i = 0; i < MaxN; ++i)
	{
		if (!visited[i])
		{
			c++;
			ListDfs(i, visited);
		}
	}
	if (c > 1) { return false; }
	return true;
}

template<typename T>
ListGraph<T>:: ~ListGraph()
{
	Node* p, *t;
	for (int i = 0; i < MaxN; ++i)
	{
		p = adj[i];
		while (p)
		{
			t = p;
			p = p->next;
			delete t;
		}
	}
	delete[] adj;
}