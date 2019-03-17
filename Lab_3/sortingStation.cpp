#include <stdio.h>
#include <iostream>
#include <string>
//#include "Header.h"

#include <stack> // Стандартные библиотеки - ЗАМЕНИТЬ
#include <queue>

using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*')

string toPostfix(string &line) {

stack<char> Stack;
queue<char> outQueue;
    
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
        while (!Stack.empty())
        {
            if (is_operator(Stack.top())
                && (op_priority(line[i]) <= op_priority(Stack.top())))
            {
                outQueue.push(Stack.top());
                Stack.pop();
                
            }
            else
                break;
        }
        Stack.push(line[i]);
    }
    
    else if(line[i] == '(')
        Stack.push(line[i]);
    
    else if(line[i] == ')')
    {
        bool logic = false;
        // До появления на вершине стека левой скобки перекладывать операторы из стека в очередь вывода
        while (!Stack.empty())
        {
            if (Stack.top() == '(')
            {
                logic = true;
                break;
            }
            else
            {
                outQueue.push(Stack.top());
                Stack.pop();
            }
        }
        // Если стек кончится до нахождения левой скобки, то была пропущена скобка
        if(!logic)
        {
            cout << "Error: bracket mismatched\n";
            exit(1);
        }
        // выкидываем левую скобку из стека (не добавляем в очередь вывода)
        Stack.pop();
    }
}

while (!Stack.empty())
{
    outQueue.push(Stack.top());
    Stack.pop();
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
        case '*':
        case '/':
            return 2;
            
        case '+':
        case '-':
            return 1;
    }
    return 0;
}
