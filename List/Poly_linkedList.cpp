//Polynomial linked list

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std; 

class PolyNode{
	friend class PolyList;
private :
	int coef;
	int exp;
	PolyNode *link;
public:
	PolyNode(int c,int e) : coef(c),exp(e) { link=NULL;}
	PolyNode();
};
class PolyList
{
friend PolyList* operator+(const PolyList&,const PolyList&);
private:
	PolyNode *head,*tail;
public:
	PolyList(){	head=tail=NULL;}
	
       int GetCoef(PolyNode *tmp){return tmp->coef;}
	int GetExp(PolyNode *tmp) { return tmp->exp;}
	PolyNode* MoveNext(PolyNode *tmp) { return tmp->link;}
	
	int empty() { return (head==NULL? true : false);}
	
	void Remove() 
	{
		PolyNode * p;
		
		if(empty())
			cout<<"empty PolyList"<<endl;
		else
		{
		p=head;
		head=p->link;
		if(head==NULL)
			tail=NULL;
		cout<<"[Rev]  coef: "<<p->coef<<"  exp: "<<p->exp<<endl;
		delete p;
		}
	}
	
       void Attach(int coef, int exp)
	{
		PolyNode *p=new PolyNode(coef,exp);
		p->link=NULL;
		

		if(tail==NULL)
		  head=p;		
		else
		  tail->link=p;
		
		tail=p;
		cout<<"[Add]  coef: "<<p->coef<<"  exp: "<<p->exp<<endl;
	}
	
       void DisplayAll()
	{
		PolyNode *p;
		p=head;
		while(p!=NULL)
		{
		cout<<" ( "<<p->coef<<","<<p->exp<<" ) ";
		p=MoveNext(p);
		}
		cout<<endl;
	}
	~PolyList()
	{
		delete head;
		delete tail;
	}
};

void main()
{
	PolyList pList1,pList2; 
	pList1.Attach(2,2);
	pList1.Attach(5,1);
	pList1.Attach(4,0);
	pList1.DisplayAll();
       cout<<endl;
	pList2.Attach(8,0);
	pList2.Remove();
	pList2.Attach(3,3);
	pList2.Attach(2,7);
	pList2.DisplayAll();
}
  
