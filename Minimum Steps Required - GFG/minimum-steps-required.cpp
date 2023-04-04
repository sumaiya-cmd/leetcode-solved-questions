//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int i=0,j=0 ;
    int count_a =0;
    int count_b =0 ;
    
    while(i<str.size()){
        if(str[i] == str[j])
            i++ ;
        else{
            if(str[j]=='a')
                count_a +=1;
            else
                count_b+=1 ;
            j=i ;  
            i++;
        }
    }
    
    if(j<=str.size()-1){
        if(str[j]=='a')
            count_a +=1;
        else
            count_b+=1 ;
    }
    
    return min(count_a , count_b) +1 ;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends