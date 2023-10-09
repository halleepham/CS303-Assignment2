#include "Employee.h"

class Nonprofessional : public Employee{
  private:
    double hourlyRate = 20.0;
    double hoursWorked;
  public:
    Nonprofessional(double hours);
    double calcWeeklySalary();
    double calcHealthcare();
    double calcVacationDays();
};