#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class DynamicMemoryAllocation {
private:
    Node* head;   

public:
    DynamicMemoryAllocation() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert_at_beginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element " << key << " found in the list." << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Element " << key << " not found in the list." << endl;
        return false;
    }

    void delete_node(int key) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << key << " deleted." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Element " << key << " not found in the list." << endl;
        } else {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            cout << "Node with value " << key << " deleted." << endl;
        }
    }
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "Linked List reversed successfully!" << endl;
    }
};
int main() {
    DynamicMemoryAllocation list;
    int choice, value, key;

    do {
        cout << "\n===== Linked List Menu =====" << endl;
        cout << "1. Append Node (at end)" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Insert at Beginning" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Delete Node" << endl;
        cout << "6. Reverse List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to append: ";
            cin >> value;
            list.append(value);
            break;
        case 2:
            list.display();
            break;
        case 3:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insert_at_beginning(value);
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> key;
            list.delete_node(key);
            break;
        case 6:
            list.reverse();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 0);

    return 0;
}
