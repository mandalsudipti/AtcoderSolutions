#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long long int n , power ;
    cin>>n>>power ;
    
    long long int left , right ;
    multiset<pair<long long int,long long int>>end_point , start_point ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>left>>right ;
        
        end_point.insert(make_pair(right , left)) ;
        start_point.insert(make_pair(left , right)) ;
    }
    
    right = -1 ;
    int step = 0 ;
    
    while(start_point.size() > 0)
    {
        if(right == -1)
        {
            right = (*end_point.begin()).first ;
            left = (*end_point.begin()).second ;
            
            end_point.erase(end_point.begin()) ;
            step++ ;
            start_point.erase(start_point.find(make_pair(left , right))) ;
            
            right = right + power - 1 ;
        }
        
        while(start_point.size() > 0 && (*start_point.begin()).first <= right)
        {
            int cur_left = (*start_point.begin()).first , cur_right = (*start_point.begin()).second ;
            
            start_point.erase(start_point.begin()) ;
            end_point.erase(end_point.find(make_pair(cur_right , cur_left))) ;
        }
        
        right = -1 ;
    }
    
    cout<<step<<endl;
    
    return 0 ;
}
