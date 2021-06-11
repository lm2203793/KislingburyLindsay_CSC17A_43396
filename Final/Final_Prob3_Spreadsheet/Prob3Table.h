/* 
 * File:   Prob3Table.h
 * Author: Lindsay Kislingbury
 * Purpose: Prob3Table Class Specification
 * Created on June 8, 2021, 11:07 PM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H
#include <fstream>
using namespace std;

template<class T>
class Prob3Table{
    protected:
        int rows;      //Number of rows in the table
        int cols;      //Number of cols in the table
        T *rowSum;     //RowSum array
        T *colSum;     //ColSum array
        T *table;      //Table array
        T grandTotal;  //Grand total
        
        //Calculate row and column sums
        void calcTable(void){                      
            //Calculate row sums and add to grand total
            for(int i=0; i<rows; i++){ //Loop on rows
                rowSum[i]=0; //Initialize to zero
                for(int j=0; j<cols; j++){ //Loop on columns
                    rowSum[i]+=table[i*cols+j]; //Add value at each element
                }
                grandTotal+=rowSum[i];      //Add to the grand total
            }
            //Calculate column sums and add to grand total
            for(int i=0; i<cols; i++){
                colSum[i]=0; //Initialize to zero
                for(int j=0; j<rows; j++){
                    colSum[i]+=table[j*cols+i];
                }
            }
        }
    public:
        //Constructor
        Prob3Table(char *file, int r, int c){
            rows=r; 
            cols=c;
            grandTotal=0;
            //Allocate memory for table
            table=new T[r*c];
            //Fill Table from file
            ifstream infile;
            infile.open(file,ios::in);
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    infile>>table[i*c+j];
                }
            }
            //Close file
            infile.close();
            //Allocate memory for rowSum and colSum
            rowSum=new T[r];
            colSum=new T[c];
            //Calculate Totals
            calcTable();
        }           
        //Destructor
        ~Prob3Table(){
            delete [] table;
            delete [] rowSum;
            delete [] colSum;
        }
        const T *getTable(void){
            return table;
        }
        const T *getRowSum(void){
            return rowSum;
        }
        const T *getColSum(void){
            return colSum;
        }
        T getGrandTotal(void){
            return grandTotal;
        }
};

#endif /* PROB3TABLE_H */

