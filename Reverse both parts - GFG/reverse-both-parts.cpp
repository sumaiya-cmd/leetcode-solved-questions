//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        // code here
        Node* kthelem = find(head , k);
        Node* nxt = kthelem->next ;
        kthelem->next =NULL; 
        
        Node* newHead1 =reverse(head );
        Node* newHead2 =reverse(nxt);
        
        head ->next = newHead2 ;
        return newHead1 ;
    }
    Node* find(Node* head , int k ){
        int i =1;
        
        Node* temp = head ;
        
        while(i<k){
            temp =temp->next ;
            i++;
        }
        
        return temp ;
    }
    
    Node* reverse(Node* head){
        
        Node* prev=NULL;
        Node* curr = head ;
        
        while(curr){
            Node* temp =curr->next ;
            curr->next =prev ;
            prev =curr ;
            curr =temp ;
        }
        
        return prev ;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends