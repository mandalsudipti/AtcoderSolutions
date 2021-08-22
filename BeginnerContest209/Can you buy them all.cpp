#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , x , total = 0 ;
    cin>>n>>x ;
    
    int cost ;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>cost ;
        if(i%2 == 0)
            total+=cost ;
        else
            total+=(cost-1);
    }
    
    if(total <= x)
        cout<<"Yes\n" ;
    else
        cout<<"No\n" ;
        
    return 0 ;
}