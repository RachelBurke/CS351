#include"PriorityQueue.h"
#include <iostream>


Priority_Queue::Priority_Queue()
{
    //Intitialize a head node for PQ
    head = NULL;
}

Priority_Queue::~Priority_Queue()
{

}

void Priority_Queue::enqueue(item* knap_node)
{
    try
    {
        // If there is no root:
        if(head == NULL){
            node* new_node = new node();
            new_node-> knap_item = knap_node;
            new_node-> left_node = NULL;
            new_node-> right_node = NULL;
            head = new_node;
            return;
        }
        //Let's find a place to put the node that needs to be below the root
        //But first create a way to keep track of what head you are on
        node* current_head = new node();
        current_head = head;
        bool added_node = 0;
        //Finding place to place the node
        while(added_node != 1){
            if(knap_node-> ratio < current_head-> knap_item-> ratio){                     //Go Left
                if(current_head-> left_node == NULL){
                    node* new_node = new node();
                    new_node-> knap_item = knap_node;
                    new_node-> left_node = NULL;
                    new_node-> right_node = NULL;
                    current_head-> left_node = new_node;  
                    added_node = 1; 
                }
                else{
                    current_head = current_head-> left_node;
                    continue;
                } 
            }
            else{                                                                      //Go Right
                if(current_head-> right_node == NULL){
                    node* new_node = new node();
                    new_node-> knap_item = knap_node;
                    new_node-> left_node = NULL;
                    new_node-> right_node = NULL;
                    current_head-> right_node = new_node;   
                    added_node = 1;
                }
                else{
                    current_head = current_head-> right_node;
                    continue;
                } 
            }
        }
    }
    catch (...)
    {
        std::cout << "UNABLE TO ENQUEUE NODE" << std::endl;
    }
}

item* Priority_Queue::dequeue()
{
    try
    {
        //No tree. Nothing to do
        if(head == NULL)
            return NULL;

        node* current_node = new node();
        current_node = head;
        
        //Return head if no right subtree
        if(head-> right_node == NULL){
            item* item_to_return = new item();
            item_to_return = head-> knap_item;
            head = head-> left_node;
            delete current_node;
            return item_to_return;
        }
        //Otherwise go find what you need in right subtree
        else{
            node* parent_node = new node();
            node* child_node = new node();
            parent_node = NULL;
            while(current_node-> right_node != NULL){
                parent_node = current_node;
                current_node = current_node-> right_node;
            }
            item* item_to_return = new item();
            item_to_return = current_node-> knap_item;
            parent_node-> right_node = current_node-> left_node;
            delete current_node;
            return item_to_return;
        }
    }
    catch (...)
    {
        std::cout << "UNABLE TO DEQUEUE NODE" << std::endl;
    }
}

void Priority_Queue:: printPreorder(node* knap_node_) 
{ 
    if (knap_node_ == NULL) 
        return; 
  

    // First, recur on left sutree
    printPreorder(knap_node_-> left_node);  

    // Then, print item ratio of node
    std::cout << knap_node_-> knap_item-> ratio << std::endl; 
  
    // Then recur on right subtree
    printPreorder(knap_node_-> right_node); 
} 

node* Priority_Queue::getHeadNode()
{
    return head;
}