/*
 * DLL.h
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define Descending  false
#define Ascending   true

struct node
{   struct node* prePtr;
    int data;
    struct node* nextPtr;
};
typedef struct node Node;
typedef struct node* NodePtr;

class DLL
{
private:
    NodePtr HeadPtr;

public:
    explicit DLL();
    int isEmpty();
    int size();
    int insert(int value,int position = 999);
    int delNode(int value);
    int delAll();
    void swap(NodePtr& N0,NodePtr& N1);
    void BubbleSort(bool mode);
    void InsertSort(bool mode);
    void reverse();
    void shuffle();
    void printLists();
};