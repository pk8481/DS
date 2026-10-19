#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int F(char symbol)
{
    switch(synbol)
    {
        case'+':
        case'-':return 2;
        case'*':
        case'/':return 4;
        case'^':
        case'$':return 5;
        case'(':return 0;
        case'#':return -1;
        default: return 8;

    }
}

int G(char symbol){
    switch(symbol){
        case'+':
        case'_':return 1;
        case'*':
        case'/':return 3;
        case'^':
        case'$':return 6;
        case'(':return 9;
        case')':return 0;
        default: return 7;


    }
}

void InfixToPostfix(char infix[],char postfix[])
{
    int top;
    int i;
    int j;
    char s[30];
    char symbol;
    top=-1;
    s[++top]='#';
    j=0;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        while(F(s[top])>G(symbol))
        {
            postfix[j]=s[top--];
            j++

        }
        if(F(s[top])!=G(symbol))
        {
            s[++top]=symbol;

        }
        else
        top--;
    }
    while(s[top!='#'])
    {
        postfix[j++]=s[top--];

    }
    postfix[j]='\0';
}
void main()
{
    char infix[30];
    char postfix[30];
    printf("\n Enter the Infix string : ");
    scanf("%s",infix);
    InfixToPostfix(infix,postfix);
    printf("\n Infix string is: %s",infix);
    InfixToPostfix(infix,postfix);
    if (strlen(postfix)>0)
    {
        printf("\n Postfix string is: %s",postfix); 
    }
    
    

}
