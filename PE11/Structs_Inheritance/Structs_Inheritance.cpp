// Structs_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Armor.h"
#include "Shield.h"
#include "Spear.h"
#include "Necklace.h"
using namespace std;

int main()
{
    // Create a vector "list" item.
    vector<Item*> inventory;

    // Create all four items.
    Item* weapon = new Spear("Spear Of The Spirit", 12.0, 0.70);
    Item* armour = new Armor("Armor Of Righteousness", 5.0, 2.1);
    Item* shield = new Shield("Shield of Trust", 2.0, 1.5);
    Item* necklace = new Necklace("Necklace Of Salvation", 1.5, 0.25);

    // Add item to the vector list.
    inventory.push_back(weapon);
    inventory.push_back(armour);
    inventory.push_back(shield);
    inventory.push_back(necklace);

    // Use a foreach loop to print our all items.
    for (Item* item : inventory)
    {
        item->print();
        cout << "------------------" << endl;
    }

    // Delete all the Items in the inventory.
    for (Item* item : inventory)
    {
        delete item;
    }

    // Dump any memory leaks left.
    _CrtDumpMemoryLeaks();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
