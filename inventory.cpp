#include <iostream>
#include <vector>
#include <string>
#include "inventory.h"

using namespace std;


Inventory::Inventory() 
{  
}


/* struct Item definition */
Inventory::Item::Item() 
{  
}

Inventory::Item::Item(string name, int quantity)
  :
    name(name), quantity(quantity)
{ 
}
/* end of Item definition */


void Inventory::Update(string item, int amount) {
  int size = inventory.size();
  for (int i = 0; i < size; i++) {
    if (inventory[i].name.compare(item) == 0) {
      inventory[i].quantity += amount;
      return;
    }
  }
  Item newItem = Item(item, amount);
  inventory.push_back(newItem);
}

void Inventory::SortByName(int start, int end) {
  int i = start, j = end;
  Item tmp;
  Item pivot = inventory[(start + end) / 2];
  /* partition */
  while (i <= j) {
     while (inventory[i].name.compare(pivot.name) < 0) {
       i++;
     }
     while (inventory[j].name.compare(pivot.name) > 0) {
       j--;
     }
     if (i <= j) {
           tmp = inventory[i];
           inventory[i] = inventory[j];
           inventory[j] = tmp;
           i++;
           j--;
     }
  }
  /* recursion */
  if (start < j)
        SortByName(start, j);
  if (i < end)
        SortByName(i, end);
}

void Inventory::SortByQuantity(int start, int end) {
  int i = start, j = end;
  Item tmp;
  Item pivot = inventory[(start + end) / 2];
  /* partition */
  while (i <= j) {
     while (inventory[i].quantity < pivot.quantity) {
       i++;
     }
     while (inventory[j].quantity > pivot.quantity) {
       j--;
     }
     if (i <= j) {
           tmp = inventory[i];
           inventory[i] = inventory[j];
           inventory[j] = tmp;
           i++;
           j--;
     }
  }
  /* recursion */
  if (start < j)
        SortByQuantity(start, j);
  if (i < end)
        SortByQuantity(i, end);
}



void Inventory::ListByName() {
  int size = inventory.size();
  if (size == 0) {
    return;
  }
  SortByName(0, size-1);
  for (int i = 0; i < size; i ++ ){ 
    cout << inventory[i].name << " : " << inventory[i].quantity << endl;
  }
}

void Inventory::ListByQuantity() {
  int size = inventory.size();
  if (size == 0) {
    return;
  }
  SortByQuantity(0, size-1);
  for (int i = 0; i < size; i ++ ){ 
    cout << inventory[i].name << " : " << inventory[i].quantity << endl;
  }
}
