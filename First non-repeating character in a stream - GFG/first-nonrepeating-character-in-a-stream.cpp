//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    unordered_map<char,int>m ;
		    
		    queue<char>q ;
		    string ans= "" ;
		    
		    for(int i=0 ;i<A.size() ;i++){
		        
		        char ch=A[i] ;
		        
		        if(m.find(ch)==m.end()){
		            q.push(ch);
		            m[ch]++;
		        }
		        else{
		            m[ch]++;
		            while(!q.empty() && m[q.front()]>1){
		                q.pop();
		            }
		        }
		        ans+= (q.empty()) ? '#' : q.front() ;
		            
		    }
		    
		    return ans ;
		   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends