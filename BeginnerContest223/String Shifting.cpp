#include<bits/stdc++.h>
using namespace std ;

int main()
{
    string S;
    cin>>S ;
    
    int smallest = 0 , largest = 0 ;
    
    for(int i = 0 ; i < S.length() ; i++)
    {
        if(S[i] < S[smallest])
            smallest = i ;
            
        if(S[i] > S[largest])
            largest = i ;
    }
    
    for(int i = 0 ; i < S.length() ; i++)
    {
        if(S[i] == S[smallest])
        {
            int j = i , k = smallest , len = 1 ;
            
            while(len <= S.length())
            {
                if(S[j] == S[k])
                {
                    j = (j+1)%S.length() ;
                    k = (k+1)%S.length() ;
                    len++ ;
                }
                else if(S[j] < S[k])
                {
                    smallest = i ;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    for(int i = 0 ; i < S.length() ; i++)
    {
        if(S[i] == S[largest])
        {
            int j = i , k = largest , len = 1 ;
            
            while(len <= S.length())
            {
                if(S[j] == S[k])
                {
                    j = (j+1)%S.length() ;
                    k = (k+1)%S.length() ;
                    len++ ;
                }
                else if(S[j] > S[k])
                {
                    largest = i ;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }
    
    string smallest_str = "" , largest_str = "" ;
    
    for(int i = 0 ; i < S.length() ; i++)
    {
        smallest_str+=S[smallest] ;
        smallest = (smallest + 1)%S.length() ;
        
        largest_str+=S[largest] ;
        largest = (largest + 1)%S.length() ;
    }
    
    cout<<smallest_str<<endl;
    cout<<largest_str<<endl;
    
    return 0 ;
}