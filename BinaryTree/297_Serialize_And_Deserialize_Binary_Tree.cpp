// LeetCode 297 - Serialize and Deserialize Binary Tree

// Difficulty: Hard

// Approach:

// 1. Use **Preorder Traversal (DFS)** to serialize the binary tree.
// 2. During serialization:

//    * Store each node's value.
//    * Use a special marker (such as `"N"`) for `NULL` nodes.
// 3. Join the serialized values into a single string.
// 4. To deserialize:

//    * Split the serialized string into tokens.
//    * Read the tokens one by one in preorder.
//    * Create a tree node for valid values.
//    * Return `NULL` whenever the null marker is encountered.
// 5. Recursively reconstruct the left and right subtrees.
// 6. Return the reconstructed root.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * n = number of nodes in the tree.
// * Every node is visited exactly once during serialization and deserialization.



class Codec {
public:

    void preorder(TreeNode* root, string &s){

        if(root==NULL){

            s+="N,";
            return;
        }

        s+=to_string(root->val)+",";

        preorder(root->left,s);

        preorder(root->right,s);
    }

    string serialize(TreeNode* root) {

        string s="";

        preorder(root,s);

        return s;
    }

    TreeNode* build(vector<string>&nodes,int &index){

        if(nodes[index]=="N"){

            index++;
            return NULL;
        }

        TreeNode* root=new TreeNode(stoi(nodes[index]));

        index++;

        root->left=build(nodes,index);

        root->right=build(nodes,index);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;

        string temp="";

        for(char c:data){

            if(c==','){

                nodes.push_back(temp);

                temp="";
            }
            else{

                temp+=c;
            }
        }

        int index=0;

        return build(nodes,index);
    }
};