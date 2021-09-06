#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    vector<long long int>arr ;
    multiset<long long int>num ;
    int left = -1 ;
    
    while(T--)
    {
        int type ;
        cin>>type ;
        
        if(type == 1)
        {
            long long int val; 
            cin>>val;
            arr.push_back(val);
            
            if(left == -1)
                left = arr.size() - 1 ;
        }
        else if(type == 2)
        {
            if(num.size() > 0)
            {
                cout<<(*num.begin())<<endl;
                num.erase(num.begin());
            }
            else
            {
                cout<<arr[left]<<endl;
                left++;
                if(left >= arr.size())
                    left = -1 ;
            }
        }
        else
        {
            if(left == -1)
                continue;
                
            for(int i = left ; i < arr.size() ; i++)
            {
                num.insert(arr[i]);
            }
            left = -1 ;
        }
    }
    
    return 0 ;
}