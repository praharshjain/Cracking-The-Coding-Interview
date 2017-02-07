#include <iostream>
using namespace std;
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
    struct node<T> *start;

  public:
    LinkedList()
    {
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
    }
    void insert(const T value)
    {
        struct node<T> *temp = start;
        if (temp != NULL)
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = create_node(value);
        }
        else
        {
            insert_begin(value);
        }
    }
    struct node<T> *getStart()
    {
        return start;
    }
};
template <class T>
struct node<T> *intersecting_node(LinkedList<T> l1, LinkedList<T> l2)
{
    struct node<T> *p1 = l1.getStart(), *p2 = l2.getStart();
    if (p1 == NULL || p2 == NULL)
        return NULL;
    int n1 = 1, n2 = 1;
    for (; p1->next != NULL; p1 = p1->next)
        n1++;
    for (; p2->next != NULL; p2 = p2->next)
        n2++;
    if (p1 == p2) //intersection exists
    {
        p1 = l1.getStart();
        p2 = l2.getStart();
        while (n1 > n2)
        {
            p1 = p1->next;
            n2++;
        }
        while (n2 > n1)
        {
            p2 = p2->next;
            n1++;
        }
        while (p1 != NULL)
        {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return NULL;
}
int main()
{
    LinkedList<int> l1, l2;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l2.insert(10);
    struct node<int> *p1 = l1.getStart(), *p2 = l2.getStart(), *temp = NULL;
    p1 = p1->next;
    p1 = p1->next;
    p1 = p1->next; //p1 now points to 4
    p2->next = p1; //creating intersection
    temp = intersecting_node(l1, l2);
    if (temp != NULL)
        cout << "\nThe lists intersect at " << temp->data << "\n";
}