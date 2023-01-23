//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* newHead = reverseList(head);
        int carry =0;
        Node* curr =newHead;
        Node* prev =NULL;
        bool flag=1;
        
        while(curr){
            int val =carry+curr->data;
            if(flag == 1){
                val++;
                flag = 0;
            }
            curr->data= val%10;
            carry =val/10;
            prev =curr;
            curr =curr->next ;
        }
        if(carry)
            prev->next =new Node(carry);
        
        return reverseList(newHead );    
    }
    
    Node* reverseList(Node* head){
        Node* prev =NULL;
        Node* curr =head ;
        
        while(curr){
            Node* tempNode =curr->next;
            curr->next =prev;
            prev=curr;
            curr=tempNode;
        }
        
        return prev ;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends