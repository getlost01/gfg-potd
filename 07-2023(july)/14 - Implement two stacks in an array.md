## 14. Implement two stacks in an array

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1)


### My Approach

The question is straightforward and involves implementing two stacks using the `starting` and `ending` of the array `arr`. The main operations required are push and pop for these two stacks. Therefore, you only need to complete these functions accordingly. Additionally, the question suggests the need to handle the underflow condition of the stack.

- For `push1`, we increment `top1` and store the element at the updated `top1` index of the array.
- For `push2`, we decrement `top2` and store the element at the updated `top2` index of the array.
- For `pop1`, we check if `top1` is -1 (indicating an empty stack). If it is, we return -1. Otherwise, we return the element at the `top1` index and decrement `top1`.
- For `pop2`, we check if `top2` is equal to `size` (indicating an empty stack). If it is, we return -1. Otherwise, we return the element at the `top2` index and increment `top2`.


**The visual representation illustrates the appearance of our stacks.**

<img width=320 src="https://github.com/getlost01/gfg-potd/assets/79409258/0a4288d6-14b5-4132-9a66-4b5e86ff749f" />

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity for all the operations (`push1`, `push2`, `pop1`, `pop2`) is `O(1)` because we are directly accessing the top elements and updating the pointers.
- **Auxiliary Space Complexity**: `O(1)`, Since we are not utilising any extra space.


### Code (C++)
```cpp
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
    
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x)
    {
        arr[++top1] = x;
    }
    
    void push2(int x)
    {
        arr[--top2] = x;
    }
    
    int pop1()
    {
        if (top1 == -1)
            return -1;
        return arr[top1--];
    }
    
    int pop2()
    {
        if (top2 == size)
            return -1;

        return arr[top2++];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.