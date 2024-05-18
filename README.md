## GFG Problem Of The Day

### Today - 18 May 2024
### Que - Find the Highest number
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1)

### My Approach
- Initialize size as the size of the input vector a.
- Set low to 0 and high to size - 1.
- Enter a while loop that continues as long as low <= high.
- Calculate mid as (low + high) / 2.
- If a[mid] is greater than a[mid-1] and a[mid+1], return a[mid].
- If a[mid] is greater than a[mid-1] but less than a[mid+1], set low to mid + 1.
- Otherwise, set high to mid - 1.
- If no peak element is found, return a[size - 1].

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(logN)`, where N is the number of elements in the array.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int size=a.size();
        int low=0, high=size-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (a[mid]>a[mid-1] && a[mid]>a[mid+1])
                return a[mid];
            else if (a[mid]>a[mid-1] && a[mid]<a[mid+1])
                low=mid+1;
            else high=mid-1;
        }
        return a[size-1];
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

