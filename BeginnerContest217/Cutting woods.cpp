#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int L , Q ;
    cin>>L>>Q ;
    
    set<int>cut ;
    cut.insert(0) ;
    cut.insert(L) ;
    
    while(Q--)
    {
        int op , x ;
        cin>>op>>x ;
        
        if(op == 1)
            cut.insert(x) ;
        else
        {
            auto itr = cut.lower_bound(x) ;
            int right = (*itr) ;
            
            --itr ;
            int left = (*itr) ;
            
            cout<<(right - left)<<endl;
        }
    }
    
    return 0 ;
}