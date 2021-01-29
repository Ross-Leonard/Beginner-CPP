//John Ross Leonard
//CS 372
//Infix to Postfix

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class List
{
private:
    int mySize;   
    int pos;
public:    
    int CAPACITY;
    int* arr;
    int currentPos, size1;    
};

//stack for postfix
class Stack
{
private:
    char* list;
    int size;
    int index;	

public:
    Stack(int s)
    {
        size = s;
        list = new char[s];
        index = -1;
    }
    void push(char p)
    {
        index++;
        list[index] = p;
    }	
    char peek()
    {
        char ret = ' ';
        if (index > -1)
        {
            ret = list[index];
        }
        return(ret);
    }
    char pop()
    {
        char ret = ' ';
        if (index > -1)
        {
            ret = list[index];
            index--;
        }
        return(ret);
    }   
    bool isEmpty()
    {
        return(index == -1);
    }	
};

//evaluation stack
class StackInt
{
private:
    int* list;
    int size;
    int index;
public:
    StackInt(int s)
    {
        size = s;
        list = new int[s];
        index = -1;
    }
    void push(int p)
    {
        index++;
        list[index] = p;
    }
    int peek()
    {
        int ret = ' ';
        if (index > -1)
        {
            ret = list[index];
        }
        return(ret);
    }
    int pop()
    {
        int ret = ' ';
        if (index > -1)
        {
            ret = list[index];
            index--;
        }
        return(ret);
    }
    bool isEmpty()
    {
        return(index == -1);
    }
    int totals()
    {
        return(index + 1);
    }
};

int preoperation(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else
    {
        if (ch == '*' || ch == '/')
        {
            return 2;
        }
        else
        {
            if (ch == '+' || ch == '-')
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}

string intopost(string s)
{   
    Stack stack(100);    
    stack.push('N');
    int len = s.length();
    string ret = " ";
    for (int i = 0; i < len; i++)
    {
        if (s.at(i) >= '0' && s.at(i) <= '9')
        {
            ret += s.at(i);
        }
        else
        {
            if (s.at(i)=='(')
            {
                stack.push('(');
            }
            else
            {
                if (s.at(i) == ')')
                {
                    while (stack.peek() != 'N' && stack.peek() != '(')
                    {
                        char c = stack.pop();
                        ret += c;
                    }
                    if (stack.peek() == '(')
                    {
                        stack.pop();
                    }
                }
                else
                {
                    while (stack.peek() != 'N' && preoperation(s.at(i)) <= preoperation(stack.peek()))
                    {
                        char c = stack.pop();
                        ret += c;
                    }
                    stack.push(s.at(i));
                }
            }
        }
    }
    while (stack.peek() != 'N')
    {
        ret += stack.pop();
    }
    return(ret);
}

int evaluatepost(string s)
{
    int len = s.length();
    int ret = 0;

    StackInt intstack(100);
    for (int i = 0; i < len; i++)
    {
        char ch = s.at(i);
        if (ch == '^' || ch == '+' || ch == '/' || ch == '*' || ch == '-')
        {
            int val1 = intstack.pop();
            int val2 = intstack.pop();

            switch(ch)
            {
            case '+':
            {
                    intstack.push(val1 + val2);
                    break;
            }
            case '-':
            {
                intstack.push(val1 - val2);
                break;
            }
            case '*':
            {
                intstack.push(val1 * val2);
                break;
            }
            case '/':
            {
                intstack.push(val1 / val2);
                break;
            }
            case'^':
            {
                intstack.push(pow(val2, val1));
                break;
            }

            }
        }
        else
        {
            intstack.push((int)(s.at(i) - '0'));
        }
    }
    ret = intstack.pop();
    return(ret);
}


int main()
{
    ifstream infile;
    string ex2;
    infile.open("infixdata.txt");  

        while (!infile.eof())
        {           
            getline(infile, ex2);           
            string postFix1 = intopost(ex2);
            cout << ex2 << endl;
            cout << "Postfix : " << postFix1;
            cout << "\nValue is : " << evaluatepost(postFix1) << endl << endl;
        }
        if (infile.eof())
        {
            cout << "End of program" << endl;
            system("pause");
            return 0;
        }    
   
	system("pause");
	return 0;
}