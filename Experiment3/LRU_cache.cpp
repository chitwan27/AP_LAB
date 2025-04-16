#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    unordered_map<int, Node *> mp;
    int capacity;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void insertAfterHead(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    void deleteNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        Node *temp = mp[key];
        deleteNode(temp);
        insertAfterHead(temp);
        return temp->val;
    }
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            insertAfterHead(temp);
        }
        else
        {
            if (mp.size() == capacity)
            {
                Node *temp = tail->prev;
                mp.erase(temp->key);
                deleteNode(temp);
            }
            Node *newNode = new Node(key, value);
            mp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};