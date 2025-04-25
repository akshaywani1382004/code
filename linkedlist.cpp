#include <iostream>
using namespace std;

class LinkedList {
    struct node {
        int val;
        node *ptr;
    };

    node *head;
    int eCount;

public:
    LinkedList() {
        head = NULL; 
        eCount = 0;
    }

    void displayLL() {
        if (head == NULL) {
            cout << "Linked List is Empty !!" << endl;
            return;
        }

        node *node1 = head;
        cout << "Linked List : { ";
        while (node1 != NULL) {
            cout << node1->val << " ";
            node1 = node1->ptr;
        }
        cout << "}" << endl;
    }

    void no_of_Nodes(){
        cout<<"Number of Nodes : "<<eCount<<endl;
    }

    void pushBack(int data) {
        node *temp = new node();
        temp->val = data;
        temp->ptr = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            node *curr = head;
            while (curr->ptr != NULL) {
                curr = curr->ptr;
            }
            curr->ptr = temp;
        }
        eCount++;
    }

    void pushFront(int data) {
        node *temp = new node();
        temp->val = data;
        temp->ptr = head;
        head = temp;
        eCount++;
    }

    void insert(int data, int pos) {
        if (pos == 0) {
            pushFront(data);
        }

        node *temp = new node();
        temp->val = data;
        temp->ptr = NULL;

        node *curr = head;
        for (int i = 0; i < pos - 1; i++) {
            if (curr == NULL) {
                cout << "Invalid position!" << endl;
                delete temp;
            }
            curr = curr->ptr;
        }

        temp->ptr = curr->ptr;
        curr->ptr = temp;
        eCount++;
    }

    void popFront() {
        if (head == NULL) {
            cout << "List is already empty!" << endl;
            return;
        }

        node *temp = head;
        head = head->ptr;
        delete temp;
        eCount--;
    }

    void popBack() {
        if (head == NULL) {
            cout << "List is already empty!" << endl;
            return;
        }

        if (head->ptr == NULL) {
            delete head;
            head = NULL;
        }

        node *temp = head;
        while (temp->ptr->ptr != NULL) {
            temp = temp->ptr;
        }

        delete temp->ptr;
        temp->ptr = NULL;
        eCount--;
    }

    void pop(int pos){
        if(pos == 0){
            node *curr = head;
            head = head->ptr;
            delete curr;
            // popFront();
        }
        else{
            node *curr = head;
            node *pre = NULL;
            for(int i = 0; i<pos && curr->ptr != NULL ; i++){
                pre = curr;
                curr = curr->ptr;
            }
            pre->ptr = curr->ptr;
            delete curr;
        }
        eCount--;
    }

    void deleteLinkedList(){
        node *temp = head;
        while(temp != NULL){
            head = head->ptr;
            delete temp;
            temp = head;
        }
        eCount = 0;
    }
};

int main() {
    LinkedList l1;
    l1.pushBack(45);
    l1.pushFront(20);
    l1.pushBack(40);
    l1.popBack();
    l1.insert(30,2);
    l1.pop(3);
    l1.insert(12,1);
    // l1.deleteLinkedList();
    l1.no_of_Nodes();
    l1.displayLL();
    return 0;
}
