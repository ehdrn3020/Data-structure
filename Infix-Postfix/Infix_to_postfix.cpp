//Infix to postfix

#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstdlib> 
#define MAXCOLS 80 
using namespace std;
class Profix
{
private:
	char postr[MAXCOLS];      
	char infix[MAXCOLS];      
	int itop,otop;                
    char opstk[MAXCOLS];        
double Result[MAXCOLS];        
public:
	Profix(char fix[])         
	{
		for(int i=0;i!='\0';i++)
			infix[i]=fix[i];
		otop=-1;
		itop=0; 
    	}
 void Show() const{cout<<postr<<endl; cout<<Result<<endl;}  
 int empty(char[]);           
 void postfix(char *, char *);  
 int isoperand(char);         
 void popandtest(char arr[],int, char *, int *); 
 int prcd(char, char);       
 void push(char[],int,char); 
 char pop(char[],int);
 double oper(char symb, double op1, double op2);
 void eval(); 
};

 int Profix::empty(char arr[]) 
{ 
   if(itop == -1) return 1;
   else return 0;
}  
char Profix::pop(char arr[],int top) 
 { 
    if (empty(arr)) { 
       printf("%s", "stack underflow"); 
       exit(1); 
    }  
    return(arr[top--]); 
 }   
void Profix::push(char arr[],int top,char x) 
 { 
     if (top == MAXCOLS-1) { 
        printf("%s", "stack overflow"); 
        exit(1); 
     } 
     else items[++itop] = x; 
     return;
 } 


void Profix::popandtest(char arr[],int top,char *topsymb, int *und) 
{ 
        if (empty(arr)) { 
            *und = 1; 
            return; 
        } 
        *und = 0; 
        *topsymb = arr[top--]; 
        return; 
} 
int Profix::isoperand(char symb)
{
	if(¡®0¡¯<=symb&&symb<=¡®9¡¯)
		return true;
	else return false;
}
int Profix::prcd(char op1,char op2)       
{                                        
	switch(op1){                   	
		case '+' : op1=1; break;
		case '-': op1=1; break;
		case '*' : op1=2; break;
		case '/' :op1=2; break;
		case '$' : op1=3; break;
		case '(':return false;    
	}
	switch(op2){
		case '+' : op2=1; break;
		case '-': op2=1; break;
		case '*' : op2=2; break;
		case '/' :op2=2; break;
		case '$' : op2=3; break;
		case '(':return false;
		case ')':return true;        
	}
	return op1>op2 ? true : false ;     
}      
void Profix::eval()           
{
  char c; 
  int position;    
  double opnd1, opnd2, value;
  int top = -1;

  for (position = 0; (c = postr[position]) != '\0'; position++)
  {              
         if (isoperand(c))     
		Result[++top]=((double)(c - '0'));
  }
         else 
         {   
			opnd2 = Result[top--];
			opnd1 = Result[top--];
			value = oper(c, opnd1, opnd2);
			Result[++top]=value; 
         }
     }
 }

double Profix::oper(char symb, double op1, double op2)
      {               
		switch (symb) {
		case '+': return (op1 + op2);
		case '-': return (op1 - op2);
		case '*': return (op1 * op2);
		case '/': return (op1 / op2);
		case '$': return (pow(op1, op2));
		default: printf("%s", "no defined operation\n");
			  exit(1);
	                    }
	}

void Profix::postfix(char infix[], char postr[]) 
 {
     int position, und;
     int outpos = 0;
     char topsymb ='+';
     char symb;  
 
     for (position = 0; (symb = infix[position]) != '\0';position++) 

         if (isoperand(symb))               
             postr[outpos++] = symb; 
         else {
             popandtest(opstk, otop,&topsymb, &und); 

             while (!und && prcd(topsymb, symb)) { 
                 postr[outpos++] = topsymb;       
                 popandtest(opstk,otop, &topsymb, &und);
             } 
             if (!und)       
                 push (opstk, otop,topsymb);

             if (und || (symb != ')')) 
                 push (opstk, otop,symb);

             else 
	 	 topsymb=pop(opstk,otop);
			 }

    while (!empty(opstk)){     
        postr[outpos++] = pop(opstk,otop); 
	}

    postr[outpos] = '\0'; 
    return; 
 } /* end postfix */

void main() 
 { 
     char fix[MAXCOLS]; 
     int pos = 0; 
     while ((fix[pos++] = getchar()) != '\n'); 
     fix[--pos] = '\0'; 
     printf("%s%s\n", "the original infix expression is ", fix);
     Profix pro(fix);         
     pro.eval();
     pro.Show();             
 } /* end main */
