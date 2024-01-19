## GFG Problem Of The Day

### Today - 19 January 2024
### Que - Top k numbers in a stream
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/top-k-numbers3425/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### Question Issue
I think there may be an issue with today's question, as incorrect answers are being generated for some test cases.

Here's an example illustrating the problem:
```
Input: 
6 3
1 10 3 1 0 9

Your Output: 
1
1 10
1 3 10
1 3 10
0 3 10
3 9 10

Expected Output: 
1
1 10
1 3 10
1 3 10
1
1
```
```
For Input: 
4 5
3 4 0 0
Your Code's output is: 
3
3 4
0 3 4
0 3 4
It's Correct output is: 
3
3 4


```
Upon closer inspection, it seems that the constraints provided are as follows:

```
1 ≤ N ≤ 10^4
1 ≤ K ≤ 10^2
1 ≤ a[i] ≤ 10^2 
```

However, in the test case, they use `a[i]` with a value of `0`. This contradicts the given constraints. It's possible that the test case is not aligned with the specified constraints.

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

