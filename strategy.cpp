#include<iostream>
using namespace std;
class Activity
{
  public:
  virtual void action()=0;	
};
class RunActivity:public Activity
{
	public:
		void action()
		{
			cout<<"Can Run"<<endl;
		}
};
class FlyActivity:public Activity
{
	public:
		void action()
		{
			cout<<"Can Fly"<<endl;
		}
};
class WalkActivity:public Activity
{
	public:
		void action()
		{
			cout<<"Can Walk"<<endl;
		}
};

class Animal
{
 public:
 Activity *activity;
 Animal(Activity * act):activity(act){}
 void GetActivity()
 {
  activity->action();	
 } 	
 void SetActivity(Activity * act)
 {
   activity = act; 	
 }
};

class Bird:public Animal
{
 public:
 Bird(Activity *act):Animal(act){cout<<"This is Bird"<<endl;}
};
class Dog:public Animal
{
 public:
 Dog(Activity *act):Animal(act){cout<<"This is Dog"<<endl;}
};
class Elephant:public Animal
{
 public:
 Elephant(Activity *act):Animal(act){cout<<"This is Elephant"<<endl;}
};

int main()
{
	Animal *animal1 = new Dog(new RunActivity());
	animal1->GetActivity();
  animal1->SetActivity(new WalkActivity());
	animal1->GetActivity();
	animal1->SetActivity(new FlyActivity());
	animal1->GetActivity();

	Animal *animal2 = new Bird(new FlyActivity());
	animal2->GetActivity();
	
	Animal *animal3 = new Elephant(new WalkActivity());
	animal3->GetActivity();

	getchar();
	return 0;
}
