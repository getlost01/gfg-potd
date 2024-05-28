## 28. Minimum cost to fill given weight in a bag
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1)

### My Approach
- Use dynamic programming to find the minimum cost to buy exactly w kg of oranges.
- Maintain two arrays: prev and curr, both of size (w+1), to store the minimum costs for different weights.
- Initialize both arrays with a large value except for prev[0] and curr[0] which are set to 0.
- Iterate through each packet size from 1 to n and update the curr array for each weight from 0 to w:
  - If the current packet size i is available (cost[i-1] != -1) and i is less than or equal to the current weight k, calculate the cost of taking i kg packet plus the cost for the remaining weight k - i.
  - Otherwise, set the cost of taking i kg packet as a large value to indicate it's not possible.
  - Update the curr[k] with the minimum cost between taking and not taking the current packet size i.
- Update prev with curr after each iteration.
- Return -1 if it's impossible to buy exactly w kg of oranges, otherwise return the minimum cost stored in prev[w].

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N*W)`
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(W)`.

### Code (C++)

```cpp
class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost)
    {
        vector<int> prev(w+1, 1e8);
        vector<int> curr(w+1, 1e8);
        prev[0]=curr[0]=0;
        for(int i=1;i<=n;i++)
        {
            curr[0]=0;
            for(int k=0;k<=w;k++)
            {
                int nontake=prev[k];
                int take=1e8;
                if(cost[i-1]!=-1 && i<=k)
                    take=cost[i-1]+curr[k-i];
                curr[k]=min(take, nontake);
            }
            prev=curr;
        }
        return prev[w]==1e8 ? -1 : prev[w];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
