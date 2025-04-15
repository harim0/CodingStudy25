// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/description/

#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int checkHeight(TreeNode* node) {
        if (node==nullptr) return 0;

        int left = checkHeight(node->left);
        if (left==-1) return -1; 

        int right = checkHeight(node->right);
        if (right==-1) return -1; 
        if (abs(left-right) > 1) return -1; 

        return max(left, right)+1; 
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root)!=-1;
    }
};

TreeNode* buildTree(const vector<int>& vals){
    if(vals.empty()) return nullptr;

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

    cout << "bal: " << sol.isBalanced(root) << endl;
}