#include <iostream>
#include <stack>
using namespace std;

/**
 * TreeNode structure
 * having attribute:
 * val:     hold the value of tree.
 * left:   hold the address left side of tree.
 * right:  hold the address right side of tree.
 */
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    /*Parameterized Constructor*/
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

/**
 * Create the BST and return the rootNode.
 */
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }

    /*Inserting into left side of tree.*/
    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

/**
 * Inorder traversal of BST in iterative-way.
 */
void inorderTraversalInIterative(TreeNode *root)
{
    stack<TreeNode *> st;
    if (root != NULL)
        st.push(root);

    while (st.size() > 0)
    {
        if (st.top()->left != NULL)
            st.push(st.top()->left);
        else if (st.top()->right != NULL)
        {
            cout << st.top()->val << "\t";
            TreeNode *temp = st.top()->right;
            st.pop();
            st.push(temp);
        }
        else
        {
            cout << st.top()->val << "\t";
            st.pop();
        }
    }
}

/**
 * Printing the element of BST inorder traversal using recursion.
 */
void inorderTraversalInRecursive(TreeNode *root)
{
    if (root == NULL)
        return;

    inorderTraversalInRecursive(root->left);
    cout << root->val << "\t";
    inorderTraversalInRecursive(root->right);
}

/**
 * Main Function
 */
int main()
{
    TreeNode *root = NULL;
    int n;
    cout << "Enter how much you want enter elment: ";
    cin >> n;
    cout << "\nNow, enter element in tree: ";
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        root = insertIntoBST(root, num);
    }

    cout << "Print element in Inorder....\n";
    
    inorderTraversalInRecursive(root);
    inorderTraversalInIterative(root);
    return 0;
}