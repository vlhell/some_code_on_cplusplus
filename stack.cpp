//creating and testing stack
//stack is realised on array of int-s
//V.Bogdanov
//2019

#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>


template <typename T, int N = 100>
class Stack
{
    std::array<T, N> a;
    std::array<T, N> maxs;
    int top;

public:
    Stack() : top(-1) {}

    void Push(T val) {
        if (top == N - 1) {
            throw "Stack is full!";
        }
        a[++top] = val;
        if (top == 0) {
            maxs[top] = val;
        } else {
            maxs[top] = std::max(maxs[top - 1], val);
        }
    }

    T Pop() {
        if (top == -1) {
            throw "Stack is empty!";
        }
        return a[top--];
    }

    T Max() {
        if (top == -1) {
            throw "Stack is empty!";
        }
        return maxs[top];
    }
};


int main() {
    int n;
    std::cin >> n;

    Stack<int> st;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        try {
            st.Push(x);
        } catch (const char* msg) {
            std::cerr << msg << '\n';
        }
    }

    std::cout << '\n';

    for (int i = 0; i < n + 1; ++i) {
        try {
            int max_curr = st.Max();
            std::cout << "top = " << st.Pop() << " , max = " << max_curr << '\n'; 
        } catch(const char* msg) {
            std::cerr << msg << '\n';
        }
    }

    return 0;
}