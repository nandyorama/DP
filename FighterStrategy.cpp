#include<iostream>
using namespace std;
class KickBehaviour
{
  public:
  virtual void kick()=0;	
};
class Lighteningkick:public KickBehaviour
{
	public:
		void kick()
		{
			cout<<"Lightening Kick"<<endl;
		}
};
class Tornadokick:public KickBehaviour
{
	public:
		void kick()
		{
			cout<<"Tornado Kick"<<endl;
		}
};
class JumpBehaviour
{
  public:
  virtual void jump()=0;	
};
class ShortJump:public JumpBehaviour
{
	public:
		void jump()
		{
			cout<<"Short Jump"<<endl;
		}
};
class LongJump:public JumpBehaviour
{
	public:
		void jump()
		{
			cout<<"Long Jump"<<endl;
		}
};

class Fighter
{
 public:
 KickBehaviour *kck;	
 JumpBehaviour *jmp;
 Fighter(KickBehaviour *kick,JumpBehaviour *jump):kck(kick),jmp(jump){}
 void Punch()
 {
  cout<<"Punch"<<endl;	
 } 	
 void Kick()
 {
  kck->kick();	
 } 	
 void Jump()
 {
  jmp->jump();	
 } 	
 void setKickBehaviour(KickBehaviour *kick)
 {
 	kck = kick;
 }
 void setJumpBehaviour(JumpBehaviour *jump)
 {
 	jmp = jump;
 }
};

class Ken:public Fighter
{
 public:
 Ken(KickBehaviour *kick,JumpBehaviour *jump):Fighter(kick,jump){cout<<"Ken"<<endl;}
};
//Can Add More Derived Class Like Ken
int main()
{
	Fighter *ken = new Ken(new Tornadokick(),new ShortJump());
	ken->Punch();
	ken->Kick();
	ken->Jump();
	ken->setJumpBehaviour(new LongJump());
	ken->Jump();		

	getchar();
	return 0;
}
