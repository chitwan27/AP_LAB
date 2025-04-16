#include<iostream>
using namespace std;

// SYMMETRIC TREE (LEETCODE 101)
// USING RECURSION - TC=O(N), SC=O(N)

bool isMirror(TreeNode * p, TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p == NULL && q != NULL)
    {
        return false;
    }
    else if (p != NULL && q == NULL)
    {
        return false;
    }
    bool left = isMirror(p->left, q->right);
    bool right = isMirror(p->right, q->left);
    bool value = p->val == q->val;
    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isSymmetric(TreeNode *root)
{
    return isMirror(root->left, root->right);
}