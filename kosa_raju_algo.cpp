#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int start, unordered_set<int> &visited, stack<int> &finished)
{
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs(edges, adjacent, visited, finished);
        }
    }
    finished.push(start);
}
void dfs2(vector<int> *edges, int start, unordered_set<int> *component, unordered_set<int> &visited)
{
    visited.insert(start);
    component->insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs2(edges, adjacent, component, visited);
        }
    }
}

unordered_set<unordered_set<int> *> *getscc(vector<int> *edges, vector<int> *edgesT, int n)
{
    unordered_set<int> visited;
    stack<int> finishvertex;
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs(edges, i, visited, finishvertex);
        }
    }
    visited.clear();
    unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
    while (finishvertex.size() != 0)
    {
        int element = finishvertex.top();
        finishvertex.pop();
        if (visited.count(element) != 0)
        {
            continue;
        }
        unordered_set<int> *component = new unordered_set<int>();
        dfs2(edgesT, element, component, visited);
        output->insert(component);
    }
    return output;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> *edges = new vector<int>[n];
    vector<int> *edgesT = new vector<int>[n];
    for (int i = 0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;
        edges[j - 1].push_back(k - 1);
        edgesT[k - 1].push_back(j - 1);
    }
    unordered_set<unordered_set<int> *> *components = getscc(edges, edgesT, n);
    unordered_set<unordered_set<int> *>::iterator it1 = components->begin();
    while (it1 != components->end())
    {
        unordered_set<int> *component = *it1;
        unordered_set<int>::iterator it2 = component->begin();
        while (it2 != component->end())
        {
            cout << *it2 + 1 << " ";
            it2++;
        }
        it1++;
        cout << endl;
    }

    delete components;
    delete[] edges;
    delete[] edgesT;

    return 0;
}