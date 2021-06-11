/* 
 * File:   Prob3TableInherited.h
 * Author: Lindsay Kislingbury
 * Purpose: Prob3Table Class Specification
 * Created on June 9, 2021, 3:24 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
#include "Prob3Table.h"

template<class T>
class Prob3TableInherited:public Prob3Table<T>{
    protected:
        T *augTable;     //Augmented Table with sums
    public:
        //Constructor
        Prob3TableInherited(char *file, int rows, int cols) : 
            Prob3Table<T>(file,rows,cols){
            //Allocate memory for augmented table with an extra row and column
            augTable=new T[(rows+1)*(cols+1)];
            //Fill with values in original table from base class
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    augTable[i*(cols+1)+j]=Prob3Table<T>::table[i*cols+j];
                }
            }
            //Add row totals to the end of each row
            for(int i=0; i<rows; i++){
                augTable[i*(cols+1)+cols]=Prob3Table<T>::rowSum[i];
            }
            //Add column totals to the end of each column
            for(int j=0; j<cols; j++){
                augTable[rows*(cols+1)+j]=Prob3Table<T>::colSum[j];
            }
            //Add grand total to the end of new column
            augTable[(rows+1)*(cols+1)-1]=Prob3Table<T>::getGrandTotal();     
        }        
            
        //Destructor
        ~Prob3TableInherited(){
            delete [] augTable;
        }
        
        //Return Augmented Table
        const T *getAugTable(void){
            return augTable;
        }
};

#endif /* PROB3TABLEINHERITED_H */

