#include <string>
#include <vector>
using namespace std;


#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
public:
	Inventory ();
	void Update (string item, int amount);
	void ListByName ();
	void ListByQuantity ();
	
private:
  struct Item {
    string name;
    int quantity;
    Item();
    Item(string name, int quantity);
  };
  
  vector<Item> inventory;
  void SortByName(int start, int end);
  void SortByQuantity(int start, int end);
  
  
};

#endif