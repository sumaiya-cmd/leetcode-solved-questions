//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages
    bool canAllocate(int a[], int n , int m , int mid){
        int stud =1; int pages =0;
        
        for( int i=0; i<n ;i++){
            if(a[i]>mid) 
                return false ;
                
            if(pages+a[i]>mid){
                stud+=1;
                pages=a[i];
            }
            
            else
                pages+=a[i];
        }
        
        return stud<=m;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        
        int sum =0 ;
        int ans=-1;
        int mini =A[0] ;
        
        for(int i=0;i<N;i++){
            mini = min(mini ,  A[i]);
            sum+=A[i];    
        }
        
        int s = mini ,  e=sum;
        
        while(s<=e){
            int mid =s+(e-s)/2 ;
            
            if(canAllocate(A ,N,M, mid)){
                ans= mid ;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends