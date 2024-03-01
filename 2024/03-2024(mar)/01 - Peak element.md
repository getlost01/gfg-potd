## 1. Peak element
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/peak-element/1)

### My Approach
- If the array has only one element, return 0 (as it is the only element and satisfies the peak condition).
- Check if the first element is greater than or equal to the second element, return 0 if true.
- Check if the last element is greater than or equal to the second-to-last element, return n-1 if true.
- Iterate through the array from index 1 to n-2.
- For each element at index i, check if it is greater than or equal to both its adjacent elements (i-1 and i+1).
- If true, return the index i as it satisfies the peak condition.
- If no peak is found in the linear search, return 0 as a default value.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where N is the number of elements in the array.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)`.

### Code (C++)
```cpp
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        if (n==1)
            return 0;
        else if (arr[0]>=arr[1])
            return 0;
        else if (arr[n-1]>=arr[n-2])
            return n-1;
        else
        {
            for (int i=1;i<n-1;i++)
            {
                if ((arr[i]>=arr[i-1])&&(arr[i]>=arr[i+1]))
                    return i;
                else continue;
            }
        }
        return 0;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
