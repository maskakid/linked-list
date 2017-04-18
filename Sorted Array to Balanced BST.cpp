#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* Add(int d)
{
    TreeNode* x=(TreeNode*) malloc(sizeof(TreeNode));
    x->val=d;
    x->right=NULL;
    x->left=NULL;
    return x;
}

TreeNode* BST(vector<int>A, int st, int ed)
{
    if(st>ed) return NULL;
    int mid=(st+ed)/2;

    TreeNode* root=Add(A[mid]);

    root->left=BST(A, st, mid);

    root->right=BST(A,mid+1,ed);

    return root;
}

int main()
{

}
