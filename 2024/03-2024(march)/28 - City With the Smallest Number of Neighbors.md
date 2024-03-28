## 28. City With the Smallest Number of Neighbors at a Threshold Distance
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1)

### My Approach
- We solve this problem using Dijkstra's algorithm.
- We iterate over each city and find the count of cities that are reachable within the given threshold distance from that city using Dijkstra's algorithm.
- We keep track of the city with the smallest count of reachable cities and return it as the output.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O((N + M)logN)`, where N is the number of cities and M is the number of edges.
- **Auxiliary Space Complexity**: `O(N + M)`, where N is the number of cities and M is the number of edges.

### Code (C++)
```cpp
class Solution {
public:
    int dijkstra(int curr, int& n, int& distThreshold, vector<vector<pair<int, int>>>& graph) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> vis(n, 0);
        pq.push({0, curr});
        
        int cnt = 0;
        while (!pq.empty()) {
            int dist = pq.top().first; 
            int node = pq.top().second;
            pq.pop();
            
            if (vis[node]) 
                continue;
                
            vis[node] = 1;
            if (dist > distThreshold) 
                continue;
            ++cnt;
            
            for (auto itr : graph[node]) {
                int nodeDist = itr.first;
                int nextNode = itr.second;
                if (!vis[nextNode]) 
                    pq.push({dist + nodeDist, nextNode});
            }
        }
        return cnt;
    }
    
    int findCity(int n, int m, vector<vector<int>>& edges, int distThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto &itr : edges) {
            graph[itr[0]].push_back({itr[2], itr[1]});
            graph[itr[1]].push_back({itr[2], itr[0]});
        }
        
        int out = -1, nax = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cnt = dijkstra(i, n, distThreshold, graph);
            
            if (cnt <= nax) {
                nax = cnt;
                out = i;
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.