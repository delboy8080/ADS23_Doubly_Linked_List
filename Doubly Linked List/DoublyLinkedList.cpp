#include <iostream>
#include "DList.h"

using namespace std;

void display(DList<int>& nums)
{
    DListIterator<int> it = nums.getIterator();
    while (it.isValid())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void displayReverse(DList<int> nums)
{
    DListIterator<int> it = nums.getIterator();
    it.end();
    while (it.isValid())
    {
        cout << *it << " ";
        it--;
    }
    cout << endl;
}
void removeDuplicates(DList<int>& nums)
{
    DListIterator<int> outer = nums.getIterator();
    while (outer.isValid())
    {
        DListIterator<int> inner(outer);
        inner++;
        while (inner.isValid())
        {
            if (*inner == *outer)
            {
                inner = nums.remove(inner);
            }
            else
            {
                inner++;
            }
        }
        outer++;
    }
}

DList<int> mergeSorted(DList<int>& n1, DList<int>& n2)
{
    DListIterator<int> n1Iter = n1.getIterator();
    DListIterator<int> n2Iter = n2.getIterator();
    DList<int> merged;
    while (n1Iter.isValid() || n2Iter.isValid())
    {
        if (!n1Iter.isValid())
        {
            merged.append(*n2Iter);
            n2Iter++;
        }
        else if (!n2Iter.isValid())
        {
            merged.append(*n1Iter);
            n1Iter++;
        }
        else if (*n1Iter < *n2Iter)
        {
            merged.append(*n1Iter);
            n1Iter++;
        }
        else
        {
            merged.append(*n2Iter);
            n2Iter++;
        }
    }
    return merged;
}


template <class T>
bool isPalindrome(DList<T>& n1)
{
    DListIterator<T> st = n1.getIterator();
    DListIterator<T> en = n1.getIterator();
    en.end();
    while (st.isValid() && en.isValid() && *st == *en)
    {
        st++;
        en--;
    }
    return (!st.isValid() && !en.isValid());
}


DList<int> reverseArray(int* arr, int size)
{
    DList<int> lst;
    for (int i = 0; i < size; i++)
    {
        lst.prepend(arr[i]);
    }
    return lst;
}

void swapPairs(DList<int>& nums)
{
    DListNode<int>* st = nums.head;
    while (st != nums.tail && st != 0)
    {
        DListNode<int>* a = st->previous;
        DListNode<int>* b = st;
        DListNode<int>* c = st->next;
        DListNode<int>* d = st->next->next;

        if (a != nullptr)
            a->next = c;
        c->previous = a;
        b->next = d;
        if (d != nullptr)
            d->previous = b;
        b->previous = c;
        c->next = b;
        if (b == nums.head)
            nums.head = c;
        if (c == nums.tail)
            nums.tail = b;
        st = d;

    }
}

int main()
{
    DList<int> nums1;
    for (int x = 1; x <= 7; x++)
    {
        for (int i = 0; i < x; i++)
        {
            nums1.append(x);
        }
    }
    display(nums1);
    removeDuplicates(nums1);
    display(nums1);

    DList<int> nums2;
    for (int x = 1; x <= 5; x++)
    {
        nums2.append(x);
    }

    DList<int> merged = mergeSorted(nums1, nums2);
    display(merged);

    string words[] = { "navan", "derek", "racecar" };
    for (int i = 0; i < 3; i++)
    {
        DList<char> w;
        for (int x = 0; x < words[i].size(); x++)
        {
            w.append(words[i][x]);
        }
        cout << words[i] << ": " << (isPalindrome(w) ? "Yes" : "No") << endl;
    }

    int* arr = new int[6] {1, 5, 9, 7, 8, 3};
    DList<int> rev = reverseArray(arr, 6);
    display(rev);
    swapPairs(rev);
    display(rev);


    return 0;
}

