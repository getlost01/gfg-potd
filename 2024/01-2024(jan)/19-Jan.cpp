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
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }

    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        unordered_map<int, int> freqMap;
        set<pair<int, int>, decltype(&comp)> topKSet(comp);
        vector<vector<int>> result(N);

        for (int i = 0; i < N; ++i) {
            if (freqMap.find(arr[i]) != freqMap.end()) {
                topKSet.erase({freqMap[arr[i]], arr[i]});
            }

            freqMap[arr[i]]++;
            topKSet.insert({freqMap[arr[i]], arr[i]});

            vector<int> temp;
            auto it = topKSet.begin();

            for (int j = 0; j < K && it != topKSet.end(); ++j, ++it) {
                temp.push_back(it->second);
            }

            result[i] = temp;
        }
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends