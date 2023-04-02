//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        int m=arr.size() ;
        int n=arr[0].size() ;
        
        vector<int>step ;
        step.push_back(arr[start_x][start_y]) ;
        
        vector<pair<int,int>>dir ={{2,1} ,{2,-1} ,{1,2} ,{1,-2} ,{-1 ,2} ,{-1,-2} ,{-2 ,1} ,{-2 ,-1}} ;
        
        queue<pair<int,int>>q ;
        q.push({start_x,start_y}) ;
        
        
        vector<vector<bool>>vis(m ,vector<bool>(n,false)) ;
        vis[start_x][start_y]=true; 
        
        while(!q.empty()){
            int size =q.size() ;
            int sum =0 ;
            
            while(size--){
                int x= q.front().first ;
                int y =q.front().second ;
                q.pop() ;
                
                for(auto i:dir){
                    int nx =x+i.first ;
                    int ny =y+ i.second ;
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                        sum+=arr[nx][ny] ;
                        q.push({nx ,ny}) ;
                        vis[nx][ny]=true ;
                    }
                }
            }
            
            step.push_back(sum) ;
        }
        
        int maxi=-1;
        int ans =0 ;
        
        for(int i=step.size()-1; i>=0 ;i--){
            if(i+step[i]>=0 && i+step[i]<step.size())
                step[i]+=step[i+step[i]];

            
            if(maxi<=step[i]){
                ans =i ;
                maxi=step[i] ;
            }
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends