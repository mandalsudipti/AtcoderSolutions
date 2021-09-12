#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int val ;
    string S = " ";
    
    for(int i = 1 ; i <= 26 ; i++)
    {
        cin>>val;
        S+=('a' + (val - 1)) ;
    }
    
    cout<<S ;
    
    return 0 ;
}