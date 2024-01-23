## 23. Course Schedule
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/course-schedule/1)

### My Approach
I am using a topological sorting approach to find the order of courses. The idea is to first create a directed graph representing the prerequisite relationships between courses. Then, I calculate the in-degree (number of incoming edges) for each course. Starting with the courses that have no prerequisites (in-degre e = 0), I use a queue to perform a topological sort.

- **Creating the Graph**
  - I create an array of vectors to represent the graph, where `graph[i]` contains the courses that depend on course `i`.
  - I also maintain an array `degree` to store the in-degree of each course.
- **Topological Sort**
  - I initialize a queue with courses having no prerequisites (in-degree = 0).
  - While the queue is not empty, I dequeue a course, add it to the result, and reduce the in-degree of its dependent courses.
  - If any dependent course now has in-degree = 0, I enqueue it.
- **Validating the Result**
  - After the topological sort, I check if all courses have been included in the result. If not, it means there is a cycle, and the schedule is not possible.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n + m)`, where n is the number of courses and m is the number of prerequisites. Building the graph takes O(m) time, and the topological sort takes O(n + m) time.
- **Auxiliary Space Complexity**: `O(n)`, where n is the number of courses. This is used for the degree array and the queue.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) {
        vector<int> graph[n];
        vector<int> degree(n, 0);

        for (auto i : pre) {
            degree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (!degree[i])
                q.push(i);

        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);
            for (auto i : graph[front]) {
                degree[i]--;
                if (degree[i] == 0)
                    q.push(i);
            }
        }

        for (auto i : degree) {
            if (i >= 1)
                return {};
        }

        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
```