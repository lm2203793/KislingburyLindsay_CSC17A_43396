/* 
 * File:   Min.h
 * Author: Lindsay Kislingbury
 * Purpose: MinMax Class specification
 * Created on June 1, 2021, 11:19 AM
 */

#ifndef MINMAX_H
#define MINMAX_H

template <class T, class T2> 
class MinMax{
private:
    T min;      //minimum value
    T max;      //maximum value;
    int size;   //size of array
    int modnum; //mod number
    T2 a;       //hold pointer to int or char array
public:
    //char Constructor
    MinMax(int sz, int mod){
        size=sz; modnum=mod;
        int_fillAry();
    }
    //int Constructor
    MinMax(int sz){
        size=sz;
        char_fillAry();
    }
    //Destructor
    ~MinMax(){
        delete []a;
    }
    //int fill array
    void int_fillAry(){
        a=new int[size];
        for(int i=0; i<size; i++){
            a[i]=rand()%modnum+3;
        }
    }
    //char fill array
    void char_fillAry(){
        a=new char[size];
        static char c='A';
        for(int i=0; i<size; i++){
            a[i]=c+rand()%24;
        }
    }
    //Sort
    void sort(){
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(a[j]<a[i]){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        min=a[0];
        max=a[size-1];
    }
    //print array
    void print(){
        for(int i=0; i<size; i++){
            cout<<a[i]<<" ";
            if(i%10==(10-1)) cout<<endl;
        }
        cout<<endl;
    }
    //Accessors
    T getMax() const{
        return max;
    }
    T getMin() const{
        return min;
    }
};


#endif /* MINMAX_H */

