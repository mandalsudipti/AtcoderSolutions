#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int>arr(10) ;
    
    for(int i = 0 ; i < 10 ; i++)
        cin>>arr[i] ;
        
    cout<<arr[arr[arr[0]]] ;
    
    return 0 ;
}