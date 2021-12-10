#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;
 

class Stack
{
    queue<int> q1, q2;
 
public:

    void push(int data)
    {
        q1.push(data);
    }
 
    int pop()
    {
        if (q1.empty())
        {
            cout<<"\nStack Underflow!!!";
            exit(0);
        }

        int front;
        while (!q1.empty())
        {
            if (q1.size() == 1)
            front = q1.front();
            else
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return front;
    }
};
 
int main()
{
    int max,ele,i;
    vector<int>v;
    cout<<"\nEnter size of stack: ";
    cin>>max;
 
    Stack s;
    cout<<"Enter elements: ";
    for(i=0;i<max;i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    for (int item:v)
    s.push(item);
 
    for (int i=0; i<=v.size();i++)
    cout<<s.pop()<<" ";
    return 0;
}