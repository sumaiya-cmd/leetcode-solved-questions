//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char>stack ;
        string res ="";
        for(int i=0;i<s.size();i++){
            char ch =s[i];
            
            if(ch=='(')
                stack.push(ch);
                
            else if(ch>='a'&&ch<='z' ||(ch>='A' && ch<='Z'))
                res+=ch;
            
            else if(ch==')'){
                while(stack.top()!='('){
                    res+=stack.top();
                    stack.pop();
                }
                stack.pop();
            }
            
            else {
                while(!stack.empty() && precedence(stack.top())>=precedence(ch)){
                    res+=stack.top();
                    stack.pop();
                }
                stack.push(ch);
                   
            }    
                
        }
        
        while(!stack.empty()){
            res+=stack.top();
            stack.pop();
        }
        return res ;
    }
    
    int precedence(char c) {
      if (c == '^')
        return 3;
      else if (c == '/' || c == '*')
        return 2;
      else if (c == '+' || c == '-')
        return 1;
      else
        return -1;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends