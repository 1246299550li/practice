//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TABLE_H
#define NEW_TABLE_H

#include "RegularEmployee.h"
#include "TemporaryEmployee.h"
const int ARR_SIZE = 100;
const int ARR_INCREMENT = 10;
eunm employeeType{ regular,temproary };

class Table {
private:
    Employee ** tableArr;
	int size;
	bool memExtension();
public:
    Table();
    bool readFromFile(string fileName, employeeType type);
    bool readFromScreen(employeeType type);
    Employee ** searchEmployee(int id = 0, string name = "", double realWage = 0.0);
    bool updateEmployee(Employee* employee);
    bool logicalDeleteEmployee();
    bool physicalDeleteEmployee();
    bool saveInFile(string fileName);
    void calculateWage(Employee **);
    void sortByRealWage();
	void statData();
	
	~Table();
};


#endif //NEW_TABLE_H
