## GFG Problem Of The Day

### Today - 18 April 2024
### Que - Count Pairs in an Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1)

### My Approach
To solve this simple traverse the array, mark elements as negative to indicate their presence.
- If an element is already negative, it means it's a repeated element. Add it to the output vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(n)
- **Auxiliary Space Complexity**: O(1)

### Code (C++)

```cpp
class Solution {
public:
    vector<int> twoRepeated(int arr[], int n) {
        vector<int> out;
        for (int i = 0; i < n + 2; ++i) {
            if (arr[abs(arr[i])] > 0)
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            else
                out.push_back(abs(arr[i]));
        }
        return out;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

