## 11. Recamans sequence

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/recamans-sequence4856/1)

### My Approach

- I used a set to keep track of the numbers already generated in the sequence.
- Starting with 0, I iteratively generate the next number in the sequence by either subtracting the current index or adding it, depending on whether the result is positive and not already in the set.
- I store each generated number in the set to ensure uniqueness.
- I repeat this process until I generate the required number of elements in the sequence.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n), where n is the number of elements required in the sequence. 
- **Auxiliary Space Complexity** : O(n), where n is the number of elements required in the sequence.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> recamanSequence(int n){
        vector<int> a(n+1,0);
        unordered_set<int> st;
        for(int i = 1; i <= n; ++i){
            if((a[i-1] - i) > 0 && st.find(a[i-1] - i) == st.end())
                a[i] = a[i-1] - i;
            else
                a[i] = a[i-1] + i;
            st.insert(a[i]);
        }
        return a;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.