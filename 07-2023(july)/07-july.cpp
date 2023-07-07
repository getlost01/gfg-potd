//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
            int i = 0, j = 0, k = 0;
            
            long long offset = 1e7;
            while(i<n && j<m){
                if(arr1[i]%offset < arr2[j%offset]){
                    if(k<n)
                        arr1[k] += offset*(arr1[i]%offset);
                    else
                        arr2[k-n] += offset*(arr1[i]%offset);
                    ++i;
                }else{
                    if(k<n)
                        arr1[k] += offset*(arr2[j]%offset);
                    else
                        arr2[k-n] += offset*(arr2[j]%offset);
                    ++j;
                }
                ++k;
            }
            
            while(i<n){
                if(k<n)
                        arr1[k] += offset*(arr1[i]%offset);
                else
                        arr2[k-n] += offset*(arr1[i]%offset);
                ++i;
                ++k;
            }
            
            while(j<m){
                if(k<n)
                        arr1[k] += offset*(arr2[j]%offset);
                else
                        arr2[k-n] += offset*(arr2[j]%offset);
                ++j;
                ++k;
            }
            
            for(int i = 0; i<n;++i)
                arr1[i] /= offset;
            for(int i = 0; i<m;++i)
                arr2[i] /= offset;
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends