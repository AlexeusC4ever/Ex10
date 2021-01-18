// Copyright 2020 Baklanov

#include "postfix.h"

std::string infix2postfix(std::string str) {
int size = 0;
MyStack<char> ans;
MyStack<char> buf;
int strlength = str.length();
for (int i = 0; i < strlength; i++) {
if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.')) {
ans.push(str[i]);
} else if (str[i] == '(') {
buf.push(str[i]);
} else if (str[i] == ')') {
while (!buf.isEmpty() && (!(buf.get() == '('))) {
ans.push(buf.get());
buf.pop();
}
if (!buf.isEmpty())
buf.pop();
} else if ((str[i] == '*') || (str[i] == '/') ||
(str[i] == '+') || (str[i] == '-')) {
if ((str[i] == '+') || (str[i] == '-')) {
while ((!buf.isEmpty()) && (!(buf.get() == '('))) {
ans.push(buf.get());
buf.pop();
}
} else {
while (((!buf.isEmpty()) && (!((buf.get() == '+') ||
(buf.get() == '-')))) && (!(buf.get() == '('))) {
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
str = "";
while (!buf.isEmpty()) {
str.push_back(buf.get());
buf.pop();
if (buf.get() != '.') {
str.push_back(' ');
} else {
str.push_back(buf.get());
buf.pop();
}
}
if(str[str.length()-1] == ' ') {
str.erase(str.length() - 1, 10);
}
return str;
}
