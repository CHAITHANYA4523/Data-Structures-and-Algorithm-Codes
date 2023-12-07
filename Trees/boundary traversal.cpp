/*
Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

Part 1: Left Boundary of the tree (excluding the leaf nodes).
Part 2: All the leaf nodes travelled in the left to right direction.
Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.
*/
#include <bits/stdc++.h>
using namespace std;

bool isLeaf(TreeNode<int>* node) {
    return (node->left == NULL && node->right == NULL);
}

void leftBoundary(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL) return;
    if(!isLeaf(root)) ans.push_back(root->data);
    if(root->left) leftBoundary(root->left, ans);
    else if(root->right) leftBoundary(root->right, ans);
}

void addLeaves(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL) return;
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    } 
    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}

void rightBoundary(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL) return;
    if(root->right) rightBoundary(root->right, ans);
    else if(root->left) rightBoundary(root->left, ans);
    if(!isLeaf(root)) ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);
    leftBoundary(root->left, ans);
    addLeaves(root, ans);
    rightBoundary(root->right, ans);
    return ans;
}

/*
Time Complexity: O(N).
Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)
Space Complexity: O(N)
Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).
*/