#include "singleLinkedList.h"

    //Class constructor: creates an empty single linked list
    Single_Linked_List::Single_Linked_List(){
      head = NULL;
      tail = NULL;
      num_items = 0;
    }

    //PRE: takes in a data item
    //POST: Adds the node to the front of the list, if the list is originaly empty, add the item as the head and tail of the list
    void Single_Linked_List::push_front(const Item_Type& item){
      Node* newNode = new Node(item);
      //If list is NOT empty, then adds the new node the the front
      if(head != NULL){
        newNode->next = head;
        head = newNode;
        num_items++;
      }
      //If list IS empty, adds the node to the list as the new head and tail
      else{
        head = newNode;
        head->next = NULL;
        tail = newNode;
        num_items++;
      }
    }

    //PRE: takes in a data item
    //POST: Adds the node to the end of the list, if the list is empty, add the data item as the head and tail of the list
    void Single_Linked_List::push_back(const Item_Type& item){
      Node* newNode = new Node(item);
      //If list IS empty, all the new node as the new head and tail
      if(head == NULL){
        head = newNode;
        head->next = NULL;
        tail = newNode;
        num_items++;
      }
      //If list is NOT empty, add node to the end of the list
      else{
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
        num_items++;
      }
    }

    //PRE: takes in no arguments
    //POST: removes the first node of the list and assigns the head accordingly, if the list is empty, throw an error and stop the program
    void Single_Linked_List::pop_front(){
      try{
        //If list IS empty, throw and error
        if(head == NULL){
          throw runtime_error("List is empty\n");
        }
        //If list is NOT empty, delete the first item
        else{
          Node* delNode = head;
          head = head->next;
          delete delNode;
          num_items--;
        }
      }
      catch (runtime_error e){
        cout << e.what();
      }
    }

    //PRE: takes in no arguments
    //POST: removes the last node of the list and assigns the tail accordingly, if the list is empty, throw an error
    void Single_Linked_List::pop_back(){
      try{
        //If list IS empty, throw an error
        if(head == NULL){
          throw runtime_error("List is empty\n");
        }
        else if(head == tail){
          this->pop_front();
          num_items--;
        }
        //If list is NOT empty, delete the last item
        else{
          Node* temp = head;
           while(temp->next != tail){
             temp = temp->next;
           }
          tail = temp;
          temp = temp->next;
          delete temp;
          tail->next = NULL;
          num_items--;
        }
      }
      catch (runtime_error e){
        cout << e.what();
      }
    }

    //PRE: takes no arguments
    //POST: returns the first item of the list, if list is empty, throws an error and stops the program
    Item_Type& Single_Linked_List::front(){
      try{
        //If list is empty, throw error and stop program
        if(head == NULL){
          throw runtime_error("List is empty. Cannot return front item.\n");
        }
        else{
          return head->data;
        }
      }
      catch(runtime_error e){
        cout << e.what();
      }
    }

    //PRE: takes no arguments
    //POST: returns the last item of the list, if list is empty, throws an error and stops the program
    Item_Type& Single_Linked_List::back(){
      try{
      //If list is empty, throw error and stop program
      if(tail == NULL){
        throw runtime_error("List is empty. Cannot return back item.\n");
      }
      else{
        return tail->data;
      }
      }
      catch(runtime_error e){
        cout << e.what();
      }
    }

    //PRE: takes in no arguments
    //POST: checks if the list is empty. If empty return true, if not, return false
    bool Single_Linked_List::empty() const{
      if (head == NULL){
        return true;
      }
      else{
        return false;
      }
    }

    //PRE: takes in the index of where to insert, and the data item to be inserted at the index
    //POST: inserts the data item at the index given and redirects nodes accordingly. If the index given is beyond the scope of the list, adds the data item to the end of the list
    void Single_Linked_List::insert(size_t index, const Item_Type& item){
      //Checks if the index is a negative number
      try{
        if(index < 0){
          throw runtime_error("Invalid index. Exiting Program...");
        }
      }
      catch(runtime_error e){
        cout << e.what() << endl;
      }
      //Checks if user wants to insert at the beginning
      Node* newNode = new Node(item);
      if(index == 0){
        this->push_front(item);
        num_items++;
      }
      //checks if the the user wants to insert an item beyond the end of the list, if they do, then just adds to the end of the list
      else if(index >= num_items - 1){
        cout << "The index you entered is beyond the end of the list. Adding the the end of the list..." << endl;
        this->push_back(item);
        num_items++;
      }
      else{
        Node* tempNode = head;
        for (int i = 0; i < num_items; i++){
          if(i + 1 == index){
            newNode->next = tempNode->next;
            tempNode->next = newNode;
            num_items++;
            return;
          }
          else{
            tempNode = tempNode->next;
          }
        }
      }
    }

    //PRE: takes in an index of the data item to be removed
    //POST: If the remove was UNsuccessful, return false. If the remove was successful, removes the item and redirects nodes accordingly, and returns true.
    bool Single_Linked_List::remove(size_t index){
      //If list is empty, return false
      if(this->empty()){
        cout << "List is empty, cannot remove item." << endl;
        return false;
      }
      //If removing at index 0
      else if(index == 0){
        this->pop_front();
        num_items--;
        return true;
      }
      //If removing the last item
      else if(index == num_items - 1){
        this->pop_back();
        num_items--;
        return true;
      }
      //if element to remove is beyond the end of the list
      else if(index > num_items - 1){
        cout << "Index is beyond the end of the list\n";
        return false;
      }
      //Find element to delete
      Node* tempNode = head;
      for (int i = 0; i < num_items; i++){
        if(i + 1 == index){
          tempNode->next = tempNode->next->next;
          num_items--;
          return true;
        }
        else{
          tempNode = tempNode->next;
        }
      }
      return false;
    }

    //PRE: takes in the data item to be found
    //POST: if the data item is found, returns the the index of the node with the first occurence of the data item, if data item is NOT found, returns the size of the list
    size_t Single_Linked_List::find(const Item_Type& item){
      //Checks if list is empty
      if(head == NULL){
        cout << "Could not find item, returning size of list.\n";
        return num_items;
      }
      Node* tempNode = head;
      for (int i = 0; i < num_items - 1; i++){
        if(tempNode->data.num == item.num){
          return i;
        }
        else{
          tempNode = tempNode->next;
        }
      }
      cout << "Could not find item, returning size of list.\n";
      return num_items;
    }

    void Single_Linked_List::printList(){
      Node* tempPtr = head;
      while(tempPtr != NULL){
        cout << tempPtr->data.num << " -> ";
        tempPtr = tempPtr->next;
      }
      
      cout << endl << endl;
    }
  
    
    
