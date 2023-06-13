// Link - https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1
// Find k-th smallest element in given n ranges

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        vector<int> out,querySearch;
        sort(range.begin(),range.end());
        vector<vector<int>> newRange;
        newRange.push_back(range[0]);
        for(int i = 1;i<range.size();++i){
            if(newRange.back()[1]<range[i][0]){
                newRange.push_back(range[i]);
            }else{
                newRange.back()[1] = max(range[i][1],newRange.back()[1]);
                newRange.back()[0] = min(range[i][0],newRange.back()[0]);
            }
        }
        
        querySearch.push_back(newRange[0][1]-newRange[0][0]+1);
        for(int i=1; i<newRange.size(); ++i) querySearch.push_back(querySearch[i-1]+newRange[i][1]-newRange[i][0]+1);


        for(auto i: queries){
            auto it = lower_bound(querySearch.begin(),querySearch.end(),i)-querySearch.begin();
            // cout<<it<<endl;
            if(it>=newRange.size()) out.push_back(-1);
            else
            out.push_back(newRange[it][1]-(querySearch[it]-i));
        }
        return out;
    } 
};