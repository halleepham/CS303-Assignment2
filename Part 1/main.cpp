#include "singleLinkedList.h"

//ASSUMPTIONS: assume that the data items of the nodes are ONLY INTEGERS

int main() {
  cout << "Creating a new single linked list: \n\n";
  Single_Linked_List list1;
  int choice = -1;
  int input1;
  size_t input2;
  Item_Type temp;

  //FOR THE GRADER: this is the menu to choose which function you want to do (enter any integer 0-10)
    cout << "What would you like to do with the list?:" << endl;
    cout << "\t1 - Add an item to the front (push_front())\n";
    cout << "\t2 - Add an item to the end (push_back())\n";
    cout << "\t3 - Remove the first item (pop_front())\n";
    cout << "\t4 - Remove the last item (pop_back())\n";
    cout << "\t5 - Get the first item (front())\n";
    cout << "\t6 - Get the last item (back())\n";
    cout << "\t7 - See if the list is empty (empty())\n";
    cout << "\t8 - Insert an item anywhere in the list (insert())\n";
    cout << "\t9 - Remove an item anywhere in the list (remove())\n";
    cout << "\t10 - Find an item in the list (find())\n";
    cout << "\t0 - Quit the program\n\n\n";

  while(choice != 0){

    //Asks user for which option they would like to choose
    cout << "--> ";
    cin >> choice;
    cout << endl;
  
    switch (choice){
      //push_front() function
      case 1:
        cout << "What item would you like to add to the front? --> ";
        cin >> input1;
        temp.num = input1;
        list1.push_front(temp);
        break;
      //push_back() function
      case 2:
        cout << "What item would you like to add to the end? --> ";
        cin >> input1;
        Item_Type temp;
        temp.num = input1;
        list1.push_back(temp);
        break;
      //pop_front() function
      case 3:
        cout << "Removing first item\n";
        list1.pop_front();
        break;
      //pop_back() function
      case 4:
        cout << "Removing last item\n";
        list1.pop_back();
        break;
      //front() function
      case 5:
        cout << "Getting the first item...\n";
        //HALLEE: print front
        cout << "First item: " << list1.front().num << endl;
        break;
      //back() function
      case 6:
        cout << "Getting the last item...\n";
        //HALLEE: print back
        cout << "Last item: " << list1.back().num << endl;
        break;
      //empty() function
      case 7:
        cout << "Checking if list is empty...\n";
        if (list1.empty() == true){
          cout << "The list is empty\n\n";
        }
        else{
          cout << "The list is NOT empty\n";
        }
        break;
      //insert() function
      case 8:
        cout << "What item would you like to insert? --> ";
        cin >> input1;
        temp.num = input1;
        cout << "\nAt what index would you like to insert the item? --> ";
        cin >> input2;
        cout << "\n\nAdding the item " << input1 << " at index " << input2 << "...\n\n";
        list1.insert(input2, temp);
        break;
      //remove() function
      case 9:
        cout << "At what index of the list would you like to remove the item from? --> ";
        cin >> input2;
        cout << "Deleting item at index " << input2 << "...\n\n";
        list1.remove(input2);
        break;
      //find() function
      case 10:
        cout << "What item would you like to find in the list? --> ";
        cin >> input1;
        temp.num = input1;
        cout << "Finding item \"" << input1 << "\" in the list...\n\n";
        cout << list1.find(temp) << endl;
        break;
      //ending the program
      case 0:
        cout << "Goodbye!\n\n";
        exit(1);
    }
    cout << "\tPrinting list: \n\t";
    list1.printList();
    
    cout << "Choose another option from the menu\n";
    
  }
}