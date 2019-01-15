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
        cout << "已打开文件"
    }

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
			if (t.tableArr[i]->isType() ){
				RegularEmployee *tmpReg = dynamic_cast<RegularEmployee *>(t.tableArr[i]);
				if (tmpReg != nullptr) {
					cout << "正式职工：" << setw(10) << t.tableArr[i]->getId() << setw(15) << t.tableArr[i]->getName() << setw(5) << sex
						<< setw(30) << t.tableArr[i]->getAddress() << setw(10) << fixed << setprecision(2) << t.tableArr[i]->getBaseWage()
						<< fixed<<setprecision(2) << tmpReg->getAllowance() <<setw(10)<<fixed << setprecision(2) << tmpReg->getTax()
						<< setw(10) << fixed << setprecision(2) << tmpReg->getInsurance() << setw(10) << fixed << setprecision(2) << tmpReg->getRealWage()<<endl;
				}	
			}
			else {
				TemporaryEmployee *tmpTem = dynamic_cast<TemporaryEmployee *>(t.tableArr[i]);
				if (tmpTem != nullptr) {
					cout << "正式职工：" << setw(10) << t.tableArr[i]->getId() << setw(15) << t.tableArr[i]->getName() << setw(5) << sex
						<< setw(30) << t.tableArr[i]->getAddress() << setw(10) << fixed << setprecision(2) << t.tableArr[i]->getBaseWage()
						<< setw(10) << fixed << setprecision(2) << tmpTem->getBonus() << setw(10) << fixed << setprecision(2) << tmpTem->getTax() 
						<< setw(10) << fixed << setprecision(2) << tmpTem->getRealWage()<<endl;
				}
			}
		}
	}
}
int main() {


    outputMenu();
//    cout << "你好风格士大夫" << endl;

//    Table t;

//    t.readFromFile("E:\\new\\1.txt", true);
//    t.readFromScreen();
//    system("pause");
//    t.tableArr[0]->displayInfo();
//    system("pause");
//    t.saveInFile("E:\\new\\output.txt", true);
//    system("pause");
    return 0;
}
