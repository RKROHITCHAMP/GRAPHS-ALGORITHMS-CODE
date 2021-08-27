#include <iostream>
#include <vector>
using namespace std;

void dfs(bool *visited, vector<int> *edges, int start, vector<int> *components)
{
    components->push_back(start);
    visited[start] = true;
    for (int i = 0; i < edges[start].size(); i++)
    {
        int next = edges[start][i];
        if (!visited[next])
        {
            dfs(visited, edges, next, components);
        }
    }
}

vector<vector<int> *> *getComponents(vector<int> *edges, int n)
{
    vector<vector<int> *> *output = new vector<vector<int> *>();
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> *components = new vector<int>();
            dfs(visited, edges, i, components);
            output->push_back(components);
        }
    }
    delete[] visited;
    return output;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> *edges = new vector<int>[n];
    for (int i = 0; i < m; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f-1].push_back(s-1);
        edges[s-1].push_back(f-1);
    }

    vector<vector<int> *> *components = getComponents(edges, n);
    vector<vector<int> *>  ::iterator it1 = components->begin();
    while (it1!=components->end()) 
    {
        vector<int>* component = *it1;
        vector<int> :: iterator it2 = component->begin();
        while (it2!=component->end()) 
        {
            cout<<*it2+1<<" ";
            it2++;
        }
        cout<<endl;
        it1++; 
        delete component;
        
    }
    delete components;
    delete [] edges;

    return 0;
}