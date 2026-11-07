#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *l,*r;

    Node(int x) {
        data=x; l=r=NULL;
    }
};

Node* insert(Node *t,int x) {
    if(!t) return new Node(x);

    if(x<t->data) t->l=insert(t->l,x);
    else t->r=insert(t->r,x);

    return t;
}

void inorder(Node *t) {
    if(t) {
        inorder(t->l);
        cout<<t->data<<" ";
        inorder(t->r);
    }
}

void preorder(Node *t) {
    if(t) {
        cout<<t->data<<" ";
        preorder(t->l);
        preorder(t->r);
    }
}

void postorder(Node *t) {
    if(t) {
        postorder(t->l);
        postorder(t->r);
        cout<<t->data<<" ";
    }
}

int main() {
    Node *root=NULL;

    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);

    cout<<"Inorder: "; inorder(root);
    cout<<"\nPreorder: "; preorder(root);
    cout<<"\nPostorder: "; postorder(root);
}