#include "h.h"

int main()
{//////////на первой строке нет числа очередей и 3е число не отвечает за длину
  Factory *f[2]={new FactoryChild1(),new FactoryChild2()};
  int n;
  vector<CQueue*> t=Get_CQueue(f[0], f[1], n); 
  
  if(n==-1) return 0;
  Child2 pp;
  cout<<endl<<"all queue before shift"<<endl;
  for(CQueue* n : t)	n->out();
  cout<<endl<<"_____________________________________"<<endl;
  rotate(t.begin(), t.begin() + 1, t.end()); // ciklicheskiy' sdvig vectora na 1

  for(CQueue* n:t) 
	n->out_file();

	
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






