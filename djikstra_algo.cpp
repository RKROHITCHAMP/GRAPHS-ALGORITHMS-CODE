#include <bits/stdc++.h>
using namespace std;
 
int getminvertex(bool *visited, int *distance, int n)
{
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((minvertex == -1) || distance[minvertex] > distance[i]))
        {
            minvertex = i;
        }
    }
 
    return minvertex;
}
 
void djikstra(int **edges, int n, int src)
{
    bool *visited = new bool[n]();
    int *distance = new int[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }
 
    distance[src] = 0;
 
    for (int i = 0; i < n - 1; i++)
    {
        int minvertex = getminvertex(visited, distance, n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minvertex][j] != 0 && !visited[j])
            {
              if (distance[j] > edges[minvertex][j] + distance[minvertex])
                {
                  distance[j] = distance[minvertex] + edges[minvertex][j];
                }
            }
        }
    }
 
 cout << "VERTEX \t SHORTEST DISTANCE FROM SOURCE(" << src << ")" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " \t\t " << distance[i] << endl;
    }
 
    delete[] visited;
    delete[] distance;
}
 
int main()
{
    int n, e;
    cout << "ENTER THE NUMBER OF VERTICES : ";
    cin >> n;
    cout << "ENTER THE NUMBER OF EDGES : ";
    cin >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
 
 cout<<"ENTER THE EDGES IN THE FORM <VERTEX1> <VERTEX2> <WEIGHT>" << endl;
    cout << "V1->V2 WEIGHT" << endl;
    for (int i = 0; i < e; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    int src;
    cout << "ENTER THE SOURCE VERTEX : ";
    cin >> src;
    cout << endl;
    djikstra(edges, n, src);
 
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
 
    return 0;
}
