#include<bits/stdc++.h>
using namespace std;

template <class T>
class Node {

public:
    T data;
    Node * left;
    Node * right;

    Node()  {
        this->left = NULL;
        this->right = NULL;
    }
    Node(T val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

template <class T>
class BinarySearchTree {

    Node <T>* root;

public:

    BinarySearchTree()    {
        this->root = new Node<T>();
    }

    BinarySearchTree(T data)    {
        this->root = new Node<T>(data);
    }

    void insertUtility(T data)   {
        root = insert(root,data);
    }

    Node<T>* insert(Node <T>* root,int data)
    {
        if(root == NULL)   { 
            root = new Node<T>(data);
            return root;
        }
        if(root->data < data)   {
            root->right = insert(root->right,data);
        }
        else if(root->data > data)  {
            root->left  = insert(root->left,data);
        }
        return root;
    }

    void deleteUtility(T data)   {

        root = deleteNode(root,data);

    }

    Node<T>* inordersuccessor(Node <T>*root)    {

        Node <T>* temp = root;
        if(temp == NULL)   return temp;
        while(temp->right != NULL)  {
            temp = temp->right;
        }
        return temp;
    }

    
    Node<T>* deleteNode(Node <T>* root,int data)
    {
        if(root == NULL)    {
            return root;
        }

        if(root->data < data)   {
            root->right = deleteNode(root->right,data);
        }
        else if(root->data > data)  {
            root->left = deleteNode(root->left,data);
        }
        else {
            if(root->left == NULL && root->right == NULL)   return NULL;
            else if(root->left == NULL) return root->right;
            else if(root->right == NULL)    return root->left;
            else {
                #
                root->left =  inordersuccessor(root->left);
            }
        }
        return root;
    }
    


    void inorder(Node<T> * root)   {
        
        if(root == NULL)
            return;

        inorder(root->left);
        cout << root->data << ' ';
        
        inorder(root->right);
    }

    void inorderUtility()   {

        inorder(root);
    }

    int height(Node<T> * root)
    {
        
        if(root == NULL)   return 0;
        return 1+max(height(root->left),height(root->right));

    }
    int heightUtility()    
    {

        return height(root);    
    }

    void view(Node <T>* root, char v, int level,int &cur)   {
        if(root == NULL)    {
            return; 
        }
        if(cur == level)    {
            cur++;
            cout << root->data << ' ';
        }
        if(v == 'L') {
            view(root->left,v,level+1,cur);
            view(root->right,v,level+1,cur);
        }
        else {
            view(root->right,v,level+1,cur);
            view(root->left,v,level+1,cur);
            
        }
        
    }
    void viewUtility(char v) {
        int cur = 0;
        view(root,v,0,cur);
    }


};

int main() 
{

    BinarySearchTree<int> root = BinarySearchTree<int>(5);
    root.insertUtility(3);
    root.insertUtility(4);
    root.insertUtility(5);
    root.insertUtility(6);
    root.insertUtility(1);
   
    root.insertUtility(8);
     root.insertUtility(7);
    root.insertUtility(9);
    root.insertUtility(10);
    
    int ht = root.heightUtility();
    cout << "Height of the BST is " << ht ;

    cout <<  endl << "Inorder of the BST is " ;
    root.inorderUtility();

    cout << endl << "Left view of the BST is ";
    root.viewUtility('L');

    cout << endl  << "Right view of th BST is ";;
    root.viewUtility('R');


}
