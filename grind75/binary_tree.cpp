// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root){
        if(root==NULL) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
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

// Helper to print tree (level-order)
void printTree(TreeNode* root){
    if(!root){
        cout << "[]\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front(); q.pop();
        if(curr){
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> vals = {4, 2, 7, 1, 3, 6, 9};
    TreeNode* root = buildTree(vals);

    cout << "Original Tree: ";
    printTree(root);

    TreeNode* inverted = sol.invertTree(root);

    cout << "Inverted Tree: ";
    printTree(inverted);

    return 0;
}