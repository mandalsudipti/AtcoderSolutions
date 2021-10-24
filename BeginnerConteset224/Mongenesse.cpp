#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int row , col ;
    cin>>row>>col ;
    
    vector<vector<long long int>>grid(row , vector<long long int>(col)) ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
            cin>>grid[i][j] ;
    }
    
    bool flag = true ;
    for(int i1 = 0 ; i1 < row ; i1++)
    {
        if(!flag)
            break ;
        for(int i2 = i1 + 1 ; i2 < row ; i2++)
        {
            if(!flag)
                break ;
            for(int j1 = 0 ; j1 < col ; j1++)
            {
                if(!flag)
                    break ;
                for(int j2 = j1 + 1 ; j2 < col ; j2++)
                {
                    if(grid[i1][j1] + grid[i2][j2] > grid[i1][j2] + grid[i2][j1])
                    {
                        flag = false ;
                        break;
                    }
                }
            }
        }
    }
    
    if(flag)
        cout<<"YES\n" ;
    else
        cout<<"NO\n" ;
        
    return 0 ;
}
