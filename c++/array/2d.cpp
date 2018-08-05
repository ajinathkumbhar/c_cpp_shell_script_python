#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <string.h>
#include <iomanip>

using namespace std;

class Graph {
private:
	int V;
	bool **adj;
public:
	Graph(int v);
	~Graph() {
		for (int i = 0; i < this->V; ++i)
		{
			delete[] adj[i];
		}
		delete[] adj;
	}
	void addEdge(int u,int v) {
		if ( u >= this->V || v >= this->V) {
			cout << "out of bound ";
            cout << "u : " << u << " ";
            cout << "v : " << v << endl;
		}

		adj[u][v]=true;
	}
	void print(void);

};

Graph::Graph(int V) {
	this->V = V;
	adj = new bool* [V];

	for (int i = 0; i < V; ++i)
	{
			adj[i] = new bool[V];
			memset(adj[i],false,V * sizeof(bool));	
	}
}

void Graph::print() {
	for (int u = 0; u < this->V; ++u)
	{
		for (int v = 0; v < this->V; ++v)
		{
			cout << setw(4) << adj[u][v];
		}
		cout << endl;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	Graph test(4);
	test.addEdge(1,4);
	test.addEdge(2,2);
	test.print();

	#ifndef H_PIX_SIZE
	#define H_PIX_SIZE 3
	#endif

	#ifndef V_PIX_SIZE
	#define V_PIX_SIZE 4
	#endif
	
	int **pixmap;
	pixmap = new int * [H_PIX_SIZE];

	for (int i = 0; i < H_PIX_SIZE; ++i)
	{
		pixmap[i] = new int[V_PIX_SIZE];
		memset(pixmap[i],0, V_PIX_SIZE * sizeof(int));
	}

	for (int hPx = 0; hPx < H_PIX_SIZE; ++hPx)
	{
		for (int vPx = 0; vPx < V_PIX_SIZE; ++vPx)
			{
				pixmap[hPx][vPx] = hPx * vPx;
				cout << setw(4) << pixmap[hPx][vPx];
			}	/* code */
			cout << endl;
	}
	cout << '\n';



	for (int i = 0; i < H_PIX_SIZE; ++i)
	{
		delete[] pixmap[i];
	}
	delete[] pixmap;
	return 0;
}