//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends

class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, [](auto &a, auto &b) {
            return a.value * b.weight > b.value * a.weight;
        });

        double value = 0;

        // Filling the knapsack
        for (int i = 0; i < n; i++) {
            auto &item = arr[i];

            if (item.weight <= W) {
                value += item.value;
                W -= item.weight;
            } else {
                value += double(item.value) * W / item.weight;
                break;
            }
        }

        return value;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends