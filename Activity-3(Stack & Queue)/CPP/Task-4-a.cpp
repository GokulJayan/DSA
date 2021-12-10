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
        //Pushing all elements to s2 untill main stack is empty
        while (!s1.empty()) 
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(element);             //Pushing Required Element
        
   
        //Pushing back all transferred elements to main stack untill s2 is empty
        while (!s2.empty())   
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
 
    int dequeue()
    {
        if (s1.empty())
        {
            cout<<"\nQUEUE Underflow!!!";
            exit(0);
        }

        int top = s1.top();
        s1.pop();
        return top;
    }
};
 
int main()
{
    int max,ele,i;
    vector<int>v;
    cout<<"\nEnter size of queue: ";
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