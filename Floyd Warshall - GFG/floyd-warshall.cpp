//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    
	    for (int i=0 ;i<n ;i++)
	        for(int j=0 ;j<n ;j++)
	             if(matrix[i][j]==-1)
	                matrix[i][j]= INT_MAX ;
	    
	    for (int intermed =0 ;intermed<n;intermed++)
	        for(int src =0 ;src<n ;src++)
	            for(int dest =0 ;dest <n ;dest++)
	                if(matrix[src][intermed]!=INT_MAX && matrix[intermed][dest]!=INT_MAX)
	                    matrix[src][dest] = min(matrix[src][dest] , matrix[src][intermed]+ matrix[intermed][dest]) ;
	            
	    
	    for(int i=0 ;i<n;i++)
	        for(int j=0;j<n;j++)
	            if(matrix[i][j]== INT_MAX)
	                matrix[i][j]=-1 ;
	    
	    return ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends