#include <iostream>
#include <vector>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;    
        }
        
        std::vector<Node *> list_order;

        // create new list (at next place)
        Node *cur_node = head;
        Node *next_node;
        while (cur_node)
        {
            list_order.push_back(cur_node);
            next_node = cur_node->next;
            cur_node->next = new Node(cur_node->val);
            cur_node = next_node;
        }

        Node *new_head = head->next;

        // link new list
        for (auto i = 0; i < list_order.size(); ++i)
        {
            cur_node = list_order[i];

            // link random
            if (cur_node->random)
            { 
                cur_node->next->random = cur_node->random->next;
            }
                
            // check last element
            if (i != list_order.size() - 1)
            {
                // link next
                next_node = list_order[i + 1];
                cur_node->next->next = next_node->next;
            }
        }
        
        // recover original list
        for (auto i = 0; i < list_order.size(); ++i)
        {
            cur_node = list_order[i];
            if (i != list_order.size() - 1)
            {                
                next_node = list_order[i + 1];
                cur_node->next = next_node;
            } else {
                cur_node->next = nullptr;
            }
        }
        
        return new_head;
    }
};