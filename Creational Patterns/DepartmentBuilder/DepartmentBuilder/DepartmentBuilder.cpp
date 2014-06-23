// houseBuilder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

/*Department parts*/
class Room
{
public:
	int square;
	std::string name;
};

// Direction
class MainDoor
{
 public:
	std::string direction;
};

class Balcony
{
public:
	std::string direction;

};

//Final Products
class Department
{
public:
	std::string name;
	Room* room;
	MainDoor mainDoor;
	Balcony balcony;

   // get spcification of department
	void specification()
	{
		std::cout<<"********************************************"<<std::endl;
		std::cout<<"Department Name: "<< name << std::endl;
		std::cout<<"********************************************"<<std::endl;

		while((room->square > 0) &&(room->name != ""))
		{
			std::cout<<"Rooms : "<< room->name<< std::endl;
			std::cout<<"S =   : "<< room->square  <<" m2"<< std::endl;
			room++;
		}

      if( mainDoor.direction != "" )
      {
         std::cout<<"Direction of main door  : "<< mainDoor.direction << std::endl;
      }
      else
      {
         std::cout<<"Direction of main door  : --"<< std::endl;
      
      }
		
      if( balcony.direction != "" )
      {
         std::cout<<"Direction of Balcony    : "<< balcony.direction << std::endl;
      }
      else
      {
         std::cout<<"Direction of Balcony    : --" << std::endl;
      }		
      std::cout<<"                                             "<<std::endl;
	}
};



class Builder
{
public:
	virtual void BuildHouse(){}
	virtual void BuildRooms(){}
	virtual void BuildFloors(){}
	virtual void BuildMainDoor(){}
	virtual void BuildBalcony() {}

	virtual Department* GetHouse() {return 0;}
};


class Director
{

public:
	void setBuilder(Builder* newBuilder)
	{
		builder = newBuilder;
	}

	Department* createHouse()
	{
		Department* house = new Department();
		builder->BuildHouse();
		builder->BuildRooms();
		builder->BuildMainDoor();
		builder->BuildBalcony();
		house = builder->GetHouse();
		return house;
	}
private:
    Builder* builder;

};

// Common Departments
class DepartmentBuilder : public Builder
{
public:
   
   DepartmentBuilder(){
		department = new Department();
	}

	virtual void BuildHouse()
	{
		department->name = "Department";

	}

	virtual void BuildRooms()
	{
		department->room = new Room[3];
		department->room[0].name = "Living Room";
		department->room[0].square = 33;
		department->room[1].name = "Bed Room";
		department->room[1].square = 10;
		department->room[2].name = "WC";
		department->room[2].square = 3;
	
	}

	virtual void BuildMainDoor()
	{
		department->mainDoor.direction = "West-North";
	}
	
	virtual void BuildBalcony()
	{
		department->balcony.direction = "South-East";
	
	}
	virtual Department* GetHouse() 
	{
		return department;
	}

private:
	Department* department;
};

// Build PenHouse
class PenHouseBuilder: public Builder
{
public:

	PenHouseBuilder(){
		penhouse = new Department();
	}

	virtual void BuildHouse()
	{
		std::string abc = "PenHouse";
		penhouse->name = abc;
	}

	virtual void BuildRooms()
	{
		penhouse->room = new Room[4];
		penhouse->room[0].name = "Living Room";
		penhouse->room[0].square = 50;
		penhouse->room[1].name = "bed Room";
		penhouse->room[1].square = 50;
		penhouse->room[2].name = "WC1";
		penhouse->room[2].square = 6;
		penhouse->room[3].name = "WC2";
		penhouse->room[3].square = 5;
	
	}

	virtual void BuildMainDoor()
	{
		penhouse->mainDoor.direction = "North";
	}

	virtual void BuildBalcony()
	{
		penhouse->balcony.direction = "South";
	
	}

   // get Departement
	virtual Department* GetHouse() 
	{
		return penhouse;
	}

private:
	Department* penhouse;

};

// Build Basement
class BasementBuilder : public Builder
{
public:
   BasementBuilder()
   {
      department = new Department();
   
   }

   virtual void BuildHouse()
	{
		department->name = "Basement1";
	}

   virtual void BuildRooms()
	{
		department->room = new Room();
		department->room->name = "Security Room";
		department->room->square = 15;
	}

	virtual void BuildMainDoor()
	{
		department->mainDoor.direction = " West ";
	}

      // get Departement
	virtual Department* GetHouse() 
	{
		return department;
	}

private:
   Department* department;
};
int _tmain(int argc, _TCHAR* argv[])
{
	Department* department;
	Director director;
	DepartmentBuilder departmentBuilder;
	PenHouseBuilder penHouseBUilder;
   BasementBuilder basementbuilder;
	
	// buid Department
	director.setBuilder(&departmentBuilder);
	department = director.createHouse();
	department->specification();


	// build penhouse
	director.setBuilder(&penHouseBUilder);
	department = director.createHouse();
	department->specification();

   // build basement
   director.setBuilder(&basementbuilder);
	department = director.createHouse();
	department->specification();



	delete department;

	return 0;
}

