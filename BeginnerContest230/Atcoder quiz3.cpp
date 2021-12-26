#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int num ;
    cin>>num ;
    
    if(num >= 42)
        num++ ;
        
    string S = "AGC" ;
    string T = to_string(num) ;
    
    if(T.length() == 3)
        S+=T ;
    else if(T.length() == 2)
        S+=("0" + T) ;
    else
        S+=("00" + T) ;
        
    cout<<S<<endl;
    
    return 0 ;
}