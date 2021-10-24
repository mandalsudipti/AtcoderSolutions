#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    
    vector<long double>distance(n) , velocity(n) ;
    
    for(int i = 0 ; i < n ; i++)
        cin>>distance[i]>>velocity[i] ;
        
    long double total_time = 0 ;
    for(int i = 0 ; i < n ; i++)
        total_time+=(distance[i] / velocity[i]) ;
        
    total_time = total_time / 2ll ;
    
    long double ans = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        long double cur_time = distance[i] / velocity[i] ;
        
        if(cur_time <= total_time)
        {
            ans+=distance[i] ;
            total_time-=cur_time;
        }
        else
        {
            ans+=(total_time * velocity[i]) ;
            break;
        }
    }
    
    cout<<fixed<<setprecision(16)<<ans<<endl;
    
    return 0 ;
}