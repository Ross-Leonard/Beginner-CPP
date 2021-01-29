//John Ross Leonard
//CS 372
//Stack and Queues

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
const int CAP = 20;
typedef char VT; //type of the element in the array

class List
{
private:
    int mySize;
    VT aryList[CAP];
    int pos;
public:
    List();
    List(List& aryList);
    int CAPACITY;
    int* arr;
    int currentPos, size1;
    void clear();
    void first();
    void prev();
    void next();
    void last();
    void replace(int, int);
    void setPos(int);
    void erase();
    void insertAfter(int, int);
    void insertBefore(int, int);
    int size();
    bool empty();
    int getXElement();
    int getYElement();
    int getPos();

    List operator= (List& aryList2);
};
class Stack
{
    int used;
private:
    VT aryList2[CAP];    
public:
    Stack() { used = -1; }
    bool push(char entry,char entry2);
    VT pop();
    int peek();
    bool isEmpty();   
};

class Queue
{
private:
    char* data;
    int count;
public:
    Queue(int n)
    {
        data = new char[n];
        count = 0;
    }
    int size()
    {
        return count;
    }
    bool empty()
    {
        return size() == 0;
    }
    void enqueue(char ch)
    {
        data[count++] = ch;
    }
    char front()
    {
        return data[0];
    }
    char dequeue() 
    {
        char ret = data[0];
        for (int i = 1; i < count; ++i)
        {
            data[i - 1] = data[i];
        }
        --count;
        return ret;
    }
};
    
    bool Stack::push(char item,char item2)
    {        
        if (used >= (CAP - 1))
        {
            cout << "Stack Overflow";
            
            system("pause");
            return 0;
        }
        else
        {
            aryList2[++used] = item;
            cout << item << " pushed into stack\n";
                return true;
        }              
    }
    VT Stack::pop()
    {
        if (used < 0)
        {
            cout << "Stack Underflow";
            return 0;
        }
        else
        {           
            int x = aryList2[used--];
            return x;
        }        
    }
    int Stack::peek()
    {
        if (used < 0)
        {
            cout << "Stack is empty";
            return 0;
        }
        else
        {            
            int x = aryList2[used];
            return x;
        }
    }
    bool Stack::isEmpty()
    {
        return(used < 0);
    }

ostream& operator <<(ostream& outs, List& aryList);
List operator + (List& ListA, List& ListB);
bool operator == (List aryList1, List aryList2);


List::List()
{
    CAPACITY = 20;
    arr = (int*)malloc(CAPACITY * sizeof(int*));
    size1 = 0;
    mySize = 0;
    currentPos = 0;
    pos = 0;
}
List::List(List& obj)
{
    arr = obj.arr;
    CAPACITY = obj.CAPACITY;
    size1 = obj.size1;
    mySize = obj.mySize;
}
bool List::empty()
{
    return mySize > 0;
}
void List::first()
{
    pos = 0;
}
void List::last()
{
    pos = mySize - 1;
}
void List::prev()
{
    if (currentPos == 0) cout << "Previous element is empty.\n";
    else
    {
        pos--;
    }
}
void List::next()
{
    if (currentPos == CAPACITY - 1) cout << "Next element is empty.\n";
    else
    {
        currentPos++;
        pos++;
    }
}
int List::getPos()
{
    return currentPos;
}
void List::setPos(int n)
{
    pos = n;
}
void List::insertBefore(int a, int b)
{
    if (currentPos < CAP)
    {
        int i;
        int n = currentPos + 1;

        for (i = n; i >= pos + 2; i = i - 2)
        {
            arr[i] = arr[i - 2];
            arr[i - 1] = arr[i - 3];
        }
        currentPos = currentPos + 2;

        if (pos == 0)
        {
            arr[pos] = a;
            arr[pos + 1] = b;
        }
        else
        {
            arr[pos - 2] = a;
            arr[pos - 1] = b;
        }
    }

}
void List::insertAfter(int a, int b)
{
    if (pos >= CAPACITY - 1)
    {
        cout << "The list is full. Elements have NOT been added.\n";
        return;
    }
    else
    {
        for (int i = mySize; i > pos; i--)
        {
            arr[i] = arr[i + 1];
            arr[i + 1] = arr[i + 2];

        }
        if (mySize == 0)
        {
            arr[pos] = a;
            arr[pos + 1] = b;

        }
        else
        {
            arr[pos + 1] = a;
            arr[pos + 2] = b;
            pos++;

        }
        mySize++;

        for (int i = currentPos + 1; i < size1; i++)
        {
            arr[i + 2] = arr[i];
        }
        arr[currentPos + 1] = a;
        arr[currentPos + 2] = b;
        size1++;
    }

}
int List::getXElement()
{
    if (size() <= 0)
        return 0;
    else
        return arr[pos];
}
int List::getYElement()
{
    if (size() <= 0)
        return 0;
    else
        return arr[pos + 1];
}
int List::size()
{
    return mySize;
}
void List::replace(int n, int n2)
{
    arr[pos] = n;
    arr[pos + 1] = n2;
}
void List::erase()
{
    for (int i = pos; i < size1; i++)
    {
        arr[i] = arr[i + 1];
        arr[i + 1] = arr[i + 2];
    }
    size1 = size1 - 2;
}
void List::clear()
{
    mySize = 0;
    pos = 0;
    for (int i = 0; i < size1; i++)
    {
        arr[i] = 0;
    }
    currentPos = 0;
    size1 = 0;
}
ostream& operator<<(ostream& out, List& l)
{
    for (int i = 0; i < l.size(); i++)
    {
        l.setPos(i);
        out << l.getXElement() << " ";
    }
    out << "\n";
    return out;
}
bool operator == (List l, List l2)
{
    if (l.size() != l2.size()) return false;
    for (int i = 0; i < l.size(); i++)
    {
        l.setPos(i);
        l2.setPos(i);
        if (l.getXElement() != l.getYElement())
            return false;
    }
    return true;
}
List List::operator = (List& l)
{
    arr = l.arr;
    return l;
}
bool operator != (List aryList1, List aryList2)
{
    if (aryList1 == aryList2)
        return false;
    else
        return true;
}
List operator+(List& l, List& l2)
{
    cout << "+ operator  ";
    List l3(l);
    int orig_pos = l2.getPos();
    l3.first();
    l2.first();

    for (int i = 0; i < l2.size(); l2.next(), l3.next(), i++)
    {
        l3.replace(l2.getXElement() + l3.getXElement(), l2.getYElement() + l3.getYElement());
        cout << "+ operator";
    }
    l2.setPos(orig_pos);
    cout << "+ operator ";
    return l3;
}

int main()
{
    ifstream infile, infile2, infile3;
    infile3.open("LispClassData.txt");
    infile2.open("Stack3.dat");
    infile.open("stackdata.txt");
    int whichone;
    string brackets;
    Stack mystack;

    cout << "Which file do you want to check first? 1. Stackdata 2.Stack3 3.LispClassData ";
    cin >> whichone;
    while (whichone < 1 || whichone > 3)
    {
        cout << "I'm sorry, you didnt enter a correct digit, try again";
        cin >> whichone;
    }
    if (whichone == 1)
    {
        char a, b;
        while(infile>>a)        
        {
            if (a == '(' || a == ')' || a == '[' || a == ']' || a == '{' || a == '}' || a == '<' || a == '>')
            {
                mystack.push(a, ' ');
            }
            getline(infile, brackets);
            cout << brackets <<endl;
        }        
        a = mystack.peek();
        mystack.pop();
        mystack.pop();
        b = mystack.peek();
        mystack.pop();
        mystack.pop();
        cout << "This data is equal" << endl;
    }
    if (whichone == 2)
    {
        char a, b;
        while(infile2>>a)       
        {
            if (a == '(' || a == ')' || a == '[' || a == ']' || a == '{' || a == '}' || a == '<' || a == '>')
            {
                mystack.push(a,' ');
            }            
            cout << brackets << endl;
        }
        
        a = mystack.peek();
        mystack.pop();
        mystack.pop();
        b = mystack.peek();
        mystack.pop();
        mystack.pop();
    }
    if (whichone == 3)
    {
        char a, b;
        while(infile3>>a)      
        {
            if (a == '(' || a == ')' || a == '[' || a == ']' || a == '{' || a == '}' || a == '<' || a == '>')
            {
                mystack.push(a, ' ');
            }            
        }
        
        a = mystack.peek();
        mystack.pop();
        mystack.pop();
        b = mystack.peek();
        mystack.pop();
        mystack.pop();
        cout << a << b << endl;
    }   
    
   Queue suitor(100);
    char ch = 'A', temp;
    for (int i = 0; i < 65; ++i)
    {
        suitor.enqueue(ch);
        ch += 1;
    }
    while (suitor.size() != 1)
    {
        temp = suitor.dequeue();
        suitor.enqueue(temp);
        temp = suitor.dequeue();
        suitor.enqueue(temp);
        suitor.dequeue();
        suitor.enqueue(temp);
        suitor.dequeue();
    }
    cout << "Remaining Person is: " << suitor.front() << endl;
    
    system("Pause");
    return 0;
}