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
#define D(x) cout << #x << " " << x << endl
#define ll long long

class Solution {
public:
    bool validateBSTAux(TreeNode* root, ll mini, ll maxi) {
        if(root == NULL) return true;
        int value = root -> val;
        if(value <= mini || value >= maxi) return false;
        bool leftSide = validateBSTAux(root -> left, mini, value);
        bool rightSide = validateBSTAux(root -> right, value, maxi);
        return leftSide && rightSide;
    }
    
    bool isValidBST(TreeNode* root) {
        return validateBSTAux(root, LONG_MIN, LONG_MAX);
    }
};
