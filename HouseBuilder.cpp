#include<iostream>
#include<string>
using namespace std;
class HousePlan
{
	public:
	virtual void setBasement(string Base)=0;
	virtual void setWall(string Wall)=0;
	virtual void setRoof(string Roof)=0;	
};
class House:public HousePlan
{
	string Base;
	string Wall;
	string Roof;
	public:
		House(){}
		void setBasement(string Base){	this->Base = Base;}
		void setWall(string Wall){	this->Wall = Wall;}
		void setRoof(string Roof){	this->Roof = Roof;}
		string getBasement(){	return Base;}
		string getWall(){	return Wall;}
		string getRoof(){	return Roof;}

};
class HouseBuilder
{
	public:
		virtual void buildBasement()=0;
		virtual void buildWall()=0;
		virtual void buildRoof()=0;
		virtual House* getHouse()=0;
};
class IglooHouse:public HouseBuilder
{
	House* house;
	public:
		IglooHouse(){
			house = new House();
		}
		void buildBasement(){ 
		 house->setBasement("ICE BASEMENT");
		}
		void buildWall(){
		 house->setWall("ICE WALL");
		}
		void buildRoof(){
		 house->setRoof("ICE ROOF");
		}
		House * getHouse(){
			return house;
		}
};
class WoodHouse:public HouseBuilder
{
	House* house;
	public:
		WoodHouse(){
			house = new House();
		}
		void buildBasement(){ 
		 house->setBasement("WOOD BASEMENT");
		}
		void buildWall(){
		 house->setWall("WOOD WALL");
		}
		void buildRoof(){
		 house->setRoof("WOOD ROOF");
		}
		House * getHouse(){
			return house;
		}
};

class CivilEngineer{
	HouseBuilder *housebuilder;
	public:
		CivilEngineer(HouseBuilder *housebuilder){
			this->housebuilder = housebuilder;
		}
		House * getHouse()
		{
			return housebuilder->getHouse();
		}
		void construct()
		{
			housebuilder->buildBasement();
			housebuilder->buildWall();
			housebuilder->buildRoof();
		}
};
int main()
{
	HouseBuilder *hbldr = new IglooHouse();
	CivilEngineer *cvengr = new CivilEngineer(hbldr);
	cvengr->construct();
	House * house = cvengr->getHouse();
	cout<<house->getBasement()<<"---"<<house->getWall()<<"--"<<house->getRoof();

	cout<<endl<<endl;
	HouseBuilder *wbldr = new WoodHouse();
	CivilEngineer *wvengr = new CivilEngineer(wbldr);
	wvengr->construct();
	House * whouse = wvengr->getHouse();
	cout<<whouse->getBasement()<<"---"<<whouse->getWall()<<"--"<<whouse->getRoof();

	getchar();
	return 0;
}
