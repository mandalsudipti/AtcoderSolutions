#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    
    vector<long long int>S(n) , T(n) ;
    int min_start = 0 ;
    for(int i = 0 ; i < n ; i++)
        cin>>S[i] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>T[i];
        if(T[i] < T[min_start])
            min_start = i ;
    }
    
    priority_queue<pair<long long int,int> , vector<pair<long long int,int>> , greater<pair<long long int,int>> >Q ; // min time , index
    vector<long long int>ans(n , -1);
    
    for(int i = 0 ; i < n ; i++)
    {
        if(T[i] == T[min_start])
            Q.push(make_pair(T[i] , i)) ;
    }
    
    while(!Q.empty())
    {
        long long int cur_time = Q.top().first ;
        int idx = Q.top().second ;
        Q.pop() ;
        if(ans[(idx+1)%n] == -1)
        {
            ans[(idx+1)%n] = min(cur_time + S[idx] , T[(idx+1)%n]) ;
            Q.push( make_pair(ans[(idx+1)%n] , (idx+1)%n) ) ;
        }
    }
    
    for(int i = 0 ; i < n ; i++)
        cout<<ans[i]<<endl;
        
    return 0 ;
}