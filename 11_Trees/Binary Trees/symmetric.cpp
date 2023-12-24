
// approach 1 (Recusive)
class Solution {
public:
    bool symCheck(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL || p->val != q->val) return false;
        return symCheck(p->left, q->right) && symCheck(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return symCheck(root->left, root->right);
    }
};

//approach 2 (Iterative)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        stack<TreeNode*> stack;
        stack.push(root->left);
        stack.push(root->right);
        while (!stack.empty()) {
            TreeNode* n1 = stack.top();
            stack.pop();
            TreeNode* n2 = stack.top();
            stack.pop();
            if (n1 == nullptr && n2 == nullptr) continue;
            if (n1 == nullptr || n2 == nullptr || n1->val != n2->val) return false;
            stack.push(n1->left);
            stack.push(n2->right);
            stack.push(n1->right);
            stack.push(n2->left);
        }
        return true;
    }
};

/*
Time complexity:The time complexity of the algorithm is O(n), where n is the number of nodes in the binary tree. We need to visit each node once to check if the tree is symmetric.
Space complexity:
The space complexity of the algorithm is O(h), where h is the height of the binary tree. In the worst case, the tree can be completely unbalanced, and the recursion stack can go as deep as the height of the tree.
*/