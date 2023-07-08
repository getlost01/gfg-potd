## 24. Prefix Match with Other Strings

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1)

### My Approach

To solve the problem, I have used the following approach:

- Check if the length of the prefix substring (`k`) is greater than the length of the given matching string (`str`). If it is, return 0 since no prefix matches are possible.
- Extract the prefix substring (`toSearch`) of length `k` from the given matching string `str`.
- Initialize a counter `c` to keep track of the number of strings in the array `arr` that have a matching prefix.
- Iterate through each string in the array `arr`. If the substring of length `k` from each string matches the `toSearch` string, increment the counter `c`.
- Finally, return the value of the counter `c`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n * k)`, where n is the number of strings in the array `arr` and `k` is the length of the prefix substring. We iterate through each string in the array and compare the substrings of length `k` with the `toSearch` string.
- **Auxiliary Space Complexity**: `O(1)` as we are not using any extra space that scales with the input.

### Code (C++)

```cpp
class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){
        if(k > str.size())
            return 0;
        
        string toSearch = str.substr(0, k);
        int c = 0;

        for(int i = 0; i < n; ++i){
            if(arr[i].substr(0, k) == toSearch)
                ++c;
        }

        return c;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.