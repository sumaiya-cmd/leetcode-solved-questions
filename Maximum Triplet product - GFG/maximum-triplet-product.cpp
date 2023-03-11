//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	priority_queue<long long , vector<long long>, greater<long long>>minH;
    	priority_queue<long long >maxH ;
    	
    	for(int i=0;i<n;i++){
    	    maxH.push(arr[i]);
    	    minH.push(arr[i]);
    	}

        long max1= maxH.top();
        maxH.pop();
        
        long max2 =maxH.top();
        maxH.pop();
        
        long max3= maxH.top();
        maxH.pop();
        
        long min1=minH.top();
        minH.pop();
        
        long min2 =minH.top();
        minH.pop();
        
        return max(max1*max2*max3 , min1*min2*max1) ;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends