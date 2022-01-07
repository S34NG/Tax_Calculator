/*
Project Assignment
Type		:		Tax Calculator
Creator		:	Lim Seang
Class		:		FT SD A 2
WriteDate	:	07/19/2021
FinishDate	:	07/26/2021
submit		:	07/28/2021
License		:	MIT
Copyright
*/

#include <iostream>
#include <windows.h>
#include <dir.h>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <dos.h> //delay
#include "bin\design.h"
#include "bin\Interface.h"
 
using namespace std;

int main(int argc, char** argv) {
	mkdir("data");
	opt op;
	
	do{
		welcome();
		cin>>op.op; cin.ignore();
		switch(op.op){
			case 'y':{
				system("cls");
				do{
					menu();
					cin>>op.op; cin.ignore();
					switch(op.op){
						case '1':{
							system("cls");
							salaryTax();
							getch();
							break;
						}
						case '2':{
							system("cls");
							vat();
							getch();
							break;
						}
						case '3':{
							system("cls");
							propertyTax();
							getch();
							break;
						}
						case '4':{
							system("cls");
							do{
							datamenu();
							cin>>op.op; cin.ignore();
								switch(op.op){
									case '1':{
										system("cls");
										salaryTaxData();
										getch();
										break;
									}
									case '2':{
										system("cls");
										vatData();
										getch();
										break;
									}
									case '3':{
										system("cls");
										propertyData();
										getch();
										break;
									}
									case '4':{
										system("cls");
										clear();
										cout<<"Clear Successfully."<<endl;
										cout<<"Thanks."<<endl;
										getch();
										break;
									}
									case '0':{
										exit();
										break;
									}
									case '<':{
										system("cls");
										break;
									}
									default :{
										system("cls");
										cout<<"please choose the correct the option to access the feature."<<endl;
										cout<<"1-4 to access the feature 0 to exit the program and < for back to menu system."<<endl;
										cout<<"press any key to continues the program."<<endl;
										cout<<"Thanks "<<endl;
										getch();
										break;
									}
								}
								system("cls");
							} while (op.op != '<');
							break;
						}
						case '0':{
							exit();
							break;
						}
						default:{
							cout<<"Please Choose between 1-4 and 0 for exit the program."<<endl;
							cout<<"thanks."<<endl;
							break;
						}
					}
					system("cls");
				}while(op.op != '0');
			}
			case 'n':{
				exit();
				break;
			}
			default :{
				system("cls");
				cout<<"your choose are out of zone.\n";
				cout<<"Please try again.\n";
				cout<<"Press (ENTER) for continues."<<endl;
				getch();
				system("cls");
				break;
			}
		} 
	} while(op.op != 'n');
	return 0;
}
