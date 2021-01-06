class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *cur = root;
        TreeNode *node = new TreeNode(val);
        while (cur) {
            if (cur -> val > val) {
                if (cur -> left) {
                    cur = cur -> left;
                } else {
                    cur -> left = node;
                    break;
                }
            } else {
                if (cur -> right) {
                    cur = cur -> right;
                } else {
                    cur -> right = node;
                    break;
                }
            }
        }
        if(root){
            return root;
        }
        return node;
    }
};
