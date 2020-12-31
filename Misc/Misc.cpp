// Misc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "pointers.h"
void play(whatever&);
int main()
{   
    Graph graph;
    graph.insertEdge(1, 11);
    //graph.insertEdge(1, 111);
    graph.print();
    /*whatever arr[5];
    arr[1].val = 1;
    
    play(arr[1]);
    std::cout << std::endl << "afer function call";
    arr[1].print();*/
   
}
void play(whatever &w) {
    std::cout << "arr1 before" << std::endl;
    w.print();
    whatever temp = whatever(99, &w);
    std::cout << "temp" << std::endl;
    temp.print();
    w = temp;
    std::cout << "arr1 after" << std::endl;
    w.print();
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
