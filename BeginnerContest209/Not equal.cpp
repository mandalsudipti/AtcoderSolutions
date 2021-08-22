#include<bits/stdc++.h>
using namespace std ;

const long long int mod = 1e9 + 7 ;

int main()
{
    int n ;
    cin>>n;
    
    vector<long long int>arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
        
    sort(arr.begin() , arr.end());
    long long int total = 1 ;
    
    for(int i = 0 ; i < n ; i++)
    {
        total = (total * (arr[i] - i))%mod ;
    }
    
    cout<<total<<endl;
    
    return 0 ;
}