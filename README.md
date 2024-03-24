## GFG Problem Of The Day

### Today - 24 March 2024
### Que - Insert an Element at the Bottom of a Stack
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1)

### My Approach
- Create a temporary stack to store elements.
- Pop all elements from the original stack and push them into the temporary stack. This reverses the order of elements.
- Push the new element 'x' into the original stack.
- Pop all elements from the temporary stack and push them back into the original stack. This restores the original order of elements with the new element inserted at the bottom.

### Time and Auxiliary Space Complexity
- **Time Complexity**: The time complexity of this approach is `O(N)`, where 'N' is the number of elements in the stack.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N)`, where 'N' is the number of elements in the stack.

### Code (C++)
```cpp
class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x)
    {
        stack<int>temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return st;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

