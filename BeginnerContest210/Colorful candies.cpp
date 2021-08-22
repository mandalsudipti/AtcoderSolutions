#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n , k ;
    cin>>n>>k;
    
    vector<int>color(n) ;
    map<int,int>freq ;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>color[i] ;
        if(i < k)
            freq[color[i]]++;
    }
    
    int max_len = freq.size() ;
    for(int i = 1 ; i < n ; i++)
    {
        if(i+k-1 >= n)
            break;
            
        freq[color[i+k-1]]++;
        freq[color[i-1]]--;
        if(freq[color[i-1]] == 0)
            freq.erase(freq.find(color[i-1]));
            
        max_len = max(max_len , (int)freq.size());
    }
    
    cout<<max_len<<endl;
    return 0 ;
        
}