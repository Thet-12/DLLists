/*
 * DLL.cpp
 */
#ifndef DLL_H
#include "DLL.h"
#endif

DLL::DLL():HeadPtr{nullptr}
{

}

int DLL::isEmpty()
{
    return HeadPtr == nullptr;
}

int DLL::size()
{
    if(isEmpty())
        return 0;
    int count = 0;
    NodePtr cur = HeadPtr;
    while(cur != nullptr)
    {   count++;
        cur = cur->nextPtr;
    }
    return count;
}

int DLL::insert(int value,int position)
{
    if(position < 0)
        return -1;

    auto newPtr = (NodePtr)malloc(sizeof(Node));
    if(newPtr == nullptr)
        return -1;
    newPtr->prePtr = nullptr;
    newPtr->data = value;
    newPtr->nextPtr = nullptr;

    if(isEmpty())
    {   HeadPtr = newPtr;
        return 1;
    }

    NodePtr pre = nullptr;
    NodePtr cur = HeadPtr;
    int curpos = 0;
    while (cur != nullptr && curpos!=position)
    {   curpos++;
        pre = cur;
        cur = cur->nextPtr;
    }

    if(pre == nullptr)
    {   newPtr->nextPtr = HeadPtr;
        HeadPtr->prePtr = newPtr;
        HeadPtr = newPtr;
        return 1;
    }
    else if(cur == nullptr)
    {   pre->nextPtr = newPtr;
        newPtr->prePtr = pre;
        return 1;
    }
    pre->nextPtr = newPtr;
    newPtr->nextPtr = cur;
    cur->prePtr = newPtr;
    newPtr->prePtr = pre;
    return 1;
}

int DLL::delNode(int value)
{
    if(isEmpty())
        return 0;

    NodePtr pre = nullptr;
    NodePtr cur = HeadPtr;
    NodePtr nex = cur->nextPtr;

    while((nex != nullptr) && (value != cur->data))
    {   pre = cur;
        cur = nex;
        nex = nex->nextPtr;
    }
    if(value != cur->data)
        return 0;

    if(pre == nullptr)  // check whether value is in Head
    {   HeadPtr = nex;
        if(nex != nullptr)  // check whether there are others left
            nex->prePtr = nullptr;
    }
    else if(nex == nullptr) // check whether value is in tail
    {   pre->nextPtr = nullptr;
    }
    else
    {   pre->nextPtr = nex;
        nex->prePtr = pre;
    }

    free(cur);
    return 1;
}

int DLL::delAll()
{
    NodePtr cur;
    while(!isEmpty())
    {   cur = HeadPtr;
        HeadPtr = cur->nextPtr;
        if(HeadPtr != nullptr)
            HeadPtr->prePtr = nullptr;
        free(cur);
    }
    return 1;
}

void DLL::swap(NodePtr& N0,NodePtr& N1)
{
    NodePtr temp0pre = N0->prePtr;
    NodePtr temp0nex = N0->nextPtr;
    NodePtr temp1pre = N1->prePtr;
    NodePtr temp1nex = N1->nextPtr;

    N1->nextPtr = temp1pre;
    N0->prePtr = temp0nex;
    N0->nextPtr = temp1nex;
    N1->prePtr = temp0pre;

    if(temp0pre != nullptr) // eliminated for head
        temp0pre->nextPtr = N1;
    else
        HeadPtr = N1;   // assigned for head

    if(temp1nex != nullptr) // eliminated for tail
        temp1nex->prePtr = N0;
//////////////////// see documentation for more detail explanation ////////////////////
}

void DLL::BubbleSort(bool mode)
{
    int ListSize = size();
    if(ListSize < 2)
        return;
    bool flag = true;
    NodePtr cur, nex;
    while (flag)
    {   cur = HeadPtr;
        nex = cur->nextPtr;
        flag = false;
        while(nex != nullptr)   //inner loop checking for end
        {   if (mode ? (cur->data) > (nex->data) : (cur->data) < (nex->data))
            {   swap(cur,nex);
                flag = true;
                nex = cur->nextPtr;
                continue;
            }
            cur = nex;  // Assign next if there was no swap
            nex = nex->nextPtr;
        }
    }
}

void DLL::InsertSort(bool mode)
{
    int ListSize = size();
    if(ListSize < 2)
        return;
    NodePtr out_curPtr,in_curPtr,in_prePtr,temp_out_cur_nexPtr;
    out_curPtr = HeadPtr->nextPtr;
    while(out_curPtr != nullptr)
    {   in_curPtr = out_curPtr;
        in_prePtr = in_curPtr->prePtr;
        temp_out_cur_nexPtr = out_curPtr->nextPtr;
        while (in_curPtr->prePtr != nullptr)
        {
            if(!mode ? (in_prePtr->data) > (in_curPtr->data) : (in_prePtr->data) < (in_curPtr->data))
                break;
            swap(in_prePtr,in_curPtr);
            in_prePtr = in_curPtr->prePtr;
        }
        out_curPtr = temp_out_cur_nexPtr;
    }
}

void DLL::reverse()
{
    if(isEmpty())
        return;
    NodePtr cur = HeadPtr;
    NodePtr temp_pre;
    NodePtr temp_nex;
    while(cur != nullptr)
    {   temp_pre = cur->prePtr;
        temp_nex = cur->nextPtr;
        cur->prePtr = temp_nex;
        cur->nextPtr = temp_pre;
        HeadPtr = cur;
        cur = temp_nex;
    }
}

void DLL::shuffle()
{
    int ListSize = size();
    if(ListSize < 2)
        return;
    bool flag;
    NodePtr cur, nex;
    srand(time(nullptr));
    int loop = rand()%7;
    for(int i=0;i<loop;i++)
    {   cur = HeadPtr;
        nex = cur->nextPtr;
        flag = i%2;
        while(nex != nullptr)   //inner loop checking for end
        {   flag = !flag;
            if (flag)
            {   swap(cur,nex);
                nex = cur->nextPtr;
                continue;
            }
            cur = nex;  // Assign next if there was no swap
            nex = nex->nextPtr;
        }
    }
}

void DLL::printLists()
{
    if(isEmpty())
    {   printf("List is empty\n\n");
        return;
    }
    NodePtr cur = HeadPtr;
    printf("List values : ");
    while(cur != nullptr)
    {   printf("%d",cur->data);
        cur = cur->nextPtr;
        if(cur != nullptr)
            printf(" <-> ");
    }
    printf("\n\n");
}