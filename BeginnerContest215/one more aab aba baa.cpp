#include<bits/stdc++.h>
using namespace std ;

void get_permutation(vector<int>& freq , string& cur , vector<string>& permutation , int len)
{
    if(cur.length() == len)
    {
        permutation.push_back(cur) ;
        return ;
    }
    
    for(int i = 0 ; i < 26 ; i++)
    {
        if(freq[i] > 0)
        {
            freq[i]--;
            cur+=('a' + i) ;
            
            get_permutation(freq , cur , permutation , len) ;
            
            freq[i]++ ;
            cur.pop_back() ;
        }
    }
}

int main()
{
    string S ;
    cin>>S;
    
    int k ;
    cin>>k;
    
    vector<int>freq(26,0) ;
    for(int i = 0 ; i < S.length() ; i++)
        freq[S[i] - 'a']++ ;
        
    vector<string>permutation ;
    string cur = "" ;
    
    get_permutation(freq , cur , permutation , S.length()) ;
    
    sort(permutation.begin() , permutation.end());
    
    cout<<permutation[k-1] ;
    
    return 0 ;
}