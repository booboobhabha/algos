#pragma once
class whatever {
public:
	int val{ -4 };
	whatever* next{ nullptr };
	whatever() {}
	whatever(int _val, whatever* _next) : val{ _val }, next (_next) {} 
	void set(int _val, whatever* _next) 
		{
			val = _val;
			next = _next;
		}
	
	void set(int _val) {
		val = _val;		
	}
	void print() {
		std::cout << std::endl << val << " next is: " << (next == nullptr ? "nullptr" : "not nullptr") <<std::endl;
	}
};
class EdgeNode {
	int y{ -1 };
	int weight{ 1 };
	EdgeNode* next{ nullptr };
public:
	EdgeNode() : y(-1), weight(1), next(nullptr) {}
	EdgeNode(int _y, int _weight, EdgeNode* _next) : y{ _y }, weight{ _weight }, next(_next) {}
	/*EdgeNode& operator=(const EdgeNode& other) {
		*this->next = *other.getNext();
		this->y = other.getY();
		this->weight = other.getWeight();
		return *this;
	}*/
	int getY() const { return y; };
	int getWeight() const { return weight; };
	EdgeNode* getNext() const { return next; };
	void const print() {
		std::cout << getY() << "(weight=" << getWeight() << "),";
	}
};

const int MAX_VERTICES = 5;
class Graph {
	EdgeNode edges[MAX_VERTICES];
	int degree[MAX_VERTICES]{ 0 };
	int verticesCount{ 0 };
	int edgesCount{ 0 };
public:
	Graph() {};
	void insertEdge(int x, int y) { insertEdge(x, y, 1, false); }
	void insertEdge(int x, int y, int weight) { insertEdge(x, y, weight, false); }
	void insertEdge(int x, int y, int weight, bool directed) {
		EdgeNode node (y, weight, &edges[x]);
		degree[x]++;
		verticesCount++;
		edgesCount++;
		edges[x] = node;
		if (directed) {
			insertEdge(y, x, weight, false);
		}
	}
	void print() {
		std::cout << std::endl << "TotalVertices:" << verticesCount << " Total Edges:" << edgesCount;
		for (int x = 0; x < MAX_VERTICES; x++) {
			
			std::cout << std::endl << x << "(degree=" << degree[x] << "):";
			EdgeNode* node = &edges[x];
			while (node!=nullptr) {
				node->print();
				node = node->getNext();
			}
		}
	}

};