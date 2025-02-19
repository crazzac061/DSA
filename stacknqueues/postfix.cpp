#include<bits/stdc++.h>
using namespace std;
# define SIZE 10

struct Stack
{
    int TOS=-1;
    int stack[SIZE];



 bool isEmpty(){
    return TOS==-1;
 }

 void push (int item)
 {
    if (TOS==SIZE-1)
    {
        cout<<"Stack overflow!!"<<endl;

    }
    else
    {
        TOS+=1;
        stack[TOS]=item;
        
    }
 }

 int pop()
 {
    if (isEmpty())
    {
        cout<<"Stack is empty!!";
        return -1;
    }
    else{

        int item= stack[TOS];
        TOS-=1;
        return item;
    }
 } 

 void display() 
 {
    for(int i=0;i<=TOS;i++)
    {
        cout<<stack[i]<<endl;

    }
 }
 char peek()
 {
    if (!isEmpty())
    {
        return stack[TOS];
    }
    return -1;
 }
};

int precedence(char c)
{
    if (c =='^' )
    {
        return 3;
    }
    else if (c=='/' || c=='*')
    {
        return 2;
    }
    else 
    {
        return 1;
    }

}

void infixTopostfix(struct Stack *st , char infix[30])
{
    char postfix[30];
    int k=0;
    for (int i=0; i<strlen(infix);i++ )
    {
        if (infix[i]>='A' && infix[i]<='Z')
        {
            postfix[k++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            st->push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(!st->isEmpty() && st->peek()!='(')
            {
                postfix[k++]=st->pop();
            }
            st->pop();
        }
        else
        {
        while (!st->isEmpty() && precedence(st->peek()) >= precedence(infix[i])) {
                postfix[k++] = st->pop();
            }
            st->push(infix[i]);  
        }
    }
   while(!st->isEmpty())
   {
    postfix[k++]=st->pop();
   }

   postfix[k]='\0';

   cout <<"Postfix expression is:"<<postfix;


}

int main ()
{
    struct Stack st;
    char infix[]="A+B*(C-D)";
    infixTopostfix(&st, infix);
    return 0;
}

