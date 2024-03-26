## 26. Additive sequence
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/additive-sequence/1)

### My Approach
This problem can be solved using simple logic of nested loops. We iterate through the string `s` and try to find the first two numbers that form a valid additive sequence. Once we find such a pair, we check if the rest of the string forms a valid additive sequence starting from the sum of the first two numbers. If we can successfully form a valid additive sequence, we return true; otherwise, we continue searching for other pairs of numbers.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n*n*n)` where n is the length of the input string `s`.
- **Auxiliary Space Complexity**: `O(1)` constant space complexity.

### Code (C++)

```cpp
class Solution {
    public:
    string mystery(string first, string second)
    {
        string res = "";
        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());
        int carry = 0;
        int i = 0;
        while(i < first.size() && i < second.size())
        {
            int x = first[i]-'0' + second[i]-'0' + carry;
            carry = x/10;
            x = x%10;
            res += to_string(x);
            i++;
        }
        while(i < first.size())
        {
            int x = first[i]-'0' + carry;
            carry = x/10;
            x = x%10;
            res += to_string(x);
            i++;
        }
        while(i < second.size())
        {
            int x = second[i]-'0' + carry;
            carry = x/10;
            x = x%10;
            res += to_string(x);
            i++;
        }
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
    bool isAdditiveSequence(string s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++)
        {
            for(int j = i+1; n -j -1 >= max(i+1,j-i); j++)
            {
                bool flag = true;
                string first = s.substr(0, i+1);
                string second = s.substr(i+1, j-i);
                int k = j+1;
                string sum;
                while(k < n)
                {
                    sum = mystery(first, second);
                    if(k + sum.size() > n || sum != s.substr(k, sum.size()))
                    {
                        flag = false;
                        break;
                    }
                    first = second;
                    second = sum;
                    k += sum.size();
                }
                if(flag) return true;
            }
        }
        return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
