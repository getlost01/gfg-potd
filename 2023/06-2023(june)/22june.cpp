//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        map<int,int> mp;
        for(auto bill: bills){
            ++mp[bill];                      // add bill note to cash box.
            
            int change = bill - 5;           // cut the price of lemonade and provide remaining change.
            
            if(change == 15 && mp[10] > 0){  // provide one 10 bill note if change value is 15.
                --mp[10];
                change -= 10;
            }
            
            if(change>=5){                   // last option, provide 5 bill notes as many as needed.
                if(change/5 <= mp[5]){  
                    mp[5] -= change/5;
                    change = 0;
                }else
                    return false;            // if we cannot provide 5 bill notes in change return false. 
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends