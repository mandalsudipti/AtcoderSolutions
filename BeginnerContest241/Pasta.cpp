#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , m ;
    cin>>n>>m ;
    
    map<int,int>pasta_len ;
    int len ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>len ;
        pasta_len[len]++ ;
    }
    
    bool possible = true ;
    
    for(int i = 0 ; i < m ; i++)
    {
        cin>>len ;
        if(pasta_len.find(len) == pasta_len.end() || pasta_len[len] == 0)
        {
            possible = false ;
        }
        else
            pasta_len[len]-- ;
    }
    
    if(possible)
        cout<<"Yes\n" ;
    else
        cout<<"No\n" ;
        
    return 0 ;
}