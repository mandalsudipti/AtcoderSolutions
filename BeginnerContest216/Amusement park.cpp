#include<bits/stdc++.h>
using namespace std ;


int main()
{
    long long int n , k , ele;
    cin>>n>>k;
    
    map<long long int , long long int , greater<long long int>>freq ;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>ele ;
        freq[ele]++;
    }
    
    long long int points = 0 ;
    
    while(freq.size() >= 2 && k > 0)
    {
        auto itr = freq.begin() ;
        long long int maximum = (*itr).first ;
        ++itr ;
        long long int max_second = (*itr).first ;
        
        long long int diff = (maximum - max_second) , cur_freq = (*freq.begin()).second ;
        
        if(k >= cur_freq*diff)
        {
            k-=(cur_freq * diff) ;
            points+=(cur_freq * ( (maximum * (maximum + 1))/2 - (max_second * (max_second + 1))/2 ) ) ;
            freq.erase(freq.begin()) ;
            freq[max_second]+=cur_freq ;
        }
        else
        {
            long long int q = k/cur_freq , rem = k%cur_freq ;
            long long int x = maximum - q ;
            
            points+=(cur_freq * ( (maximum * (maximum + 1))/2 - (x * (x + 1))/2 ) ) ;
            points+=(x * rem) ;
            k = 0 ;
            break;
        }
    }
    
    if(k != 0)
    {
        long long int step = (*freq.begin()).first , cur_freq = (*freq.begin()).second ;
        if(k >= step*cur_freq)
            points+=(cur_freq * ( ((step)*(step + 1))/2 ) ) ;
        else
        {
            long long int q = k / cur_freq , rem = k % cur_freq ;
            long long int x = step - q ;
            
            points+=(  ((step * (step + 1))/2) - ((x * (x+1))/2)  )*cur_freq ;
            points+=(rem * x) ;
        }
    }
    
    cout<<points<<endl;
    
    return 0 ;
}