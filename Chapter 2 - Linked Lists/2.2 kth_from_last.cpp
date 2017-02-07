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
    struct node<T> *kth_from_last(int k) //by counting elements
    {
        if (k <= 0)
            return NULL;
        struct node<T> *temp = start;
        int count = 0;
        for (; temp != NULL; temp = temp->next)
            count++;
        count -= k;
        temp = start;
        for (int i = 0; i < count; i++)
            temp = temp->next;
        return temp;
    }
    struct node<T> *kth_from_last_two_pointer(int k) //by using two pointers
    {
        if (k <= 0)
            return NULL;
        struct node<T> *temp = start, *curr = start;
        for (int i = 0; i < k && temp != NULL; i++)
            temp = temp->next;
        for (; temp != NULL; temp = temp->next)
            curr = curr->next;
        return curr;
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
    cout << ll.kth_from_last(3)->data << "\n";
    cout << ll.kth_from_last_two_pointer(4)->data;
}