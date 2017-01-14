//PreFix to PostFix 
//ex)
//¢º-/63/+52*42   =  63/52+42*/-  =  1.125
//¢º-2/+55+11    =  255+11+/-    =  -3

#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAXLENGTH 20
using namespace std; 

class Prepost               
{
private:
  char prefix[MAXLENGTH];     
  char postfix[MAXLENGTH];  
public:
  Prepost(char receive[])     
  {
	  strcpy(prefix,receive);
	  convert(prefix,postfix);
  }
  void Show()             
  {
	  cout<<prefix<<endl;
	  cout<<postfix<<endl;
  }
  char* getpost()       
  {
	  return postfix;
  }
 void substr(char s1[ ], int i, int j, char s2[ ])  
{                          
      int k, m;
      for (k=i, m=0; m<j; s2[m++]=s1[k++]);
      s2[m] ='\0';
 }
 int isalpha(char symb)  
{
	if(('A'<=symb&&symb<='Z')||('0'<=symb&&symb<='9')) 
		return true;
	else return false;
}
 int find(char str[]){                 
   char temp[MAXLENGTH]; 
   int length; 
   int m, n;

   if ((length = strlen(str)) == 0)  
      return (0); 
   if (isalpha(str[0]) != 0)  
      return (1); 
   
   if (strlen(str) < 2) 
      return (0); 
   substr(str, 1, length-1, temp); 
   m = find(temp); 
   if (m == 0 || strlen(str) == m)

   substr(str, m+1, length-m-1, temp); 
   n = find(temp); 
   if (n == 0) 
      return (0); 
   return (m+n+1); 
 }
 void convert (char prefix[], char postfix[]) 
 {                           
    char post1[MAXLENGTH],post2[MAXLENGTH]; 
    char temp[MAXLENGTH]; 
    char op[2]; 
    int length; 
    int m, n; 
    if ((length = strlen(prefix)) == 1) { 
        if (isalpha(prefix[0])) {     
            postfix[0] = prefix[0]; 
            postfix[1] = '\0'; 
            return; 
        } 
        printf("\nillegal prefix string"); 
        exit(1);
    }
    op[0] = prefix[0]; 
    op[1] = '\0'; 
    substr(prefix, 1, length-1, temp); 
    m = find(temp); 
    substr(prefix, m+1, length-m-1, temp); 
    n = find(temp); 
    

if((op[0]!='+'&&op[0]!='-'&&op[0]!='*'&&op[0]!='/')||(m==0)||(n==0)
||(m+n+1!=length))
   {
        printf("\nillegal prefix string"); 
        exit(1); 
    }
    substr(prefix, 1, m, opnd1); 
    substr(prefix, m+1, n, opnd2); 
    convert(opnd1, post1); 
    convert(opnd2, post2); 
    strcat(post1, post2); 
    strcat(post1, op); 
    substr(post1, 0, length, postfix); 
 }
};



class Postfix  
{
private:
	char expr[MAXLENGTH];         
	int top;                         
	double items[MAXLENGTH];      
public:
	Postfix(char copy_expr[])    
	{
		strcpy(expr, copy_expr);
		eval();
	}
	void Show()
	{	 cout<<pop()<<endl;      }
	void eval()    
	{
	  int c, position;    
	  double opnd1, opnd2, value;

top = -1;
for (position = 0; (c = expr[position]) != '\0'; position++)
if (isdigit(c))      
push((double)(c - '0'));
else {                       
	 opnd2 = pop();       
	 opnd1 = pop();       
	 value = oper(c, opnd1, opnd2);  
	 push(value);          
     }
  }
double pop()
{
     if (top < 0){cout << "underflow" << endl; exit(1)                                       
		 return items[top--];
}
void push(double c)
{
      if(top >= 80){cout << "overflow" << endl;  exit(1);}                                   
	  items[++top] = c;
}
int isdigit(char symb)   
	{  return(symb >= '0' && symb <= '9'); } 
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
int main()
{
  Prepost p("-/63/+52*42");     
  p.Show();
  Postfix f(p.getpost());
  f.Show();
  return 0;
}