#include <iostream>
#include "Table.h"
#include<iomanip>
using namespace std;
Table *table = nullptr;
void wageStatistic(Table t) {		//功能4
	double sum = 0, average = 0;
	t.calculateWage(t.tableArr, sum, average);
	cout << "工资总值:" << fixed << setprecision(2) << sum << endl;
	cout << "平均工资:" << fixed << setprecision(2) << average << endl;
}

void sortWage(Table t) {			//功能5
	t.sortByRealWage();
	string sex;
	for (int i = 0; i < t.apacity; i++) {
		if (t.tableArr[i] != nullptr) {
			if (t.tableArr[i]->isSex()) {
				sex = "男";
			}
			else {
				sex = "女";
			}
			if (t.tableArr[i]->isType()) {
				RegularEmployee *tmpReg = dynamic_cast<RegularEmployee *>(t.tableArr[i]);
				if (tmpReg != nullptr) {
					cout << "正式职工：" << setw(10) << t.tableArr[i]->getId() << setw(15) << t.tableArr[i]->getName() << setw(5) << sex
						<< setw(30) << t.tableArr[i]->getAddress() << setw(10) << fixed << setprecision(2) << t.tableArr[i]->getBaseWage()
						<< fixed << setprecision(2) << tmpReg->getAllowance() << setw(10) << fixed << setprecision(2) << tmpReg->getTax()
						<< setw(10) << fixed << setprecision(2) << tmpReg->getInsurance() << setw(10) << fixed << setprecision(2) << tmpReg->getRealWage() << endl;
				}
			}
			else {
				TemporaryEmployee *tmpTem = dynamic_cast<TemporaryEmployee *>(t.tableArr[i]);
				if (tmpTem != nullptr) {
					cout << "正式职工：" << setw(10) << t.tableArr[i]->getId() << setw(15) << t.tableArr[i]->getName() << setw(5) << sex
						<< setw(30) << t.tableArr[i]->getAddress() << setw(10) << fixed << setprecision(2) << t.tableArr[i]->getBaseWage()
						<< setw(10) << fixed << setprecision(2) << tmpTem->getBonus() << setw(10) << fixed << setprecision(2) << tmpTem->getTax()
						<< setw(10) << fixed << setprecision(2) << tmpTem->getRealWage() << endl;
				}
			}
		}
	}
}

void inquireEmployee(Table t) {			//功能7
	cout << "请输入查找选项 1.按编号  2.按姓名  3.按实发工资\n";
	int c;
	t.checkInput(c);
	Employee **p;
	loop:
	switch (c) {
	case 1:
		cout << "请输入编号\n";
		int tmpId;
		t.checkInput(tmpId);
		p=t.searchEmployee(tmpId,true);
		break;
	case 2: {
		cout << "请输入姓名\n";
		string tmpName;
		t.checkInput(tmpName);
		p = t.searchEmployee(tmpName, true);
	}
		break;
	case 3:
		cout << "请输入实发工资\n";
		double tmpRealWage;
		t.checkInput(tmpRealWage);
		p = t.searchEmployee(tmpRealWage, true);
		break;
	default:
		cout << "输入信息有误，重新输入\n";
		goto loop;
		
	}
	for (int i = 0; p[i] != nullptr; i++) {
		if (p[i]->isType()) {
			dynamic_cast<RegularEmployee *>(p[i])->displayInfo();
		}
		else {
			dynamic_cast<TemporaryEmployee *>(p[i])->displayInfo();
		}
	}
}

void modifyEmployee(Table t) {			//功能8
	cout << "请输入修改的职工编号\n";
	int tmpId;
	loop:
	t.checkInput(tmpId);
	Employee**p = t.searchEmployee(tmpId,true);
	if (p[0]->isType()) {
		dynamic_cast<RegularEmployee *>(p[0])->displayInfo();
	}
	else {
		dynamic_cast<TemporaryEmployee *>(p[0])->displayInfo();
	}
	cout << "请确认这是否是您要修改的职工  是输入1 否输入0";
	int c;
	t.checkInput(c);
	if (c) {
		t.updateEmployee(p[0]);
	}
	else {
		cout << "请重新输入\n";
		goto loop;
	}

}
void outputMenu() {
    cout << "-------欢迎使用职工工资信息管理系统-------\n";
    cout << "-   1.新建数据文件                      -\n";
    cout << "-   2.打开数据文件                      -\n";
    cout << "-   3.保存数据到文件                    -\n";
    cout << "-   4.数据统计(计算工资总额、平均值)      -\n";
    cout << "-   5.排序输出每个职工实发工资           -\n";
    cout << "-   6.添加职工信息                      -\n";
    cout << "-   7.查询职工信息                      -\n";
    cout << "-   8.修改职工信息                      -\n";
    cout << "-   9.删除职工信息                      -\n";
    cout << "-   10.恢复职工信息                     -\n";
    cout << "---------------------------------------\n";
}

void newDataFile() {
    if (table != nullptr){
		cout << "已打开文件";
    }

}


int main() {
    cout << "Hello, World!" << endl;
    Table t;
//    t.readFromFile("E:\\new\\1.txt", true);
    t.readFromScreen();
    system("pause");
    t.tableArr[0]->displayInfo();
    system("pause");
    t.saveInFile("E:\\new\\output.txt", true);
    system("pause");
    return 0;
}
