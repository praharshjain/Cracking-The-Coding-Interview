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
    void partition(T pivot)
    {
        LinkedList less, more;
        struct node<T> *temp = start, *curr = NULL;
        for (; temp != NULL; temp = temp->next)
        {
            if (temp->data < pivot)
                less.insert(temp->data);
            else
                more.insert(temp->data);
        }
        temp = less.getStart();
        if (temp != NULL)
        {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = more.getStart();
            start = less.getStart();
        }
        else
            start = more.getStart();
    }
    struct node<T> *getStart()
    {
        return start;
    }
};
int main()
{
    LinkedList<int> ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(6);
    ll.insert(2);
    ll.insert(0);
    ll.insert(1);
    struct node<int> *temp = ll.getStart();
    cout << "\nOriginal list\n";
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
    cout << "\n";
    ll.partition(2);
    cout << "\nAfter partitioning\n";
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
}