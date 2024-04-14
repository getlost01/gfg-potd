## GFG Problem Of The Day

### Today - 14 April 2024
### Que - Xoring and Clearing

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/xoring-and-clearing/1)

### My Approach

- For printArr function:
  - Iterate through the array from index 0 to n-1.
  - Print each element of the array followed by a space.
  - Print a newline character after printing all elements.

- For setToZero function:
  - Iterate through the array from index 0 to n-1.
  - Set each element in the array to zero using direct assignment.
 
- For xor1ToN function:
  - Iterate through the array from index 0 to n-1.
  - For each element at index i, perform a bitwise XOR operation with i.
  - Update the element in the array with the result of the XOR operation.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the size of the array.
- **Auxiliary Space Complexity**: O(1) - No extra space is used; the space complexity remains constant.

### Code (C++)

```cpp
class Solution {
  public:
    void printArr(int n, int arr[])
    {
        // Your code for printing array here
        for (int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    void setToZero(int n, int arr[])
    {
        // Use memset to set arr to zero
        for (int i=0;i<n;i++)
            arr[i]=0;
    }

    void xor1ToN(int n, int arr[])
    {
        // Xor arr[i]^i
        for (int i=0;i<n;i++)
            arr[i]^=i;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

