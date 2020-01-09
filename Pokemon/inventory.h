#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>

class item;

class Inventory
{
public:
    Inventory(int size);

    std::vector<item> vec;

    void FindItem(const char symbol);
    void RemoveItem();

    item& GetReqItem();

};

#endif // INVENTORY_H
