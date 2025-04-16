#include <bits/stdc++.h>
using namespace std;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    ListNode *ans = new ListNode(-1);
    ListNode *ptr = ans;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            ptr->next = list1;
            ptr = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            ptr = list2;
            list2 = list2->next;
        }
    }
    if (list1 != NULL)
    {
        ptr->next = list1;
    }
    if (list2 != NULL)
    {
        ptr->next = list2;
    }
    return ans->next;
}