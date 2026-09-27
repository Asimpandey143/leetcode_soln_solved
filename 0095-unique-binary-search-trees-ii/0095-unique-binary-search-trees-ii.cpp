class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
    
private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> allTrees;
        
        // Base case: if start > end, there is no valid number to form a tree.
        // We push nullptr to represent an empty subtree so the loops below execute.
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }
        
        // Pick each number i as the root
        for (int i = start; i <= end; ++i) {
            // Recursively generate all possible left and right subtrees
            vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightTrees = buildTrees(i + 1, end);
            
            // Connect each combination of left and right subtrees to the root i
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* currentTree = new TreeNode(i);
                    currentTree->left = left;
                    currentTree->right = right;
                    allTrees.push_back(currentTree);
                }
            }
        }
        
        return allTrees;
    }
};