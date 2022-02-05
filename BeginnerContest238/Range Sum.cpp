#include<bits/stdc++.h>
using namespace std ;

bool BFS(vector<vector<int>>& adj_list , int node)
{
    vector<bool>visited(node , false) ;
    node-- ;
    
    queue<int>Q ;
    Q.push(0) ;
    visited[0] = true ;
    
    while(Q.size() > 0)
    {
        int cur_node = Q.front() ;
        Q.pop() ;
        
        if(cur_node == node)
            return true ;
            
        for(int child : adj_list[cur_node])
        {
            if(!visited[child])
            {
                visited[child] = true ;
                Q.push(child) ;
            }
        }
    }
    
    return false ;
}

int main()
{
    long long int node , query ;
    cin>>node>>query ;
    
    node++ ;
    
    vector<vector<int>>adj_list(node) ;
    
    while(query--)
    {
        int left , right ;
        cin>>left>>right ;
        
        left-- ;
        adj_list[left].push_back(right) ;
        adj_list[right].push_back(left) ;
    }
    
    bool possible = BFS(adj_list , node) ;
    
    if(possible)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
    return 0 ;
}