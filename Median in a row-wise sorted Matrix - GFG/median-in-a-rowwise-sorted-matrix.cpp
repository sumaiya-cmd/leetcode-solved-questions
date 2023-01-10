//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countLessElem(vector<vector<int>>matrix , int row , int colmn , int midElem){
        int count= 0;
        for(int i =0 ;i<row ;i++){
            int s =0 , e =colmn-1 ;
            
            while(s<=e){
                int mid =s+(e-s)/2 ;
                
                if(matrix[i][mid] <= midElem)
                    s=mid+1;
                else
                    e=mid-1;
            }
            
            count+=s ;
        }
        return count ;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here 
        int s =0 , e=2000 ;
        
        while(s<=e){
            int mid = s+(e-s)/2 ;
            int count = countLessElem(matrix, R,C , mid);
            if(count<=(R*C)/2)
                s=mid+1;
            else
                e=mid-1;
        }
        return s ;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends