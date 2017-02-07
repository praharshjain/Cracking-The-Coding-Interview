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
    void delete_middle_node(struct node<T> *temp) //should not be the first or last node
    {
        if (temp == start || temp == NULL || temp->next == NULL)
            return;
        else
        {
            struct node<T> *curr = temp->next;
            temp->data = curr->data;
            temp->next = curr->next;
            delete curr;
        }
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
    temp = ll.getStart();
    temp = temp->next;
    ll.delete_middle_node(temp); //delete 2
    cout << "\nAfter deletion\n";
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
}