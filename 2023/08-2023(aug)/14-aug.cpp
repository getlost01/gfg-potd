//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorVal = 0;
        for(auto num: nums){
            xorVal ^= num;      // Xor of two same values = 0, so after this operation we get xor value of two unpaired numbers.
        }

        int mask = 1;           
        while(!(xorVal & 1)){   // Making bit mask of rightmost set bit 
            mask <<= 1;
            xorVal >>= 1;
        }
        
        vector<int> out(2,0);   
        for(auto num: nums){
           if((mask & num))     // All value who have set bit stored in out[0];
                out[0] ^= num;
            else                // All values who have unset bit stored in out[1]; 
                out[1] ^= num;
        }
        sort(out.begin(),out.end());
        return out;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends