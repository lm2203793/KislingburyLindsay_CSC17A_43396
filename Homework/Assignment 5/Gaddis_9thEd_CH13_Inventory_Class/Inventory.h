/* 
 * File:   Inventory.h
 * Author: Lindsay Kislingbury
 * Purpose: Inventory Class specification
 * Created on May 23, 2021, 12:47 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H
#include <cstdlib>

class Inventory{
private:
    int         itemNum,
                qty;
    float       cost,
                totCost;

public:
    //Default Constructor
    //Initializes Class Member Variables to 0    
    Inventory(){
        itemNum=0; qty=0; cost=0; totCost=0;
    }
    
    //Constructor #2
    Inventory(int i, int q, float c){
        itemNum=i; qty=q; cost=c;
    }
    
    //Set item Number
    void setNum(int i){
        itemNum=i;
    }
    //Set Quantity
    void setQty(int q){
        qty=q;
    }
    //Set Cost
    void setCost(float c){
        cost=c;
    }
    //Set total cost to product of quantity * cost
    void setTot(){
        totCost=qty*cost;
    }
    //Get Item Number
    int getNum(){
        return itemNum;
    }
    //Get Quantity
    int getQty(){
        return qty;
    }
    //Get Cost
    float getCost(){
        return cost;
    }
    //Get Total Cost
    float getTot(){
        return totCost; 
    }
    

};


#endif /* INVENTORY_H */

