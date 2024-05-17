## GFG Problem Of The Day

### Today - 17 May 2024
### Que - Find Pair Given Difference
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1)

### My Approach
- The input array arr is sorted to facilitate the two-pointer technique.
- Use two pointers low and high. Initialize low to 0 and high to 1.
- Use a while loop to traverse the array with the condition low < n and high < n.
- If the absolute difference between the elements at high and low is equal to x, return 1 (indicating a pair is found).
- If the absolute difference is less than x, increment the high pointer to increase the difference.
- If the absolute difference is greater than x, increment the low pointer to decrease the difference.
- If no such pair is found by the end of the loop, return -1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(NlogN)`, where N is the number of elements in the array.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int low=0, high=1;
        while (low<n && high<n)
        {
            if (abs(arr[high]-arr[low])==x)
                return 1;
            else if (abs(arr[high]-arr[low])<x)
                high++;
            else low++;
        }
        return -1;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

