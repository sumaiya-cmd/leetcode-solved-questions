//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string exp) {
        stack<string>stack ;
        
        for(int i=exp.size()-1 ;i>=0 ;i--){
            char  ch =exp[i];
            
            if(ch>='a'&&ch<='z' ||(ch>='A' && ch<='Z')  ){
                string str;
                str+=ch;
                stack.push(str);
            }
                
            
            else{
                string first =stack.top();
                stack.pop();
                string second =stack.top();
                stack.pop();
                
                stack.push(first+second+ch);
            }    
            
        }
        
        return stack.top() ;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends