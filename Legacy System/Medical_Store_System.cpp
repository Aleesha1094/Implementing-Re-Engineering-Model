#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;
class MedicalSystem{
	private:
		//For Medicine
		int MID;
		char Title[20];
		char Manufacturer[20];
		char Expiry[20];
		char Price[20];
		int Stock;
		char Disease[20];
		//For Sale Person
		int SID;
		char Fname[20];
		char Lname[20];
		char City[20];
		char Datejoining[20];
		char Salary[20];
		char Phonenum[20];
	public:
		//Constructor
		MedicalSystem(){
			MID=0;
			SID=0;
			strcpy(Title," ");
			strcpy(Manufacturer," ");
			strcpy(Price," ");
			strcpy(Expiry," ");
			strcpy(Disease," ");
			Stock=0;
			strcpy(Fname," ");
			strcpy(Lname," ");
			strcpy(City," ");
			strcpy(Datejoining," ");
			strcpy(Salary," ");
			strcpy(Phonenum," ");
		}
		void SaleMEd(MedicalSystem Obb){
			int IDD,NStock;
            cout<<"*************************************\n";
    		cout<<"----------------------------------------------------------------------------------------------------\n"; 
			cout<<"\n\t\t---------------Sale New Medicine---------------\n";
			cout<<"*************************************\n";
    		cout<<"----------------------------------------------------------------------------------------------------\n";
			cout<<"\nFollowing Medicine Stock Available : \n\n";
			Obb.DisplayMedRecord(Obb);
			cout<<"\nEnter ID of Medicine you want to Sell : ";
			cin>>IDD;
			fstream NFile("Med_Data.dat",ios::out|ios::binary|ios::in);
			if(!NFile){
				cout<<"File could not be found"<<endl;
				system("pause"); exit(1);
			}
			NFile.seekg((IDD-1)*sizeof(MedicalSystem));
			NFile.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
			Obb.MID=IDD;
			cerr<<endl<<left<<setw(10)<<"ID";cerr<<setw(16)<<"Title";cerr<<setw(16)<<"Manufacturer";cerr<<setw(16)<<"Expiry";cerr<<setw(16)<<"Price";cerr<<setw(16)<<"Stock"<<setw(16)<<"Disease"<<endl<<endl;
			cerr<<left<<setw(10)<<Obb.MID;cerr<<setw(16)<<Obb.Title;cerr<<setw(16)<<Obb.Manufacturer;cerr<<setw(16)<<Obb.Expiry;cerr<<setw(16)<<Obb.Price;cerr<<setw(16)<<Obb.Stock;cerr<<setw(16)<<Obb.Disease<<endl;
			cout<<"\n\nAvailable stock for current Medicine : ";
			cout<<Obb.Stock;
			cout<<"\n\nEnter Stock you want to sell : ";
			cin>>NStock;
			Obb.Stock=Obb.Stock-NStock;
			cout<<"\nMedicine sell successfully.\n\n";
			strcpy(Obb.Title,Obb.Title);strcpy(Obb.Manufacturer,Obb.Manufacturer);strcpy(Obb.Expiry,Obb.Expiry);strcpy(Obb.Price,Obb.Price);Obb.Stock=Obb.Stock; 
			NFile.seekp((IDD-1)*sizeof(MedicalSystem));
			NFile.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
			NFile.close();
			cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";
		}
		void AddMedRecordNew(MedicalSystem Obb){
			system("cls");
			fstream File("Med_Data.dat",ios::out|ios::binary);
			if(!File){
				cout<<"File could not be found"<<endl;
				system("pause"); exit(1);
			}
			for(int i=0;i<100;i++){
				File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
			}
			File.close();
			char ans='a';
			int i=1;
			cout<<"\n\t\t---------------Add Medicine Record---------------\n";
			fstream Add_File("Med_Data.dat",ios::out|ios::binary);
			if(!Add_File){
				cout<<"File not founded"<<endl;
				system("pause"); exit(1);
			}
			while(true){
				if(i==100){
					cout<<"File capacity reached"<<endl;
					break;
				}
				else if(ans=='y'||ans=='Y'){
					break;
				}
				else{
					Obb.MID=i;
					cout<<"Enter Medicine Title : ";
					cin>>Obb.Title;
					cout<<"Enter Medicine Manufacturer : ";
					cin>>Obb.Manufacturer;
					cout<<"Enter Medicine Expiry : ";
					cin>>Obb.Expiry;
					cout<<"Enter Medicine Price : ";
					cin>>Obb.Price;
					cout<<"Enter Medicine Stock : ";
					cin>>Obb.Stock;
					cout<<"Enter Medicine Disease : ";
					cin>>Obb.Disease;
					Add_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
					cout<<"*************************************\n";
    	        	cout<<"----------------------------------------------------------------------------------------------------\n"; 
					cout<<"\n\n\t\t-----------------Record added successfully----------------\n";
                    cout<<"*************************************\n";
    		        cout<<"----------------------------------------------------------------------------------------------------\n"; 		
					cout<<"\nDo you wish to stop entering new records?  (y to exit) :"; cin>>ans;
					cout<<"\t\t---------------------------------\n";
				}
				i++;
			}
			File.close();
		}
		void AddMedRecord(MedicalSystem Obb){
			system("cls");
			cout<<"\n\t\t---------------Add Medicine Record---------------\n";
			char ans='a';
			int i=1;
			fstream File("Med_Data.dat",ios::out|ios::in|ios::binary);
			if(!File){
				cout<<"File not found";
				system("pause");exit(1);
			}
			File.clear();
			File.seekg(0L,ios::beg);
			while(!File.eof()){
				File.read((char *)(&Obb),sizeof(MedicalSystem));
				if(File.eof()){break;}
				if(Obb.MID!=0){
					i++;
				}
			}
			File.clear();
			File.seekg((i-1)*sizeof(MedicalSystem));
			while(true){
				if(i==100){
					cout<<"File capacity reached"<<endl;
					break;
				}
				else if(ans=='y'||ans=='Y'){
					break;
				}
				else{
					Obb.MID=i;
					cout<<"Enter Medicine Title : ";
					cin>>Obb.Title;
					cout<<"Enter Medicine Manufacturer : ";
					cin>>Obb.Manufacturer;
					cout<<"Enter Medicine Expiry : ";
					cin>>Obb.Expiry;
					cout<<"Enter Medicine Price : ";
					cin>>Obb.Price;
					cout<<"Enter Medicine Stock : ";
					cin>>Obb.Stock;
					cout<<"Enter Medicine Disease : ";
					cin>>Obb.Disease;
					File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
                    cout<<"*************************************\n";
    		        cout<<"----------------------------------------------------------------------------------------------------\n"; 	
					cout<<"\n\n\t\t-----------------Record added successfully----------------\n";
                    cout<<"*************************************\n";
    		        cout<<"----------------------------------------------------------------------------------------------------\n"; 			
					cout<<"\nDo you wish to stop entering new records?  (y to exit) : "; cin>>ans;
					cout<<"\t\t---------------------------------\n";
				}
				i++;
			}
			File.close();
		}
		void AddSalepersonRecord(MedicalSystem Obb){
			system("cls");
			cout<<"\n\t\t---------------Add Sale Person Record---------------\n";
			char ans='a';
			int i=1;
			fstream SA_File("Sale_Data.dat",ios::out|ios::in|ios::binary);
			if(!SA_File){
				cout<<"File not found";
				system("pause");exit(1);
			}
			SA_File.clear();
			SA_File.seekg(0L,ios::beg);
			while(!SA_File.eof()){
				SA_File.read((char *)(&Obb),sizeof(MedicalSystem));
				if(SA_File.eof()){break;}
				if(Obb.SID!=0){
					i++;
				}
			}
			SA_File.clear();
			SA_File.seekg((i-1)*sizeof(MedicalSystem));
			while(true){
				if(i==100){
					cout<<"File capacity reached"<<endl;
					break;
				}
				else if(ans=='y'||ans=='Y'){
					break;
				}
				else{
					Obb.SID=i;
					cout<<"Enter First Name : ";
					cin>>Obb.Fname;
					cout<<"Enter Last Name : ";
					cin>>Obb.Lname;
					cout<<"Enter City : ";
					cin>>Obb.City;
					cout<<"Enter Date Of Joining : ";
					cin>>Obb.Datejoining;
					cout<<"Enter Salery : ";
					cin>>Obb.Salary;
					cout<<"Enter Phone Number : ";
					cin>>Obb.Phonenum;
					SA_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
                    cout<<"*************************************\n";
    		        cout<<"----------------------------------------------------------------------------------------------------\n"; 		
					cout<<"\n\n\t\t-----------------Record added successfully----------------\n";
                    cout<<"*************************************\n";
    		        cout<<"----------------------------------------------------------------------------------------------------\n"; 		
					cout<<"\nDo you wish to stop entering new records?  (y to exit) : "; cin>>ans;
					cout<<"\t\t---------------------------------\n";
				}
				i++;
			}
			SA_File.close();
		}
		void AddSalepersonRecordNew(MedicalSystem Obb){
			system("cls");
			fstream S_File("Sale_Data.dat",ios::out|ios::binary);
			if(!S_File){
				cout<<"File could not be found"<<endl;
				system("pause"); exit(1);
			}
			for(int i=0;i<100;i++){
				S_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
			}
			S_File.close();
			char ans='a';
			int i=1;
			cout<<"\n\t\t---------------Add Sale Person Record---------------\n";
			fstream AddS_File("Sale_Data.dat",ios::out|ios::binary);
			if(!AddS_File){
				cout<<"File not founded"<<endl;
				system("pause"); exit(1);
			}
			while(true){
				if(i==100){
					cout<<"File capacity reached"<<endl;
					break;
				}
				else if(ans=='y'||ans=='Y'){
					break;
				}
				else{
					Obb.SID=i;
					cout<<"Enter First Name : ";
					cin>>Obb.Fname;
					cout<<"Enter Last Name : ";
					cin>>Obb.Lname;
					cout<<"Enter City : ";
					cin>>Obb.City;
					cout<<"Enter Date Of Joining : ";
					cin>>Obb.Datejoining;
					cout<<"Enter Salery : ";
					cin>>Obb.Salary;
					cout<<"Enter Phone Number : ";
					cin>>Obb.Phonenum;
					AddS_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
                    cout<<"*************************************\n";
    		        cout<<"----------------------------------------------------------------------------------------------------\n"; 	
					cout<<"\n\n\t\t-----------------Record added successfully----------------\n";
                    cout<<"*************************************\n";
    		        cout<<"----------------------------------------------------------------------------------------------------\n"; 			
					cout<<"\nDo you wish to stop entering new records?  (y to exit) : "; cin>>ans;
					cout<<"\t\t---------------------------------\n";
				}
				i++;
			}
			AddS_File.close();
		}
		void DisplayMedRecord(MedicalSystem Obb){
			system("cls");
			cout<<"\t\t---------------Displaying Medicine Record---------------\n\n";
			fstream Dis_File("Med_Data.dat",ios::in);
			if(!Dis_File){
				cout<<"File not found"<<endl;
				system("pause"); exit(1);
			}
			cerr<<left<<setw(10)<<"ID";cerr<<setw(16)<<"Title";cerr<<setw(16)<<"Manufacturer";cerr<<setw(16)<<"Expiry";cerr<<setw(16)<<"Price";cerr<<setw(16)<<"Stock"<<setw(16)<<"Disease"<<endl<<endl; 
			while(!Dis_File.eof()){
				Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
				if(Dis_File.eof()){break;}
				if(Obb.MID!=0){
					cerr<<left<<setw(10)<<Obb.MID;cerr<<setw(16)<<Obb.Title;cerr<<setw(16)<<Obb.Manufacturer;cerr<<setw(16)<<Obb.Expiry;cerr<<setw(16)<<Obb.Price;cerr<<setw(16)<<Obb.Stock;cerr<<setw(16)<<Obb.Disease<<endl;
				}
			}
			Dis_File.close();
			cout<<endl;
		}
		void DisplaySalePersonRecord(MedicalSystem Obb){
			system("cls");
			cout<<"\t\t---------------Displaying Sale Person Record---------------\n\n";
			fstream Disp_File("Sale_Data.dat",ios::in);
			if(!Disp_File){
				cout<<"File not found"<<endl;
				system("pause"); exit(1);
			}
			cerr<<left<<setw(10)<<"ID"<<setw(16)<<"First Name";cerr<<setw(16)<<"Last Name";cerr<<setw(16)<<"City";cerr<<setw(16)<<"Date Joining";cerr<<setw(16)<<"Salery";cerr<<setw(16)<<"Ph. Number"<<endl<<endl; 
			while(!Disp_File.eof()){
				Disp_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
				if(Disp_File.eof()){break;}
				if(Obb.SID!=0){
					cerr<<left<<setw(10)<<Obb.SID;cerr<<setw(16)<<Obb.Fname;cerr<<setw(16)<<Obb.Lname;cerr<<setw(16)<<Obb.City;cerr<<setw(16)<<Obb.Datejoining;cerr<<setw(16)<<Obb.Salary;cerr<<setw(16)<<Obb.Phonenum<<endl;
				}
			}
			Disp_File.close();
			cout<<endl;
		}
		void UpdateMedRecord(MedicalSystem Obb){
			while(true){
				system("cls");
				int ch2,IDD;
				cout<<"*************************************\n";
                cout<<"----------------------------------------------------------------------------------------------------\n"; 
				cout<<"\n\t\t------------Update Medicine Record ------------\n\n";
				cout<<"*************************************\n";
    		    cout<<"----------------------------------------------------------------------------------------------------\n"; 
				cout<<"\t1) Update Title.\n";
				cout<<"\t2) Update Manufacturer.\n";
				cout<<"\t3) Update Price.\n";
				cout<<"\t4) Update Expiry.\n";
				cout<<"\t5) Update Stock.\n";
				cout<<"\t6) Exit.\n\n";
				cout<<"Enter your choice : ";
				cin>>ch2;
				switch(ch2){
					case 1:{
						Obb.DisplayMedRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Mdicine ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Med_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.MID=IDD;
						cout<<"\nEnter New Title : ";
						cin>>Obb.Title;
						strcpy(Obb.Title,Obb.Title);strcpy(Obb.Manufacturer,Obb.Manufacturer);strcpy(Obb.Expiry,Obb.Expiry);strcpy(Obb.Price,Obb.Price);Obb.Stock=Obb.Stock; 
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";		
						system("pause");
						break;
					}
					case 2:{
						Obb.DisplayMedRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Mdicine ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Med_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.MID=IDD;
						cout<<"\nEnter New Manufacture : ";
						cin>>Obb.Manufacturer;
						strcpy(Obb.Title,Obb.Title);strcpy(Obb.Manufacturer,Obb.Manufacturer);strcpy(Obb.Expiry,Obb.Expiry);strcpy(Obb.Price,Obb.Price);Obb.Stock=Obb.Stock;strcpy(Obb.Disease,Obb.Disease); 
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";		
						system("pause");
						break;
					}
					case 3:{
						Obb.DisplayMedRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Mdicine ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Med_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.MID=IDD;
						cout<<"\nEnter New Price : ";
						cin>>Obb.Price;
						strcpy(Obb.Title,Obb.Title);strcpy(Obb.Manufacturer,Obb.Manufacturer);strcpy(Obb.Expiry,Obb.Expiry);strcpy(Obb.Price,Obb.Price);Obb.Stock=Obb.Stock;strcpy(Obb.Disease,Obb.Disease);  
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";		
						system("pause");
						break;
					}
					case 4:{
						Obb.DisplayMedRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Mdicine ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Med_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.MID=IDD;
						cout<<"\nEnter New Expiry : ";
						cin>>Obb.Expiry;
						strcpy(Obb.Title,Obb.Title);strcpy(Obb.Manufacturer,Obb.Manufacturer);strcpy(Obb.Expiry,Obb.Expiry);strcpy(Obb.Price,Obb.Price);Obb.Stock=Obb.Stock;strcpy(Obb.Disease,Obb.Disease);  
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";		
						system("pause");
						break;
					}
					case 5:{
						Obb.DisplayMedRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Mdicine ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Med_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.MID=IDD;
						cout<<"\nEnter New Stock : ";
						cin>>Obb.Stock;
						strcpy(Obb.Title,Obb.Title);strcpy(Obb.Manufacturer,Obb.Manufacturer);strcpy(Obb.Expiry,Obb.Expiry);strcpy(Obb.Price,Obb.Price);Obb.Stock=Obb.Stock;strcpy(Obb.Disease,Obb.Disease);  
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";
                        cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 		
						system("pause");
						break;
					}
					case 6:{
						break;
						break;
					}
					default:cout<<"\nInvalid Choice.\n";system("pause");break;			
				}
				if(ch2==6)break;
			}
		}
		void UpdateSaleRecord(MedicalSystem Obb){
			while(true){
				system("cls");
				int ch4,IDD;
				cout<<"*************************************\n";
    		    cout<<"----------------------------------------------------------------------------------------------------\n"; 
				cout<<"\n\t\t------------Update Sale Person Record ------------\n\n";
				cout<<"*************************************\n";
                cout<<"----------------------------------------------------------------------------------------------------\n"; 
				cout<<"\t1) Update First Name.\n";
				cout<<"\t2) Update Last Name.\n";
				cout<<"\t3) Update City.\n";
				cout<<"\t4) Update Phone Number.\n";
				cout<<"\t5) Update Salery.\n";
				cout<<"\t6) Exit.\n\n";
				cout<<"Enter your choice : ";
				cin>>ch4;
				switch(ch4){
					case 1:{
						Obb.DisplaySalePersonRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Sale person ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Sale_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.SID=IDD;
						cout<<"\nEnter New First Name : ";
						cin>>Obb.Fname;
						strcpy(Obb.Fname,Obb.Fname);strcpy(Obb.Lname,Obb.Lname);strcpy(Obb.City,Obb.City);strcpy(Obb.Datejoining,Obb.Datejoining);strcpy(Obb.Phonenum,Obb.Phonenum);strcpy(Obb.Salary,Obb.Salary);
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";
                        cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 		
						system("pause");
						break;
					}
					case 2:{
						Obb.DisplaySalePersonRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Sale person ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Sale_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.SID=IDD;
						cout<<"\nEnter New Last Name : ";
						cin>>Obb.Lname;
						strcpy(Obb.Fname,Obb.Fname);strcpy(Obb.Lname,Obb.Lname);strcpy(Obb.City,Obb.City);strcpy(Obb.Datejoining,Obb.Datejoining);strcpy(Obb.Phonenum,Obb.Phonenum);strcpy(Obb.Salary,Obb.Salary);
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";
                        cout<<"*************************************\n";
                        cout<<"----------------------------------------------------------------------------------------------------\n"; 		
						system("pause");
						break;
					}
					case 3:{
						Obb.DisplaySalePersonRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Sale person ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Sale_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.SID=IDD;
						cout<<"\nEnter New City : ";
						cin>>Obb.City;
						strcpy(Obb.Fname,Obb.Fname);strcpy(Obb.Lname,Obb.Lname);strcpy(Obb.City,Obb.City);strcpy(Obb.Datejoining,Obb.Datejoining);strcpy(Obb.Phonenum,Obb.Phonenum);strcpy(Obb.Salary,Obb.Salary);
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";
                        cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 		
						system("pause");
						break;
					}
					case 4:{
						Obb.DisplaySalePersonRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Sale person ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Sale_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.SID=IDD;
						cout<<"\nEnter New Phone Number : ";
						cin>>Obb.Phonenum;
						strcpy(Obb.Fname,Obb.Fname);strcpy(Obb.Lname,Obb.Lname);strcpy(Obb.City,Obb.City);strcpy(Obb.Datejoining,Obb.Datejoining);strcpy(Obb.Phonenum,Obb.Phonenum);strcpy(Obb.Salary,Obb.Salary);
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";
                        cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 		
						system("pause");
						break;
					}
					case 5:{
						Obb.DisplaySalePersonRecord(Obb);
						cout<<"\n\n===========================================================\n\n";
						cout<<"Enter Sale person ID to be update : ";
						cin>>IDD;
						cout<<"\n\t-------Record Founded-------\n\n";
						fstream UPD_File("Sale_Data.dat",ios::in|ios::out|ios::binary);
						if(!UPD_File){
							cout<<"File Not Founded.";
							system("pause");exit(1);
						}
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						Obb.SID=IDD;
						cout<<"\nEnter New Salery : ";
						cin>>Obb.Salary;
						strcpy(Obb.Fname,Obb.Fname);strcpy(Obb.Lname,Obb.Lname);strcpy(Obb.City,Obb.City);strcpy(Obb.Datejoining,Obb.Datejoining);strcpy(Obb.Phonenum,Obb.Phonenum);strcpy(Obb.Salary,Obb.Salary);
						UPD_File.seekp((IDD-1)*sizeof(MedicalSystem));
						UPD_File.write(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
						UPD_File.close();
						cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\n\n\t\t-----------------Record Updated successfully----------------\n\n";	
                        cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 	
						system("pause");
						break;
					}
					case 6:{
						break;
						break;
					}
					default:cout<<"\nInvalid Choice.\n";system("pause");break;			
				}
				if(ch4==6)break;
			}
		}
		void DeleteMedRecord(MedicalSystem Obb){
			system("cls");
			int IDD;
			Obb.DisplayMedRecord(Obb);
			cout<<"\n\n===========================================================\n\n";
			cout<<"Enter Medicine ID to be delete : ";
			cin>>IDD;
			cout<<"*************************************\n";
    		cout<<"----------------------------------------------------------------------------------------------------\n"; 
			cout<<"\n\t-------Record Deleted Successfully-------\n\n";
			cout<<"*************************************\n";
    		cout<<"----------------------------------------------------------------------------------------------------\n"; 
			fstream Del_MED_Record("Med_Data.dat",ios::in|ios::out|ios::binary);
			if(!Del_MED_Record){
				cout<<"File Not Founded.";
				system("pause");exit(1);
			}
			MedicalSystem Empty;
			Del_MED_Record.seekg((IDD-1)*sizeof(MedicalSystem));
			Del_MED_Record.write(reinterpret_cast<char*>(&Empty),sizeof(MedicalSystem));
			Del_MED_Record.close();
		}
		void DeleteSaleRecord(MedicalSystem Obb){
			system("cls");
			int IDD;
			Obb.DisplaySalePersonRecord(Obb);
			cout<<"\n\n===========================================================\n\n";
			cout<<"Enter Sale Person ID to be delete : ";
			cin>>IDD;
			cout<<"*************************************\n";
    		cout<<"----------------------------------------------------------------------------------------------------\n"; 
			cout<<"\n\t-------Record Deleted Successfully-------\n\n";
			cout<<"*************************************\n";
    		cout<<"----------------------------------------------------------------------------------------------------\n"; 
			fstream Del_Sale_Record("Sale_Data.dat",ios::in|ios::out|ios::binary);
			if(!Del_Sale_Record){
				cout<<"File Not Founded.";
				system("pause");exit(1);
			}
			MedicalSystem Empty;
			Del_Sale_Record.seekg((IDD-1)*sizeof(MedicalSystem));
			Del_Sale_Record.write(reinterpret_cast<char*>(&Empty),sizeof(MedicalSystem));
			Del_Sale_Record.close();
		}
		void SaleMed(MedicalSystem Obb){
			
		}
		void DisplaySaleRec_with_ID(MedicalSystem Obb){
			while(true){
				system("cls");
				int ch3;
				cout<<"\n\t\t------------Display Data With------------\n\n";
				cout<<"\t1) With First Name.\n";
				cout<<"\t2) With Last Name.\n";
				cout<<"\t3) With City.\n";
				cout<<"\t4) With Phone number.\n";
				cout<<"\t5) Exit.\n\n";
				cout<<"Enter your choice : ";
				cin>>ch3;
				switch(ch3){
					case 1:{
                         cout<<"*************************************\n";
    		             cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\t\t---------------Displaying Sale Person Record with First Name---------------\n\n";
						cout<<"*************************************\n";
    		            cout<<"----------------------------------------------------------------------------------------------------\n"; 
						cout<<"\nEnter First Name you want to search : ";string RTitle;cin>>RTitle;
						fstream Dis_File("Sale_Data.dat",ios::in);
						if(!Dis_File){
							cout<<"File not found"<<endl;
							system("pause"); exit(1);
						}
						bool found=false;
						while(!Dis_File.eof()){
							Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
							if(Dis_File.eof()){break;}
							if(RTitle==Obb.Fname){
								found=true;
								cerr<<left<<setw(10)<<"ID"<<setw(16)<<"First Name";cerr<<setw(16)<<"Last Name";cerr<<setw(16)<<"City";cerr<<setw(16)<<"Date Joining";cerr<<setw(16)<<"Salery";cerr<<setw(16)<<"Ph. Number"<<endl<<endl; 
								cerr<<left<<setw(10)<<Obb.SID;cerr<<setw(16)<<Obb.Fname;cerr<<setw(16)<<Obb.Lname;cerr<<setw(16)<<Obb.City;cerr<<setw(16)<<Obb.Datejoining;cerr<<setw(16)<<Obb.Salary;cerr<<setw(16)<<Obb.Phonenum<<endl;
							}
						}
						if(found==true){
							cout<<"\n\n";
							system("pause");
						}
						if(found==false){
							cout<<"\nNo match found"<<endl;system("pause");
						}
						Dis_File.close();
						cout<<endl;
						break;
					}
					case 2:{
						cout<<"\t\t---------------Displaying Sale Person Record with Last Name---------------\n\n";
						cout<<"\nEnter Last Name you want to search : ";string RTitle;cin>>RTitle;
						fstream Dis_File("Sale_Data.dat",ios::in);
						if(!Dis_File){
							cout<<"File not found"<<endl;
							system("pause"); exit(1);
						}
						bool found=false;
						while(!Dis_File.eof()){
							Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
							if(Dis_File.eof()){break;}
							if(RTitle==Obb.Lname){
								found=true;
								cerr<<left<<setw(10)<<"ID"<<setw(16)<<"First Name";cerr<<setw(16)<<"Last Name";cerr<<setw(16)<<"City";cerr<<setw(16)<<"Date Joining";cerr<<setw(16)<<"Salery";cerr<<setw(16)<<"Ph. Number"<<endl<<endl; 
								cerr<<left<<setw(10)<<Obb.SID;cerr<<setw(16)<<Obb.Fname;cerr<<setw(16)<<Obb.Lname;cerr<<setw(16)<<Obb.City;cerr<<setw(16)<<Obb.Datejoining;cerr<<setw(16)<<Obb.Salary;cerr<<setw(16)<<Obb.Phonenum<<endl;
							}
						}
						if(found==true){
							cout<<"\n\n";
							system("pause");
						}
						if(found==false){
							cout<<"\nNo match found"<<endl;system("pause");
						}
						Dis_File.close();
						cout<<endl;
						break;
					}
					case 3:{
						cout<<"\t\t---------------Displaying Sale Person Record with City---------------\n\n";
						cout<<"\nEnter City you want to search : ";string RTitle;cin>>RTitle;
						fstream Dis_File("Sale_Data.dat",ios::in);
						if(!Dis_File){
							cout<<"File not found"<<endl;
							system("pause"); exit(1);
						}
						bool found=false;
						while(!Dis_File.eof()){
							Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
							if(Dis_File.eof()){break;}
							if(RTitle==Obb.City){
								found=true;
								cerr<<left<<setw(10)<<"ID"<<setw(16)<<"First Name";cerr<<setw(16)<<"Last Name";cerr<<setw(16)<<"City";cerr<<setw(16)<<"Date Joining";cerr<<setw(16)<<"Salery";cerr<<setw(16)<<"Ph. Number"<<endl<<endl; 
								cerr<<left<<setw(10)<<Obb.SID;cerr<<setw(16)<<Obb.Fname;cerr<<setw(16)<<Obb.Lname;cerr<<setw(16)<<Obb.City;cerr<<setw(16)<<Obb.Datejoining;cerr<<setw(16)<<Obb.Salary;cerr<<setw(16)<<Obb.Phonenum<<endl;
							}
						}
						if(found==true){
							cout<<"\n\n";
							system("pause");
						}
						if(found==false){
							cout<<"\nNo match found"<<endl;system("pause");
						}
						Dis_File.close();
						cout<<endl;
						break;
					}
					case 4:{
						cout<<"\t\t---------------Displaying Sale Person Record with Phone Name---------------\n\n";
						cout<<"\nEnter Phone number you want to search : ";string RTitle;cin>>RTitle;
						fstream Dis_File("Sale_Data.dat",ios::in);
						if(!Dis_File){
							cout<<"File not found"<<endl;
							system("pause"); exit(1);
						}
						bool found=false;
						while(!Dis_File.eof()){
							Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
							if(Dis_File.eof()){break;}
							if(RTitle==Obb.Phonenum){
								found=true;
								cerr<<left<<setw(10)<<"ID"<<setw(16)<<"First Name";cerr<<setw(16)<<"Last Name";cerr<<setw(16)<<"City";cerr<<setw(16)<<"Date Joining";cerr<<setw(16)<<"Salery";cerr<<setw(16)<<"Ph. Number"<<endl<<endl; 
								cerr<<left<<setw(10)<<Obb.SID;cerr<<setw(16)<<Obb.Fname;cerr<<setw(16)<<Obb.Lname;cerr<<setw(16)<<Obb.City;cerr<<setw(16)<<Obb.Datejoining;cerr<<setw(16)<<Obb.Salary;cerr<<setw(16)<<Obb.Phonenum<<endl;
							}
						}
						if(found==true){
							cout<<"\n\n";
							system("pause");
						}
						if(found==false){
							cout<<"\nNo match found"<<endl;system("pause");
						}
						Dis_File.close();
						cout<<endl;
						break;
					}
					case 5:break;
					default:cout<<"\nInvalid Choice.";system("pause");break;
				}
				if(ch3==5)break;
			}
		}
		void DisplayMedRec_with_MedID(MedicalSystem Obb){
			while(true){
				system("cls");
				int ch1;
				cout<<"*************************************\n";
    		    cout<<"----------------------------------------------------------------------------------------------------\n"; 
				cout<<"\n\t\t------------Display Data With------------\n\n";
				cout<<"*************************************\n";
                cout<<"----------------------------------------------------------------------------------------------------\n"; 
				cout<<"\t1) With Title.\n";
				cout<<"\t2) With Manufacturer.\n";
				cout<<"\t3) With Disease.\n";
				cout<<"\t4) Exit.\n\n";
				cout<<"Enter your choice : ";
				cin>>ch1;
				switch(ch1){
					case 1:{
						cout<<"\t\t---------------Displaying Medicine Record with Title---------------\n\n";
						cout<<"\nEnter Title you want to search : ";string RTitle;cin>>RTitle;
						fstream Dis_File("Med_Data.dat",ios::in);
						if(!Dis_File){
							cout<<"File not found"<<endl;
							system("pause"); exit(1);
						}
						bool found=false;
						while(!Dis_File.eof()){
							Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
							if(Dis_File.eof()){break;}
							if(RTitle==Obb.Title){
								found=true;
								cerr<<endl<<left<<setw(10)<<"ID";cerr<<setw(16)<<"Title";cerr<<setw(16)<<"Manufacturer";cerr<<setw(16)<<"Expiry";cerr<<setw(16)<<"Price";cerr<<setw(16)<<"Stock"<<setw(16)<<"Disease"<<endl<<endl;
								cerr<<left<<setw(10)<<Obb.MID;cerr<<setw(16)<<Obb.Title;cerr<<setw(16)<<Obb.Manufacturer;cerr<<setw(16)<<Obb.Expiry;cerr<<setw(16)<<Obb.Price;cerr<<setw(16)<<Obb.Stock;cerr<<setw(16)<<Obb.Disease<<endl;
							}
						}
						if(found==true){
							cout<<"\n\n";
							system("pause");
						}
						if(found==false){
							cout<<"\nNo match found"<<endl;system("pause");
						}
						Dis_File.close();
						cout<<endl;
						break;
					}
					case 2:{
						cout<<"\t\t---------------Displaying Medicine Record with Manufacturer---------------\n\n";
						cout<<"\nEnter Manufacturer you want to search : ";string RTitle;cin>>RTitle;
						fstream Dis_File("Med_Data.dat",ios::in);
						if(!Dis_File){
							cout<<"File not found"<<endl;
							system("pause"); exit(1);
						}
						bool found=false;
						while(!Dis_File.eof()){
							Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
							if(Dis_File.eof()){break;}
							if(RTitle==Obb.Manufacturer){
								found=true;
								cerr<<endl<<left<<setw(10)<<"ID";cerr<<setw(16)<<"Title";cerr<<setw(16)<<"Manufacturer";cerr<<setw(16)<<"Expiry";cerr<<setw(16)<<"Price";cerr<<setw(16)<<"Stock"<<setw(16)<<"Disease"<<endl;
								cerr<<left<<setw(10)<<Obb.MID;cerr<<setw(16)<<Obb.Title;cerr<<setw(16)<<Obb.Manufacturer;cerr<<setw(16)<<Obb.Expiry;cerr<<setw(16)<<Obb.Price;cerr<<setw(16)<<Obb.Stock;cerr<<setw(16)<<Obb.Disease<<endl;
							}
						}
						if(found==true){
							cout<<"\n\n";
							system("pause");
						}
						if(found==false){
							cout<<"\nNo match found"<<endl;system("pause");
						}
						Dis_File.close();
						cout<<endl;
						break;
					}
					case 3:{
						cout<<"\t\t---------------Displaying Medicine Record with Disease---------------\n\n";
						cout<<"\nEnter Disease you want to search : ";string RTitle;cin>>RTitle;
						fstream Dis_File("Med_Data.dat",ios::in);
						if(!Dis_File){
							cout<<"File not found"<<endl;
							system("pause"); exit(1);
						}
						bool found=false;
						while(!Dis_File.eof()){
							Dis_File.read(reinterpret_cast<char*>(&Obb),sizeof(MedicalSystem));
							if(Dis_File.eof()){break;}
							if(RTitle==Obb.Disease){
								found=true;
								cerr<<endl<<left<<setw(10)<<"ID";cerr<<setw(16)<<"Title";cerr<<setw(16)<<"Manufacturer";cerr<<setw(16)<<"Expiry";cerr<<setw(16)<<"Price";cerr<<setw(16)<<"Stock"<<setw(16)<<"Disease"<<endl;
								cerr<<left<<setw(10)<<Obb.MID;cerr<<setw(16)<<Obb.Title;cerr<<setw(16)<<Obb.Manufacturer;cerr<<setw(16)<<Obb.Expiry;cerr<<setw(16)<<Obb.Price;cerr<<setw(16)<<Obb.Stock;cerr<<setw(16)<<Obb.Disease<<endl;
							}
						}
						if(found==true){
							cout<<"\n\n";
							system("pause");
						}
						if(found==false){
							cout<<"\nNo match found"<<endl;system("pause");
						}
						Dis_File.close();
						cout<<endl;
						break;
					}
					case 4:break;
					default:cout<<"\nInvalid Choice.";system("pause");break;
				}
				if(ch1==4)break;
			}
		}
};
MedicalSystem Obb;
//MENU Function
void Menu(MedicalSystem*Obj){
	int choice;
	cout<<"\n\n\t\t\t\t******************\n";
	cout<<"\t\t\t\t             Medical Store Management System";
	cout<<"\n\t\t\t\t******************\n";
	cout<<"\t\tFor Medicine :\n\n";
	cout<<"\t\t\t 1) Add Medicine Record.\n";
	cout<<"\t\t\t 2) Display Medicine Record.\n";
	cout<<"\t\t\t 3) Display Medicine Record with related data.\n";
	cout<<"\t\t\t 4) Update Medicine Record.\n";
	cout<<"\t\t\t 5) Delete Medicine Record.\n\n";
	cout<<"\t\tFor Sale Person :\n\n";
	cout<<"\t\t\t 6) Add Sale Person Record.\n";
	cout<<"\t\t\t 7) Display Sale Person Record.\n";
	cout<<"\t\t\t 8) Display Sale Person Record with related data.\n";
	cout<<"\t\t\t 9) Update Sale Person Record.\n";
	cout<<"\t\t\t 10) Delete Sale Person Record.\n\n";
	cout<<"\t\tSale Medicine : \n\n";
	cout<<"\t\t\t 11) Sale New Medicine.\n";
	cout<<"\t\t\t 12) Exit\n";
	cout<<"\tEnter choice : ";
	cin>>choice;
	switch(choice){
		case 1:{
			cout<<"Do you want to enter new records by removing previous? (y to create NEW) : "; char res; cin>>res;
			if(res=='y'||res=='Y'){
				Obj->AddMedRecordNew(Obb);system("pause");break;
			}
			else{
				Obj->AddMedRecord(Obb);system("pause");break;
			}
			break;
		}
		case 2:Obj->DisplayMedRecord(Obb);system("pause");break;
		case 3:Obj->DisplayMedRec_with_MedID(Obb);system("pause");break;
		case 4:Obj->UpdateMedRecord(Obb);system("pause");break;
		case 5:Obj->DeleteMedRecord(Obb);system("pause");break;
		case 6:{
			cout<<"Do you want to enter new records by removing previous? (y to create NEW) : "; char res; cin>>res;
			if(res=='y'||res=='Y'){
				Obj->AddSalepersonRecordNew(Obb);system("pause");break;
			}
			else{
				Obj->AddSalepersonRecord(Obb);system("pause");break;
			}
			break;
		}
		case 7:Obj->DisplaySalePersonRecord(Obb);system("pause");break;
		case 8:Obj->DisplaySaleRec_with_ID(Obb);system("pause");break;
		case 9:Obj->UpdateSaleRecord(Obb);system("pause");break;
		case 10:Obj->DeleteSaleRecord(Obb);system("pause");break;
		case 11:Obj->SaleMEd(Obb);system("pause");break;
		case 12:exit(1);system("pause");break;
		default:cout<<"\nInvalid Input.\n";system("pause");break;
	}
}
int main(){
	MedicalSystem *Obj1;
	while(true){
		system("cls");
		Menu(Obj1);
	}
	return 0;
}
