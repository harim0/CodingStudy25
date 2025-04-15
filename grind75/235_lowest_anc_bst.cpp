// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=nullptr){
            if(p->val < root->val && q->val < root->val) root = root->left;  
            else if(p->val > root->val && q->val > root->val) root = root->right;
            else return root; 
        }
        return nullptr;
    }
};

TreeNode* buildTree(const vector<int>& vals){
    if (vals.empty()) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while(!q.empty()&&i<vals.size()){
        TreeNode* curr = q.front(); q.pop();
        if(vals[i]!=-1) {
            curr->left = new TreeNode(vals[i]);
            q.push(curr->left);
        }
        i++;
        if(i<vals.size()&&vals[i]!=-1){
            curr->right = new TreeNode(vals[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main(){
    Solution sol;
    vector<int> v = {6,2,8,0,4,7,9,-1,-1,3,5};
    TreeNode* root = buildTree(v);

    TreeNode* p = root->left;  
    TreeNode* q = root->right;

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "LCA: " << (lca ? lca->val : -1) << endl;
}