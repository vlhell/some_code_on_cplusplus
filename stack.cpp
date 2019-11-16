//creating and testing stack
//stack is realised on array of int-s
//V.Bogdanov
//2019

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Stack
{
    int a[100];
    int maxs[100];
    int top;
public:
    Stack(){
        for (int j = 0; j < 100; ++j){
            a[j] = 0;
            maxs[j] = 0;
        }
        top = -1;
    }
    void Push(int val){
        if (top == 99){
            throw "Stack is full!";
        }
        a[++top] = val;
        if (top == 0)
            maxs[top] = val;
        else
            maxs[top] = max(maxs[top - 1], val);
    }
    int Pop(){
        if (top == -1){
            throw "Stack is empty!";
        }
        int ret = a[top];

        top--;
        return ret;
    }
    int Max(){
        if (top == -1){
            throw "Stack is empty!";
        }
        return maxs[top];
    }
};

int main(){

    int n;

    scanf("%d", &n);

    int x;

    Stack st;

    for (int i = 0; i < n; ++i){
        scanf("%d", &x);
        try
        {
            st.Push(x);
        }
        catch (const char* msg)
        {
            printf("%s\n", msg);
        }
    }

    /*
        for (int i = 0; i < 100; ++i){
            try
            {
                st.Push(1);
            }
            catch (const char* msg)
            {
                printf("%s\n", msg);
            }
    }
    */

    printf("\n");

    int max_curr = -1;

    for (int i = 0; i < n + 1; ++i){
        try
        {
            {
                max_curr = st.Max();

                printf("top = %d, max = %d\n", st.Pop(), max_curr); 
            }
        }
        catch(const char* msg)
        {
            cerr << msg << '\n';
        }
    }

    return 0;
}