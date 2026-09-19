class Solution {
public:
    
    // Find minimum node in a subtree
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // Node not found
        if (root == nullptr) {
            return nullptr;
        }
        
        // Search in left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        
        // Search in right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        
        // Node found
        else {
            
            // Case 1: No left child
            if (root->left == nullptr) {
                return root->right;
            }
            
            // Case 2: No right child
            if (root->right == nullptr) {
                return root->left;
            }
            
            // Case 3: Two children
            TreeNode* successor = findMin(root->right);
            
            root->val = successor->val;
            
            root->right = deleteNode(root->right, successor->val);
        }
        
        return root;
    }
};