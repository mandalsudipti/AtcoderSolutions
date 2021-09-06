#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<string>contest = {"ABC" , "ARC" , "AGC" , "AHC"};
    
    sort(contest.begin() , contest.end());
    
    vector<string>S(3) ;
    for(int i = 0 ; i < 3 ; i++)
        cin>>S[i] ;
        
    sort(S.begin() , S.end()) ;
    string ans = contest[3] ;
    
    for(int i = 0 ; i < 3 ; i++)
    {
        if(S[i] != contest[i])
        {
            ans = contest[i] ;
            break;
        }
    }
    
    cout<<ans ;
    
    return 0 ;
}