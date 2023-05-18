// Link - https://practice.geeksforgeeks.org/problems/trace-path3840/1
// Trace Path

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int x , y , l , r , t , u ;
        x = y = l = r = t = u = 0;
        for(auto i: s){
            if(i == 'L') --x, l = min(l,x);
            if(i == 'R') ++x, r = max(r,x);
            if(i == 'U') --y, t = min(t,y);
            if(i == 'D') ++y, u = max(u,y);
            // cout<<abs(l)<<" "<<r<<" "<<t<<" "<<u<<endl;
            if((abs(l)+r)>=m || (abs(t)+u)>=n) return 0;
        }
        return 1;
    }
};