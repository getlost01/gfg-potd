## GFG Problem Of The Day

### Today - 10 April 2024
### Que - Party of Couples
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/alone-in-couple5507/1)

### My Approach
- Initialize a variable ans to 0.
- Iterate through the array arr using a loop.
- For each element in the array, perform bitwise XOR operation with ans.
- After iterating through all elements, ans will contain the single element occurring only once in the array.
- Return ans.

### Time and Auxiliary Space Complexity
- **Time Complexity**: The time complexity of this approach is `O(N)`, where `N` is the number of elements in the array
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` because the algorithm uses a constant amount of extra space.

### Code (C++)
```cpp
class Solution{
    public:
    int findSingle(int n, int arr[])
    {
        int ans=0;
        for (int i=0;i<n;i++)
        {
            ans^=arr[i];
        }
        return ans;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

