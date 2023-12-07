// root =
// [1,null,2,null,3,null,4,null,5,null,6]
// Output
// "1(2()(3()(4()(5()(6)))))"
// Expected
// "1()(2()(3()(4()(5()(6)))))"        failed test case 

/* code for failed test case 
class Solution {
public:
    void subtree(TreeNode* &root, string &subString){
        if(root == NULL){
            return;
        }
        subString += "(" + to_string(root->val);
        if(root->left == NULL && root->right != NULL) subString += "()";
        subtree(root->left, subString);
        subtree(root->right, subString);
        subString += ")";
    }
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string res = to_string(root->val);
        string leftString = "", rightString = "";
        subtree(root->left, leftString); //for left sub tree 
        subtree(root->right, rightString); // for right sub tree
        res += leftString+rightString;
        return res;
    }
};
*/

/*
The difference that can observed is that for left part we create parentheses even when there is no left child, but for right part we create parentheses only when there is right child.
*/
class Solution {
public:
    void subtree(TreeNode* &root, string &subString){
        if(root == NULL){
            return;
        }
        subString += "(" + to_string(root->val);
        if(root->left == NULL && root->right != NULL) subString += "()";
        subtree(root->left, subString);
        subtree(root->right, subString);
        subString += ")";
    }
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string res = to_string(root->val);
        string leftString = "", rightString = "";
        if(root->left == NULL && root->right != NULL) res += "()";
        subtree(root->left, leftString); //for left sub tree 
        subtree(root->right, rightString); // for right sub tree
        res += leftString+rightString;
        return res;
    }
};

// cleaner version of code
class Solution {
public:
    string tree2str(TreeNode* root) {
		string ans = to_string(root->val);
		if (root->left) //left side check
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) { //right side check
			if (!root->left) ans += "()"; //left side not present, but right side present
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
	}
};