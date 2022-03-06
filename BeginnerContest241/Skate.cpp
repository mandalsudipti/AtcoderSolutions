#include<bits/stdc++.h>
using namespace std ;

int BFS(int start_i , int start_j , int target_i , int target_j , map<int,set<int>>& obstacle)
{
    map<int,set<int>> obstacle_rotate ;
    
    for(pair<int,set<int>>P : obstacle)
    {
        for(int ele : P.second)
            obstacle_rotate[ele].insert(P.first) ;
    }
    
    set<pair<int,int>>visited ;
    queue<pair<int,int>> Q ;
    
    int distance = -1 ;
    Q.push(make_pair(start_i , start_j));
    visited.insert(make_pair(start_i , start_j));
    
    while(Q.size() > 0)
    {
        int s = Q.size() ;
        distance++ ;
        
        while(s--)
        {
            
            int x = Q.front().first , y = Q.front().second ;
            Q.pop() ;
            //cout<<x<<" "<<y<<endl;
        
            if(x == target_i && y == target_j)
                return distance ;
            
        
            //move horizontal go right
            auto itr = obstacle[x].lower_bound(y) ;
        
            if(obstacle[x].size() > 0 && itr != obstacle[x].end() && visited.find(make_pair(x , (*itr)-1)) == visited.end())
            {
                visited.insert(make_pair(x,(*itr)-1)) ;
                Q.push(make_pair(x,(*itr)-1));
            }
        
            //move horizontal go left
            if(obstacle[x].size() > 0 && itr != obstacle[x].begin())
            {
                (itr)-- ;
                if(visited.find(make_pair(x,(*itr)+1)) == visited.end())
                {
                    visited.insert(make_pair(x,(*itr)+1));
                    Q.push(make_pair(x,(*itr)+1)) ;
                }
            }
        
            //move vertical downward
            itr = obstacle_rotate[y].lower_bound(x) ;
        
            if(obstacle_rotate[y].size() > 0 && itr != obstacle_rotate[y].end() && visited.find(make_pair((*itr)-1,y)) == visited.end())
            {
                visited.insert(make_pair((*itr)-1,y)) ;
                Q.push(make_pair((*itr)-1,y)) ;
            }
        
            //move vertical upward
            if(obstacle_rotate[y].size() > 0 && itr != obstacle_rotate[y].begin())
            {
                (itr)-- ;
                if(visited.find(make_pair((*itr)+1,y)) == visited.end())
                {
                    visited.insert(make_pair((*itr)+1,y));
                    Q.push(make_pair((*itr)+1,y)) ;
                }
            }
        }
    }
    
    return -1 ;
}

int main()
{
    int row , col , n ;
    cin>>row>>col>>n ;
    
    int start_i , start_j , target_i , target_j ;
    cin>>start_i>>start_j>>target_i>>target_j ;
    
    map<int,set<int>>obstacle ;
    int x , y ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>x>>y ;
        obstacle[x-1].insert(y-1) ;
    }
    
    cout<<BFS(start_i - 1, start_j - 1, target_i - 1, target_j - 1, obstacle)<<endl;
    
    return 0 ;
}
