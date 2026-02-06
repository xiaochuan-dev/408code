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
    T top();
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
T Stack<T>::top()
{
    return this->v.back();
}

template <typename T>
bool Stack<T>::empty()
{
    return v.empty();
}

// 下面开始算法

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

/**
 * 中缀转后缀
 */
std::string infixToSuffix(std::string input)
{
    std::string res;

    Stack<char> s;
    for (char ch : input)
    {
        switch (ch)
        {
        case '(':
            s.push(ch);
            break;
        case ')':
            while (s.top() != '(')
            {
                res.push_back(s.pop());
            }
            s.pop();
            break;
        case '*':
        case '/':
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                res.push_back(s.pop());
            }
            s.push(ch);
            break;
        case '+':
        case '-':
            while ((!s.empty() && (s.top() == '+' || s.top() == '-' ||
                                   s.top() == '*' || s.top() == '/')))
            {
                res.push_back(s.pop());
            }
            s.push(ch);
            break;
        default:
            res.push_back(ch);
            break;
        }
    }
    while (!s.empty())
    {
        res.push_back(s.pop());
    }
    return res;
}

/**
 * 中缀转后缀c语言版本
 */
void infixToSuffix(char *input, char *res)
{
    Stack<char> s;
    char *ch = input;
    char *_res = res;

    while (*ch != '\0')
    {
        switch (*ch)
        {
        case '(':
            s.push(*ch);
            break;
        case ')':
            while (s.top() != '(')
            {
                *_res = s.pop();
                _res++;
            }
            s.pop();
            break;
        case '*':
        case '/':
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                *_res = s.pop();
                _res++;
            }
            s.push(*ch);
            break;
        case '+':
        case '-':
            while ((!s.empty() && (s.top() == '+' || s.top() == '-' ||
                                   s.top() == '*' || s.top() == '/')))
            {
                *_res = s.pop();
                _res++;
            }
            s.push(*ch);
            break;
        default:
            *_res = *ch;
            _res++;
            break;
        }
        ch++;
    }

    while (!s.empty())
    {
        *_res = s.pop();
        _res++;
    }
}

} // namespace datastructure
