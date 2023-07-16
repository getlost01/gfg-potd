## GFG Problem Of The Day

### 🎉 Announcement
I have created a Git Book that contains all previous editorials for my GFG-POTD solutions. You can visit **[here](https://gl01.gitbook.io/gfg-editorials/)** to access it and refer to my previous solutions. In the future, I intend to establish a contribution flow, where others can contribute their solutions to this Git Book. I would appreciate hearing your thoughts and views on this in the [discussion section](https://github.com/getlost01/gfg-potd/discussions).

----
### Today - 16 July 2023
### Que - Queue Reversal

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

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.


![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
