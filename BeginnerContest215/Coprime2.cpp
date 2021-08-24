#include<bits/stdc++.h>
using namespace std ;


int main()
{
    int n , m ;
    cin>>n>>m;
    
    vector<long long int>arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i] ;
        
    vector<bool>ans(m+1 , true) ;
    
    for(int i = 0 ; i < n ; i++)
    {
        int  num = arr[i] ;
        if(num%2 == 0)
        {
            while(num%2 == 0)
                num = num / 2 ;
            if(ans[2])
                for(int j = 2 ; j < ans.size() ; j+=2)
                    ans[j] = false ;
        }
        
        for(int j = 3 ; j <= sqrt(num) ; j+=2)
        {
            if(num%j == 0)
            {
                while(num%j == 0)
                    num = num / j ;
                
                if(ans[j])
                {
                    for(int k = j ; k < ans.size() ; k+=j)
                        ans[k] = false ;
                }
            }
        }
        
        if(num != 1 && ans[num] == true)
        {
           for(int j = num ; j < ans.size() ; j+=num)
                ans[j] = false ;
        }
    }
    
    vector<int>coprime ;
    for(int i = 1 ; i <= m ; i++)
    {
        if(ans[i])
            coprime.push_back(i) ;
    }
    
    cout<<coprime.size()<<endl;
    for(int i = 0 ; i < coprime.size() ; i++)
        cout<<coprime[i]<<endl;
        
    return 0 ;
}
