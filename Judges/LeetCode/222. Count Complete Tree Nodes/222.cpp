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
#define ll long long
#define vb vector<bool>
#define D(x) cout << #x << " " << x << endl

class Solution {
public:
    vb toBinary(ll n) {
        vb ans;
        for(int i = 0; n > 0; ++i) {    
            ans.push_back(n % 2);
            n = n / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    ll getHeight(TreeNode* root) {
        if(root == NULL) return 0LL;
        return 1LL + getHeight(root -> left);
    }
    
    bool existElement(TreeNode* root, vb binary) {
        TreeNode *currNode = root;
        for(int i = 1; i < binary.size(); ++i) {
            if(binary[i]) currNode = currNode -> right;
            else currNode = currNode -> left;
        }
        return currNode != NULL;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        ll maxH = getHeight(root);
        ll bot = (ll)pow(2, maxH - 1), top = (int)pow(2, maxH) - 1;
        while(bot <= top) {
            int mid = (bot + top) / 2;
            vb binary = toBinary(mid);
            if(existElement(root, binary)) bot = mid + 1;
            else top = mid - 1;
        }
        return top;
    }
};
