#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long long int  n ;
    cin>>n ;
    
    long long int root = sqrt(n) ;
    
    long long int sum = 0 ;
    
    for(int i = 1 ; i <= root ; i++)
        sum+=(n/i) ;
    
    sum = (2 * sum) - (root * root) ;
    
    cout<<sum<<endl;
    
    return 0 ;
}