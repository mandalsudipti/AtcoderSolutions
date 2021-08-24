#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long long int n ;
    cin>>n ;
    
    long long int val = 1 ;
    for(int i = 0 ; i < 62 ; i++)
    {
        if(val * 2ll > n)
        {
            cout<<i ;
            break;
        }
        val = val * 2ll ;
    }
    
    return 0 ;
}


