#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int lookahead;
bool IL = true;
void expr(void);
void rest(void);
void term(void);
void match(int);
void error(void);


//////////expr Function
void expr(void)
{
    term();
    ///////code of REST
    while (1) {
        if (lookahead == '+') {
            match('+');
            term();

            if (IL)
            printf("pop r1\npop r2\nadd r2,r1\npush r2");
          
            else
            putchar('+');
            


        }
        else if (lookahead == '-') {
            match('-');
            term();

            if (IL)
            printf("pop r1\npop r2\nsub r2,r1\npush r2");
            
            else
            putchar('-');
            


        }
        else
            break;
    }
    ////////end of REST 
}

//////////term Function
void term(void)
{
    if (isdigit(lookahead)) {

        if (IL)
        printf("push %c\n", lookahead);
        
        else
        putchar(lookahead);


        match(lookahead);
    }
    else
        error();
}
//////////match Function
void match(int t)
{
    if (lookahead == t)
        lookahead = getchar();
    else
        error();
}
//////////error Function
void error(void)
{
    printf("syntax error\n"); /* print error message */
    //exit(1); /* then halt */
}




int main(void)
{
    lookahead = getchar();
    expr();
    putchar('\n'); /* adds trailing newline character */
}
