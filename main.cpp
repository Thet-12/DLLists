/*
 * Doubly Links Lists
 * main.cpp
 * Author : Thet Nyi Hmue
*/
#include <iostream>
#include <conio.h>
#include "DLL.h"

int main() {
    DLL DUT{};
    printf("Before Inserting any Lists\n");
    DUT.printLists();

    DUT.insert(0,0);
    DUT.insert(2,1);
    DUT.insert(9,2);
    DUT.insert(5,3);
    DUT.insert(8,2);
    DUT.insert(56);
    DUT.insert(25);
    DUT.insert(12);
    DUT.insert(16);
    DUT.insert(35);
    DUT.insert(45);
    DUT.insert(38);
    DUT.insert(15);
    DUT.insert(35);
    DUT.insert(29);
    printf("After Inserting Lists\n");
    DUT.printLists();

    printf("After Shuffling\n");
    DUT.shuffle();
    DUT.printLists();

    printf("Bubble Sort (Descending Mode)\n");
    DUT.BubbleSort(Descending);
    DUT.printLists();

    printf("Insert Sort (Ascending Mode)\n");
    DUT.InsertSort(Ascending);
    DUT.printLists();

    DUT.delNode(0);
    printf("After Deleting Head\n");
    DUT.printLists();

    printf("After Shuffling\n");
    DUT.shuffle();
    DUT.printLists();

    printf("After Reversing Lists\n");
    DUT.reverse();
    DUT.printLists();

    printf("The size of Lists is : %d\n\n", DUT.size());

    DUT.delAll();
    printf("After Deleting All Lists\n");
    DUT.printLists();
    return 0;
}