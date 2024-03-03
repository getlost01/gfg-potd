## 03. Largest Number formed from an Array
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1)

### My Approach
- Define a custom comparison function func that compares two strings a and b based on their concatenation in different orders (a + b vs. b + a).
- The goal is to arrange the strings in a way that concatenating them results in the largest possible number.
- Use the sort function to sort the array of strings (arr) in descending order based on the custom comparison function func.
- This step ensures that the strings are arranged to form the largest number when concatenated.
- Concatenate the sorted strings to form the final result.
- Return the concatenated string as the output.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(NlogN)`, where N is the number of strings in the array.
- **Auxiliary Space Complexity**: `O(N)`, where N is the number of strings in the array.

### Code (C++)
```cpp
bool func(string a, string b)
{
    return a+b > b+a;
}
class Solution{
public:
	string printLargest(int n, vector<string> &arr)
	{
	      sort(arr.begin(), arr.end(), func);
        string result;
        for (const string &s : arr)
            result+=s;
        return result;
	}
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
