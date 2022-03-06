#include<bits/stdc++.h>
using namespace std ;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    multiset<long long int>ele ;
    
    int query ;
    cin>>query ;
    
    int type , k;
    long long int x ;
    
    while(query--)
    {
        cin>>type>>x ;
        
        
        if(type == 1)
            ele.insert(x) ;
        else if(type == 2) 
        {
            cin>>k ;
            
            auto itr = ele.upper_bound(x) ; //find k-th element which is less equal to X
            
            if(itr == ele.begin())
                cout<<"-1\n";
            else
            {
                bool flag = true ;
                (itr)-- ;
                
                for(int i = 0 ; i+1 < k ; i++)
                {
                    //cout<<(*itr)<<" ";
                    if(itr == ele.begin())
                    {
                        flag = false ;
                        break ;
                    }
                    (itr)-- ;
                }
                if(flag)
                    cout<<(*itr)<<"\n";
                else
                    cout<<"-1\n";
            }
        }
        else if(type == 3)
        {
            cin>>k ;
            
            auto itr = ele.lower_bound(x) ;
            
            for(int i = 0 ; i+1 < k ; i++)
            {
                if(itr == ele.end())
                    break ;
                ++itr ;
            }
            if(itr != ele.end())
                cout<<(*itr)<<"\n";
            else
                cout<<"-1\n";
        }
    }
    
    return 0 ;
}


