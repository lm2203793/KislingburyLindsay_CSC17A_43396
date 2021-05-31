/* 
 * File:   Employee.h
 * Author: Lindsay Kislingbury
 * Purpose: Employee Class Specification
 * Created on May 30, 2021, 2:57 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee{
private:
    string name;    //employee name
    string number;  //employee number
    int hireDt;     //employee hire date
public:
    //Default Constructor
    Employee(){
        name=""; number=""; hireDt=0;
    }
    
    //Constructor
    Employee(string n, string num, int dt){
        name=n; number=num; hireDt=dt;
    }
    
    //Mutators
    void setName(string n){
        name=n;
    }
    
    void setNum(string num){
        number=num;
    }
    
    void sethireDt(int dt){
        hireDt=dt;
    }
    
    //Accessors
    string getName() const{
        return name;
    }
    
    string getNum() const{
        return number;
    }
    
    int getHireDt() const{
        return hireDt;
    }
};



#endif /* EMPLOYEE_H */

