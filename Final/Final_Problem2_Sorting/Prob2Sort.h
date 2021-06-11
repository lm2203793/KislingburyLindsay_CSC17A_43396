/* 
 * File:   Prob2Sort.h
 * Author: Lindsay Kislingbury
 * Purpose: Prob2Sort Class Specification
 * Created on June 8, 2021, 8:04 PM
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H
#include <cstdlib>  //C Standard Library
#include <iostream> //I/O Library
using namespace std;

//This class sorts arrays either ascending or descending
template <class T>
class Prob2Sort{
    private:
            int *index;  //Index utilized in the sort
    public:
        Prob2Sort(){//Constructor
            index=NULL;
        }                 
        ~Prob2Sort(){//Destructor
            delete []index;
        }
        
        //Sorts a single column array
        //Call 2D sort function passing 1 column and 1 row for 1D array
        T *sortArray(const T *array, int size, bool asc){
            return sortArray(array,size,1,1,asc);
        }          
        
        //Sorts a 2 dimensional array represented as a 1 dim array
        T *sortArray(const T *array, int rows, int cols, int sortOnC, bool asc){
            int srtIndex=0;       //Sorted index
            int temp=0;           
            //Allocate memory for array of indexes 
            index=new int[rows];
            //Fill index array with starting order
            for(int i=0; i<rows; i++){
                index[i]=i;
            }
            //Get the sorted index for each row
            //Compare the element at rows*cols + column to sort on with next row
            for(int i=0; i<rows; i++){ 
                srtIndex=i; //Sorted index starts at original index
                for(int j=i+1; j<rows; j++){
                    if(asc){ //Ascending
                        if(array[index[j]*cols+sortOnC-1] > 
                                array[index[srtIndex]*cols+sortOnC-1]){
                            srtIndex=j;
                        }
                    }
                    else if(array[index[j]*cols+sortOnC-1] < 
                            array[index[srtIndex]*cols+sortOnC-1]){//Descending 
                        srtIndex=j;
                    }
                }
                //Swap starting index with sorted index
                temp=index[i];
                index[i]=index[srtIndex];
                index[srtIndex]=temp;
            }
            //Allocate memory for sorted array
            T *srtAry=new T[rows*cols];
            //Fill new array with values at sorted indexes
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    srtAry[i*cols+j]=array[index[i]*cols+j];
                }
            }
            return srtAry;
        }
}; 
#endif /* PROB2SORT_H */

