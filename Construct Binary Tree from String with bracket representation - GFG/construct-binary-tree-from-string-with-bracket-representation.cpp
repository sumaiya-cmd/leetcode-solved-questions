//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        stack<Node*>stack ;
        
        for(int i=0 ;i<str.size();i++){
            int j =i ;
            
            if(isdigit(str[i])){
                
                while(i+1 < str.size() && isdigit(str[i+1]) ) i++;
                
                string str1 = str.substr(j ,(i+1-j)) ;
                int valOfStr = stoi(str1);
                
                // cout<< valOfStr<< endl ;
                
                Node* temp= new Node(valOfStr) ;
                
                if(stack.empty())
                    stack.push(temp) ;
                    
                else{
                    if(!stack.top()->left)
                        stack.top()->left = temp ;
                        
                    else 
                        stack.top()->right = temp ;
                    
                    stack.push(temp);    
                }    
            }
            
            if(str[i]==')')
                stack.pop() ;
        }
        
        return stack.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends