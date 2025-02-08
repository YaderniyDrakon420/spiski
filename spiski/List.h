#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}
    ~List() { clear(); }

    void push_back(const T& value) {
        Node* new_node = new Node(value);
        if (tail) {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        else {
            head = tail = new_node;
        }
    }

    void push_front(const T& value) {
        Node* new_node = new Node(value);
        if (head) {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        else {
            head = tail = new_node;
        }
    }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void pop_back() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
        }
    }

    T& front() {
        return head ? head->data : *(new T());
    }

    T& back() {
        return tail ? tail->data : *(new T());
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    int find(const T& value) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    void erase(int position) {
        if (position < 0) return;

        Node* current = head;
        int index = 0;
        while (current) {
            if (index == position) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
            index++;
        }
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }
};

#endif 

