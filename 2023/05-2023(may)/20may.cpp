class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        priority_queue<int, vector<int>, greater<int>> que;
        if(N%groupSize) return false;
        int it;
        for(auto i: hand){
            que.push(i);
        }
        int last = -1;
        for(int i = 0;i<N/groupSize;++i){
            last = que.top();
            que.pop();
            it = groupSize-1;
            vector<int> extra;
            // cout<<last<<endl;
            while(it>0 && !que.empty()){
                // cout<<que.top()<<" ";
                if(que.top() == last){
                    extra.push_back(que.top());
                    que.pop();
                }else if(que.top() == last+1){
                    que.pop();
                    ++last;
                    --it;
                }else{
                    return false;
                }
            }
            if(it != 0) return false;
            for(auto i: extra) que.push(i);
        }
        return true;
    }
};