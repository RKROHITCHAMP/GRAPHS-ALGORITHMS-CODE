#include<bits/stdc++.h>
using namespace std;

class edge {
    public:
    int source, destination,weight;

};

bool compare(edge a, edge b) {
    return a.weight < b.weight;
}
int get_parent(int v,int *parent)
{
    if (parent[v]==v)
    {
        return v;
    }
    return get_parent(parent[v], parent);
    
}
edge* kruskals_algo(edge *edges,int n,int e)
{
    edge *output = new edge[n-1];
    int count = 0;
    sort(edges,edges+e,compare);
    int i = 0;
    int *parent = new int[n];
    for(int i = 0; i < n;i++) {
        parent[i] =i;
    }
    while (count<(n-1))
    {
        edge curr = edges[i];
        int srcparent = get_parent(curr.source,parent);
        int destparent = get_parent(curr.destination,parent);
        if (srcparent!=destparent)
        {
            output[count] = curr;
            parent[srcparent] = destparent;
            count++;
        }
        i++; 
        
    }
    
return output;

}


int main()
{
    int n,e;
    cin>>n>>e;
    edge* edges = new edge[e];
    for (int i = 0; i < e; i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].source = s; 
        edges[i].destination = d;
        edges[i].weight = w;
    }
     
    edge* output = kruskals_algo(edges,n,e);
    for (int i = 0; i < n-1; i++)
    {
        if (output[i].source<output[i].destination)
        {
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
        
        
    }
    

    
         
return 0;
}