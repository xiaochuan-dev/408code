#pragma once
#include <string>
#include <vector>

namespace datastructure
{
template <typename T = int>
struct Stack
{
    std::vector<T> v;
    Stack() = default;
    ~Stack() = default;
    Stack &push(T);
    T pop();
    bool empty();
};

template <typename T>
Stack<T> &Stack<T>::push(T data)
{
    this->v.push_back(data);
    return *this;
}

template <typename T>
T Stack<T>::pop()
{
    T temp = this->v.back();
    this->v.pop_back();
    return temp;
}

template <typename T>
bool Stack<T>::empty()
{
    return v.empty();
}

/**
 * 字符串匹配，只有中括号和小括号
 * c++版
 */
bool parenMatch(std::string str)
{
    Stack<char> s;

    for (char ch : str)
    {
        if (ch == '[' || ch == '(')
            s.push(ch);
        else if (ch == ']' && s.pop() != '[')
            return false;
        else if (ch == ')' && s.pop() != '(')
            return false;
    }
    return true;
}

/**
 * 重载一个c风格的
 */
bool parenMatch(char *str)
{
    Stack<char> s;
    char *cur = str;

    while (*cur != '\0')
    {
        char ch = *(cur);
        if (ch == '[' || ch == '(')
            s.push(ch);
        else if (ch == ']' && s.pop() != '[')
            return false;
        else if (ch == ')' && s.pop() != '(')
            return false;
        cur++;
    }
    return true;
}

} // namespace datastructure
