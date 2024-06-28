//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        set<int> st;
        int suma = 0;
        int sumb = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            suma += a[i];
            st.insert(a[i]);
        }

        for(int i = 0 ; i < m ; i++ )
            sumb += b[i];

        if((sumb-suma)%2 != 0) return -1;


        for(int i = 0 ; i < m ; i++ )
            if(st.find((suma-sumb)/2+b[i]) != st.end())
                return 1;

        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
