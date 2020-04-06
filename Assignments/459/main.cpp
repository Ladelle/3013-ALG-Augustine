///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Ladelle Augustine
// Email:            ladelle2016@gmail.com
// Label:            10-PO4
// Title:            Graph Connectivity 
// Course:           3013-Algorithm
// Semester:         Spring 2020
//
// Description:
//       This program is based on Graph connectivity. We are dealing with graphs that
//       are connected and not connected. A graph that is not connected can still be 
//       connected through the subgraph which is maximal. Knowing this we now can decipher
//       if there are no nodes and edges in the original graph that can be added to subgraph 
//       and it still leaves it connected, which is maximal.
// Usage:
//       This program determined the number of maximal connected subgraph of
//        given graph.
//
// Files:            input.txt
//                   input2.txt
// Accepted 04/05/2020 1:21am
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n";

using namespace std;

/* CONSTANT VARIABLES: visited and unvisited */
const int VISITED = 1;
const int UNVISITED = -1;

/* Vectors to hold the values               */
typedef vector<int> vi; // vectors of integers
typedef vector<vi> vii; // vectors of vi 

vi been_visited;            // container to keep track of who get visited


/**
 * Depth First Search
 *
 * Params:
 *  int u - starting node id
 *  vii &Graph - reference of Graph
 *
 */

void dfs(int u, vii& Graph) {
    // In DFS we use a stack structure to keep track of who to visit next.
    // Recursive acts just like a stack so we dont need to declare any 
    // structure to keep track for us, we let the recursive calls do it for us

    been_visited[u] = VISITED;  // mark u as visited

    // Loop overadjacency list looking for connections
    for (int j = 0; j < (int)Graph[u].size(); j++) {

        int v = Graph[u][j];

        // check to see if our neighbor was visited
        if (been_visited[v] == UNVISITED) {
            dfs(v, Graph);
        }
    }
}


int main(int argc, char** argv)
{
    int cases;
    cin >> cases;
    // counting connections
    int cC = 0;
    while (cases--)
    {
        //largest node name in the graph
        char largN;
        int nodes;

        cin >> largN;

        //math behind it- nodes(5)= "E"(69) - 'A'(65)+ 1
        nodes = largN - 'A' + 1;

        // Clears input buffer 
        cin.ignore();

        // vector of size 5
        vii Graph(nodes);

        // resizes the vector object 
        been_visited.resize(nodes + 1, UNVISITED);

        string listnode;
        while (getline(cin, listnode) && listnode != "")
        {
            // can use 'A'(65)
            Graph[listnode[0] - 'A'].push_back(listnode[1] - 'A');
            Graph[listnode[1] - 'A'].push_back(listnode[0] - 'A');
        }

        for (int i = 0; i < nodes; i++)
        {
            if (been_visited[i] == UNVISITED)
            {
                dfs(i, Graph);
                ++cC;
            }

        }
        for (int i = 0; i < nodes; i++)
        {
            if (been_visited[i] == UNVISITED)
            {
                dfs(i, Graph);
                ++cC;
            }

        }
        // printing out connected componenets
       cout << cC << "\n";
        if (cases)
            cout<< "\n";
        cC = 0;

        // reset values in been_visited vector
        fill(been_visited.begin(), been_visited.end(), UNVISITED);


    }
    return 0;
}