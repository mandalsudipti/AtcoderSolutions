#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n;
    string S ;
    cin>>S;
    
    string winner ;
    for(int i = 0 ; i < n ; i++)
    {
        if(S[i] == '1')
        {
            winner = ( i%2 == 0 ? "Takahashi" : "Aoki") ;
            break;
        }
    }
    cout<<winner<<endl;
    return 0 ;
}
