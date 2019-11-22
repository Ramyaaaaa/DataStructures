#include<bits/stdc++.h>
using namespace std;


template <class T>
class Node {

public:
    T data;
    Node *next;

    Node(T d)    
    {
        data = d;
        next = NULL;
    }
};

template <class T>
class LinkedList {
    Node<T>* head;

public:
    LinkedList(T data)    
    {
        head = new Node<T>(data);
    }

    void insert(T data,int pos)   {
        Node<T> * newNode = new Node<T>(data);
        Node<T> * temp = head;
        Node<T> * prev = NULL;
        pos--;
        while(pos--)    {
            prev = temp;
            temp = temp->next;
        }

        if(prev == NULL)    { // insertion at head
            newNode->next = head;
            head = newNode;
        }
        else    {
            prev->next = newNode;
            newNode->next = temp;
        }
    }

    void remove(int pos)   {
        Node<T> * temp = head;
        Node<T> * prev = NULL;
        if(pos == 1)    {
            head = head->next;
        }
        else    {
            pos--;
            while(pos--)    {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    void print()    {
        Node<T>* temp = this->head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse();

    void nthNodeFromLast(int n);
    void middle();
};

template<class  T>
void LinkedList<T>::nthNodeFromLast(int n)   {
    cout  << n<<"th noode from last -> ";
    Node<T> * temp1 = head;
    Node<T> * temp2 = head;
    while(n--)  {
        temp1 = temp1->next;
    }
    while(temp1 != NULL)    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout <<temp2->data << endl;
}

template<class T>
void LinkedList<T>::middle()    {
    Node<T>* slow = head;
    Node<T>* fast = head;   
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element -> "<< 
    slow->data << endl;
}
template<class T>
void LinkedList<T>::reverse() {

    Node<T> * prev = NULL;
    Node<T> * next = NULL;
    while(head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}
int main()  {

    // LinkedList<int> l = LinkedList<int>(3);
    // l.insert(2,2);
    // l.insert(1,3);
    // l.insert(4,1);
    // l.insert(6,1);
    // l.insert(7,6);
    // l.remove(6);
    // l.print();

    LinkedList<char> l = LinkedList<char>('c');
    l.insert('b',2);
    l.insert('a',3);
    l.nthNodeFromLast(2);
    l.middle();
    l.insert('d',1);
    l.insert('f',1);
    l.insert('g',6);
    l.print();
    l.nthNodeFromLast(4);
    l.nthNodeFromLast(1);
    l.middle();
    l.remove(1);
    l.middle();
    l.print();
    l.reverse();
    l.middle();
    l.print();
}