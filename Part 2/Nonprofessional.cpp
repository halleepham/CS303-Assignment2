#include "Nonprofessional.h"

//Nonprofessional employee constructor
//Assume that all nonprofessional employees have an hourly rate of $20/hour
Nonprofessional::Nonprofessional(double hours){
  hoursWorked = hours;
}

//PRE: takes in no arguments
//POST: returns a non-professional employee's weekly salary
double Nonprofessional::calcWeeklySalary(){
  return (hourlyRate * hoursWorked);
}

//PRE: takes in no arguments
//POST: returns the weekly healthcare contribution of a non-professional employee
//Non-professional employees contribute 3% of their weekly salary to health care
double Nonprofessional::calcHealthcare(){
  return (hourlyRate * hoursWorked) * 0.03;
}

//PRE: takes in no arguments
//POST: returns the number of vacation days earn a week
//Every 40 hours worked is 3 hours of vacation time
double Nonprofessional::calcVacationDays(){
  return(hoursWorked * 0.075 / 24.0);
}