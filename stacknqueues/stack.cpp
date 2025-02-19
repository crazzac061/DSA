# include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int TOS=-1;
    int stack[4];
};

void push (struct Stack *st, int item)
{
    if (st->TOS==3)
    {
        cout<<"Stack overflow!!"<<endl;

    }
    else
    {
        st->TOS+=1;
        st->stack[st->TOS]=item;
        
    }
}

int pop(struct Stack *st)
{
    if (st->TOS==-1)
    {
        cout<<"Stack is empty!!";
        return -1;
    }
    else{

        int item= st->stack[st->TOS];
        st->TOS-=1;
        return item;
    }
}

void display(struct Stack *st)
{
    for(int i=0;i<=st->TOS;i++)
    {
        cout<<st->stack[i]<<endl;

    }
}
int peek(struct Stack * st)
{
    return st->stack[st->TOS];
}

int main()
{
    struct Stack st;
    push(&st,4);
    push(&st,48);
    push(&st,2);
    push(&st,3);
    display(&st);
    cout<<"the poped element is"<<pop(&st)<<endl;
    cout<<"the element at TOS is "<<peek(&st)<<endl;
    return 0;
    

}