#include <iostream>
#include "Table.h"
#include<iomanip>
using namespace std;
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
    cout << "Hello, World!" << endl;
    Table t;
    return 0;
}
