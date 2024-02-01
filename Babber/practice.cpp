#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node* createNode(node* root){
    int data;
    cout << "Enter the data " <<endl;
    cin >> data;

    root = new node(data);
    if(data == -1){
        return NULL;
    }

    cout << "Enter the node for left of " << data << endl;
    root->left = createNode(root->left);
    cout << "Enter the node for right of " << data << endl;
    root->right = createNode(root->right);

    return root;
}

void display(node* root){
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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node* root = NULL;
    root = createNode(root);
    //display(root);
    inorder(root);
    return 0;
}