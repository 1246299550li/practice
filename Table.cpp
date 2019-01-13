//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>
Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
	size = ARR_SIZE;
	int i = 0;
    ifstream infile1("RegStaffInf.txt");    //读取 
    RegularEmployee *p;                     //缓存对象
    while(!infile1.eof()){
        double tmpAllowance,tmpProvidentFund,tmpPension,tmpTax,tmpInsurance,tmpBaseWage,tmpRealWage;
		int tmpId, tmpAge;
		bool tmpSex;
		string tmpName,tmpAddress;
		infile1 >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress >> tmpBaseWage >> tmpAllowance >>
			tmpProvidentFund >> tmpPension >> tmpTax >> tmpInsurance >> tmpRealWage;
		p = new RegularEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpAllowance,
								tmpProvidentFund, tmpPension, tmpTax, tmpInsurance);
		if (i >= ARR_SIZE) {
			tableArr = (Employee**)realloc((ARR_SIZE * 2) * sizeof(Employee *));
		}
		tableArr[i] = p;
		i++;
    }
	infile1.close();
	ifstream infile2("TemStaffInf.txt");
	TemporaryEmployee *q;
	while (!infile2.eof()) {
		double tmpBaseWage, tmpRealWage, tmpTax, tmpBonus;
		int tmpId, tmpAge;
		bool tmpSex;
		string tmpName, tmpAddress;
		infile2 >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress >>
			tmpBaseWage >> tmpBonus >> tmpTax >> tmpRealWage;
		q = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus, tmpTax);
		if (i >= ARR_SIZE) {
			tableArr = (Employee**)realloc((ARR_SIZE * 2) * sizeof(Employee *));
			if (i >= ARR_SIZE) {
				Employee **tmp;
				tmp = tabelArr;
				tabelArr = new Empolyee*[ARR_SIZE + INCREASE];
				size += ARR_INCREASE
					for (int i = 0; i < size; i++) {
						tabelArr[i] = tmp[i];
					}
				delete[]tmp;
			}
		}
		tableArr[i] = q;
		i++;
	}
    
    


}
bool Table::readFromFile() {

}