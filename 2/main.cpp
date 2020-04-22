#include "h.h"

int main()
{
  Factory *f[2]={new FactoryChild1(),new FactoryChild2()};
  vector<CQueue*> t=Get_CQueue(f[0], f[1]); 
  vector<CQueue*>::iterator the_iterator;
  vector<CQueue*>::iterator tmp_it;
  int n=t.size();
  if(n==-1) return 0;
  Child2 pp;
  cout<<endl<<"all queue before shift"<<endl;
  for(CQueue* n : t)	n->out();
  cout<<endl<<"_____________________________________"<<endl;
//делаю циклический сдвиг
  int count=0;
  Child2 qq=**(t.begin());
  for(vector<CQueue*>::iterator it=t.begin(); it!=t.end();++it)
  {
    if(it==(t.end()-1)) { **it=qq; break;}
    **it=**(it+1);
  }

  cout<<endl<<"all queue after shift"<<endl;
  for(CQueue* n : t)	n->out();
//вывожу очереди по файлам
  for(CQueue* n:t) 
	n->out_file();
cout<<endl<<"_______________"<<endl;

	int cc=0;
    the_iterator = (t.begin());
    while (the_iterator != (t.end())) 
	{
	  if(cc!=0)  **(t.begin()) =**(t.begin()) + **the_iterator; 
	  the_iterator++;
	  cc++;
	}
cout<<endl<<"All sum"<<endl;
    (**(t.begin())).out();

// del
 for (vector<CQueue*>::iterator ii = t.begin(); ii != t.end(); ++ii) 
 {
  delete *ii;
 }

 t.clear(); 
 delete f[0];
 delete f[1];
cout<<"!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
  return 0;
}






