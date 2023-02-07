//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    // Code here
	    set<int>set ;
	    vector<int>ans ;
	    
	    int i =2;
	    while(n!=1 && i<=n){
	        if(n%i==0){
	            if(set.find(i)==set.end())
	                ans.push_back(i);
	            set.insert(i);
	            n=n/i ;
	        }
	        else
	            i++;
	    }
	    
	    return ans ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends