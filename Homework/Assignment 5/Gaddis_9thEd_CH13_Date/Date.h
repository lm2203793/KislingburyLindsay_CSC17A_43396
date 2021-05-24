/* 
 * File:   Date.h
 * Author: Lindsay Kislingbury
 * Purpose: Specification for Date class
 * Created on May 22, 2021, 7:34 PM
 */

#ifndef DATE_H
#define DATE_H

class Date{
private:
    int     month,  //Month
            day,    //Day
            year;   //Year
public:
    //Default constructor initializes values to 0
    Date(int m, int d, int y){ 
        month=m;
        day=d;
        year=y;
    }
    //Get functions
    int getMnth() const{ //Get month
        return month;
    }
    int getDay() const{ //Get day
        return day;
    }
    int getYear() const{ //Get year
        return year;
    }
    string cnvMnth(int m){
        string name;
        name=(m==1)?"January":
             (m==2)?"February":
             (m==3)?"March":
             (m==4)?"April":
             (m==5)?"May":
             (m==6)?"June":
             (m==7)?"July":
             (m==8)?"August":
             (m==9)?"September":
             (m==10)?"October":
             (m==11)?"November":"December";
        return name;
    }
    

    
   
};


#endif /* DATE_H */

