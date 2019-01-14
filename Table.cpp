//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>

Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
    size = ARR_SIZE;
	
	rear = 0;             

    if (!readFromFile("RegStaffInf.txt", regular))
        cout << "can not read data correctly";
    if (!readFromFile("TmpStaffInf.txt", temporary))
        cout << "can not read data correctly";
}

//只统计某数额的工资人数
void Table::statData() {
    float wageSum = 0, wageAvg = 0;
    int l = Table::length();
    for (int i = 0; i < l; i++) {
        wageSum += Table::tableArr[i]->getBaseWage;
    }
    wageAvg = wageSum / l;
}

bool Table::readFromFile(string fileName, employeeType type) {

    ifstream infile(fileName);
    if (!infile.is_open())
        return false;
    else {
        switch (type) {
            case Regular:
                RegularEmployee *p;
				while (!infile.eof()） {//update:使用push_back后不需要i
                    double tmpAllowance, tmpProvidentFund, tmpPension,
                            tmpTax, tmpInsurance, tmpBaseWage, tmpRealWage;
                    int tmpId, tmpAge;
                    bool tmpSex;
                    string tmpName, tmpAddress;
                    infile >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress >> tmpBaseWage >> tmpAllowance >>
                           tmpProvidentFund >> tmpPension >> tmpTax >> tmpInsurance >> tmpRealWage;
                    p = new RegularEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpAllowance,
                                            tmpProvidentFund, tmpPension, tmpTax, tmpInsurance);
					//内存重新分配
					//update:直接使用push_back函数添加新项
					push_back(p);
				}
                break;
            case Temporary:
                TemporaryEmployee *q;
                while(!infile.eof()）{//update:使用push_back后不需要i
                    double tmpBaseWage, tmpRealWage, tmpTax, tmpBonus;
                    int tmpId, tmpAge;
                    bool tmpSex;
                    string tmpName, tmpAddress;
                    infile >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress
                            >> tmpBaseWage >> tmpBonus >> tmpTax >> tmpRealWage;
                    q = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus,
                                              tmpTax);
					//update:直接使用push_back函数添加新项
					push_back(p);
                }
                break;
        }
    }
    infile.close();
    return true;
}



bool Table::memExtension() {
    Employee **desMem = new Employee *[size + ARR_INCREMENT];
    if (!desMem)
        return false;
    else
        for (int i = 0; i < size; i++)
            desMem[i] = tableArr[i];
    delete[] tableArr;
    tableArr = desMem;
    size += ARR_INCREMENT;
    return true;
}

bool Table::readFromScreen() {
    bool type;
    cout << "请输入要添加的职工种类(1表示正式职工 0表示临时职工):";
    while (!(cin >> type)) {
        cout << "\n输入错误！请重新输入";
        cin.clear();
        while (cin.get() != '\n') {
        }
    }
    cout << "\n输入成功";
    while (cin.get() != '\n') {
    }
    Employee *p;
    if (type){
        p = new RegularEmployee();
        p->readInfo();
    } else {
        p = new TemporaryEmployee();
        p->readInfo();
    }
    //插入表中
    //this.push
}
void push_back(Employee* employee){
	if (rear == size)
		if (!memExtension())
		{
			cout << "memory error";
			return;
		}
	tableArr[rear] = employee;
	rear++;
}

   void sortByRealWage() {                                         //将总表按实发工资进行排序
	for (int i = 0; i < this.size; i++) {
		if (*(*tableArr + i) != NULL) {
			for (int j = 0; j < this.size - i; j++) {
				if (*(*tableArr + j) != NULL) {
					if (*(*tableArr + i).realwage < *(*tableArr + j).realwage) {
						int t = (*tableArr + i);
						(*tableArr + i) = (*tableArr + j);
						(*tableArr + j) = t;
					}
				}
			}
		}
	 }
}








