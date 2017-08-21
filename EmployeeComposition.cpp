#include<iostream>
using namespace std;
#include<vector>
class Employee
{
public:
virtual void showEmployeeDeatails()=0;	
};
class Developer:public Employee
{
public:
	string name;
	string position;
	string empId;
	public:
		Developer(string n,string p,string e)
		{
			name = n;
			position = p;
			empId = e;
		}
		void showEmployeeDeatails()
		{
			cout<<"Developer name is "<<name<<" and having position "<<position<<endl;	
		}	
};
class Manager:public Employee
{
	string name;
	string position;
	string empId;	

	public:
		vector<Employee *> employeeList;
		Manager(string n,string p,string e)
		{
			name = n;
			position = p;
			empId = e;
		}
		void showEmployeeDeatails()
		{
			 cout<<"Manager name is "<<name<<" and having position "<<position<<endl;
			 cout<<"Manager "<<name<<" has below reportees to him"<<endl;
			 for (int i = 0; i < employeeList.size(); i++)
			 {
        	   employeeList[i]->showEmployeeDeatails();
			 }
		}
		void add(Employee *emp)
		{
			employeeList.push_back(emp);
		}
};
int main()
{
	Developer *d1 = new Developer("Pramod","SEII","100");
	Developer *d2 = new Developer("Ramesh","SEIII","101");
	Manager *mgr = new Manager("Srini","MgrI","001");
	mgr->add(d1);
	mgr->add(d2);
	mgr->showEmployeeDeatails();
		
	getchar();
	return 0;
}
