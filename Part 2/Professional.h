#include "Employee.h"

class Professional : public Employee{
  private:
    double monthlySalary;
    double yearlyVacationDays;
  public:
    Professional();
    double calcWeeklySalary();
    double calcHealthcare();
    double calcVacationDays();
};