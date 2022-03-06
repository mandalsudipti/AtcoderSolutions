#include<bits/stdc++.h>
using namespace std ;

bool check_horiontal(vector<string>& grid)
{
    int n = grid.size() ;
    
    int black = 0 ;
    
    for(int i = 0 ; i < n ; i++)
    {
        black = 0 ;
        for(int j = 0 ; j < n ; j++)
        {
            if(grid[i][j] == '#')
                black++ ;
            if(j - 6 >= 0 && grid[i][j-6] == '#')
                black-- ;
                
            if(black >= 4)
                return true ;
        }
    }
    
    return false ;
}

bool check_vertical(vector<string>& grid)
{
    int black = 0 , n = grid.size();
    
    for(int j = 0 ; j < n ; j++)
    {
        black = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(grid[i][j] == '#')
                black++ ;
                
            if(i-6 >= 0 && grid[i-6][j] == '#')
                black-- ;
                
            if(black >= 4)
                return true ;
        }
    }
    
    return false ;
}

bool check_diagonal(vector<string>& grid)
{
    int black = 0 , n = grid.size() ;
    
    map< int,vector<pair<int,int>> >diagonal ;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            diagonal[i-j].push_back(make_pair(i,j)) ;
    }
    
    for(pair<int,vector<pair<int,int>>> P : diagonal)
    {
        vector<pair<int,int>>arr = P.second ;
        
        if(arr.size() < 6)
            continue ;
            
        black = 0 ;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(grid[arr[i].first][arr[i].second] == '#')
                black++ ;
                
            if(arr[i].first - 6 >= 0 && arr[i].second - 6 >= 0 && grid[arr[i].first - 6][arr[i].second - 6] == '#')
                black-- ;
                
            if(black >= 4)
                return true ;
        }
    }
    
    return false ;
}

bool check_antidiagonal(vector<string>& grid)
{
    int n = grid.size() ;
    
    map<int , vector<pair<int,int>>> anti_diagonal ;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            anti_diagonal[i+j].push_back(make_pair(i,j)) ;
        }
    }
    
    for(pair<int,vector<pair<int,int>> > P : anti_diagonal)
    {
        vector<pair<int,int>>arr = P.second ;
        
        if(arr.size() < 6)
            continue ;
            
        int black = 0 ;  
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            int u = arr[i].first , v = arr[i].second ;
            
            if(grid[u][v] == '#')
                black++ ;
                
            if(u-6 >= 0 && v + 6 < n && grid[u-6][v+6] == '#')
                black-- ;
                
            if(black >= 4)
                return true ;
        }
    }
    
    return false ;
}

int main()
{
    int n ;
    cin>>n;
    
    vector<string>grid(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>grid[i] ;
        
    bool possible = check_horiontal(grid) ;
    
    if(!possible)
        possible = check_vertical(grid) ;
        
    if(!possible)
        possible = check_diagonal(grid) ;
        
    if(!possible)
        possible = check_antidiagonal(grid) ;
        
    if(possible)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        
    return 0 ;
    
}