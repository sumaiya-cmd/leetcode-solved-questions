//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int count5=0;
        int count10=0 ;
        int count20=0 ;
        
        for(int i=0;i<N;i++){
            int earn =bills[i];
            
            if(earn==5){
                count5++;
            }
            else if(earn==10 ){
                if(count5>0){
                    count5-=1 ;
                    count10+=1;
                }
                else
                    return false;
            }
            else{
                if(count10>0){
                    if(count5>0){
                        count20+=1;
                        count5-=1;
                        count10-=1 ;
                    }
                    else{
                        return false;
                    }
                }
                else if(count5>2){
                    count5-=3;
                    count20+=1;
                }
                else
                    return false;
            }
        }
        
        return true ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends