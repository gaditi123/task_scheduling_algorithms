#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Data structure to store a graph edge
struct Edge {
    int src, dest, weight;
};
 
typedef pair<int, int> Pair;
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type vector<Edge>
        adjList.resize(n);
 
        // add edges to the directed graph
        for (auto &edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
 
            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
 
            // uncomment the following code for undirected graph
            // adjList[dest].push_back(make_pair(src, weight));
        }
    }
};
 
// Function to print adjacency list representation of a graph
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Function to print all neighboring vertices of a given vertex
        for (Pair v: graph.adjList[i]) {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        cout << endl;
    }
}
 
// Graph Implementation using STL
int main()
{
    // vector of graph edges as per the above diagram.
    // Please note that the initialization vector in the below format will
    // work fine in C++11, C++14, C++17 but will fail in C++98.
    // vector<Edge> edges =
    // {
    //     // (x, y, w) —> edge from `x` to `y` having weight `w`
    //     {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    // };
 
    // total number of nodes in the graph (labelled from 0 to 5)
    int n;
    cout<<"Enter the number of Tasks: ";
    cin>>n;
    int r;
    cout<<"Enter the number of Available Resources: ";
    cin>>r;
    vector<vector<int> > resource(r, std::vector<int>(r, 0));
    for(int x = 0; x < r; ++x){
        for(int y = 0; y < r; ++y){
            if(x<y){
                cout << "Enter the communication cost from resource " << x + 1  << " to resource "<< y+ 1 << ": ";
                cin >> resource[x][y];
            }
        }
   cout << "\n";
}
for(int x = 0; x < r; ++x){
        for(int y = 0; y < r; ++y){
            if(x>y){
                resource[x][y] = resource[y][x];
            }
        }
   cout << "\n";
}
for(int x = 0; x < r; ++x){
        for(int y = 0; y < r; ++y){
            cout << resource[x][y];
        }
   cout << "\n";
}
    vector<vector<int> > task(n, std::vector<int>(r, 0));
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < r; ++y){
        cout << "Enter the computation cost of task " << x + 1  << " on resource "<< y+ 1 << ": ";
        cin >> task[x][y];
        }
   cout << "\n";
}
    vector<Edge> edges;
// source is 0
// destination is 2nr+1
// for(int i=0; i<r; i++){
//     Edge s = {0, i, 1};
//     edges.insert(edges.begin(), s);
//     Edge d = {2*n*r+1, 2*n*r+1 - i, 1};
//     edges.insert(edges.begin(), d);
// }
int count =1;
for(int i=1; i<2*n+1; i++){
    for(int j=0; j<r; j++){
        Edge e = {count, count+1, task[i-1][j] };
        cout<< count << ' '<< count+1 << ' '<< task[i-1][j] << '\n';
        edges.insert(edges.begin(), e);
        Edge d = {count+1, count + 2*r - 1, resource[i-1][i]};
        edges.insert(edges.begin(), d);
        cout<< count+1 << ' '<< count + 2*r << ' '<< resource[i-1][j] << '\n';
        count=count +2;
    }
}
    // construct graph
    Graph graph(edges, 2);
 
    // print adjacency list representation of a graph
    printGraph(graph, 2);
 
    return 0;
}