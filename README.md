# GFG Problem Of The Day

## Today - 14 June 2023
### Que - Maximum Diamonds

[Question Link](https://practice.geeksforgeeks.org/problems/chinky-and-diamonds3340/1)


### My approach
This is a simple `greedy` problem where we have to maximize the number of diamonds in bags at each iteration (from `0` to `k`). We retrieve the maximum number of diamonds from a bag and then put back `half` of the diamonds into the same bag.

To find the maximum number of diamonds at any given moment, I utilize a `priority queue`. Firstly, I push all elements of the `a` array into the priority queue. Then, for `k` iterations, I execute a loop that retrieves the maximum element from the priority queue (which is at the top), removes it, and replaces it with the `halved` value.


#### Time Complexity
`O(k log n)`  where `n` & `k` are number of diamond bags and time in minutes respectively and `logn` for putting and popping operations in priority_queue.

### Code (c++)
```
class Solution {
  public:
    long long maxDiamonds(int a[], int n, int k) {
        priority_queue<int> pq;
        for(int i = 0 ; i<n ;++i)
            pq.push(a[i]);
            
        long long out = 0, pqTop;
        while(k--){
            pqTop = pq.top();
            pq.pop();
            out += pqTop;
            pq.push(pqTop/2);
        }
        return out;
    }
};
```

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
