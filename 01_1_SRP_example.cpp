//
// Created by ashok on 23-04-2026.
// Example 1.1: Single Responsibility Principle (SRP)
// File: 01_1_SRP_example.cpp
//
// Goal:
// Show SRP with a simple real-life industry example.
// We separate employee data, salary calculation, and persistence.
//

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Holds employee data only.
// Responsibility: represent employee information.
struct Employee
{
    int id;
    string name;
    double monthlySalary;
    double bonus;

    Employee(int id, const string& name, double monthlySalary, double bonus)
        : id(id), name(name), monthlySalary(monthlySalary), bonus(bonus)
    {
    }
};

// Handles salary calculation only.
// Responsibility: business logic for payroll calculation.
struct SalaryCalculator
{
    static double calculateAnnualSalary(const Employee& employee)
    {
        return (employee.monthlySalary * 12) + employee.bonus;
    }
};

// Handles report formatting only.
// Responsibility: convert employee data into a printable report.
struct EmployeeReportFormatter
{
    static string formatPayrollReport(const Employee& employee)
    {
        const double annualSalary = SalaryCalculator::calculateAnnualSalary(employee);

        return "Employee Payroll Report\n"
               "ID: " + to_string(employee.id) + "\n" +
               "Name: " + employee.name + "\n" +
               "Monthly Salary: " + to_string(employee.monthlySalary) + "\n" +
               "Bonus: " + to_string(employee.bonus) + "\n" +
               "Annual Salary: " + to_string(annualSalary) + "\n";
    }
};

// Handles file saving only.
// Responsibility: persist the report to storage.
struct FileManager
{
    static void saveToFile(const string& filename, const string& content)
    {
        ofstream ofs(filename);
        ofs << content;
    }
};

int main()
{
    Employee employee(101, "Ashok", 5000.0, 10000.0);

    const string report = EmployeeReportFormatter::formatPayrollReport(employee);

    cout << report << endl;

    // File saving is kept separate from Employee.
    // This follows SRP and is closer to real industry design.
    FileManager::saveToFile("employee_payroll_report.txt", report);

    return 0;
}
