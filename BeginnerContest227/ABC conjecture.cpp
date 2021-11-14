#include<bits/stdc++.h>
using namespace std ;


int main()
{
    long long int  n , count = 0;
    cin>>n ;
    
    for(long long int A = 1 ; A*A*A <= n ; A++)
    {
        for(long long int B = A ; A*B*B <= n ; B++)
            count+=((n/A/B) - B + 1) ; 
    }
    
    cout<<count<<endl;
    
    return 0 ;
}