/****************************
 * 
 * Check if a tree is a BST, brute force method
 * 
******************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

    
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        // we want to compare val of current node with the 
        //largest number of its left tree
        int maxOfLeft = root->val;
        if (root->left){
            maxOfLeft = root->left->val;
            TreeNode* temp = root->left->right;
            while (temp){
                maxOfLeft = temp->val;
                temp = temp->right;
            }
        }
        
        if (root->left && root->val <= maxOfLeft) return false;
        
        
        int minOfRight = root->val;
        if (root->right){
            minOfRight = root->right->val;
            TreeNode* temp = root->right->left;
            while(temp){
                minOfRight = temp->val;
                temp = temp ->left;
            }
        if (root->right && root->val >= minOfRight) return false;
        }
        //Above is to check if the current node satisfying BST
        
        //The folowing is to check if left node and right node satisfying BST
        if (!isValidBST(root->left) || !isValidBST(root->right)) return false;
        
        return true;
        
        
        
    }
