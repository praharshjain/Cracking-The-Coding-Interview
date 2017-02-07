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
    void reverse()
    {
        if (start != NULL && start->next != NULL)
        {
            struct node<T> *p1 = NULL, *curr = start, *p2 = start->next;
            while (p2 != NULL)
            {
                curr->next = p1;
                p1 = curr;
                curr = p2;
                p2 = p2->next;
            }
            curr->next = p1;
            start = curr;
        }
    }
    struct node<T> *getStart()
    {
        return start;
    }
};
template <class T>
bool is_equal(LinkedList<T> l1, LinkedList<T> l2)
{
    struct node<T> *p1 = l1.getStart(), *p2 = l2.getStart();

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data != p2->data)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1 == NULL && p2 == NULL;
}
template <class T>
bool is_palindrome(LinkedList<T> l1)
{
    LinkedList<T> l2;
    struct node<T> *temp = l1.getStart();
    while (temp != NULL)
    {
        l2.insert_begin(temp->data);
        temp = temp->next;
    }
    return is_equal(l1, l2);
}
int main()
{
    LinkedList<int> ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    cout << is_palindrome(ll) << "\n";
    ll.insert(10);
    cout << is_palindrome(ll) << "\n";
    ll.insert_begin(10);
    cout << is_palindrome(ll) << "\n";
}