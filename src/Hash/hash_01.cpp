//
// Created by LYM on 2018/12/8.
//

#include <iostream>
#include <list>

using namespace std;

class Hash
{
public:
    Hash(int no);

    void insertItem(int key);

    void deleteItem(int key);

    int hashFunction(int x)
    {
        return (x%(this->BUCKET));
    }

    void displayHash();

private:
    int BUCKET;
    list<int> *table;
};

int main(void)
{
    int arr[] = {15, 11, 27, 8, 12};
    int len = sizeof(arr) / sizeof(arr[0]);

    Hash h(7);

    for (int i=0; i<len; i++)
    {
        h.insertItem(arr[i]);
    }

//    cout << "\n删除前...\n";
    h.displayHash();

    h.deleteItem(15);

    cout << "\nAfter...\n" << endl;
//    cout << endl << endl;

    h.displayHash();

    return 0;
}

Hash::Hash(int no)
{
    this->BUCKET = no;
    this->table = new list<int>[this->BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    list<int>::iterator it;
    for (it=table[index].begin(); it!=table[index].end(); it++)
    {
        if (*it == key)
        {
            table[index].erase(it);
            break;
        }
    }
}

void Hash::displayHash()
{
    for (int i=0; i<BUCKET; i++)
    {
        cout << i ;
        list<int>::iterator it = table[i].begin();
        for (; it!=table[i].end(); it++)
        {
            cout << " --> " << *it ;
        }
        cout << endl;
    }
}
