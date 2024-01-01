//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int dp[n][2];
        
        dp[n][1] = dp[n][0] = 0;
        
        for(int i = n-1; i>=0; --i){
            for(int canBuy = 0; canBuy<2;++canBuy){
                dp[i][canBuy] = dp[i+1][canBuy];
                if(canBuy)
                    dp[i][canBuy] = max(dp[i+1][0] - prices[i], dp[i][canBuy]);
                else
                    dp[i][canBuy] = max(dp[i+1][1] + prices[i], dp[i][canBuy]);
            }
        }
        
        return dp[0][1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends