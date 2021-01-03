// BGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bfs.h"
#include "dfs.h"

int main()
{
    dfs g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.addEdge( 7,9);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(9, 10);
    g.print();
    g.traverse(1);


 /*   g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(1, 8);
    g.addEdge(2, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);*/
   // g.print();
    //g.traverse(1);
  //  g.hasCycle();
   // g.traverse(1);
    return 1;

    //s=0, a=1, x=2, z=3, c=4, d=5, f=6, v=7
    /*g.addEdge(0, 1); //s,a
    g.addEdge(0, 2);//s,x
    g.addEdge(1, 3);//a,z
    g.addEdge(2, 4);//x,c
    g.addEdge(2, 5);//x,d
    g.addEdge(4, 5);//c,d
    g.addEdge(4, 6);//c,f
    g.addEdge(4, 7);//c,v
    g.addEdge(5, 6);//d,f
    g.addEdge(6, 7);//f,v*/


    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(63, 65);*/
    g.print();
//    g.printEdges();
    g.traverse(0);
  /*  g.countComponents();
    g.isConnected(0, 1);
    g.findPath(0, 1);
    g.isConnected(0, 65);
    g.findPath(0, 65);
    g.isConnected(1, 4);
    g.findPath(1, 4);
    g.isConnected(65, 63);
    g.findPath(65, 63);
    g.isConnected(78, 53);
    g.findPath(78, 53);
    g.isConnected(2, 5);
    g.findPath(2, 5);
    g.isBipartite();*/
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
