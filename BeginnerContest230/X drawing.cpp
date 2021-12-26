#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int N , A , B ;
    cin>>N>>A>>B ;
    
    long long int P , Q , R , S  ;
    
    cin>>P>>Q>>R>>S ;
    
    int row = Q - P + 1 , col = S - R + 1 ;
    vector<vector<char>>grid(row , vector<char>(col, '.')) ;
    
    long long int start = max(P - A , R - B) , end = min(Q - A , S - B) ;
    
    for(long long int k = start ; k <= end ; k++)
    {
        long long int x = A + k , y = B + k ;
        
        if(x - P >= 0 && x - P < row && y - R >= 0 && y - R < col)
            grid[x - P][y - R] = '#' ;
    }
    
    start = max(P - A , B - S) ;
    end = min(Q - A , B - R) ;
    
    for(long long int k = start ; k <= end ; k++)
    {
        long long int x = A + k , y = B - k ;
        
        if(x - P >= 0 && x - P < row && y - R >= 0 && y - R < col)
            grid[x - P][y - R] = '#' ;
    }
    
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
            cout<<grid[i][j] ;
        cout<<endl;
    }
    
    return 0 ;
}