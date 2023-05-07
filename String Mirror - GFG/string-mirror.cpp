//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string s ="" ;
        s +=str[0]; 
        for(int i=1 ;i<str.size() ;i++){
            if(i==1 && s[s.size()-1] == str[i])
                break ;
            if(s[s.size()-1]>=str[i]){
                s+=str[i] ;
            }
            else
                break ;
        }
        string s1 =s ;
        reverse(s.begin() ,s.end());
        
        return s1+s ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends