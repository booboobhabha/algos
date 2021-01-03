#pragma once
#include <iostream>
static  const int MAX_VERTICES = 100;
static  const int UNSET = -1;
class baseTraversal {
public:
	virtual void traverse(int x) = 0;
	virtual bool isConnected(int x, int y) = 0;
	virtual void countComponents() = 0;
	virtual bool isBipartite() = 0;

	virtual void findCycle(int x) = 0;//not done in bfs
	virtual bool hasCycle() = 0;//not done in bfs
	enum edgeTypes { UNKNOWN = 1, TREE = 2, BACK = 3, CROSS = 4, FORWARD = 5, COUNT = 6 };
	
};
class edgeNode {
private:
	int y{ UNSET };
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
			parents[i] = UNSET;
			processed[i] = false;
			componentIds[i] = UNSET;
			color[i] = 0;
		}
		components = 0;
		finished = false;
		isTwoColor = true;
	}
	virtual void findPath(int x, int y, bool print) {
		if (x == y) {
			std::cout << x;
			return;
		}
		if (y == UNSET) {
			std::cout << "\tPath does not exist";
			return;
		}
		std::cout << y << "->";
		findPath(x, parents[y], print);

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
			parents[i] = UNSET;
			degree[i] = 0;
			componentIds[i] = UNSET;
			color[i] = 0;			
		}
		components = 0;
		finished = false;
		isTwoColor = true;
	}
	void findPath(int x, int y) {
		if (x > MAX_VERTICES || y > MAX_VERTICES) {
			std::cout << "\n" << x << " is not connected with " << y << ". Please check vertex\n";
			return;
		}
		std::cout << "\nFinding Path from " << x << " to " << y << std::endl;
		findPath(x, y, true);
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