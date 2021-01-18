// Copyright 2020 A.SHT
#include "MyStack.h"
#include "postfix.h"
#include <vector>
#include <sstream>
#include <iostream>


std::string infix2postfix(std::string infix) {
    std::string buf(infix), result;
    std::vector<std::string> words;
    std::istringstream ist(buf);
    std::string tmp;
    while ( ist >> tmp )
        if (tmp[0] == '(')
        {
            words.emplace_back("(");
            words.push_back(tmp.substr(1, tmp.size()-1));
        } else if (tmp[tmp.size()-1] == ')') {
            words.push_back(tmp.substr(0, tmp.size() - 1));
            words.emplace_back(")");
        } else {
            words.push_back(tmp);
        }
    MyStack<char> ms;
    std::map<char, int> weights {{'(', 0}, {')', 1}, {'+', 2},
                                 {'-', 2}, {'*', 3}, {'/', 3}};
    for (const std::string& s : words)
    {
        if (weights.find(s[0]) != weights.end()) {
            if (ms.isEmpty() || weights[ms.get()] < weights[s[0]] || 0 == weights[s[0]]) {
                ms.push(s[0]);
            } else {
                while (!ms.isEmpty() && weights[ms.get()] >= weights[s[0]]) {
                    result += ' ';
                    result += ms.pop();
                }
                if (1 == weights[s[0]]) {
                    ms.pop();
                } else {
                    ms.push(s[0]);
                }
            }
        } else {
            result += ' ' + s;
        }
    }
    while (!ms.isEmpty()) {
        result += ' ';
        result += ms.pop();
    }
    return result.substr(1, result.size()-1);
}
