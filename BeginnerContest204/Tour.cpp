#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int node , edge ;
    cin>>node>>edge ;
    
    vector<vector<int>>adj_list(node+1) ;
    int u , v ;
    
    for(int i = 0 ; i < edge ; i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v) ;
    }
    
    vector<vector<bool>>paired_node(node+1 , vector<bool>(node + 1 , false)) ;
    for(int start = 1 ; start <= node ; start++)
    {
        vector<bool>visited(node+1,false) ;
        queue<int>Q ;
        Q.push(start) ;
        visited[start] = true ;
    
        while(!Q.empty())
        {
            int cur_node = Q.front() ;
            paired_node[start][cur_node] = true ;
            Q.pop() ;
            
            for(int child : adj_list[cur_node])
            {
                if(!visited[child])
                {
                    visited[child] = true ;
                    Q.push(child) ;
                }
            }
        }
    }
    
    int count = 0 ;
    for(int i = 1 ; i <= node ; i++)
    {
        for(int j = 1 ; j <= node ; j++)
        {
            if(paired_node[i][j])
                count++;
        }
    }
    
    cout<<count<<endl;
    
    return 0 ;
}