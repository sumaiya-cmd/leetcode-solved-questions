//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string exp) {
        // Write your code here
        stack<string>stack ;
        
        for(int i=0;i<exp.size() ;i++){
            char  ch =exp[i];
            
            if(ch>='a'&&ch<='z' ||(ch>='A' && ch<='Z')  ){
                string str;
                str+=ch;
                stack.push(str);
            }
                
            
            else{
                string second =stack.top();
                stack.pop();
                string first =stack.top();
                stack.pop();
                
                stack.push(ch+first+second);
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends