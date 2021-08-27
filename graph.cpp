#include <bits/stdc++.h>
using namespace std;

void print_dfs(int **edges, int n, int sv, bool *visited) //dfs-depth first because we go in depth first
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i])
        {
            if (visited[i])
            {
                continue;
            }
            print_dfs(edges, n, i, visited);
        }
    }
}

void print_bfs(int **edges, int n, int sv, bool *visited) //bfs-breadth first because we go in breadth first
{

    queue<int> bfs;
    bfs.push(sv);
    visited[sv] = true;

    while (!bfs.empty())
    {
        int index = bfs.front();
        cout << index << " ";
        for (int i = 0; i < n; i++)
        {
            if (edges[index][i])
            {
                if (visited[i])
                {
                    continue;
                }

                bfs.push(i);
                visited[i] = true;
            }
        }

        bfs.pop();
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n]; //to keeep a track of what elements are already visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_dfs(edges, n, i, visited);
        }
    }
    cout << endl;

    delete[] visited;
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n]; //to keeep a track of what elements are already visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_bfs(edges, n, i, visited);
        }
    }
    cout << endl;
    delete[] visited;
}

bool haspath(int **edges, int n, int sv, int ed, bool *visited)
{
    bool flag = false;
    if (edges[sv][ed] == 1)
    {
        flag = true;
    }
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i])
        {
            if (!visited[i])
            {
                flag = haspath(edges, n, i, ed, visited);
                visited[i] = true;
            }
        }
    }

    return flag;
}
bool haspath(int **edges, int n, int sv, int ed)
{
    bool *visited = new bool[n]; //to keeep a track of what elements are already visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return haspath(edges, n, sv, ed, visited);
    delete[] visited;
}
vector<int> getpathdfs(int **edges, int n, int start, int end, bool *visited)
{
    vector<int> path;
    if (start == end)
    {
        path.push_back(end);
        return path;
    }
    for (int i = 0; i < n; i++)
    {
        if (edges[start][i] == 1)
        {
            if (!visited[i])
            {
                path = getpathdfs(edges, n, i, end, visited);
                visited[i] = true;
                if (path.size() != 0)
                {
                    path.push_back(i);
                }
            }
        }
    }

    return path;
}
vector<int> getpathdfs(int **edges, int n, int start, int end)
{
    bool *visited = new bool[n]; //to keeep a track of what elements are already visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return getpathdfs(edges, n, start, end, visited);
    delete[] visited;
}

bool isconnecteddfs(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i])
        {
            if (visited[i])
            {
                continue;
            }
            isconnecteddfs(edges, n, i, visited);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

bool isconnected(int **edges, int n)
{
    bool *visited = new bool[n]; //to keeep a track of what elements are already visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return isconnecteddfs(edges, n, 0, visited);
}


vector<int> componentdfs(int **edges, int n,int sv,bool * visited,vector<int> comp)
{
    comp.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i])
        {
            if (visited[i])
            {
                continue;
            }
            componentdfs(edges, n, i, visited,comp);
        }
    }
    return comp;
}
vector<vector<int>> components(int **edges, int n)
{
    bool *visited = new bool[n]; //to keeep a track of what elements are already visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<vector<int>> components;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vector<int> comp;
            components.push_back(componentdfs(edges,n,i,visited,comp));
        }
    }
    return components;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "DFS IS : ";
    DFS(edges, n);
    cout << "BFS IS : ";
    BFS(edges, n);
    cout << "IS THE GRAPH CONNECTED : " << isconnected(edges, n) << endl;
    vector<vector<int>> comp = components(edges, n);
    for (int i = 0; i < comp.size(); i++)
    {
        for(int j = 0; j < comp[i].size(); j++)
        {
            cout << comp[i][j] << " ";
        }
        cout << endl;
    }
    
    // int start, end;
    // cin >> start >> end;
    // cout << "IS THERE ANY PATH BETWEEN " << start << "->" << end << " : " << haspath(edges, n, start, end) << endl;

    // vector<int> path = getpathdfs(edges, n, start, end);
    // for (int i = 0; i < n; i++)
    //     cout << path[i] << " ";
    // cout << endl;

    for (int i = 0; i < n; i++)
        delete[] edges[i];

    delete[] edges;
    return 0;
}