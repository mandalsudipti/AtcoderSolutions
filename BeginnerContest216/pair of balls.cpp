#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n , m ;
    cin>>n>>m;
    
    vector<vector<int>>cylinder(m) ;
    vector<int>idx(m) ;
    set<int>open ;
    for(int i = 0 ; i < m ; i++)
    {
        int k , color;
        cin>>k ;
        for(int j = 0 ; j < k ; j++)
        {
            cin>>color ;
            cylinder[i].push_back(color) ;
        }
        idx[i] = k-1;
        open.insert(i) ;
    }
    
    map<int , pair<int,int> >ball_pos ; // color - position
    
    while(open.size() > 0)
    {
        int row = (*open.begin()) ;
        int color = cylinder[row][idx[row]] ;
        
        if(ball_pos.find(color) != ball_pos.end())
        {
            idx[row]-- ;
            if(idx[row] < 0)
                open.erase(open.begin());
                
            idx[ball_pos[color].first]-- ;
            if(idx[ball_pos[color].first] >= 0)
                open.insert(ball_pos[color].first) ;
                
            ball_pos.erase(ball_pos.find(color)) ;
            
        }
        else
        {
            ball_pos[color] = make_pair(row , idx[row]) ;
            open.erase(open.begin()) ;
        }
    }
    
    bool flag = true ;
    for(int i = 0 ; i < m ; i++)
    {
        if(idx[i] >= 0)
        {
            flag = false ;
            break;
        }
    }
    
    if(flag)
        cout<<"Yes";
    else
        cout<<"No" ;
        
    return 0 ;
}