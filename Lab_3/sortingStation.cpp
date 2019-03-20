#include <stdio.h>
#include <iostream>
#include <string>
#include "Header.h"
#include "QueueArray.h"
#include "QueueHeader.h"
#include "StackHeader.h"

using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')

string toPostfix(string &line) {

Stack <char> inStack;
Queue <char> outQueue;
    
string result;

for (int i=0; i< line.length(); i++)
{
    if (isdigit(line[i])) // Если число - в выходную очередь
    {
        //cout << line[i] << " is digit, TO queue\n";
        outQueue.push(line[i]);
    }
    
    else if (is_operator(line[i])) // Если оператор
    {
        while (!inStack.empty())
        {
            if (is_operator(inStack.top())
                && (op_priority(line[i]) <= op_priority(inStack.top())))
            {
                outQueue.push(inStack.top());
                inStack.pop();
                
            }
            else
                break;
        }
        inStack.push(line[i]);
    }
    
    else if(line[i] == '(')
        inStack.push(line[i]);
    
    else if(line[i] == ')')
    {
        bool logic = false;
        // До появления на вершине стека левой скобки перекладывать операторы из стека в очередь вывода
        while (!inStack.empty())
        {
            if (inStack.top() == '(')
            {
                logic = true;
                break;
            }
            else
            {
                outQueue.push(inStack.top());
                inStack.pop();
            }
        }
        // Если стек кончится до нахождения левой скобки, то была пропущена скобка
        if(!logic)
        {
            cout << "Error: bracket mismatched\n";
            exit(1);
        }
        // выкидываем левую скобку из стека (не добавляем в очередь вывода)
        inStack.pop();
    }
}

while (!inStack.empty())
{
    outQueue.push(inStack.top());
    inStack.pop();
}

while (!outQueue.empty())
{
    result += outQueue.front();
    result += " ";
    outQueue.pop();
    }
    return result;
}

int op_priority(const char c) // Приоритет булевой операции
{
    switch(c)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
            
        case '+':
        case '-':
            return 1;
    }
    return 0;
}
