#include<vector>
#include<string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> ans;
        dfs(root,path,ans);
        return ans;
    }

    void dfs(TreeNode* root, string &path, vector<string> &ans){
        if(path.empty()) path.push_back(root->val);
        else path.append("->"+root->val);
        if  (!root->left && !root->right){
            ans.push_back(path);
            return;
        }
        if (root->left) dfs(root->left,path,ans);
        if (root->right) dfs(root->right,path,ans);
        if (path.size() > 1) {
            path.pop_back();
            path.pop_back();
            path.pop_back();
        }
    }
};