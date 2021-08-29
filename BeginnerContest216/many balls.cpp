#include<bits/stdc++.h>
using namespace std ;


int main()
{
    long long int n ;
    cin>>n; 
    
    string move = "" ;
    
    while(n >= 1)
    {
        if(n%2)
        {
            n-- ;
            move = "A" + move ;
        }
        else
        {
            n = n / 2 ;
            move = "B" + move ;
        }
    }
    
    cout<<move ;
    
    return 0 ;
}