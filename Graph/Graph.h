#pragma once
#include <iostream>
#include <queue>

const int MAX_VERTICES = 10000;
struct EdgeNode {
private:
	int y{ -1 };
	int weight{ 1 };
	EdgeNode* next{ nullptr };
public: 
	EdgeNode(int _y, int _weight, EdgeNode* _next) : y{ _y }, weight{ _weight }, next{ _next }{}
	EdgeNode(int _y, EdgeNode* _next) : y{ _y }, next{ _next }{}
	EdgeNode(int _y) : y{ _y }, next{ nullptr}{}
	const int getWeight() const { return weight; } ;
	const int getY() const { return y; } ;
	const EdgeNode* const getNext() const { return next; };
	void print() const{std::cout << "," << y << "(Weight=" << weight << (next== nullptr ? ",next=nullptr)" : ",next=value)");	}
};

class Graph {
	EdgeNode* edges[MAX_VERTICES]{ nullptr };
	int degree[MAX_VERTICES]{ 0 };
	int totalVertices{ 0 };
	int totalEdges{ 0 };	
	bool directed{ false };
	bool processed[MAX_VERTICES]{ false };
	bool discovered[MAX_VERTICES]{ false };
	bool finished = false;
	int parents[MAX_VERTICES];
	void initializeSearch() {
		for (int i = 0; i < MAX_VERTICES; i++)
		{
			parents[i] = -1;
			processed[i] = false;
			discovered[i] = false;
		}
		finished = false;
	}
public:
	int Vertices() const 	{return totalVertices; }
	int Edges() const { return totalEdges; }
	const EdgeNode* getEdge(int x) const {
		if (x > MAX_VERTICES)  return nullptr;
		return edges[x];
	}
	bool insertEdge(int x, int y) { return insertEdge(x, y, 1, false); }
	bool insertEdge(int x, int y, int weight, bool _directed) {
		if (x > MAX_VERTICES) { std::cout << std::endl << "Unable to insert edge. Max vertices allowed:" << MAX_VERTICES; return false; }
		EdgeNode* temp = new EdgeNode(y, weight, edges[x]);
		if (degree[x] == 0) totalVertices++;
		edges[x] = temp;
		degree[x]++;
		totalEdges++;
		if (!_directed) {
			insertEdge(y, x, weight, true);
		}
		return true;
	}	
	void print() const {
		std::cout << std::endl << "Total Edges=" << totalEdges <<  " Total Vertices=" << totalVertices;
		for (int x = 0; x < MAX_VERTICES; x++){
			EdgeNode* edge = edges[x];		
			if (edge == nullptr)
				continue;
			std::cout << std::endl  << "Vertex=" << x << " " << "(Degree=" << degree[x]<< ") : ";
			const EdgeNode* node = edge;
			while (node != nullptr) {
				node->print();
				node = node->getNext();
			}
		}
	}
	void bfs(int start) {bfs(start, true);}
	void bfs(int start, bool print) {
		const EdgeNode* edge = getEdge(start);
		if (edge == nullptr) return;
		std::queue<int> queue;
		initializeSearch();
		int vertex = -1;
		queue.push(start);
		discovered[start] = true;
		while (!queue.empty()) {
			vertex = queue.front();
			queue.pop();
			if (processed[vertex])
				continue;
			if (print)	process_vertex_early(vertex);
			edge = getEdge(vertex);
			while (edge != nullptr) {
				int y = edge->getY();
				if (!processed[y] || directed) {
					if (print)	process_edge(vertex, y);
				}
				if (!discovered[y]) {
					queue.push(y);
					discovered[y] = true;
					parents[y] = vertex;
				}
				edge = edge->getNext();
			}
			processed[vertex] = true;
			if (print)	process_vertex_late(vertex);
		}
		if (print) {
		std::cout << "\n(ChildVertex,ParentVertex)\n";		
			for (int i = 0; i < MAX_VERTICES ; i++) {
				const EdgeNode* node = getEdge(i);
				if (node == nullptr) { continue; }
				std::cout << "(" << i << "," << parents[i] << ")";
			}
		}		
	}	
	void connected_components() {
		initializeSearch();
		int count = 0;
		const EdgeNode* edge = nullptr;
		for (int i = 0; i < MAX_VERTICES; i++) {
			edge = getEdge(i);
			if (!discovered[edge->getY()]) {
				count++;
				bfs(edge->getY());
			}
		}
		std::cout << "\n Connected Components Count:" << count;
	}
	void find_path(int start, int end) {
		bfs(start, false);
		std::cout << "\nfind shortest path from " << start << " to " << end << std::endl;
		find_path(start, end, processed);
	}
	void find_path(int start, int end, bool *processed) {
		if ( end == -1)
			return;		
		if (end == start) {
			std::cout << start;
			return;
		}
		std::cout << end << "->";
		find_path(start, parents[end], processed);
	}

		void process_vertex_early(int vertex) {
			std::cout << std::endl << "Processing Vertex: " << vertex;
	}
	void process_edge(int vertex, int y) {
		std::cout << std::endl << "\tProcessing Edge(" << vertex << "," << y << ")";		
	}
	void process_edge_dfs(int x, int y) {		
		std::cout << std::endl << "\tProcessing Edge(" << x << "," << y << ")";
		if (discovered[y] && (parents[x] != y)) {
			std::cout << std::endl << "Cycle(" << x << "," << y << ")";
			find_path(x, y);
			std::cout << std::endl << std::endl;
			finished = true;
		}
	}
	void process_vertex_late(int vertex) {

	}
	void dfs1(int start) {
		initializeSearch();
		dfs(start, false);
	}
	void dfs(int v, bool print) {
		const EdgeNode* p;
		int y;
		if (finished) 
			return;
		discovered[v] = true;
		process_vertex_early(v);
		p = getEdge(v);
		while (p != nullptr) {
			y = p->getY();
			if (!discovered[y]) {
				parents[y] = v;
				process_edge_dfs(v, y);
				dfs(y, false);
			}
			else if (((!processed[y]) && (parents[v] != y)) || (directed))
			{
				process_edge_dfs(v, y);
				if (finished) 
					return;
				p = p->getNext();
			}
		//	p = p->getNext();
		}
		process_vertex_late(v);
		processed[v] = true;
	}
};