#include "Professional.h"

//Professional employee constructor
//Assume that all professional employees earn a monthly salary of $6000 and start with 14 vacation days a year
Professional::Professional(){
  monthlySalary = 6000.0;
  yearlyVacationDays = 14.0;
}

//PRE: takes in no arguments
//POST: returns weekly salary of professional employee
//Since professional employees are paid on a monthly salary, divide that salary by number of weeks in a month (4) to get weekly salary
double Professional::calcWeeklySalary(){
  return monthlySalary/4.0;
}

//PRE: takes in no arguments
//POST: returns healthcare contributions for a professional employee
//A professional employee has to contribute 5% of weekly salary to health care
double Professional::calcHealthcare(){
  return (monthlySalary/4.0) * 0.05;
}

//PRE: takes in no arguments
//POST: 
//A professional employee gets 14 days of vacation per year
double Professional::calcVacationDays(){
  //52 weeks in a year
  return yearlyVacationDays/52.0;
}