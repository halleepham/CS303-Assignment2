#include <iostream>
#include "Professional.h"
#include "Nonprofessional.h"

/*ASSUMPTIONS: 
Professional Employees:
  -Earns a monthly salary of $6000
  -Contributes 5% of weekly salary to healthcare
  -Gets 14 days of vacation time each year
Nonprofessional Employees:
  -Has an hourly rate of $20/hour
  -Contributes 3% of weekly salary to healthcare
  -Earns 3 hours of vacation time every 40 hours worked
*/

int main() {
  //Creating an instance of a Professional Employee
  Professional employeeP = Professional();
  cout << "Professional Employee:\n";
  cout << "\tWeekly Salary: $" << employeeP.calcWeeklySalary() << endl;
  cout << "\tWeekly Healthcare Contribution: $" << employeeP.calcHealthcare() << endl;
  cout << "\tVacation Days Earned this Week: " << employeeP.calcVacationDays() << " days\n\n";


  //Asking the user how many hours the nonprofessional employee worked this week
  double hoursWorked = 0;
  cout << "How many hours did the nonprofessional employee work this week? --> ";
  cin >> hoursWorked;
  //Creating an instance of a Nonprofessional Employee
  Nonprofessional employeeN = Nonprofessional(hoursWorked);
  cout << "Nonprofessional Employee:\n";
  cout << "\tWeekly Salary: $" << employeeN.calcWeeklySalary() << endl;
  cout << "\tWeekly Healthcare Contribution: $" << employeeN.calcHealthcare() << endl;
  cout << "\tVacation Days Earned this Week: " << employeeN.calcVacationDays() << " days\n\n";
}