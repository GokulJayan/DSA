#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
 

class QUEUE
{
    stack<int> s1, s2;
 
public:

    void enqueue(int element)
    {
        s1.push(element);
    }
 
    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout<<"\nQueue Underflow!!!";
            exit(0);
        }
        if(s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top=s2.top();
        s2.pop();
        return top;
    }
};
 
int main()
{
    int max,ele,i;
    vector<int>v;
    cout<<"\nEnter size of Queue: ";
    cin>>max;
 
    QUEUE q;
    cout<<"Enter elements: ";
    for(i=0;i<max;i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    for (int item:v)
    q.enqueue(item);
 
    for (int i=0; i<=v.size();i++)
    cout<<q.dequeue()<<" ";
    return 0;
}