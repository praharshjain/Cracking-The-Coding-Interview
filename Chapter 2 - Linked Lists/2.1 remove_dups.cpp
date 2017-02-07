//C++11 support needed
#include <bits/stdc++.h>
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
    void remove_duplicates()
    {
        if (start == NULL || start->next == NULL)
            return;
        unordered_set<T> s;
        struct node<T> *temp = NULL, *curr = start;
        s.insert(curr->data);
        for (temp = curr->next; temp != NULL; temp = temp->next)
        {
            if (s.find(temp->data) == s.end())
            {
                s.insert(temp->data);
            }
            else
            {
                curr->next = temp->next;
                delete temp;
            }
            curr = temp;
        }
    }
    void remove_duplicates_without_buffer()
    {
        if (start == NULL || start->next == NULL)
            return;
        struct node<T> *temp = NULL, *curr = start;
        for (; curr != NULL; curr = curr->next)
        {
            for (temp = curr; temp != NULL && temp->next != NULL; temp = temp->next)
            {
                if (temp->next->data == curr->data)
                {
                    temp->next = temp->next->next;
                    delete temp->next;
                }
            }
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
    cout << "Original list\n";
    struct node<int> *temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    ll.remove_duplicates();
    cout << "\nAfter duplicates removed\n";
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    ll.insert(6);
    ll.insert(2);
    cout << "\nDuplicates added again\n";
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    ll.remove_duplicates_without_buffer();
    cout << "\nDuplicates removed\n";
    temp = ll.getStart();
    for (; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    cout << "\n";
}