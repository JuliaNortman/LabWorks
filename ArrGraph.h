#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstdlib>

template <typename T>class ArrGraph
{
private:
	int **arr;
	T *data;
	int MaxN;

public:
	void ArrDfs(int, bool*);
	bool connected(); //check if graph is connected
	int arrDistance(int, int);
	ArrGraph(std::string, T*); // constructor
	~ArrGraph(); //destructor
	void print();
};


template <typename T>
bool ArrGraph<T>::connected()
{
	bool *visited = new bool[MaxN];
	for (int i = 0; i < MaxN; ++i) { visited[i] = false; }
	int c = 0;
	for (int i = 0; i < MaxN; ++i)
	{
		if (!visited[i])
		{
			c++;
			ArrDfs(i, visited);
		}
	}
	if (c > 1) { return false; }
	return true;
}

template <typename T>
int ArrGraph<T>::arrDistance(int u, int v)
{
	if (u == v) return 0;
	if (u < 0 || u >= MaxN || v < 0 || v >= MaxN) { return -1; }//wrong value
	std::stack <int> s;
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
		if (i != MaxN) { break; }
	}
	if (s.empty())
	{
		return -1;//vertexes sre not connecred
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
ArrGraph<T>:: ~ArrGraph()
{
	for (int i = 0; i < MaxN; ++i)
	{
		delete arr[i];
	}
	delete[] arr;
}

template <typename T>
void ArrGraph<T>::ArrDfs(int u, bool *visited)
{
	visited[u] = true;
	for (int i = 0; i < MaxN; ++i)
	{
		if (arr[u][i] == 1 && !visited[i]) { ArrDfs(i, visited); }
	}
}

template <typename T>
ArrGraph<T>::ArrGraph(std::string fname, T* dat)
{
	std::ifstream in(fname, std::ios::binary);
	in.read((char*)&MaxN, sizeof(int));
	data = new T[MaxN];
	arr = new int*[MaxN];
	for (int i = 0; i < MaxN; ++i)
	{
		arr[i] = new int[MaxN];
		data[i] = dat[i];
	}
	int k = 0;
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < MaxN; j++)
		{
			in.read((char*)&k, sizeof(int));
			arr[i][j] = k;
		}
	}
	in.close();
}

template<typename T>
void ArrGraph<T>::print()
{
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < MaxN; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < MaxN; ++i)
	{
		std::cout << "Data: ";
		std::cout << data[i] << std::endl;
	}

}