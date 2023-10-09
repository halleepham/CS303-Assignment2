#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Item_Type{
  int num;
};

struct Node{
  Item_Type data;
  Node* next;
  Node(const Item_Type& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}
};

class Single_Linked_List {
  private:
    Node* head = NULL;
    Node* tail = NULL;
    int num_items;
  public:
    Single_Linked_List();
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type& front();
    Item_Type& back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
    void printList();
    
    

};