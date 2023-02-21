#include <iostream>
using namespace std;

typedef struct list
{
    int key;
    struct list* next;
} list;

void Init(list* head)
{
    head->next = nullptr;
    head->key = 0;
}
void InsertEl(int& i, list* l) // wstawia element na koniec listy
{
    while (l->next != nullptr)
    {
        l = l->next;
    }
    l->next = new list;
    l->next->key = i;
    l->next->next = nullptr;
}
void DeleteEl(list* l) // kasuje element z końca listy 
{
    while (l->next->next != nullptr)
    {
        l = l->next;
    }
    cout << l->next->key << "\n";
    delete l->next;
    l->next = nullptr;
}
void DeleteList(list* l) // kasuje liste
{
    while (l->next->next != nullptr)
    {
        l = l->next;
    }
    delete l->next;
    l->next = nullptr;
}
int GetEl(int& i, list* l) // pobiera element z danego indexu i wyswietla go na ekranie
{
    int j = 0;
    while (j != i)
    {
        l = l->next;
        j++;
    }
    return l->next->key;
}

int main()
{
    list m;
    Init(&m);
    int i = 0;
    char command;

    while (1) {
        cin >> command;

        if (command == 'i')
        {
            cin >> i;
            InsertEl(i, &m);
        }
        else if (command == 'd')
        {
            DeleteEl(&m);
        }
        else if (command == 'g')
        {
            cin >> i;
            cout << GetEl(i, &m) << "\n";
        }
        else if (command == 'q')
        {
            while (m.next->next != nullptr)
            {
                DeleteList(&m);
            }
            break;
        }
    }
    return 0;
}