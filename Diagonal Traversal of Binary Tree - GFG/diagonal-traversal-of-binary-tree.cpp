//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector<int> diagonal(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void diagonalView (Node*root , int slope ,unordered_map<int , vector<int>> &memo ,int &maxSlope ){
    if(root == NULL)
        return ;
        
    maxSlope = max(maxSlope ,slope ) ;
    
    if(memo.find(slope) != memo.end()){
        memo[slope].push_back(root->data);
    }else{
        vector<int>current ;
        current.push_back(root->data);
        memo[slope]= current ;
    }
    
    diagonalView(root->left , slope+1 ,memo ,maxSlope);
    diagonalView(root->right , slope ,memo,maxSlope);
    
    return ;
}

void traverse(Node* temp , vector<int>&answer , queue<Node*>&queue){
    while(temp){
       
        if(temp->left)
            queue.push(temp->left);
        
        if(temp->right){
            answer.push_back(temp->right->data);
        }
        
        temp = temp->right ;
   }
   
   return ;
}

vector<int> diagonal(Node *root)
{
   vector<int>answer ;
   unordered_map<int , vector<int>>memo ;
   int maxSlope =   -1000000;
   
//   diagonalView(root ,0 ,memo , maxSlope) ;

// BFS :-

   queue<Node*>queue;
   
   answer.push_back(root->data);
   
   Node* temp = root ;
   traverse(root , answer , queue) ;
   
   while(!queue.empty()){
       Node* currentNode = queue.front() ;
       queue.pop() ;
       
       answer.push_back(currentNode->data);
       
       traverse(currentNode , answer ,queue);
   }
   
//   for(int i=0; i<=maxSlope ;i++){
//       for(auto current :memo[i])
//             answer.push_back(current);
//   }
   
   return answer ;
}


