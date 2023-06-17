# GFG Problem Of The Day

## Today - 17 June 2023
### Que - Queue Operations

[Question Link](https://practice.geeksforgeeks.org/problems/queue-operations/1)


### My approach 1
- To find the frequency of a given number `k` in the queue, you can iterate over all the elements in the queue and count the occurrences of `k`.

#### Time Complexity
`O(1)` for `insert()` function and `O(n)` for `findFrequency` function.

### Code (c++) 
```
class Solution{
    public:
    
    void insert(queue<int> &q, int k){
        q.push(k);
    }
    
    
    int findFrequency(queue<int> &q, int k){
        int sz = q.size();
        int c = 0;
        while(sz--){
            if(q.front() == k)
                ++c;
            q.push(q.front());
            q.pop();
        }
        return c;
    }
    
};
```

### My approach 2
- To find the frequency of a given number `k` in the queue, you can use a map or hash structure to store the frequency of each element in the queue. Then, you can return the frequency of `k` from the map and return it.

#### Time Complexity
`O(logn)` for `insert()` function and `O(logn)` for `findFrequency` function.

### Code (c++) 
```
class Solution{
    public:
    
    map<int,int> hash;
    void insert(queue<int> &q, int k){
        ++hash[k];
        q.push(k);
    }
    
    
    int findFrequency(queue<int> &q, int k){
        return hash[k];
    }
    
};
```

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)