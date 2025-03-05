#include <stdio.h>

#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node* next;
  Node(int value) {
    this->value = value;
    this->next = NULL;
  }
};

class LinkedList {
private:
  Node* head;
  Node* tail;
  int length;

public:
  LinkedList(int value) {
    Node* newNode = new Node(value);
    this->head = newNode;
    this->tail = newNode;
    this->length = 1;
  }

  void append(int value) {
    Node* newNode = new Node(value);
    if (this->length == 0) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }
    this->length++;
  }

  void printList() {
    Node* temp = this->head;
    while (temp) {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }

  void getHead() { cout << "Head: " << this->head->value << endl; }

  void getTail() { cout << "Tail: " << this->tail->value << endl; }

  void getLength() { cout << "Length: " << this->length << endl; }

  ~LinkedList() {
    Node* temp = this->head;
    while (this->head) {
      head = head->next;
      delete temp;
      temp = this->head;
    }
  }
};

int main() {
  LinkedList* myLinkedList = new LinkedList(10);

  myLinkedList->append(5);
  myLinkedList->append(16);
  myLinkedList->printList();

  return 0;
}