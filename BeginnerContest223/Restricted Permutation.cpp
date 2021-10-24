#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int nodes , edges ;
    cin>>nodes>>edges ;
    
    vector<int>indegree(nodes+1 , 0) ;
    vector<vector<int>>adj_list(nodes+1) ;
    
    int u , v ;
    for(int i = 0 ; i < edges ; i++)
    {
        cin>>u>>v ;
        adj_list[u].push_back(v) ;
        indegree[v]++ ;
    }
    
    vector<int>permutation ;
    set<int>s ;
    
    for(int i = 1 ; i <= nodes ; i++)
    {
        if(indegree[i] == 0)
            s.insert(i) ;
    }
    
    while(!s.empty())
    {
        int cur_node = (*s.begin()) ;
        s.erase(s.begin()) ;
        
        permutation.push_back(cur_node) ;
        for(int  child : adj_list[cur_node])
        {
            indegree[child]-- ;
            if(indegree[child] == 0)
                s.insert(child) ;
        }
    }
    
    if(permutation.size() != nodes)
            cout<<"-1"<<endl;
    else
    {
        for(int i = 0 ; i < permutation.size() ; i++)
            cout<<permutation[i]<<" ";
        cout<<endl;
    }
    
    return 0 ;
}