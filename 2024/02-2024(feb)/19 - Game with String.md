## 19. Game with String
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/game-with-string4100/1)

### My Approach

The problem is about playing a game with a given string where the goal is to minimize the string's value. We count the frequency of each character in the string and repeatedly remove the most frequent character k times. Then, we calculate the sum of squares of the remaining frequencies, which represents the value of the resulting string.

- We first count the frequency of each character in the string using an unordered map.
- We use a priority queue to store the frequencies of characters. This allows us to easily remove the most frequent character each time.
- We repeatedly remove the most frequent character k times and update the priority queue accordingly.
- After the removal process, we calculate the value of the resulting string by summing the squares of the remaining frequencies.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the solution is `O(n + k log m)`, where n is the length of the string, k is the given integer, and m is the number of unique characters in the string. 
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(m)`, where m is the number of unique characters in the string, due to the usage of the unordered map and priority queue.

### Code (C++)

```cpp
class Solution {
public:
    int minValue(string s, int k){
        unordered_map<char,int> mp;
        for(auto i: s){
            ++mp[i];
        }
        
        priority_queue<int> pq;
        for(auto i: mp)
            pq.push(i.second);
        
        while(k--){
            int t = pq.top();
            pq.pop();
            --t;
            if(t) pq.push(t);
        }
        
        int out = 0;
        while(!pq.empty()){
            out += pq.top() * pq.top();
            pq.pop();
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.