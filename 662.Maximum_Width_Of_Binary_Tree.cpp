/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        long long int ans=0;
        queue<pair<TreeNode*,long long int>> q;//node and it's index
        q.push({root,1});
        while(!q.empty()){
            long long int leftmost,rightmost;
            int size=q.size();
            long long int ref=q.front().second;//reference variable to avoid overflow
            long long int index;//index variable
            for(int i=0;i<size;i++){
                 auto temp=q.front();
                index=temp.second-ref;//index of parent
                if(i==0){//if first element then leftmost
                    leftmost=index;
                }
                if(i==size-1){//if last then rightmost
                    rightmost=index;
                }
                if(temp.first->left!=NULL){
                    q.push({temp.first->left,2*index});//left child is 2i
                }
                if(temp.first->right!=NULL){
                    q.push({temp.first->right,2*index+1});//right child is 2i+1
                }
                q.pop();
            }
            ans=max(ans,rightmost-leftmost);
        }
        return ans+1;//since we're dealing with indexes
    }
};
