// Link - https://practice.geeksforgeeks.org/problems/cutting-binary-string1342/1
// Cutting Binary String

class Solution{
    public:
    
    int cuts(string s){
        //code
        vector<long long int> pre(23);
        long long int temp = 1;
        pre[0] = 1;
        for(int i = 1;i<=22;++i){
            temp*=5;
            pre[i] = temp;
        }
        temp = 0;
        for(auto i: s){
            temp *=2;
            if(i == '1')
                temp +=1;
        }
        int it = lower_bound(pre.begin(),pre.end(),temp)-pre.begin();
        if(pre[it] == temp) return 1;
        int c = 0;
        while(--it>=0){
            string check = "";
            temp = pre[it];
            while(temp){
                check += (char)('0'+temp%2);
                temp = temp/2;
            }
            reverse(check.begin(),check.end());
            
            for(int i = 0;i<=s.size()-check.size();++i){
                if(s[i] == '1'){
                    int j = 0;
                    for(j = 0;j<check.size();++j){
                        if(check[j] != s[i+j]) break;
                    }
                    if(j == check.size()){
                        for(j = 0;j<check.size();++j){
                            s[i+j] = '9';
                        }                       
                        i += j-1;
                        ++c;
                        // cout<<s<<endl;
                    }
                    
                }
            }
        }
        for(auto i: s) {if(i == '0') c = -1;}
        if(c == 0) c = -1;
        return c;
        
    }
};