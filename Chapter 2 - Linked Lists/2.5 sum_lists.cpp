#include <bits/stdc++.h>
using namespace std;
int carry = 0;
template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class LinkedList
{
  private:
    int size;
    struct node<T> *start;

  public:
    LinkedList()
    {
        size = 0;
        start = NULL;
    }
    struct node<T> *create_node(const T value)
    {
        struct node<T> *temp = new (struct node<T>);
        temp->next = NULL;
        temp->data = value;
        return temp;
    }
    void insert_begin(const T value)
    {
        struct node<T> *temp = create_node(value);
        temp->next = start;
        start = temp;
        size++;
    }
    void insert(const T value)
    {
        struct node<T> *temp = start;
        if (temp != NULL)
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = create_node(value);
            size++;
        }
        else
        {
            insert_begin(value);
        }
    }
    int Size()
    {
        return size;
    }
    struct node<T> *getStart()
    {
        return start;
    }
};
LinkedList<int> sum_lists(LinkedList<int> l1, LinkedList<int> l2) //617 stored as 7->1->6
{
    int carry = 0, n;
    LinkedList<int> ll;
    struct node<int> *p1 = l1.getStart(), *p2 = l2.getStart();
    while (p1 != NULL && p2 != NULL)
    {
        n = (p1->data) + (p2->data) + carry;
        if (n > 9)
        {
            carry = 1;
            n -= 10;
        }
        else
            carry = 0;
        ll.insert(n);
        p1 = p1->next;
        p2 = p2->next;
    }
    p1 = (p1 != NULL ? p1 : p2);
    while (p1 != NULL)
    {
        n = (p1->data) + carry;
        if (n > 9)
        {
            carry = 1;
            n -= 10;
        }
        else
            carry = 0;
        ll.insert(n);
        p1 = p1->next;
    }
    return ll;
}
void add_recursive(struct node<int> *p1, struct node<int> *p2, LinkedList<int> *ll)
{
    if (p1->next != NULL)
        add_recursive(p1->next, p2->next, ll);
    int n = (p1->data) + (p2->data) + carry;
    if (n > 9)
    {
        carry = 1;
        n -= 10;
    }
    else
        carry = 0;
    ll->insert_begin(n);
}
LinkedList<int> sum_reversed_lists(LinkedList<int> l1, LinkedList<int> l2) //617 stored as 6->1->7
{
    int s1 = l1.Size(), s2 = l2.Size();
    if (s1 == 0)
        return l2;
    if (s2 == 0)
        return l1;
    while (s1 > s2)
    {
        l2.insert_begin(0);
        s2++;
    }
    while (s2 > s1)
    {
        l1.insert_begin(0);
        s1++;
    }
    LinkedList<int> ll;
    add_recursive(l1.getStart(), l2.getStart(), &ll);
    return ll;
}
int main()
{
    LinkedList<int> l1;
    LinkedList<int> l2;
    LinkedList<int> ll;
    l1.insert(7);
    l1.insert(1);
    l1.insert(6);
    l2.insert(5);
    l2.insert(9);
    l2.insert(2);
    ll = sum_lists(l1, l2);
    struct node<int> *temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
    LinkedList<int> l3;
    LinkedList<int> l4;
    l3.insert(6);
    l3.insert(1);
    l3.insert(7);
    l4.insert(2);
    l4.insert(9);
    l4.insert(5);
    cout << "\nAdding reversed (follow up)\n";
    ll = sum_reversed_lists(l3, l4);
    for (temp = ll.getStart(); temp != NULL; temp = temp->next)
        cout << temp->data << " ";
}