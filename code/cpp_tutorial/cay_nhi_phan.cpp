//them node vao vi tri bat ki
#include<iostream>
using namespace std;

template<class T> class Node {
    public:
        Node<T>* left;
        Node<T>* right;
        T data;

        Node(T data){
            this->left = nullptr;
            this->right = nullptr;
            this->data = data;

        }
};

template<class T> class binarySearchTree{
    Node<T>* root;
    public:
        binarySearchTree(){
            root = nullptr;
        }
        void add(T value){
            root = add(root, value);
        }
        Node<T>* add(Node<T>* r, T value){
            if(r == nullptr){
                return new Node<T> (value);
            }
            if(value>= r->data){
                r->right = add(r->right, value);
            }
            else{
                r->left= add(r->left, value);
            }
            return r;
        }
        void inOrder(){
            inOrder(root);
            cout<<endl;
        }
        void inOrder(Node<T>* r){
            if(r!=nullptr){
                inOrder(r->left);
                cout<<r->data<<" ";
                inOrder(r->right);
            }
        }
};

int main(){
    binarySearchTree<string> tree;
    tree.add("nam");
    tree.add("hung");
    tree.add("tao");
    tree.add("truc");
    tree.add("nem");
    cout<<"=============\n";
    cout<<"danh sach cac node trong cay:\n";
    tree.inOrder();
    return 0;
}