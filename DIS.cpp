#include<bits/stdc++.h>
using namespace std;
//Abstract class to hide defination of lower class from Higher class
class Emp{
  public:
  virtual void work()=0;
};
//Higher class
class Mgr{
  public:
  list<Emp*> lemp;
  Mgr(){cout<<"Mgr Created"<<endl;}
  void addEmp(Emp *e)
  {
      lemp.push_back(e);
  }
  void display()
  {
      cout<<lemp.size()<<endl;
      list<Emp*>::iterator ei=lemp.begin();
      for(;ei!=lemp.end();ei++)
        (*ei)->work();
  }
};
//lower class with defination
class Dev: public Emp{
  public:
  Dev():Emp(){cout<<"DEV added"<<endl;}
  void work(){cout<<"DEV is Working"<<endl;}
};
//lower class with defination
class UX: public Emp{
  public:
  UX():Emp(){cout<<"UX added"<<endl;}
  void work(){cout<<"UX is Working"<<endl;}
};
//lower class:- added later without changing anything in higher class get executed.
class QA: public Emp{
  public:
  QA():Emp(){cout<<"QA added"<<endl;}
  void work(){cout<<"QA is Working"<<endl;}
};

int main()
{
    Mgr *m = new Mgr();
    m->addEmp(new Dev());
    m->addEmp(new UX());
    m->addEmp(new QA());//added later
    m->display();
    return 0;
}
