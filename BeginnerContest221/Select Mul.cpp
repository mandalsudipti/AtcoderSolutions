#include<bits/stdc++.h>
using namespace std ;

long long int get_product(string& S)
{
    long long int maximum = 0 ;
    //cout<<S<<endl;
    if(S[0] == '0')
        return 0 ;
        
    for(int i = 1 ; i < S.length() ; i++)
    {
        if(S[i] == '0')
            continue ;
            
        string S1 = S.substr(0 , i) , S2 = S.substr(i) ;
        long long int num1 = stoll(S1) , num2 = stoll(S2) ;
        
        maximum = max(maximum , num1 * num2) ;
    }
    
    return maximum ;
}

void permute(string& S , int left , int right , long long int* max_product)
{
    if(left == right)
        (*max_product) = max((*max_product) , get_product(S)) ;
    else
    {
        for(int i = left ; i <= right ; i++)
        {
            swap(S[left] , S[i]) ;
            permute(S , left+1 , right , max_product) ;
            swap(S[left] , S[i]) ;
        }
    }
}

int main()
{
    string S ;
    cin>>S ;
    
    long long int max_product = 0 ;
    
    permute(S , 0 , S.length() - 1 , &max_product) ;
    
    cout<<max_product<<endl;
    
    return 0 ;
}