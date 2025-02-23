// Copyright 2025 Dergynov Sergey

#include <gtest.h>
#include "../lib_Stack/stack.h"

// Проверка конструктора по умолчанию
TEST(TestStackLib, DefaultConstructor) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

// Проверка конструктора копирования
TEST(TestStackLib, CopyConstructor) {
    Stack<int> stack1;
    stack1.push(500);
    stack1.push(600);
    Stack<int> stack2(stack1);
    EXPECT_EQ(stack2.size(), 2);
    EXPECT_EQ(stack2.top(), 600);
}

// Проверка оператора присваивания
TEST(TestStackLib, AssignOperator) {
    Stack<int> stack1;
    stack1.push(700);
    stack1.push(800);
    Stack<int> stack2;
    stack2 = stack1;
    EXPECT_EQ(stack2.size(), 2);
    EXPECT_EQ(stack2.top(), 800);
}

// Проверка добавления элемента на вершину стека
TEST(TestStackLib, push) {
    Stack<int> stack;
    stack.push(10);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 10);
}

// Проверка удаления элемента с вершины стека
TEST(TestStackLib, pop) {
    Stack<int> stack;
    stack.push(20);
    stack.push(30);
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 20);
}

// Проверка получения элемента с вершины стека
TEST(TestStackLib, top) {
    Stack<int> stack;
    stack.push(40);
    stack.push(50);
    EXPECT_EQ(stack.top(), 50);
}

// Проверка получения элемента с вершины стека (const)
TEST(TestStackLib, topConst) {
    Stack<int> stack;
    stack.push(60);
    const Stack<int>& constStack = stack;
    EXPECT_EQ(constStack.top(), 60);
}

// Проверка на пустоту стека
TEST(TestStackLib, empty) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    stack.push(70);
    EXPECT_FALSE(stack.empty());
}

// Проверка на подсчёт кол-ва элементов стека
TEST(TestStackLib, size) {
    Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);
    stack.push(80);
    stack.push(90);
    EXPECT_EQ(stack.size(), 2);
}

// Проверка очистку стека
TEST(TestStackLib, clear) {
    Stack<int> stack;
    stack.push(100);
    stack.push(200);
    stack.clear();
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

// Проверка вывод стека
TEST(TestStackLib, print) {
    Stack<int> stack;
    stack.push(300);
    stack.push(400);
    EXPECT_NO_THROW(stack.print());
}