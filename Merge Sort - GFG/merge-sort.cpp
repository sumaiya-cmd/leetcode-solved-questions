//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int s=l , e=r , mid=m;
         int merged[e-s+1] ;
         
         int indx1 =s ;
         int indx2 =mid+1 ;
         int x =0 ;
         
         while(indx1<=mid && indx2<=e) {
            if(arr[indx1]>arr[indx2])
                merged[x++] =arr[indx2++] ;
            
            else
                merged[x++] =arr[indx1++] ;
         }
         
        while(indx1<=mid)
            merged[x++] =arr[indx1++] ;
            
        while(indx2<=e)
            merged[x++] =arr[indx2++] ;
            
        for(int i= 0 , j=s ;i<sizeof(merged)/sizeof(merged[0]) ;j++ ,i++){
            arr[j] = merged[i];
        } 
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        int s= l;
        int e =r ;
        int mid = s+(e-s)/2 ;
        if(s>=e)
            return ;
            
        mergeSort(arr , s , mid) ;
        mergeSort(arr , mid+1 , e) ;
        merge(arr , s, mid , e) ;
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends