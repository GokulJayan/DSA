#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;
 

class STACK
{
    queue<int> q1, q2;
 
public:
    void push(int data)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
 
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
 
    int pop()
    {
        if (q1.empty())
        {
            cout<<"\nSTACK Underflow!!!";
            exit(0);
        }
        int front = q1.front();
        q1.pop();
        return front;
    }
};
 
int main()
{
    int max,ele,i;
    vector<int>v;
    cout<<"\nEnter size of stack: ";
    cin>>max;
 
    STACK s;
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