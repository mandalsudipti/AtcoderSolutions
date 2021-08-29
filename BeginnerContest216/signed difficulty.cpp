#include<bits/stdc++.h>
using namespace std ;

int main()
{
    string S ;
    cin>>S ;
    
    string T = "" ;
    for(int i = 0 ; i < S.length() ; i++)
    {
        if(S[i] == '.')
            break;
        T+=S[i] ;
    }
        
    if(S.back() >= '0' && S.back() <= '2')
    {
        cout<<T<<"-" ;
    }
    else if(S.back() >= '3' && S.back() <= '6')
        cout<<T;
    else
        cout<<T<<"+" ;
        
    return 0 ;
}