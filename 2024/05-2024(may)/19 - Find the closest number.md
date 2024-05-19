## 19. Find the closest number
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1)

### My Approach
- Check if k is greater than the largest element in arr, return the largest element.
- Check if k is less than the smallest element in arr, return the smallest element.
- Initialize low to 0 and high to n-1.
- Use binary search :
  - Calculate mid as low + (high - low) / 2.
  - If arr[mid] equals k, return arr[mid].
  - If arr[mid] is greater than k, set ans1 to the absolute difference between arr[mid] and k, adjust high.
  - If arr[mid] is less than k, set ans2 to the absolute difference between arr[mid] and k, adjust low.
- Compare ans1 and ans2, return the closest value between arr[high] and arr[low].

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(logN)`, where N is the number of elements in the array.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution{
    public:
    int findClosest( int n, int k, int arr[]) 
    { 
        if (k>arr[n-1])
            return arr[n-1];
        if (k<arr[0])
            return arr[0];
        int low=0, high=n-1, ans1, ans2, ans;
        while (low<=high)
        {
            int mid=low+((high-low)/2);
            if (arr[mid]==k)
                return arr[mid];
            else if (arr[mid]>k)
            {
                ans1=abs(arr[mid]-k);
                high=mid-1;
            }
            else
            {
                ans2=abs(arr[mid]-k);
                low=mid+1;
            }
        }
        if (ans1>ans2)
            ans=arr[high];
        else ans=arr[low];
        return ans;
    } 
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
