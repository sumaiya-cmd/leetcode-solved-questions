//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int odd = 0;
	    int even = 0;
	    for(int i = 0 ; i < s.size(); i++){
	        if(i%2){
	            odd += (int)(s[i] - '0');
	        }
	        else{
	        even+= (int)(s[i] - '0');
	            
	        }
	    }
	    
	    if(abs(odd-even) % 3){
	        return 0;
	    }
	    
	    return 1;

	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends