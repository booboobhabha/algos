#pragma once

#include "BGraph.h"
#include <queue>

class bfs : public bGraph, public baseTraversal {
		void process_vertex_early(int x, bool print) { if (print) 	std::cout << "\nEarly Process Vertex: " << x << std::endl; }
		void process_vertex_late(int x, bool print) { if (print) std::cout << "\nLate Process Vertex: " << x << std::endl; }
		void processEdge(int x, int y, bool print) {
			if (print) std::cout << "(" << x << "," << y << ") ";
			if (color[x] == color[y]) {
				isTwoColor = false;
				if (print && !isTwoColor) {
					//std::cout << "\nFound a color match, not bipartite(" << x << "," << y << ")";					
				}
			}
			else {
				color[y] = getOppositeColor(color[x]);
			}
		}
		void traverse(int v, bool print) {
			//Each edge of the connected component is touched twice for undirected and once for directed
			//Each vertex is touched only once outside of the while loop of the connected component
			//time complexity to traverse using bfs is O(E + V) i-e linear complexity
			//It first discovers a vertex and then discovers all adjacent nodes and add them to a queue.
			//One it finishes discovering all adjacent nodes, the vertex is considered processed.
			//It then picks the next item from the queue (which was one of the adjacent nodes of the vertex just finished processing) and repeats the process
			//The outer while loop of fifo queue, touches each vertex only once, if it was connected.
			//the inner while loop of node, touches each vertex twice for undirected graphs because adjacency list stores each edge twice (3,4) and (4,3)
			//Except for root node, each vertex has a processed adjacent node.
			//traversing with bfs creates a tree with start node as the root.
			//confirm this...If there are no cycles then 3 should be a parent of 4 and 4 should be a parent of 3. parent[x]==y and parent[y]==x if both x and  y are discovered. If not then there must be cycle.
			int x, y;
			
			std::queue<int> fifo;
			fifo.push(v);
			while (!fifo.empty()) {				
				x = fifo.front();
				fifo.pop();
				edgeNode* node = getEdge(x);//test with an invalid vertex that has not been added as an edge
				if (node == nullptr)
					continue;
				discovered[x] = true;
				process_vertex_early(x, print);
				componentIds[x] = components;
				while (node != nullptr) {
					y = node->getY();
				//	if (!processed[y] || directed) {//remove this line if want to see each edge twice for undirected graph
						processEdge(x, y, print);						
					//}
					if (!discovered[y]) {
						fifo.push(y);
						parents[y] = x;
						discovered[y] = true;
					}					
					node = node->getNext();
				}
				process_vertex_late(x, print);
				processed[x] = true;
			}
		}
		void findPath(int x, int y, bool print) {
			if (x == y) {
				std::cout << x;
				return;
			}
			if (y == -1) {
				std::cout << "\tPath does not exist";
				return;
			}
			std::cout << y << "->";
			findPath(x, parents[y], print);

		}
public: 
	void traverse(int x) override { initSearch(); traverse(x, true); }
	bool isConnected(int x, int y) {
		countComponents();
		if (x > MAX_VERTICES || y > MAX_VERTICES || componentIds[x] == -1 || componentIds[y] == -1) {
			std::cout << "\n" << x  << " is not connected with " << y << ". Please check vertex\n";
			return false;
		}
		std::cout << "\n" << x << (componentIds[x] == componentIds[y] ? " is " : " is not ") << "connected with " << y;
		return componentIds[x] == componentIds[y];
	}
	void countComponents() override {
		initSearch();
		for (int x = 0; x < MAX_VERTICES; x++) {
			if (edges[x] == nullptr) continue;
			if (!discovered[x])
			{
				components++;
				traverse(x, false);
			}
		}
		std::cout << "\nComponent Count is:" << components;
	}
	void findPath (int x, int y) override {
		if (x > MAX_VERTICES || y > MAX_VERTICES ) {
			std::cout << "\n" << x << " is not connected with " << y << ". Please check vertex\n";
			return;
		}
		traverse(x);
		std::cout << "\nFinding Path from " << x << " to " << y << std::endl;
		findPath(x, y, true);
	}
	
	void findCycle (int x) override {}
	
	
	bool hasCycle() override { return true; }	
	bool isBipartite() override {
		initSearch();
		for (int x = 0; x < MAX_VERTICES; x++) {
			if (edges[x] == nullptr) continue;
			if (!discovered[x])
			{
				color[x] = 1;
				traverse(x, false);
			}
		}
		std::cout << "\nIs Bipartite:" << (isTwoColor? "Yes":"No") <<std::endl;
		return isTwoColor;
	}
	
};
