#include<string>

#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_

/*
* Item Declaration
*/
struct item
{
    std::string name;
    int weight;
    int value;
    double ratio;
};

/*
 * Node Declaration
 */
struct node
{
	struct node* right_node;
    struct node* left_node;
    struct item* knap_item;
};

/*
 * Class Priority Queue
 */
class Priority_Queue
{
    private:
        node *head;

    public:
        /*
        * Initialize the Priority Queue
        */
        Priority_Queue();

        /*
        * Deconstruct Priority Queue
        */
        ~Priority_Queue();

        /*
         * Enqueue into Priority Queue
         */
        void enqueue(item* knap_node);

        /*
        * Dequeue from Priority Queue
        * 
        * @ return the max ratio node
        */
        item* dequeue();

        /*
        * Print out the Priority Queue
        */ 
       void printPreorder(node* knap_node_);

       /*
       * Get the head node
       * 
       * @return the root of the tree
       */
       node* getHeadNode();
};

#endif   // !defined _PRIORITYQUEUE_H
