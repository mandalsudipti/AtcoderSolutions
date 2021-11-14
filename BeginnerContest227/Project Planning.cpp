#include<bits/stdc++.h>
using namespace std ;

long long int count_group(vector<long long int>& arr , int k , long long int mid)
{
    long long int sum = 0 ;
    for(int i = 0 ; i < arr.size() ; i++)
        sum+=min(arr[i] , mid) ;
        
    if(sum >= mid * k)
    {
        //cout<<sum<<" "<<mid<<endl;
        return true ;
    }
    else
        return false ;
}

int main()
{
    int n , k ;
    cin>>n>>k ;
    
    vector<long long int>arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i] ;
        
    
    long long int low = 0 , high = 2e17 ;
    
    while(high - low > 1)
    {
        long long int mid = (low + high)/2 ;
        
        bool group_formed = count_group(arr , k , mid) ;
        
        if(group_formed)    
            low = mid ;
        else
            high = mid ;
    }
    
    cout<<low<<endl; 
    
    return 0 ;
}

