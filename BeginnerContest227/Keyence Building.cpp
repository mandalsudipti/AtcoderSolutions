#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int  n ;
    cin>>n ;
    
    vector<int>area(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>area[i] ;
        
    set<int>valid_area ;
    
    for(int i = 1 ; i <= 1000 ; i++)
    {
        for(int j = 1 ; j <= 1000 ; j++)
        {
            if(j - (3*i) <= 0)
                continue ;
                
            if((j - (3*i)) % ((4*i) + 3) != 0)
                continue ;
                
            valid_area.insert(j) ;
        }
    }
    
    int count = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        if(valid_area.find(area[i]) != valid_area.end())
        {
            count++ ;
        }
    }
    
    cout<<n - count<<endl;
    
    return 0 ;
}