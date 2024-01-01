class Solution {
    public:
    int solve(int N, vector<int> p){
        vector<int> count(N, 0);
        int  c= 0;
        if(count[0] == 1)
            ++c;
        for(int i = 1; i < N; i++){
            ++count[p[i]];
        }
        for(auto i: count)
            if(!i)
            ++c;
            
        return max(N - 1 - c, 0);
    }
};