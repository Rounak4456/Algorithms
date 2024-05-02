#include <bits/stdc++.h>
using namespace std;

#define V 4

int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;

    do
    {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }

        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}
int main()
{
    cout << "There are 4 vertices\n";
    int graph[V][V];

    cout << "Enter the adjacency matric:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    
    int s = 0;
    cout << "Mininum Cost: " << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}