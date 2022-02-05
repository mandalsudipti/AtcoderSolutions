#include<bits/stdc++.h>
using namespace std ;

const long long int mod = 998244353 ;

int main()
{
    long long int n ;
    cin>>n ;
    
    long long int ans = 0 ;
    
    long long int left = 1 , right = 9 ;
    
    while(right <= n)
    {
        long long int num = (right - left + 1) ;
        
        long long int add = 0 ;
        
        if(num % 2 == 1)
        {
            add = (num%mod) * ( ( (num + 1)/2)%mod) ;
        }
        else
        {
            add = ((num + 1)%mod) * ((num / 2)%mod) ;
        }
        
        //cout<<left<<" "<<right<<" "<<num<<" "<<add<<endl ;
        
        ans = (ans + (add % mod))%mod ;
        
        if(right < n)
        {
            left = right + 1 ;
        
            right = (left * 10) - 1 ;
        }
        else
            break ;
    }
    
    if(left <= n && right > n)
    {
        long long int num = (n - left + 1) ;
        
        long long int add = 0 ;
        
        if(num % 2 == 1)
        {
            add = (num % mod) * ( ((num + 1)/2)%mod) ;
        }
        else
        {
            add = ( (num + 1)%mod) * ( (num / 2)%mod) ;
        }
        
        //cout<<add<<endl;
        
        ans = (ans + (add % mod))%mod ;
    }
    
    cout<<ans<<endl;
    
    return 0 ;
}