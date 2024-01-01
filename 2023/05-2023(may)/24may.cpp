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
    int getMaximum(int N, vector<int> &arr) {
        // code here
        long long int sum = 0;
        for(auto i: arr) sum += i;
        for(int i = min((int)sqrt(sum),N);i>0;--i){
            if(sum%i == 0) 
            {
                if(sum/i>N) return i;
                else return sum/i;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.getMaximum(N, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends