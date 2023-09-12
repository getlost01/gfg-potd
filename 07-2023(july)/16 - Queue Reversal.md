## 16. Queue Reversal

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/queue-reversal/1)

### My Approach

#### Aproach-1 (Using rescusive stack)
To reverse a queue, we can use a recursive approach.
- We'll use a helper function called `reverse` that pops the front element from the queue and recursively calls itself until the queue is empty. 
- Then, we push the popped element back into the queue. This process continues until all elements are reversed.

#### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the `reverse` function is `O(n)`, where n is the number of elements in the queue.
- **Auxiliary Space Complexity**: `O(n)` as we use recursion and the call stack to reverse the queue.

#### Code (C++)

```cpp
class Solution
{
public:
    void reverse(queue<int>& q)
    {
        if (!q.empty())
        {
            int temp = q.front();
            q.pop();
            reverse(q);
            q.push(temp);
        }
    }

    queue<int> rev(queue<int> q)
    {
        reverse(q);
        return q;
    }
};
```

#### Approach-2 (Using STL stack)

To reverse a queue, we can use a stack. We iterate through the input queue and push each element onto the stack. Then, we pop elements from the stack and enqueue them back into the original queue. 

- Create an empty stack and iterate through the input queue and push each element of the queue onto the stack.
- Pop elements from the stack and enqueue them back into the queue.

#### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the number of elements in the queue.
- **Auxiliary Space Complexity**: `O(n)`, where n is the number of elements in the queue.

#### Code (C++)

```cpp
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;

        while (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }

        return q;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.