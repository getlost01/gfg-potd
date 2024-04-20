## 20. Union of Two Sorted Arrays
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1)

### My Approach
- Initialize two pointers, p1 and p2, to traverse arr1 and arr2 respectively. Also, initialize an empty vector vec to store the union.
- While both p1 and p2 are within their respective array bounds:
  - Compare the elements at arr1[p1] and arr2[p2].
  - If arr1[p1] is less than arr2[p2], add arr1[p1] to the union vector if it's not already present.
  - If arr1[p1] is greater than arr2[p2], add arr2[p2] to the union vector if it's not already present.
  - If both elements are equal, add either one to the union vector if it's not already present, and move both pointers.
  - Increment the pointers accordingly.
- After the above process, there might be remaining elements in either arr1 or arr2.
- Traverse any remaining elements in arr1 and arr2, adding them to the union vector if they're not already present.
- Return the vector vec containing the union of the two arrays.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n + m)`, where `n` is the size of array arr1 and `m` is the size of array arr2.
- **Auxiliary Space Complexity**: `O(n + m)`, where `n` is the size of array arr1 and `m` is the size of array arr2.

### Code (C++)
```cpp
class Solution
{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int>vec;
        int p1=0, p2=0;
        while (p1<n && p2<m)
        {
            if (arr1[p1]<arr2[p2])
            {
                if (vec.empty() || vec.back()!=arr1[p1])
                    vec.push_back(arr1[p1]);
                p1++;
            }
            else if (arr1[p1]>arr2[p2])
            {
                if (vec.empty() || vec.back()!=arr2[p2])
                    vec.push_back(arr2[p2]);
                p2++;
            }
            else
            {
                if (vec.empty() || vec.back()!=arr1[p1])
                    vec.push_back(arr1[p1]);
                p1++;
                p2++;
            }
        }
        while (p1 < n)
        {
            if (vec.empty() || vec.back()!=arr1[p1])
                vec.push_back(arr1[p1]);
            p1++;
        }
        while (p2 < m)
        {
            if (vec.empty() || vec.back()!=arr2[p2])
                vec.push_back(arr2[p2]);
            p2++;
        }
        return vec;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
