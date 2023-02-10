//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        unordered_map<char , int>m ;
        
        for(int i=0 ; i<s.size() ; i++)
            m[s[i]]++;
            
        // for(auto i:m)
            // cout<<i.first<<" "<<i.second<<endl;
        
        int findOne = min(m['b'] , min(m['a'] , m['n']));
        
        int findTwo =min(m['l'], m['o']);
        
        int ans =findTwo/2;
        
        while(findOne<ans)
            ans=ans/2 ;
        
        return ans ;    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends