// Copyright 2020 Baklanov
#pragma once

#include <iostream>
#include "MyStack.h"

#include "postfix.h"

int main()
{
 std::string s1("2 + 6 * 3 / (4 - 2)");
 std::string s2 = infix2prefix(s1);
 std::cout << s2;  // 2 6 3 * 4 2 - / +
}