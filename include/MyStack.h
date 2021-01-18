//  Copyright 2020 Baklanov

#ifndef INCLUDE_MYSTACK_H_

#define INCLUDE_MYSTACK_H_

template<typename Stack>
class MyStack {
 private:
Stack* stackPtr;  // указатель на стек
int top;  // вершина стека

 public:
MyStack() {
this->stackPtr = 0;
this->stackPtr = new Stack[1000];
this->top = 0;
}
explicit MyStack(int size) {
this->size = size;
this->stackPtr = new Stack[size];
this->top = 0;
}
~MyStack() {
delete[] stackPtr;
}
void push(Stack phead) {
++top;
stackPtr[top] = phead;
}
void pop() {
if (top != -1) {
stackPtr[top] = 0;
--top;
}
}
bool isEmpty() {
if (top == 0)
return true;
return false;
}
Stack get() {
return stackPtr[top];
}
};

#endif  // INCLUDE_MYSTACK_H_
