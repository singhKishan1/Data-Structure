#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";

        string ans = to_string(root->val);
        string leftString = serialize(root->left);
        string rightString = serialize(root->right);

        if (leftString.size() > 0)
            ans += "," + leftString;

        if (rightString.size() > 0)
            ans += "," + rightString;

        return ans;
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }

    TreeNode *deserialize(string data)
    {
        data = "["+data+"]";
        TreeNode *root = NULL;
        string temp = "";
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] != ',' && data[i] != '[' && data[i] != ']')
                temp += data[i];
            else
            {
                if (temp.size() > 0)
                {
                    root = insertIntoBST(root, stoi(temp));
                }
                temp = "";
            }
        }

        return root;
    }
};
