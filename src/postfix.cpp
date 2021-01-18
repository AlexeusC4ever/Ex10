// Copyright 2020 Baklanov

#pragma once
#include "postfix.h"

std::string infix2prefix(std::string str) {
MyStack<char> ans;
MyStack<char> buf;
int strlength = str.length();
for (int i = 0; i < strlength; i++) {
if ((str[i] >= '0') && (str[i] <= '9')) {
ans.push(str[i]);
}
else if (str[i] == '(') {
buf.push(str[i]);
}
else if (str[i] == ')') {
while (!buf.isEmpty() && (!(buf.get() == '('))) {
ans.push(buf.get());
buf.pop();
}
if (!buf.isEmpty())
buf.pop();
}
else if ((str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-')) {
if ((str[i] == '+') || (str[i] == '-')) {
while ((!buf.isEmpty()) && (!(buf.get() == '('))) {
ans.push(buf.get());
buf.pop();
}
}
else
{
while (((!buf.isEmpty()) && (!((buf.get() == '+') || (buf.get() == '-')))) && (!(buf.get() == '('))) {
ans.push(buf.get());
buf.pop();
}
}
buf.push(str[i]);
}
}
while (!buf.isEmpty()) {
ans.push(buf.get());
buf.pop();
}
while (!ans.isEmpty()) {
buf.push(ans.get());
ans.pop();
}
std::string answer;
while (!buf.isEmpty()) {
answer.push_back(buf.get());
buf.pop();
}
return answer;
}
