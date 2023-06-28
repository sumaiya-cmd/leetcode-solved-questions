//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class disjointSet{
    public: 
   
   vector<int>par, size ;
   
   disjointSet(int n){
       par.resize(n);
       size.resize(n,1);
       
       for(int i=0;i<n;i++){
           par[i]=i;
       }
   }
   
   int findPar(int x){
        if(par[x]==x)
            return x ;
        
        return par[x] =findPar(par[x] );
   }
   
   void union_by_size(int x, int y){
        int ulp_x =findPar(x) ;
        int ulp_y =findPar(y);
       
        if(ulp_x==ulp_y)
            return ;
        
        if(size[ulp_x]<size[ulp_y]){
            par[ulp_x]=ulp_y ;
            size[ulp_y]+=size[ulp_x] ;
        }    
        else{
            par[ulp_y]=ulp_x ;
            size[ulp_x]+=size[ulp_y] ;
        }
   }
    
} ;

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        disjointSet ds(n);
        
        int extraEdges =0 ;
        for(auto i:edge){
            int x=i[0];
            int y=i[1];
            
            int ulp_x=ds.findPar(x);
            int ulp_y =ds.findPar(y);
            
            if(ulp_x==ulp_y)
                extraEdges++;
            else
                ds.union_by_size(x,y);
        }
        
        int cnt =0;
        
        for(int i=0;i<n;i++){
            if(ds.par[i]==i)
                cnt++;
        }
        
        if(extraEdges>=cnt-1)
            return cnt-1; 
        
        return -1 ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends