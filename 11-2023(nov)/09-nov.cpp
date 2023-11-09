//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int columnWithMaxZeros(vector<vector<int>> &arr, int n) {
        int maxZeros = 0;
        int columnIdx = -1;
        
        for (int j = 0; j < n; j++) {
            int zerosCount = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i][j] == 0) {
                    zerosCount++;
                }
            }
            
            if (zerosCount > maxZeros) {
                maxZeros = zerosCount;
                columnIdx = j;
            }
        }
        
        return columnIdx;
    }
};


//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends