#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<fstream>
#include<algorithm>
#include<map>
#include<iterator>
#include<vector>
#include<cstdio>
#include<stdlib.h>
using namespace std;


long int empcnt=20000;
class registration
{
	public:
	string name,email,address,password,rpassword,status;
	int age;
	double mobile;
	public:
		void getdetails()
		{
			cout<<"Enter your name : "<<endl;
			cin>>name;
			cout<<"Enter your age : "<<endl;
			cin>>age;
			cout<<"Enter the Mobile Number : "<<endl;
			cin>>mobile;
			cout<<"Enter the Email ID : "<<endl;
			cin>>email;
			cout<<"Enter your current address : "<<endl;
			cin>>address;
			cout<<"Create your login password : "<<endl;
			cin>>password;
			cout<<"Enter the Unique keyword to recover password : "<<endl;
			cin>>rpassword;
			cout<<"Enter your current status"<<"\t"<<"EMPLOYEE OR EMPLOYER"<<endl;
			cin>>status;
		}


		void showdetails()
		{
			cout<<"1.NAME : "<<name<<endl;
			cout<<"2.AGE : "<<age<<endl;
			cout<<"3.MOBILE_NO : "<<mobile<<endl;
			cout<<"4.EMAIL ID : "<<email<<endl;
			cout<<"5.ADDRESS : "<<address<<endl;
		}

		void editdetails()
		{
			cout<<"Your Profile Details are : "<<endl;
			showdetails();
			int choice;
			int nage;
			string nname;
			double nmobile;
			string nemail;
			string naddress;
			cout<<"Enter the Detail No. to be changed : "<<endl;
			cin>>choice;
			switch(choice)
			{
				case 1: 
					cout<<"Enter your name correctly : "<<endl;
					cin>>nname;
					name=nname;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;

				case 2:
					cout<<"Enter the age : "<<endl;
					cin>>nage;
					age=nage;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;
				
				case 3: 
					cout<<"Enter the Mobile Number : "<<endl;
					cin>>nmobile;
					mobile=nmobile;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;
			
				case 4: 
					cout<<"Enter the Email_ID : "<<endl;
					cin>>nemail;
					email=nemail;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;

				case 5: 
					cout<<"Enter the Address : "<<endl;
					cin>>naddress;
					address=naddress;
					cout<<"Your Profile Updated Successfully !"<<endl;
					break;

				default:cout<<"You have choosen invalid option ! "<<endl;
					exit(1);
			}
		}

	
		void setdetails()
		{}

};



class login:public registration
{
	int loginattempt=0;
	double lmobile;
	string lpassword;
	public:
		bool validate()
		{

			while(loginattempt<5)
			{
				cout<<"Please enter your registered mobile number : "<<endl;
				cin>>lmobile;
				cout<<"Please enter your login password : "<<endl;
				cin>>lpassword;

				if(lmobile==mobile && password==lpassword)
				{
					cout<<"Hearty welcome !!!"<<endl;
				}
				else
				{
					cout<<"Invalid mobile number or password."<<endl;
					loginattempt++;
				}
			}

			if(loginattempt==5)
			{
				cout<<"Too many login attempts.Try again after sometime ! "<<endl;
				return 0;
			}
			return 1;
		}
};


class employee:public registration
{
	string field;
	int exp,rate=2,qua;
	
	string status;
	int cur_stat;//Depends on the no. of employees required by the employer
	public:
	void set_emp()
	{
		cout<<"Enter the field in which you want to work\n";
		cin>>field;
		cout<<"Enter your years of experience\n";
		cin>>exp;
		cout<<"Enter your level of qualification: 1.Higher secondary or school 2.degree\n";
		cin>>qua;
		if(qua==2)
		{
			status="Supervisor";
		}
		else
			status="Employee";
		
		
	}															
	bool emp_chk()
	{
		if(empcnt>0)
		{
			return true;
		}
		else 
		return false;
	}
	void emp_details()
	{
		ofstream myfile;
		myfile.open("employee.txt",ios::app);
			myfile<<name<<endl;
			myfile<<age<<endl;
			myfile<<mobile<<endl;
			myfile<<email<<endl;
			myfile<<address<<endl;
			myfile<<password<<endl;
			myfile<<rpassword<<endl;
			myfile<<status<<endl;
			myfile.close();
		myfile<<"Field:"<<field<<" "<<"experience:"<<exp<<" "<<"rate:"<<rate<<" "<<"Status:"<<status<<endl;
	}
};
class payment
{
	long int acc_no,card_no;
	int cash,cvv,exp_dt,upi_pin;
	string upi_id,name;
	public:
		void debit_card()
		{
			cout<<"Enter the name on your debit card : "<<endl;
			cin>>name;
			cout<<"Enter 16-digit debit card number : "<<endl;
			cin>>card_no;
			cout<<"Enter the expiry date on your debit card : "<<endl;
			cin>>exp_dt;
			cout<<"Enter the cvv of your debit card : "<<endl;
			cin>>cvv;
			cout<<"Your payment has been successfull!!"<<endl;
			
		}
		void UPI()
		{
			cout<<"Enter your UPI id:\n";
			cin>>upi_id;
			cout<<"Enter UPI pin:\n";
			cin>>upi_pin;
			cout<<"Your payment has been successfull!!"<<endl;
		}
};
				
		
			
		


class agriculture
{
	int crop;
	int land;
	int duration;
	int soil_type;
	int cost_per_day[10];
	int larr[10];

	public:
		int agro()
		{
			cout<<"Enter the crop type :\n1.cotton\n2.Rice "<<endl;
			cin>>crop;
			cout<<"Enter the duration time in days : "<<endl;
			cin>>duration;
			map<string,int> agrimap;
			if(crop==1)
			{
				cout<<"Enter the land in acres"<<endl;
				cout<<"1: for 5 to 10 acres"<<endl;
				cout<<"2: for 10 to 20 acres"<<endl;
				cin>>land;
				
				
					switch(land)
					{
						case 1:
							agrimap["prep_field"]=20;
							cost_per_day[2]=200;
							agrimap["transplant"]=30;
							cost_per_day[4]=500;
							agrimap["field_main"]=10;
							cost_per_day[0]=300;
							agrimap["sowing"]=40;
							cost_per_day[3]=150;
							agrimap["harvest"]=50;
							cost_per_day[1]=400;
							break;

						case 2:
							agrimap["prep_field"]=30;
							cost_per_day[2]=400;
							agrimap["transplant"]=40;
							cost_per_day[4]=1000;
							agrimap["field_main"]=20;
							cost_per_day[0]=600;
							agrimap["sowing"]=50;
							cost_per_day[3]=300;
							agrimap["harvest"]=60;
							cost_per_day[1]=600;
							break;
					}
				
			}
			else
			{
				cout<<"Enter the land in acres :\n1.5 to 10\n2.10 to 20"<<endl;
				cin>>land;
				
					switch(land)
					{
						case 1:
							agrimap["prep_field"]=35;
							cost_per_day[2]=450;
							agrimap["transplant"]=45;
							cost_per_day[4]=520;
							agrimap["field_main"]=25;
							cost_per_day[0]=440;
							agrimap["sowing"]=45;
							cost_per_day[3]=520;
							agrimap["harvest"]=65;
							cost_per_day[1]=500;
							break;

						case 2:
							agrimap["prep_field"]=45;
							cost_per_day[2]=600;
							agrimap["transplant"]=55;
							cost_per_day[4]=450;
							agrimap["field_main"]=35;
							cost_per_day[0]=520;
							agrimap["sowing"]=80;
							cost_per_day[3]=450;
							agrimap["harvest"]=100;
							cost_per_day[1]=540;
							break;
					}
				
				
			}
			int i=0,total_cost=0,sum=0,sum1=0;
			string work;
			cout<<"Enter the field for which you want labour:\nprep_field\ntransplant\nfield_main\nsowing\nharvest\nall\n";
			cin>>work;
			for(auto it=agrimap.begin();it!=agrimap.end();it++)
			{
				if(it->first==work)
				{
					total_cost=it->second * cost_per_day[i++] ;
					sum+=it->second;
					break;
				}
				 if(work=="all")
				{
					total_cost=it->second * cost_per_day[i++];
					sum=it->second;
				}
			}
			return total_cost;	
			
			
			
		}


};

class construction
{
	int input1,input2,input3,input4;
	int dur;
	int cpd[10];
	int nol;
	public:
	
	int buildings()
	{
		double t_cost=0;
		map<string,int>build;
		cout<<"What kind of buildings do you want to construct:\n1.Educational institution\n2.Personal residence\n";
		cin>>input1;
		if(input1==1)
		{
			cout<<"What are you going to construct:\n1.School\n2.College\n";
			cin>>input2;
			if(input2==1)
			{
				build["pc"]=50;
				cpd[0]=200;
				build["spr"]=60;
				cpd[1]=200;
			}
			else if(input2==2)
			{
				build["pc"]=60;
				cpd[0]=300;
				build["spr"]=80;
				cpd[1]=300;
			}
		}
		else if(input1==2)
		{
			cout<<"Enter the type of house you want to construct:\n1.Apartment\n2.Villa\n";
			cin>>input2;
			if(input2==1)
			{
				build["pp"]=50;
				cpd[0]=200;
				build["spr"]=60;
				cpd[1]=300;
			}
			else if(input2==2)
			{
				build["pp"]=72;
				cpd[0]=300;
				build["spr"]=80;
				cpd[1]=300;
			}
		}
		else
			cout<<"Invalid option\n";
		int i=0,sum=0;
		auto it=build.begin();
		while(it!=build.end() && i<2)
		{
			t_cost+=it->second*cpd[i];
			sum+=it->second;
			it++;
			i++;
		}
		return t_cost;
			
	}

	int railways()
	{
		int sum=0;
		double t_cost=0;
		map<string,int>rail;
		cout<<"Enter the option for railway:\n1.Construction\n2.Maintenance\n";
		cin>>input3;
		int i;
		if(input3==1)
		{
			rail["pa"]=30;
			cpd[3]=200;
			rail["pcm"]=50;
			cpd[4]=300;
			rail["lbb"]=60;
			cpd[2]=320;
			rail["anc"]=70;
			cpd[0]=280;
			rail["apo"]=75;
			cpd[1]=200;
			rail["tb"]=65;
			cpd[6]=250;
			rail["ra"]=60;
			cpd[5]=270;
			auto it=rail.begin();
			while(it!=rail.end() && i<6)
			{
				t_cost+=it->second*cpd[i];
				sum+=it->second;
				it++;
				i++;
			}
			return t_cost;
		}
		else if(input3==2)
		{
			cout<<"Enter the option for your maintenance:\n1.rail apology and track laying\n2.Anchorage problem\n";
			cin>>input4;
			if(input4==1)
			{
				rail["apo"]=75;
				cpd[0]=200;
			}
			else if(input4==2)
			{
				rail["anc"]=70;
				cpd[0]=240;
			}
			auto it=rail.begin();
			while(it!=rail.end() && i<1)
			{
				t_cost+=it->second*cpd[i];
				sum+=it->second;
				it++;
				i++;
			}
			return t_cost;
			
		}
		else
			cout<<"Sorry invalid statement:\n";

			
	}
	
	int roads()
	{
		int sum=0;
		map<string,int>road;
		double t_cost=0;
		int i=0;
		cout<<"Enter the option:\n1.Construction\n2.Widening\n";
		cin>>input4;
		if(input4==1)
		{
			road["embankmentlayer"]=50;
			cpd[2]=150;
			road["subgradeconstr"]=65;
			cpd[4]=200;
			road["subbase"]=60;
			cpd[3]=220;
			road["basecourse"]=55;
			cpd[0]=180;
			road["bituminouslayer"]=62;
			cpd[1]=240;
		}
		else if(input4==2)
		{
			road["earthwork"]=56;
			cpd[2]=200;
			road["subgradeconstr"]=60;
			cpd[4]=180;
			road["subbase"]=62;
			cpd[3]=220;
			road["basecourse"]=65;
			cpd[0]=210;
			road["bituminouslayer"]=58;
			cpd[1]=250;
		}
			
			
		else	
		{
			cout<<"Invalid statement\n";
		}
		
			auto it=road.begin();
			while(it!=road.end() && i<5)
			{
				t_cost+=it->second*cpd[i];
				sum+=it->second;
				it++;
				i++;
			}
			return t_cost;
	}
	
};
					
class industry
{
	int input,duration,no_of_lab,cpd[10],t_cost=0;

	public:
		int sum=0;
		map<string,int>indo;
		int garments()
		{
			indo["design"]=50;
			cpd[1]=180;
			indo["sample"]=45;
			cpd[4]=62;
			indo["stitch"]=65;
			cpd[5]=200;
			indo["button"]=62;
			cpd[0]=210;
			indo["threadtrim"]=55;
			cpd[6]=180;
			indo["dying"]=58;
			cpd[2]=180;
			indo["pack"]=65;
			cpd[3]=156;
			string work;
			cout<<"Enter the field for which you want labour:\ndesign\nsample\nstitch\nbutton\nthreadtrim\ndying\npack";
			cin>>work;
			int i=0;
			for(auto it=indo.begin();it!=indo.end();it++)
			{
				if(it->first==work)
				{
					t_cost=it->second * cpd[i++] ;
					sum+=it->second;
					break;
				}
			}
			return t_cost;
		}
		int pharmaceutical()
		{
			map<string,int>pharma;
			pharma["milling"]=60;
			cpd[1]=182;
			pharma["granulation"]=65;
			cpd[0]=190;
			pharma["tabletpressing"]=56;
			cpd[3]=220;
			pharma["packing"]=54;
			cpd[2]=150;
			
			string work;
			cout<<"Enter the field for which you want labour:\nmilling\ngranulation\ntabletpressing\npacking\n";
			cin>>work;
			int i=0;
			for(auto it=pharma.begin();it!=pharma.end();it++)
			{
				if(it->first==work)
				{
					t_cost=it->second * cpd[i++] ;
					sum+=it->second;
					break;
				}
				
			}
			return t_cost;
		}
};

class employer:public payment,public agriculture,public construction,public industry
{
	string job;
	int n_male;
	int n_female;
	int days;
	int exper;
	int l_plan;
	int l1_plan;
	string field;
	public:
	void exp_check()
	{
		cout<<"In which field do you require labourers:\n";
		cin>>field;
		cout<<"Are you a well experienced employer:\n1.Yes 2.No\n";
		cin>>exper;
		if(exper==2)
		{
				cout<<"Don't worry we plan labourers for you in a cost efficient and standardised manner:\n";
				cout<<"Planning......\n";/*Inherit the respective class of job variety as necessary and assign labour jobs in 									a function of the respective derived class*/ 
				if (field=="agriculture")
				{
					int k=agro();
					cout<<"Total estimated cost is :"<<k<<endl;
					cout<<"Is our plan satisfiable for you:\n1.Yes 2.No";
					cin>>l1_plan;
					if(l1_plan==1)
					{
						empcnt-=sum;
					}

				}
				
				else if (field=="construction")
				{
					int ch,k;
					cout<<"1.Roads\n2.Buildings\n3.Railways\n"<<endl;
					cin>>ch;
					switch(ch)
					{
						case 1:
							k=roads();
							break;
						case 2:
							k=buildings();
							break;

						case 3:
							k=railways();
							break;
						default:
							cout<<"invalid option ";
							exit(1);
					}
					cout<<"Total estimated cost is :"<<k<<endl;
					cout<<"Is our plan satisfiable for you:\n1.Yes 2.No";
					cin>>l1_plan;
					if(l1_plan==1)
					{
						empcnt-=sum;
					}
				}

				else if(field=="industry")
				{
					
					int c,t;
					cout<<"1.Garments\n2.Pharmaceutical\n";
					cin>>c;
					switch(c)
					{
						case 1:
							t=garments();
							break;
						case 2:
							t=pharmaceutical();
							break;	
						default:
							cout<<"invalid option ";
							exit(1);
					}
					cout<<"Total estimated cost is :"<<t<<endl;
					cout<<"Is our plan satisfiable for you:\n1.Yes 2.No";
					cin>>l1_plan;	
					if(l1_plan==1)
					{
						empcnt-=sum;
					}
				}			
			
			if(l1_plan==1)
			{
				int c;
				cout<<"Taking you to payment portal:\n";
				cout<<"Please choose your payment option :"<<endl;
				cout<<"1.Debit_card\n2.UPI\n"<<endl;
				cin>>c;
				switch(c)
				{
					case 1:
						debit_card();
						break;
					case 2:
						UPI();
						break;

					default:
							cout<<"invalid option ";
							exit(1);
				}
			
					
				
							
				/*Now inherit the payment class and call the ffunction for payment. After payment show the employees details from the employee class print function to the employer only*/ 
				cout<<"Employee details have been loaded into your file:\n";
				ofstream myfile;
				myfile.open("employee.txt",ios::app);
				myfile<<"Field of requested labour: "<<field<<"\n"<<"Employee details:\n";
				cout<<"Thank you:\nDon't forget to share your ratings in our official twitter page after succesfull completion of our contract\n";
			}
			else
			cout<<"Sorry for the plan which did not satisfy you. Please give us feedback in our official twitter page on how can we improve our service to cater your expectations.Thank you:\n";
		}
		else
		{
			cout<<"Enter the number of male labourers required for your job\n";
			cin>>n_male;
			cout<<"Enter the number of female labourers required for your job\n";	
			cin>>n_female;
			cout<<"Enter the total number of days for which you require labourers\n";
			cin>>days;
			cout<<"Taking you into the payment portal:\n";/*Now inherit the payment class and call the function for payment. After payment show the employees details from the employee    class print function to the employer only*/ 
			cout<<"The employee details are loaded into your file:\n";
			cout<<"Thank you:\nDon't forget to share your ratings in our official twitter page\n";
				ofstream myfile;
				myfile.open("employee.txt",ios::app);
				myfile<<"Field of requested labour: "<<field<<"\n"<<"Number of male employees requested for: "<<n_male<<"\n"<<"Number of female employees requested for: "<<n_female<<"\n"<<"Number of days of contract: "<<days<<"\n"<<"Employee details:\n";
				myfile.close();
		}
	}
		
};


int main()
{
	int input;
	cout<<"Enter the option : 1.Registration 2.Login\n";
	cin>>input;
	registration r;
	if(input==1)
	{	
			r.getdetails();
			r.store_in_file();
			employee e;
			e.set_emp();
			e.emp_details();
		
	agriculture a;
	a.agro();
	return 0;
	cout<<"Please choose the required option : "<<endl;
	cout<<"1.Registration\n2.Login\n3.Employer\n4.Employee\5.Agriculture\n6.Construction\n7.Industry";

	
}






	
			
					
					



















		
			
	
	
