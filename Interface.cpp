#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include<stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <dir.h>
#include <fstream>
#include <string.h> 
#include <cctype>
#include <string>
#include "bin\design.h"
#include "bin\Interface.h"

using namespace std;

void welcome(){
	char wel[] = "---Welcome---";
	int x = (getScreen()-strlen(wel))/4;
	
	//coordinate.. line.. getScreen.. come from headerfile design 
	//and the source code i'm learn from internet and change some code and some value to ez understand 
	//if u interested with it can download or copy the code from the headerfile.
	//getScreen is for getting cmd width screen with anyside 
	//coordinate is for make ur sentence/ word/ or anything in cmd screen to show any where u want just change the value of x and y;
	//x for column./ y for row 
	//line for draw a line.
	
	coordinate(x,0);  cout<<wel;
	line(x,1,strlen(wel),7);
	coordinate(1,2);	cout<<"Hi Dear, our program are use for calculate the Tax in Cambodia.\n";
	coordinate(1,3);	cout<<"we have some of feature for you to choosing.\n";
	coordinate(1,5);	cout<<"Press (y) key for continuse.\n";	
	coordinate(1,4);	cout<<"Press (n) key for exit the program.\n";
	coordinate(1,6);	cout<<"(y/n): ";
}

void menu(){
	cout<<"---TAX CALCULATOR---"<<endl;
	cout<<"Please select the menu at below ...";
	char menus[] = "---Menu---";
	int x = (getScreen()-strlen(menus))/4;
	coordinate(x,2);  cout<<menus;
	line(x,3,strlen(menus),7);
	coordinate(1,4);	cout<<"1. Salary Tax. \n";
	coordinate(1,5);	cout<<"2. Value Added Tax or Sales Tax. \n";
	coordinate(1,6);	cout<<"3. Tax on Property. \n";	
	coordinate(1,7);	cout<<"4. Check Data. \n";
	coordinate(1,8);	cout<<"0. Exit. \n";
	line(1,9,50,7);
	coordinate(1,10);	cout<<"Choose: ";
	
}

void salaryTax(){
	salTax s;
	cout<<"---Salary Tax---";
	line(0,1,50,7); cout<<endl;
	cout<<"Enter Salary (Riel) : "; cin>>s.salary;
	cout<<"Enter Bonus  (Riel) : "; cin>>s.bonus;
	cout<<"Enter Spouse        : "; cin>>s.spouse;
	cout<<"Enter Child         : "; cin>>s.child;
	line(0,6,50,7); cout<<endl;
	
	//the value is take from the General Department of Taxation
	//that will post or upgrade every end of year.
	//we can get it from the General Department of Taxation website
	
	if(s.salary >= 0 && s.bonus >= 0){
		if(s.spouse >= 1){
			s.spouse = 1;
		}else{
			s.spouse = 0;
		}
		if(s.child >= 9 ){
			s.child = 9;
		}else if(s.child <= 0){
			s.child = 0;
		}
		s.family = 150000 * (s.spouse + s.child);
		s.salary = s.salary - s.family;
		if(s.salary <= 1200000){
			s.tax = 0;
			cout<<"Tax Rate: 0%."<<endl;
		}else if(s.salary <= 2000000){
			s.tax = s.salary * 0.05 - 60000;
			cout<<"Tax Rate: 5%."<<endl;
		}else if(s.salary <= 8500000){
			s.tax = s.salary * 0.1 - 160000;
			cout<<"Tax Rate: 10%."<<endl;
		}else if(s.salary <= 12500000){
			s.tax = s.salary * 0.15 - 585000;
			cout<<"Tax Rate: 15%."<<endl;
		}else {
			s.tax = s.salary * 0.2 - 1210000;
			cout<<"Tax Rate: 20%."<<endl;
		}
		
		if(s.bonus > 0){
			cout<<"your bonus Tax are automatic multi with 20% rate."<<endl;
		}
		
		s.tax += s.bonus * 0.2;
		s.lastSal = (s.salary + s.family + s.bonus) - s.tax;
		
		line(0,9,50,7);	cout<<endl;
		
		cout<<"Tax Pay    : "<<setprecision(12)<<s.tax<<" Riel"<<endl;
		cout<<"LastSalary : "<<setprecision(12)<<s.lastSal<<" Riel"<<endl;
		
	}else {
		cout<<"Invalid Input.";
	}
	
	ofstream *write = new ofstream;
	write -> open("data/dataSalaryTax.db", ios::app);
	(*write)<<setprecision(12)<<s.salary<<"  "<<setprecision(12)<<s.tax<<"  "<<setprecision(12)<<s.lastSal<<"  "<<endl;
	
	write -> close();
	delete(write);
}

void vat(){
	vats v;
	cout<<"---Value Added Tax or Sales Tax---";
	
	// line is take from headerfile design that i learn from other and make it for myself. 
	
	line(0,1,50,7); cout<<endl;
	cout<<"we have 2 feature for calculate: "<<endl;
	cout<<"(s) for standard or sales in country."<<endl;
	cout<<"(e) for service that export to other country."<<endl;
	cout<<"press (s) for standard and (e) for export."<<endl<<endl;
	line(0,6,50,7);cout<<endl;

	cout<<"(s/e)       : "; cin>>v.ch; cin.ignore();
	system("cls");
	
	cout<<"---Value Added Tax or Sales Tax---";
	line(0,1,50,7); cout<<endl;
	cout<<"which type of currency u want to calculate."<<endl;
	cout<<"(Note: r for KHR (Riel) and $ for USD ($))."<<endl;
	cout<<"KHR (r) or USD ($): "; 	cin>>v.op;
	system("cls");
	
	if(v.op == 'r'){
		cout<<"Sales Revenuse: (Riel) "; cin>>v.income; 
		if(v.income >= 0){
			if(v.ch == 's'){
				v.tax = v.income * 0.1;
				v.lastincome = v.income - v.tax;
				line(0,2,50,7);	cout<<endl;
				cout<<"Vat Rate: 10%."<<endl;
				line(0,4,50,7);	cout<<endl;
				cout<<"Tax Pay           : "<<setprecision(10)<<v.tax<<" (Riel)"<<endl;
				cout<<"Revenuse after Pay: "<<setprecision(10)<<v.lastincome<<" (Riel)"<<endl;
			}else if(v.ch == 'e'){
				v.tax = v.income * 0;
				v.lastincome = v.income - v.tax;
				line(0,2,50,7);	cout<<endl;
				cout<<"Vat Rate: 0%."<<endl;
				line(0,4,50,7);	cout<<endl;
				cout<<"Tax Pay           : "<<setprecision(10)<<v.tax<<" (Riel)"<<endl;
				cout<<"Revenuse after Pay: "<<setprecision(10)<<v.lastincome<<" (Riel)"<<endl;
			}else {
				cout<<"please enter (s) or (e) for access the feature."<<endl;
				cout<<"Thanks."<<endl;
			}
		}else {
			cout<<"Invalid Input";
		}
		
		
	}else if( v.op == '$'){
		cout<<"Sales Revenuse: $ "; cin>>v.income; 
		if(v.income >= 0){
			if(v.ch == 's'){
				v.tax = v.income * 0.1;
				v.lastincome = v.income - v.tax;
				line(0,2,50,7);	cout<<endl;
				cout<<"Vat Rate: 10%."<<endl;
				line(0,4,50,7);	cout<<endl;
				cout<<"Tax Pay           : "<<setprecision(10)<<v.tax<<" $"<<endl;
				cout<<"Revenuse after Pay: "<<setprecision(10)<<v.lastincome<<" $"<<endl;
			}else if(v.ch == 'e'){
				v.tax = v.income * 0;
				v.lastincome = v.income - v.tax;
				line(0,2,50,7);cout<<endl;
				cout<<"Vat Rate: 0%."<<endl;
				line(0,4,50,7);	cout<<endl;
				cout<<"Tax Pay           : "<<setprecision(10)<<v.tax<<" $"<<endl;
				cout<<"Revenuse after Pay: "<<setprecision(10)<<v.lastincome<<" $"<<endl;
			}else {
				cout<<"please enter (s) or (e) for access the feature."<<endl;
				cout<<"Thanks."<<endl;
				}
		}else {
			cout<<"Invalid Input";
		}
		
	}else {
		cout<<"Press key (r) for Riel Currency."<<endl;
		cout<<"Press key ($) for USD Currency. "<<endl;
		cout<<"Thanks."<<endl;
	}
	
	ofstream *write = new ofstream;
	write -> open("data/dataVat.db", ios::app);
	(*write)<<v.income<<" "<<v.tax<<" "<<v.lastincome<<" "<<endl;
	
	write -> close();
	
}

void propertyTax(){
	
	pro p;
	cout<<"---Tax on Properties---";
	
	// line is take from headerfile design that i learn from other and make it for myself. 
	
	line(0,1,50,7); cout<<endl;
	cout<<"which type of currency u want to calculate."<<endl;
	cout<<"(Note: r for KHR (Riel) and $ for USD ($))."<<endl;
	cout<<"KHR (r) or USD ($): "; 	cin>>p.op;
	system("cls");
	cout<<"---Tax on Properties---";
	line(0,1,50,7); cout<<endl;
	if(p.op == 'r'){
		cout<<"Enter Revenues : (Riel) "; cin>>p.sale;
		
		// the values and the step of calculate is take from the General Department of Taxation
		
		if(p.sale >= 0){
			line(0,3,50,7); cout<<endl;
			cout<<"Calculate Form: (( "<<setprecision(20)<<p.sale<<" * 0.8) - 100000000 ) * 0.1"<<endl;
			cout<<"0.8 is mean you have to multi 80% of your revenuse and deduct with 100000000 riel that agree from the goverment."<<endl;
			cout<<"0.1 is Tax Rate = 10%."<<endl;
			p.sale = (p.sale * 0.8) - 100000000;
			p.tax = p.sale * 0.1;
			p.afterpay = (p.sale + 100000000)/0.8 - p.tax;
			line(0,7,50,7);	cout<<endl;
			cout<<"Tax Payment            : (Riel) "<<setprecision(20)<<p.tax<<endl;
			cout<<"Revenues after payment : (Riel) "<<setprecision(20)<<p.afterpay<<endl;
		}else {
			cout<<"Invalid Input.";
		}
		
	}else if(p.op == '$'){
		cout<<"Enter Revenues : $ "; cin>>p.sale;
		if(p.sale >= 0){
			line(0,3,50,7); cout<<endl;
			cout<<"Calculate Form: (( "<<setprecision(12)<<p.sale<<" * 0.8) - 25000 ) * 0.1"<<endl;
			cout<<"0.8 is mean you have to multi 80% of your revenuse and deduct with 25000$ that agree from the goverment."<<endl;
			cout<<"0.1 is Tax Rate = 10%."<<endl;
			p.sale = (p.sale * 0.8) - 25000;
			p.tax = p.sale * 0.1;
			p.afterpay = (p.sale + 25000)/0.8 - p.tax;
			line(0,7,50,7); cout<<endl;
			cout<<"Tax Payment            : $ "<<setprecision(12)<<p.tax<<endl;
			cout<<"Revenues after payment : $ "<<setprecision(12)<<p.afterpay<<endl;
		}else {
			cout<<"Invalid Input.";
		}
		
	}else {
		cout<<"Press key (r) for Riel Currency."<<endl;
		cout<<"Press key ($) for USD Currency. "<<endl;
		cout<<"Thanks."<<endl;
	}
	
		ofstream *write = new ofstream;
		write -> open("data/propertyData.db", ios::app);
		(*write)<<p.sale<<" "<<p.tax<<" "<<p.afterpay<<" "<<endl;
		
		write -> close();
}

void salaryTaxData(){
	ifstream read;
	string data;
	int n = -1;
	
	read.open("data/dataSalaryTax.db");
	while(!read.eof()){
		getline(read, data);
		n++;
	}
	read.close();
	string s[n][3];
	cout<<endl;
	
	cout<<"Salary  /  Tax Payment  /  Salary After Payment"<<endl;
	
	read.open("data/dataSalaryTax.db");
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			read>>s[i][j];
			cout<<s[i][j]<<" R /  ";
		}
		cout<<endl;
	}
	read.close();
}

void vatData(){
	ifstream read;
	string data;
	int n = -1;
	
	read.open("data/dataVat.db");
	while(!read.eof()){
		getline(read, data);
		n++;
	}
	read.close();
	string s[n][3];
	cout<<endl;
	
	cout<<"Income/Tax Payment/Revenuse after payment"<<endl;
	
	read.open("data/dataVat.db");
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			read>>s[i][j];
			cout<<s[i][j]<<" / ";
		}
		cout<<endl;
	}
	read.close();
}

void propertyData(){
	ifstream read;
	string data;
	int n = -1;
	
	read.open("data/propertyData.db");
	while(!read.eof()){
		getline(read, data);
		n++;
	}
	read.close();
	string s[n][3];
	cout<<endl;
	
	cout<<"Properties Sales / Tax Payment / Revenuse after payment"<<endl;
	
	read.open("data/propertyData.db");
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			read>>s[i][j];
			cout<<s[i][j]<<" / ";
		}
		cout<<endl;
	}
	read.close();
}

void clearSalary(){
	ifstream read;
	string data;
	int n=0;
	
	// read to get line data till end of data
	
	read.open("data/dataSalaryTax.db");
	while (!read.eof()){
		getline(read,data);
		n++;
	}
	read.close();
	
	// read every line and column
	
	string s[n][3];
	read.open("data/dataSalaryTax.db");
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			read>>s[i][j];
		}
	}
	read.close();
	
	//after read we have to write a space for clear
	
	ofstream write;
	write.open("data/dataSalaryTax.db");
	for(int i=0;i<n;i++){
		write<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<" ";
	}
	write.close();
}

void clearVat(){
	ifstream read;
	string data;
	int n=0;
	// read to get line data till end of data
	read.open("data/dataVat.db");
	while (!read.eof()){
		getline(read,data);
		n++;
	}
	read.close();
	// read every line and column
	string s[n][3];
	read.open("data/dataVat.db");
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			read>>s[i][j];
		}
	}
	read.close();
	//after read we have to write a space for clear 
	ofstream write;
	write.open("data/dataVat.db");
	for(int i=0;i<n;i++){
		write<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<" ";
	}
	write.close();
}

void clearProperty(){
	ifstream read;
	string data;
	int n=0;
	
	//same as vat and salary
	
	read.open("data/propertyData.db");
	while (!read.eof()){
		getline(read,data);
		n++;
	}
	read.close();
	
	string s[n][3];
	read.open("data/propertyData.db");
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			read>>s[i][j];
		}
	}
	read.close();
	
	ofstream write;
	write.open("data/propertyData.db");
	for(int i=0;i<n;i++){
		write<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<" ";
	}
	write.close();
}

void clear(){
	clearSalary();
	clearVat();
	clearProperty();
}

void datamenu(){
	cout<<"---Data---";
	line(0,1,50,7); cout<<endl;
	cout<<"1. Salary Tax Data"<<endl;
	cout<<"2. Values Added Tax Data"<<endl;
	cout<<"3. Tax on Property Data"<<endl;
	cout<<"4. Clear Data"<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"<. Back"<<endl;
	line(0,8,50,7); cout<<endl;
	cout<<"Options: ";
}


