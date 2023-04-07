//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Node{
public :    
  int data ; 
  int i;
  int j;
  
  Node(int val , int row , int  col ){
      data=val ;
      i=row ;
      j =col ;
  }
};

class compare{
    public:
    
    bool operator()(Node* a , Node* b){
        return a->data >b->data ;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>ans ;
        priority_queue<Node* , vector<Node*> , compare >pq ;
        
        for(int i=0;i<K ;i++){
            Node* temp = new Node(arr[i][0] ,i ,0);
            pq.push(temp );
        }
        
        while(!pq.empty()){
            Node* newNode = pq.top() ;
            pq.pop() ;
            
            int c_row = newNode->i ;
            int c_col = newNode->j ;
            
            ans.push_back(newNode->data) ;
            
            if(c_col+1 <K )
            {
                Node* temp = new Node(arr[c_row][c_col+1] , c_row, c_col+1) ;
                pq.push(temp) ;
            }
               
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends