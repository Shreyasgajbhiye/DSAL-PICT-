#include<iostream>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node *right;
    node *left;

    node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
node* buildTree(node* root){
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter the left chid of " << data << endl;
    root->left = buildTree(root->left); // calls buildTree with parameter NULL

    cout << "Enter tjhe right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){  
        node* temp = q.front(); 
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1