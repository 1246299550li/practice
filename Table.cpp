//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>
Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
	size = ARR_SIZE;
	if (!readFromFile("RegStaffInf.txt", regular))
		cout << "can not read data correctly";
	if (!readFromFile("TemStaffInf.txt", temporary))
		cout << "can not read data correctly";
}

//只统计某数额的工资人数
void Table::statData() {
	float wageSum = 0, wageAvg = 0;
	int l = Table::length();
	for (int i = 0; i < l; i++)
	{
		wageSum += Table::tableArr[i]->getBaseWage;
	}
	wageAvg = wageSum / l;
}

bool Table::readFromFile(string fileName, employeeType type){

	ifstream infile(fileName);
	if (!infile.is_open())
		return FALSE;
	else
	{
		switch (type)
		{
		case Regular:
			RegularEmployee * p;
			for (int i=0;!infile.eof();i++) {
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
				if(i>=size)
					if (!memExtension()) {
						cout << "memory error";
						return FALSE;
					}
				tableArr[i] = p;
			}
			break;
		case Temporary:
			TemporaryEmployee * q;
			for (int i = 0; !infile.eof(); i++) {
				double tmpBaseWage, tmpRealWage, tmpTax, tmpBonus;
				int tmpId, tmpAge;
				bool tmpSex;
				string tmpName, tmpAddress;
				infile2 >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress 
						>>tmpBaseWage >> tmpBonus >> tmpTax >> tmpRealWage;
				q = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus, tmpTax);
				//内存重新分配
				if (i >= size)
					if (!memExtension()){
						cout << "memory error";
						return FALSE;
					}
				tableArr[i] = q;
			}
			break;
		}
	}
	infile.close();
	return TRUE;
}

bool Table::memExtension(){
	Employee ** desMem=new Employee *[size+ ARR_INCREMENT];
	if (!desMem)
		return FALSE;
	else
		for (int i = 0; i < size; i++)
			desMem[i] = tableArr[i];
	delete[] tableArr;
	tableArr = desMem;
	size += ARR_INCREMENT;
	return TRUE;
}
bool Table::readFromScreen(employeeType type) {
	int i;
	switch (type) {
	case Regular:
		RegularEmployee * p;
			double tmpAllowance, tmpProvidentFund, tmpPension,
				tmpTax, tmpInsurance, tmpBaseWage, tmpRealWage;
			int tmpId, tmpAge;
			bool tmpSex;
			string tmpName, tmpAddress;
			cin >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress >> tmpBaseWage >> tmpAllowance >>
				tmpProvidentFund >> tmpPension >> tmpTax >> tmpInsurance >> tmpRealWage;
			p = new RegularEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpAllowance,
				tmpProvidentFund, tmpPension, tmpTax, tmpInsurance);
			for (i = 0; tableArr[i] != NULL && i < size; i++);
			if (i == size) {
				if (!memExtension()) {
					cout << "memory error";
					return FALSE;
				}
			}
			tableArr[i] = p;
			return TRUE;
	case Temporary:
		TemporaryEmployee * q;
		double tmpBaseWage, tmpRealWage, tmpTax, tmpBonus;
		int tmpId, tmpAge;
		bool tmpSex;
		string tmpName, tmpAddress;
		cin >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress
			>> tmpBaseWage >> tmpBonus >> tmpTax >> tmpRealWage;
		q = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus, tmpTax);
		for (i = 0; tableArr[i] != NULL && i < size; i++);
		if (i == size) {
			if (!memExtension()) {
				cout << "memory error";
				return FALSE;
			}
		}
		tableArr[i] = q;
		return TRUE;
	}

}











