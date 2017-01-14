//The postfixes are stored in an array through a stack

#include <iostream> 
#include <cstdlib> 
#include <cmath>
#include <cstring>
#define MAXCOLS 80 

using namespace std;

class Postfix
{
private:
	char expr[MAXCOLS];         
	int top;                    
	double items[MAXCOLS];    
public:
	Postfix(char copy_expr[])     
	{
		strcpy(expr, copy_expr);
	}
	double eval()           
	{
		int c, position;    
		double opnd1, opnd2, value;

        top = -1;
	for (position = 0; (c = expr[position]) != '\0'; position++)
                                                   .

			if (isdigit(c))      
				push((double)(c - '0'));
      
else {                       
	 opnd2 = pop();       
	 opnd1 = pop();      
	 value = oper(c, opnd1, opnd2);  
	 push(value);          
     }
			return pop();   
  }
	double pop()
	{
		if (top < 0){cout << "underflow" << endl; exit(1);}                                                 //언더플로우 방지 조건문이다.
		return items[top--];
	}
	void push(double c)
	{
		if (top >= 80){cout << "overflow" << endl;  exit(1);}                                               //오버플로우 방지 조건문이다.
		return items[++top] = c;
      }
	int isdigit(char symb)   
	{
		return(symb >= '0' && symb <= '9');
	} 
      double oper(int symb, double op1, double op2)
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
	
};
void main()
{
	char expr[MAXCOLS];
	int position = 0;
	while ((expr[position++] = getchar()) != '\n');
	expr[--position] = '\0';         

	Postfix postfix(expr);                                         
	cout << "the original postfix expression is " << expr << endl;
	cout << "The result is : " << postfix.eval() << endl;
	                              
}