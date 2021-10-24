#include<bits/stdc++.h>
using namespace std ;


int main()
{
    string S , T ;
    cin>>S>>T ;
    
    bool flag = false , possible = true;
    for(int i = 0 ; i < S.length() ; i++)
    {
        if(S[i] == T[i])
            continue ;
            
        if(S[i] != T[i] && (flag || i == S.length()-1 || S[i] != T[i+1] || S[i+1] != T[i]))
        {
            possible = false ;
            break ;
        }
        else
        {
            swap(S[i] , S[i+1]) ;
            flag = true ;
        }
    }
    
    if(possible)
        cout<<"Yes\n" ;
    else
        cout<<"No\n" ;
        
    return 0 ;
}