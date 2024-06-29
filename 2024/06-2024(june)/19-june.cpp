//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double P, double A)
    {
        double discriminant = P * P - 24 * A;
        if (discriminant < 0) 
            return -1; 
        double length = (P - sqrt(discriminant)) / 12;
        double height = P / 4 - 2 * length;
        double volume = length * length * height;
        volume = round(volume * 100) / 100;
        return volume;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends
