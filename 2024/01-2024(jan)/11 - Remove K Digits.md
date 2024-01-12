## 11. Remove K Digits
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-k-digits/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
- Initialize a pair last with values {0, K}, where last.first represents the index and last.second represents the remaining removal count.
- Iterate through the string S:
  - Skip leading zeros and update the last pair accordingly.
  - Decrement K until it becomes zero or no more leading zeros are encountered.
  - Break out of the loop if K becomes zero.
- Create a stack num to store the digits of the final number.
- Set the starting index as last.first and update K from last.second.
- Iterate through the remaining characters of the string:
  - While the stack is not empty, the top element is greater than the current digit, and there are still removals (K), pop elements from the stack.
  - Push the current digit onto the stack.
- Pop any remaining elements from the stack based on the remaining removals (K).
- Construct the final result string by popping elements from the stack and reversing it.
- If the result is an empty string, set it to "0".
- Return the final result.

### Time and Auxiliary Space Complexity
- **Time Complexity**: `O(N)`, where n is the length of the input string
- **Auxiliary Space Complexity**: `O(N)`, where n is the length of the input string

### Code (C++)
```cpp
string removeKdigits(string S, int K)
    {
        pair<int, int> last={0, K};
        int n=S.size();
        int index=0;
        while(index < n)
        {
            if(S[index] != '0')
            {
                if(K)
                    --K;
                else break;
                index++;
            }
            else
            {
                while(index<n and S[index]=='0')
                    index++;
                last={index, K};
            }
        }
        stack<int>num;
        int start=last.first;
        K=last.second;
        for(int i = start; i < n; i++
        {
            while(num.size() and num.top()>(S[i]-'0') and K)
            {
                K--;
                num.pop();
            }
            
            num.push(S[i]-'0');
        }
        
        while(num.size() and K--)
            num.pop();
        string ans="";
        while(num.size())
        {
            ans+=to_string(num.top());
            num.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans=="")
            ans="0";
        return ans;
    }
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
