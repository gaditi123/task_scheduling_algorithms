#include <bits/stdc++.h>
#define infi 1000000000
using namespace std;
 
// Class of the node
class Node {
public:
    int vertexNumber;
 
    // Adjacency list that shows the
    // vertexNumber of child vertex
    // and the weight of the edge
    vector<pair<int, int> > children;
    Node(int vertexNumber)
    {
        this->vertexNumber = vertexNumber;
    }
 
    // Function to add the child for
    // the given node
    void add_child(int vNumber, int length)
    {
        pair<int, int> p;
        p.first = vNumber;
        p.second = length;
        children.push_back(p);
    }
};
 
// Function to find the distance of
// the node from the given source
// vertex to the destination vertex
vector<int> dijkstraDist(
    vector<Node*> g,
    int s, vector<int>& path)
{
    // Stores distance of each
    // vertex from source vertex
    vector<int> dist(g.size());
 
    // Boolean array that shows
    // whether the vertex 'i'
    // is visited or not
    bool visited[g.size()];
    for (int i = 0; i < g.size(); i++) {
        visited[i] = false;
        path[i] = -1;
        dist[i] = infi;
    }
    dist[s] = 0;
    path[s] = -1;
    int current = s;
 
    // Set of vertices that has
    // a parent (one or more)
    // marked as visited
    unordered_set<int> sett;
    while (true) {
 
        // Mark current as visited
        visited[current] = true;
        for (int i = 0;
             i < g[current]->children.size();
             i++) {
            int v = g[current]->children[i].first;
            if (visited[v])
                continue;
 
            // Inserting into the
            // visited vertex
            sett.insert(v);
            int alt
                = dist[current]
                  + g[current]->children[i].second;
 
            // Condition to check the distance
            // is correct and update it
            // if it is minimum from the previous
            // computed distance
            if (alt < dist[v]) {
                dist[v] = alt;
                path[v] = current;
            }
        }
        sett.erase(current);
        if (sett.empty())
            break;
 
        // The new current
        int minDist = infi;
        int index = 0;
 
        // Loop to update the distance
        // of the vertices of the graph
        for (int a: sett) {
            if (dist[a] < minDist) {
                minDist = dist[a];
                index = a;
            }
        }
        current = index;
    }
    return dist;
}
 
// Function to print the path
// from the source vertex to
// the destination vertex
void printPath(vector<int> path,
               int i, int s)
{
    if (i != s) {
 
        // Condition to check if
        // there is no path between
        // the vertices
        if (path[i] == -1) {
            cout << "Path not found!!";
            return;
        }
        printPath(path, path[i], s);
        cout << path[i] << " ";
    }
}
 
// Driver Code
int main()
{
    vector<Node*> v;
    int tasks=3, resources=3;
    int n = 2*tasks*resources + 2, s = 0, e = 33;
 
    // Loop to create the nodes
    for (int i = 0; i < n; i++) {
        Node* a = new Node(i);
        v.push_back(a);
    }
 
    // Creating directed
    // weighted edges
    v[0]->add_child(1, 0);
    v[0]->add_child(3, 0);
    v[0]->add_child(5, 0);
    v[1]->add_child(2, 1);
    v[2]->add_child(7, 0);
    v[2]->add_child(9, 2);
    v[2]->add_child(11, 4);
    v[3]->add_child(4, 2);
    v[4]->add_child(7, 2);
    v[4]->add_child(9, 0);
    v[4]->add_child(11, 3);
    v[5]->add_child(6, 3);
    v[6]->add_child(7, 4);
    v[6]->add_child(9, 3);
    v[6]->add_child(11, 0);
    v[7]->add_child(8, 4);
    v[8]->add_child(13, 0);
    v[8]->add_child(15, 2);
    v[8]->add_child(17, 4);
    v[9]->add_child(10, 5);
    v[10]->add_child(13, 2);
    v[10]->add_child(15, 0);
    v[10]->add_child(17, 3);
    v[11]->add_child(12, 6);
    v[12]->add_child(13, 4);
    v[12]->add_child(15, 3);
    v[12]->add_child(17, 0);
    v[13]->add_child(14, 7);
    v[14]->add_child(19, 0);
    v[15]->add_child(16, 8);
    v[16]->add_child(19, 0);
    v[17]->add_child(18, 9);
    v[18]->add_child(19, 0);
    vector<int> path(v.size());
    vector<int> dist
        = dijkstraDist(v, s, path);
 
    // Loop to print the distance of
    // every node from source vertex
    if (dist[19] == infi) {
        cout << 19 << " and " << s
                << " are not connected"
                << endl;
        }
    else{
    cout << "Distance of the destination vertex from source vertex is: "<< dist[19] << endl;
    }
    return 0;
}
