#include "stack.h"

Operation::Operation()
{
    begin = NULL;
}

int Operation::Prior(char a)
{
    switch (a)
    {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        case '(': return 1;
    }
    return 0;
}

Stack* Operation::InStack(Stack *p, char in)
{
    Stack *temp = new Stack;
    temp->data = in;
    temp->next = p;
    return temp;
}

Stack* Operation::OutStack(Stack *p, char *out)
{
    Stack* temp = p;
    *out = p->data;
    p = p->next;
    delete temp;
    return p;
}

QString Operation::toPolish(QString qstr)
{
    begin = NULL;
    char add, prov;
    string InStr, OutStr;
    InStr = qstr.toStdString();
    for(int i = 0; i < (int)InStr.length(); i++){
           if(InStr[i] != '+' && InStr[i] != '-' && InStr[i] != '*' && InStr[i] != '/' && InStr[i] != '('
                   && InStr[i] != ')' && InStr[i] != 'a' && InStr[i] != 'b' && InStr[i] != 'c' && InStr[i] != 'd' && InStr[i] != 'e'){
               QMessageBox::critical(0, "Critical error", "Wrong input");
               exit(0);
           }
       }

    unsigned long len = InStr.length();
    for (unsigned long i = 0; i < len; i++)
    {
        prov = InStr[i];

        if (prov == '(')
        {
            begin = InStack(begin, prov);
        }

        if (prov == ')')
        {
            while(begin->data != '(')
            {
                begin = OutStack(begin, &add);
                OutStr += add;
            }
            begin = OutStack(begin, &add);
        }

        if (prov >= 'a' && prov <= 'e')
        {
            OutStr += prov;
        }

        if (prov == '^' || prov == '*' || prov == '/' || prov == '+' || prov == '-')
        {
            while (begin != NULL && Prior(begin->data) >= Prior(prov)) {
                begin = OutStack(begin, &add);
                OutStr += add;
            }
            begin = InStack(begin, prov);
        }

    }

    while (begin != NULL)
    {
        begin = OutStack(begin, &add);
        if (add != '(')
                    OutStr += add;
    }

    return QString::fromStdString(OutStr);

}


QString Operation::Result(QString qstr, double* array)
{
    string str = qstr.toStdString();
    for(int i = 0; i < (int)str.length(); i++){
           if(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '('
                   && str[i] != ')' && str[i] != 'a' && str[i] != 'b' && str[i] != 'c' && str[i] != 'd' && str[i] != 'e'){
               QMessageBox::critical(0, "Critical error", "Wrong input");
               exit(0);
           }
       }
    char ch, ch1, ch2;
    double oper1, oper2, rez;
    char chr = 'e' + 1;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        ch = str[i];
         if (ch != '^' && ch != '*' && ch != '/' && ch != '+' && ch != '-')
         {
             begin = InStack(begin, ch);
         }
         else
         {

             begin = OutStack(begin, &ch1);
             begin = OutStack(begin, &ch2);
             oper1 = array[int(ch1)];
             oper2 = array[int(ch2)];

             switch (ch)
             {
             case '+': rez = oper1 + oper2; break;
             case '-': rez = oper2 - oper1; break;
             case '*': rez = oper2 * oper1; break;
             case '/': rez = oper2 / oper1; break;
             case '^': rez = pow(oper2 , oper1); break;
             }

             array[int(chr)] = rez;
             begin = InStack(begin, chr);
             chr++;
         }
    }

    qstr = QString::number(rez);
    return qstr;
}









