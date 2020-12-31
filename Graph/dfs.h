#pragma once
#include <iostream>
class graph {
	const static int MAX_VERTICES = 1000;
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
	edgeNode* edges[MAX_VERTICES];
	int edgeCount{ 0 };
	int vertexCount{ 0 };
	int componentCount{ 0 };
	int componentIds[MAX_VERTICES];
	bool discovered[MAX_VERTICES];
	int parents[MAX_VERTICES];
	void initSearch() {
		for (int i = 0; i < MAX_VERTICES; i++)
		{
			discovered[i] = false;
			parents[i] = -1;
			componentIds[i] = -1;
		}
		componentCount = 0;
		hasCycle = false;
	}
	bool isDiscovered(int x) { return discovered[x]; }
public:
	graph() {
		for (int i = 0; i < MAX_VERTICES; i++)
		{
			edges[i] = nullptr;
			discovered[i] = false;
			parents[i] = -1;
			componentIds[i] = -1;
		}
	}
	void print() {
		std::cout << "\nVertices:" << vertexCount << " Edges:" << edgeCount << " Components:" << componentCount << std::endl;
	}
	void addEdge(int x, int y) { addEdge(x, y, false); }
	void addEdge(int x, int y, bool directed) {
		if (edges[x] == nullptr)
			vertexCount++;
		edgeNode* node = new edgeNode(y, edges[x]);
		edges[x] = node;
		edgeCount++;
		if (!directed)
			addEdge(y, x, true);
	}
	void printEdges() {
		for (int x = 0; x < MAX_VERTICES; ++x) {
			edgeNode* node = edges[x];
			while (node != nullptr) {
				std::cout << "\n(" << x << "," << node->getY() << ")";
				node = node->getNext();
			}
		}
	}
	void process_dfs_early(int v, bool print) { if (print) std::cout << "\nStart:" << v << "\n"; }
	void process_dfs_late(int v, bool print) { if (print) std::cout << "\nDone:" << v << "\n"; }
	void process_dfs_edge(int x, int y, bool print) { if (print) std::cout << "\t(" << x << "," << y << ")"; }
	void dfs(int x) { initSearch(); dfs(x, true); }
	void dfs(int x, bool print) {
		edgeNode* node = edges[x];
		std::cout << "\n";
		discovered[x] = true;
		process_dfs_early(x, print);
		componentIds[x] = componentCount;
		while (node != nullptr) {
			int y = node->getY();
			//if (print)
				//std::cout << "(" << x << "," << y << ")" << (discovered[x] ? "Visted" : ":Not Visited") << (discovered[y] ? "Visted" : ":Not Visited") << "\t";
			process_dfs_edge(x, y, print);
			if (!discovered[y]) {
				parents[y] = x;
				dfs(y, print);
			}
			node = node->getNext();
		}
		process_dfs_late(x, print);
	}
	void findPath(int x, int y, bool print) {
		initSearch();
		dfs(x, false);
		if (!isDiscovered(y) || x == y || parents[y] < 0) {
			std::cout << "Invalid search vertcies. A path does not exist between " << x << " and " << y;
			return;
		}
		std::cout << "\nFind Path from " << x << " to " << y << std::endl;
		findPath(x, y);
	}
	void findPath(int x, int y) {
		std::cout << y;
		if (x == y || y < 0) {
			return;
		}
		std::cout << "->";
		findPath(x, parents[y]);
	}
	void countComponents() {
		initSearch();
		for (int i = 0; i < MAX_VERTICES; i++) {
			if (edges[i] == nullptr) continue;
			if (!isDiscovered(i)) {
				componentCount++;
				dfs(i, false);
			}
			else {
				int y = 0;
			}
		}
	}
	void areConnected(int x, int y) {
		std::cout << std::endl << x << (componentIds[x] == componentIds[y] ? " is " : " is not ") << "connected with " << y << std::endl;
	}
	void isCyclical() {
		cycle();
		std::cout << "\nHas Cycle: " << (hasCycle ? " Yes\n" : " No\n");		
	}
private:
	bool hasCycle = false;
	void cycle() {
		initSearch();
		for (int s = 0; s < MAX_VERTICES; s++) {
			if (edges[s] == nullptr) continue;
			if (!isDiscovered(s))
				dfs(s, s);
		}
	}
	void dfs(int x, int x1) {
		discovered[x] = true;
		edgeNode* node = edges[x];
		while (node != nullptr) {
			int y = node->getY();
			if (!isDiscovered(y))
				dfs(y, x);
			else if (y != x1)
				hasCycle = true;
			node = node->getNext();
		}
	}
};