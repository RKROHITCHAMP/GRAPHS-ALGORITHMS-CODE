#include<bits/stdc++.h>
using namespace std;

int getminvertex(bool *visited,int *weight,int n)
{
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ((minvertex==-1) || weight[minvertex]>weight[i]))
        {
            minvertex = i;
        }
        
    }
    
    return minvertex;
}

void prims(int **edges, int n)
{
    int *parent = new int[n];
    bool *visited = new bool[n]();
    int *weight = new int[n];
    for (int i = 0; i < n; i++)
    {
           weight[i] = INT_MAX;
    }
    
  
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        int minvertex = getminvertex(visited, weight,n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++)
        {
            if(edges[minvertex][j]!=0 && !visited[j])
            {
                if (weight[j] > edges[minvertex][j])
                {
                    weight[j] = edges[minvertex][j];
                    parent[j] = minvertex;
                }
                
            }
        }
        
    }
    
    for (int i = 1; i < n; i++)
    {
        if (parent[i]<i)
        {
            cout <<parent[i] <<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout <<i <<" "<<parent[i] <<" "<<weight[i]<<endl;
            
        }
        
        
    }
    delete [] parent;
    delete [] weight;
    delete [] visited;

}

int main()
{
int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
   for (int i = 0; i < n; i++)
   {
       edges[i] = new int[n];
       for (int j = 0; j < n;j++)
       {
           edges[i][j] = 0;
       }
       
   }

   for (int i = 0; i < e; i++)
   {
       int f,s,weight;
       cin>>f>>s>>weight;
       edges[f][s] = weight;
       edges[s][f] = weight;
   }
   cout<<endl;
   prims(edges, n);
   
     
    // for (int i = 0; i < n-1; i++)
    // {
    //     if (output[i].source<output[i].destination)
    //     {
    //         cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    //     }
    //     else
    //     {
    //         cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    //     }
        
        
    // }

    for (int i = 0; i < n; i++)
    {
        delete []  edges[i];
    }
    delete [] edges;

    
return 0;
}