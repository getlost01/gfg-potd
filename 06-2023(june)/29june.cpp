//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:

    bool isHappy(int n) {
        // 7 & 1 are the only numbers which can be happy in single digit by observation
        if (n == 1 || n == 7) 
            return 1;
            
        int next, sum;
        next = sum = n;

        while (next > 9) {
            sum = 0;

            while (next > 0) {
                int digit = next % 10;
                next /= 10;
                sum += digit * digit;
            }

            if (sum == 1 || sum == 7)
                return 1;

            next = sum;
        }

        return 0;
    }

    int nextHappy(int n) {
        int nextNum = n + 1;

        while (isHappy(nextNum) != 1)
            nextNum++;

        return nextNum;
    }
    
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends