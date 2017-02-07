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
struct node<T> *begining_of_loop(LinkedList<T> ll)
{
    struct node<T> *slow = ll.getStart(), *fast = ll.getStart();
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) //meeting point
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    slow = ll.getStart(); //move slow to head of list
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
int main()
{
    LinkedList<int> ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);
    ll.insert(8);
    ll.insert(9);
    struct node<int> *temp = ll.getStart();
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = ll.getStart()->next->next; //creating loop at 3
    temp = begining_of_loop(ll);
    if (temp != NULL)
        cout << "\nThe loop starts at " << temp->data << "\n";
}