//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s){
            //code here.
            int n=s.size();
            stack<string>stack ;
            
            string ans ="";
            
            int i=0 ;
            
            while(i<s.size()){
                string str ="";
                
                if(s[i]>='0'&& s[i]<='9'){
                    
                    while(i<n && s[i]>='0' && s[i]<='9'){
                        str+=s[i++];
                    }
                    
                    stack.push(str);
                }
                
                str ="";
                
                if(s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/')
                    str+=s[i++];
                
                if(str.size()>0)
                    stack.push(str);
            }
            
            while(!stack.empty()){
                string  str = stack.top();
                stack.pop();
                
                ans+=str ;
            }
            
            return ans ;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends