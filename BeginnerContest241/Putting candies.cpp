#include<bits/stdc++.h>
using namespace std ;

int get_pos(vector<int>& visiting_order , int idx)
{
   for(int i = 0 ; i < visiting_order.size() ; i++)
   {
        if(visiting_order[i] == idx)
            return i ;
   }
   
   return -1 ;
}


int main()
{
    long long int n , k;
    cin>>n>>k;
    
    vector<int>arr(n) , candy(n);
    vector<bool>visited(n,false) ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>candy[i];
        arr[i] = candy[i]%n ;
    }
    
    int loop_start = -1 , idx = 0 ;
    vector<int>visiting_order ;
    
    while(!visited[idx])
    {
        visiting_order.push_back(idx) ;
        visited[idx] = true ;
        idx = (idx + arr[idx]) % n ;
        
        if(visited[idx])
        {
            loop_start = get_pos(visiting_order , idx) ; // position of index in visiting_order
            break ;
        }
    }
    
    int len = visiting_order.size() ;
    vector<long long int>prefix_sum(len,0) ;
    
    for(int i = 0 ; i < visiting_order.size() ; i++)
        prefix_sum[i] = candy[visiting_order[i]] + (i > 0 ? prefix_sum[i-1] : 0) ;
    
    k-- ;
    if(k <= len)
        cout<<prefix_sum[k]<<endl;
    else
    {
        long long int ans = prefix_sum[len-1] ;
        k-=(len-1) ;
        
        ans+=( prefix_sum[len-1] - (loop_start > 0 ? prefix_sum[loop_start - 1] : 0) )*(k/(len - loop_start)) ;
        
        k = k % (len - loop_start) ;
        
        if(k > 0)
            ans+=(prefix_sum[loop_start + k - 1] - (loop_start > 0 ? prefix_sum[loop_start - 1] : 0)) ;
            
        cout<<ans<<endl;
    }
    
    return 0 ;
}
