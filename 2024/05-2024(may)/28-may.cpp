//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost)
    {
        vector<int> prev(w+1, 1e8);
        vector<int> curr(w+1, 1e8);
        prev[0]=curr[0]=0;
        for(int i=1;i<=n;i++)
        {
            curr[0]=0;
            for(int k=0;k<=w;k++)
            {
                int nontake=prev[k];
                int take=1e8;
                if(cost[i-1]!=-1 && i<=k)
                    take=cost[i-1]+curr[k-i];
                curr[k]=min(take, nontake);
            }
            prev=curr;
        }
        return prev[w]==1e8 ? -1 : prev[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends
