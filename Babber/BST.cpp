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

node* createNode(node* &root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data){
        root->right = createNode(root->right, data);
    }
    else{
        root->left = createNode(root->left, data);
    }
    
    return root;
}

void takeInput(node* &root){
    int d;
    cin >> d;
    while(d != -1){
        root = createNode(root, d);
        cin >> d;
    }
}

void display(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty()){
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

void inorder(node* &root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node* &root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* &root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}
int main()
{
    node* root = NULL;
    cout << "Enter data for root : \n";
    takeInput(root);
    //display(root);
    inorder(root);
    return 0;
}