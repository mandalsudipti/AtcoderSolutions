#include<bits/stdc++.h>
using namespace std ;


int main()
{
    string base_str = "oxx" ;
    string T = "" ;
    
    for(int i = 0 ; i < 1e5 ; i++)
        T+=base_str ;
        
    string S ;
    cin>>S ;
    
    bool possible = false ;
    for(int i = 0 ; i < T.length() ; i++)
    {
        if(i + S.length() - 1 >= T.length())
            break; 
           
        bool flag = true ; 
        for(int j = 0 ; j < S.length() ; j++)
        {
            if(S[j] != T[i+j])
            {
                flag = false ;
                break;
            }
        }
        
        if(flag)
        {
            possible = true ;
            break;
        }
    }
    
    if(possible)
        cout<<"Yes\n" ;
    else
        cout<<"No\n" ;
        
    return 0 ;
}