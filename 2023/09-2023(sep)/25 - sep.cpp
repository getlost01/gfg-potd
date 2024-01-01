//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    struct Trip {
        int value, a, b;
        bool operator<(const Trip& other) const {
            if(value == other.value){
                if(a == other.a)
                    return b > other.b;
                return a > other.a;
            }
            return value > other.value;
        }
    };
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        set<Trip> st;
        st.insert({A.back() + B.back(), N-1, N-1});
        vector<int> out;
        while(K--){
           int value = st.begin()->value;
           int a = st.begin()->a;
           int b = st.begin()->b;
           st.erase(st.begin());
           out.push_back(value);
           if(a > 0)
            st.insert({A[a-1] + B[b], a-1, b});
           if(b > 0)    
            st.insert({A[a] + B[b-1], a, b-1});
        }
        return out;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends