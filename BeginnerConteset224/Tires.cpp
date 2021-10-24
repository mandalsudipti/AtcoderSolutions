#include<bits/stdc++.h>
using namespace std ;


int main()
{
    string S;
    cin>>S;
    
    int n = S.length() ;
    if(S[n-2] == 'e' && S[n-1] == 'r')
        cout<<"er"<<endl;
    else
        cout<<"ist"<<endl;
        
    return 0 ;
}