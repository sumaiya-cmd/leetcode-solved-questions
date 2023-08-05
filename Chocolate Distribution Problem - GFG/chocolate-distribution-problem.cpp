//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
        if(n<m)
            return -1 ;
            
        sort(a.begin(),a.end()) ;
        int i=1,j=m;
        
        long long mini=a[m-1]-a[0] ;
        
        while(j<n){
            mini =min(mini, a[j]-a[i]);
            i++;
            j++;
        }
        return mini ;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends