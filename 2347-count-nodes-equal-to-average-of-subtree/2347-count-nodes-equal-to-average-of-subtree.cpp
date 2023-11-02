/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int totalCount;
    pair<int,int> solve(TreeNode* root){
        if(root == NULL)
            return {0,0};
        auto left = solve(root->left);
        int ls = left.first;
        int lc = left.second;
        auto right = solve(root->right);
        int rs = right.first;
        int rc = right.second;

        int sum = root->val + ls + rs;
        int count = lc + rc + 1;
        if(root->val == sum/count)
            totalCount++;

        return {sum,count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        totalCount = 0;
        solve(root);
        return totalCount;
    }
};