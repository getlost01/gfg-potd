## GFG Problem Of The Day

### Today - 05 March 2024
### Que - Maximum Index
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1)

### My Approach
- Initialize the answer (ans) variable to -1, representing the maximum difference of indices.
- Create two arrays (lmin and rmax) to store the minimum values on the left and maximum values on the right for each element.
- Calculate the minimum values on the left (lmin) using a loop and store them in the array.
- Calculate the maximum values on the right (rmax) using a loop and store them in the array.
- Initialize two pointers (i and j) to iterate through the arrays.
- While both pointers are within the array bounds:
  - Compare the minimum on the left (lmin[i]) and maximum on the right (rmax[j]).
  - If lmin[i] is less than rmax[j], update the answer (ans) with the maximum difference of indices (j - i), and increment j.
  - Otherwise, increment i.
- Return the final answer.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where N is the size of the array.
- **Auxiliary Space Complexity**: `O(N)`, two additional arrays of size N (lmin and rmax) are used.

### Code (C++)
```cpp
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        if (n==1)
            return 0;
        int ans=-1;
        int lmin[n];
        int rmax[n];
        lmin[0]=a[0];
        for (int i=1;i<n;i++)
        {
            lmin[i]=min(lmin[i-1], a[i]);
        }
        rmax[n-1]=a[n-1];
        for (int j=n-2;j>=0;j--)
        {
            rmax[j]=max(rmax[j+1], a[j]);
        }
        int i=0, j=0;
        while (i<n && j<n)
        {
            if (lmin[i]<=rmax[j])
            {
                ans=max(ans, j-i);
                j++;
            }
            else i++;
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

