#pragma once
#include <iostream>
using namespace std;

class Employee{
  public:
    virtual double calcWeeklySalary() = 0;
    virtual double calcHealthcare() = 0;
    virtual double calcVacationDays() = 0;
};


