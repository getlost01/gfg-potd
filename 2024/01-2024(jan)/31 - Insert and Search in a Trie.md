## 31. Insert and Search in a Trie
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1)

### My Approach
- For both `insert` and `search` functions, I'm using recursion to traverse the trie based on the characters of the input key.
- In the `insert` function, if a character node is not present in the current TrieNode, I create a new node for that character and continue the insertion.
- In the `search` function, I check for the existence of each character in the trie, and if the end of the key is reached and the current node is a leaf, I return true, indicating a successful search.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where N is the length of the key. In both `insert` and `search` functions, we visit each character of the key once.
- **Auxiliary Space Complexity** : `O(N)`, where N is the length of the key. The space complexity is determined by the recursion stack depth.

### Code (C++)
```cpp
class Solution {
public:
    void insert(struct TrieNode *root, string key) {
        if (key.size() == 0) {
            root->isLeaf = true;
            return;
        }

        if (root->children[key[0] - 'a'] != NULL)
            insert(root->children[key[0] - 'a'], key.substr(1));
        else {
            root->children[key[0] - 'a'] = new TrieNode();
            insert(root->children[key[0] - 'a'], key.substr(1));
        }
    }

    bool search(struct TrieNode *root, string key) {
        if (key.size() == 0 && root->isLeaf == true)
            return true;

        if (root->children[key[0] - 'a'] != NULL)
            return search(root->children[key[0] - 'a'], key.substr(1));
        else
            return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.