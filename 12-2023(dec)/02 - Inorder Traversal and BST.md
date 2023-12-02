## 02. Inorder Traversal and BST
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/inorder-traversal-and-bst5855/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
Since it is a BST, its inorder traversal should always be a sorted array, hence the code just checks if the array is sorted or not

- Iterates through the array.
- Checks if each element is less than its immediate successor.
- Returns 1 if the entire array satisfies the condition, otherwise returns 0.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N), where N is the number elements in the array
- **Auxiliary Space Complexity**: O(1), as no extra space is used.

### Code (C++)
```cpp
class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        for (int i=0;i<N-1;i++)
        {
            if (arr[i]<arr[i+1])
                continue;
            else return 0;
        }
        return 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
