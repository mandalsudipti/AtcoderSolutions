#include<bits/stdc++.h>
using namespace std ;

bool has_common_bit(long long int a , long long int b)
{
    while(a >= 1 && b >= 1)
    {
        if(a%2 == b%2 && a%2 == 1) // common set bit
            return true ;
            
        a = a / 2 ;
        b = b / 2 ;
    }
    
    return false ;
}

int main()
{
    int T ;
    cin>>T ;
    
    while(T--)
    {
        long long int a , s ;
        cin>>a>>s ;
        
        if(2*a > s)
            cout<<"No"<<endl;
        else
        {
            long long int diff = s - 2*a ;
            
            if(has_common_bit(a , diff))
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
    }
    
    return 0 ;
}