//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int appl, vector<vector<int>>&g , vector<int>&match , vector<int>&vis){
        
        for(int i=0 ;i<g[0].size() ;i++){
            if(g[appl][i]==1 && !vis[i]){
                vis[i]=1 ;
                
                if(match[i]==-1 || solve(match[i] ,g, match, vis)){
                    match[i]=appl;
                    return true ;
                }
            }
        }
        
        return false; 
        
    }
	int maximumMatch(vector<vector<int>>&g){
	    // Code here
	    int m=g.size();
	    int n=g[0].size();
	    
	    vector<int>match(n,-1); // to check whether the ith job is assigned to an applicant
	    
	    int ans =0;
	    
	    for(int i=0;i<m;i++){
	        vector<int>vis(n ,0);
	        
	        if(solve(i, g ,match, vis))
	            ans++;
	    }
	    
	    return ans ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends