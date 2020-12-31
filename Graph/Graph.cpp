// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "Graph.h"
#include "dfs.h"

int main()
{
    /*Graph graph;
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 5);
    graph.insertEdge(1, 6);
    graph.insertEdge(2, 5);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 4);    
    graph.insertEdge(4, 5);
    graph.dfs1(1);*/
    /* graph.print();
    graph.bfs(1, false);
    graph.find(1, 222);
   graph.find_path(3, 6);
   graph.connected_components();*/
    
    graph g;
   /* g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.printEdges();*/
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);
   
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);


   // g.addEdge(68, 37);


    /*

    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);*/
  
    /*g.countComponents();
    g.print();
    g.areConnected(37, 68);
    g.areConnected(68,37);
    g.areConnected(37, 4);
    g.areConnected(68, 0);
    g.areConnected(2, 3);*/
    g.isCyclical();

  //  g.dfs(0);
    /*g.findPath(0, 1, true);
    g.findPath(0, 2, true);
    g.findPath(0, 3, true);
    g.findPath(0, 4, true);
    g.findPath(0, 5, true);*/
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
