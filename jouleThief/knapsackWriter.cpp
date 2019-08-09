#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    int numberItems = 0, knapsackCapacity = 0, itemName, itemValue, itemWeight;               //Creating variables

    srand(time(NULL));                                                                //Ensuring Random Numbers Changed

    //Create File
    std::ofstream file;
    file.open ("jouleFile.txt");

    while(numberItems <= 0 || knapsackCapacity <= 0){
        //Number of Items & Knapsack Capacity
        std::cout << "Number of Items: ";                                                 //Gathering Number of Items
        std::cin >> numberItems;
        std::cout << "Knapsack Capacity: ";                                               //Gathering Knapsack Capacity
        std::cin >> knapsackCapacity;
    }
    
    file << numberItems << " " << knapsackCapacity << "\n";                           //Input Information

    //Item, Item Value, and Item Weight
    for(int i = 0; i < numberItems; i++)
    {   
        itemName = i + 1;                                                             //Setting Item Number
        itemValue = rand()%(176) + 25;                                                  //Allowing for between 25 and 200 in item value
        itemWeight = rand()%(3*numberItems) + 1;                                      //Allowing for weights between 1 and 3 * numberItems
        file << itemName << " " << itemValue << " " << itemWeight << std::endl;       //Input Information
    }

    //Close File
    file.close();

    return 0;
}