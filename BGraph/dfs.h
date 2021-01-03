#pragma once
#include "BGraph.h"
class dfs : public bGraph, public baseTraversal {
	int entry_time[MAX_VERTICES];
	int exit_time[MAX_VERTICES];
	int reachable_ancestor[MAX_VERTICES];
	int tree_outdegree[MAX_VERTICES];
	int time = 0;
	void initSearch() override {
		bGraph::initSearch();
		for (int i = 0; i < MAX_VERTICES; i++) {
			entry_time[i] = UNSET;
			exit_time[i] = UNSET;
			reachable_ancestor[i] = UNSET;
			tree_outdegree[i] = 0;
		}
		time = 0;
	}	
	edgeTypes edgeClassification(int x, int y) {
		if (parents[y] == x) return edgeTypes::TREE;
		if (discovered[y] && !processed[y]) return edgeTypes::BACK;
		std::cout << "\nUnknow edge type found (" << x << "," << y << ")\n";
		return edgeTypes::UNKNOWN;
	}

	void process_vertex_early(int x, bool print) {
		if (print) 	std::cout << "\nEarly Process Vertex: " << x << std::endl;
		reachable_ancestor[x] = x;
	}
	void process_vertex_late(int x, bool print) {
		if (print) std::cout << "\nLate Process Vertex: " << x << std::endl;
		if (parents[x] == UNSET && tree_outdegree[x] > 1)//is root node with more than 1 child
		{
			std::cout << "\nArticulation Vertex Root:" << x << "\n";
			return;
		}
		bool root = (parents[parents[x]] < 1);
		if (!root) {
			if (reachable_ancestor[x] == parents[x])
				std::cout << "\nArticulation Vertex Parent:" << parents[x] << "\n";
			if (reachable_ancestor[x] == x)
				std::cout << "\nBridge Articulation Vertex:" << parents[x] << "\n";
			if(tree_outdegree[x] > 0) //x is not a leaf
				std::cout << "\nBridge Articulation Vertex:" << x<< "\n";
		}

		if (entry_time[reachable_ancestor[x] < entry_time[reachable_ancestor[parents[x]]]])
			reachable_ancestor[parents[x]] = reachable_ancestor[x];
	}
	void processEdge(int x, int y, bool print) {
		if (print) std::cout << "(" << x << "," << y << ") ";
		edgeTypes edgeType = edgeClassification(x, y);
		if (edgeType == edgeTypes::TREE)
			tree_outdegree[x] = tree_outdegree[x] + 1;
		else if (edgeType == edgeTypes::BACK && parents[x]!=y) {
			if (entry_time[y] < entry_time[reachable_ancestor[x]])
				reachable_ancestor[x] = y;
		}
		if (discovered[y] && parents[y] != x) {//definition of back edge. 
			//x touching y when y has not touched x(not double processing the same edge). this was established inside traverse()
			// but y is already discovered and x is not its parent i-e it was discovered by someone else. The if condition above.
			// has to be a cycle as:
			// 1) y is not processed
			// 2) y is discovered
			// 3) x is visiting it in this edge (x,y)
			// 4) y has a different parent.
			// This shows y was discovered by x's ancestor in the same traversal chain and x is seeing y again in the same traversal chain so y is connecting with x and its ancestor. This is a cycle
			
			std::cout << "\nFound a cycle ";
			findPath(y, x, print);
			//finished = true;
		}
	}
	void traverse(int x, bool print) {
		if (finished) return;		
		discovered[x] = true;		
		time = time + 1;
		entry_time[x] = time;
		process_vertex_early(x, print);
		edgeNode* node = getEdge(x);
		while (node != nullptr) {
			int y = node->getY();
			if (!discovered[y]) {
				parents[y] = x;
				processEdge(x, y, print);
				traverse(y, print);
			}
			//ensures no double processeding of edge. 
			else if ((!processed[y] && parents[x]!=y)|| directed) {//(x,y) edge is already processed by (y,x) as y was discovered before x
				processEdge(x, y, print);
			}
			if (finished) return;
			node = node->getNext();
		}
		process_vertex_late(x, print);
		time = time + 1;
		exit_time[x] = time;
		processed[x] = true;
	}
public:
	dfs() {
		for (int i = 0; i < MAX_VERTICES; i++) {
			entry_time[i] = UNSET;
			exit_time[i] = UNSET;
			reachable_ancestor[i] = UNSET;
			tree_outdegree[i] = 0;
		}
		time = 0;
	}
	void traverse(int x) override { initSearch(); traverse(x, true); }	
	void findCycle(int x) override { initSearch(); traverse(x, true); };
	bool isConnected(int x, int y) override { return true; };
	void countComponents() override {};
	bool isBipartite() override { return true; };
	
	bool hasCycle() override { 
		initSearch();
		for (int i = 0; i < MAX_VERTICES; i++) {
			edgeNode* node = getEdge(i);
			if (node == nullptr)
				continue;
			if (!discovered[i])
			{
				traverse(i, false);
				if (finished) {
					std::cout << "\nThere is a cycle for traversal starting from:" << i << std::endl;
					return true;
				}
			}
		}
		return false;
	};
};
