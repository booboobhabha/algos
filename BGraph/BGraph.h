#pragma once
#include <iostream>
static  const int MAX_VERTICES = 100;
class baseTraversal {
public:
	virtual void findPath(int x, int y) = 0;
	virtual void traverse(int x) = 0;
	virtual bool isConnected(int x, int y) = 0;
	virtual void countComponents() = 0;
	virtual bool isBipartite() = 0;

	virtual void findCycle(int x) = 0;//not done in bfs
	virtual bool hasCycle() = 0;//not done in bfs
};
class edgeNode {
private:
	int y{ -1 };
	edgeNode* next{ nullptr };
public:
	edgeNode(int _y, edgeNode* _node) : y{ _y }, next{ _node }{}
	edgeNode(int _y) : y{ _y }, next(nullptr){}
	edgeNode() : y(0), next(nullptr) {}
	int getY() const { return y; }
	edgeNode* getNext() const { return next; }
	void print() { std::cout << y; }
};
class bGraph {

protected:
	int verticesCount{ 0 };
	int edgesCount{ 0 };
	int components{ 0 };
	bool isTwoColor{ true	};
	bool directed{ false };
	edgeNode* edges[MAX_VERTICES];
	bool discovered[MAX_VERTICES];
	bool processed[MAX_VERTICES];
	int parents[MAX_VERTICES];
	int degree[MAX_VERTICES];
	int componentIds[MAX_VERTICES];
	int color[MAX_VERTICES];
	bool finished{ false };
	
	virtual void initSearch() {
		for (int i = 0; i < MAX_VERTICES; i++) {			
			discovered[i] = false;
			parents[i] = -1;
			processed[i] = false;
			componentIds[i] = -1;
			color[i] = 0;
		}
		components = 0;
		finished = false;
		isTwoColor = true;
	}
	int getOppositeColor(int x) {
		if (x == 1) return 2;
		if (x == 2) return 1;
		return 0;
	}
public:
	bGraph() {
		for (int i = 0; i < MAX_VERTICES; i++) {
			edges[i] = nullptr;
			discovered[i] = false;
			processed[i] = false;
			parents[i] = -1;
			degree[i] = 0;
			componentIds[i] = -1;
			color[i] = 0;			
		}
		components = 0;
		finished = false;
		isTwoColor = true;
	}
	edgeNode* getEdge(int v) { return edges[v]; }
	void addEdge(int x, int y) {addEdge(x, y, false);}
	void addEdge(int x, int y, bool directed) {
		edgeNode* node = new edgeNode(y, edges[x]);
		edges[x] = node;		
		if (degree[x] == 0) verticesCount++;
		degree[x]++;
		edgesCount++;
		if (!directed) {
			addEdge(y, x, true);
		}
	}
	void print() {std::cout << "\nVertices:" << verticesCount << " Edges:" << edgesCount << " Components:" << components << std::endl;}
	void printEdges() {
		for (int x = 0; x < MAX_VERTICES; ++x) {
			edgeNode* node = edges[x];
			if (node == nullptr)
				continue;
			std::cout << "\nvertex: " << x << "\n";			
			while (node != nullptr) {
				std::cout << node->getY() << "\t" ;
				node = node->getNext();
			}
		}
	}


};