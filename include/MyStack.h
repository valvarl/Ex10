// Copyright 2020 A.SHT
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <stack>
#include <map>

template<class T>
class MyStack {
 private:
    std::stack<T> st;
 public:
    void push(const T t)
    {
        st.push(t);
    }
    T pop(){
        T t = st.top();
        st.pop();
        return t;
    }
    T get() const
    {
        return st.top();
    }
    bool isEmpty()
    {
        return st.empty();
    }
};

#endif  // INCLUDE_MYSTACK_H_
