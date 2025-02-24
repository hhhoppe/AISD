// Copyright 2025 Dergynov Sergey

#include <gtest.h>
#include "../lib_Queue/queue.h"
/*
// Проверка конструктора по умолчанию
TEST(TestTQueueLib, DefaultConstructor) {
    TQueue<int> queue;
    EXPECT_TRUE(queue.ifEmpty());
    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(queue.capacity(), 10);
}

// Проверка конструктора с параметром
TEST(TestTQueueLib, ParameterConstructor) {
    TQueue<int> queue(5);
    EXPECT_TRUE(queue.ifEmpty());
    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(queue.capacity(), 5);
}

// Проверка конструктора копирования
TEST(TestTQueueLib, CopyConstructor) {
    TQueue<int> queue1;
    queue1.push(10);
    queue1.push(20);

    TQueue<int> queue2(queue1);
    EXPECT_EQ(queue2.size(), 2);
    EXPECT_EQ(queue2.pop(), 10);
    EXPECT_EQ(queue2.pop(), 20);
}

// Проверка конструктора из массива
TEST(TestTQueueLib, MassConstructor) {
    TDmassive<int> mass;
    mass.push_back(1);
    mass.push_back(2);
    mass.push_back(3);

    TQueue<int> queue(mass);
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
}

// Проверка на полноту очереди
TEST(TestTQueueLib, ifFull) {
    TQueue<int> queue(2);
    queue.push(1);
    queue.push(2);
    EXPECT_TRUE(queue.ifFull());
}

// Проверка на постоту очереди
TEST(TestTQueueLib, ifEmpty) {
    TQueue<int> queue;
    EXPECT_TRUE(queue.ifEmpty());
    queue.push(42);
    EXPECT_FALSE(queue.ifEmpty());
}

// Проверка на добавление элемента в конец
TEST(TestTQueueLib, push) {
    TQueue<int> queue;
    queue.push(10);
    EXPECT_FALSE(queue.ifEmpty());
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.pop(), 10);
}

// Проверка на удаление и возврат элемента из начала
TEST(TestTQueueLib, pop) {
    TQueue<int> queue;
    queue.push(20);
    queue.push(30);
    EXPECT_EQ(queue.pop(), 20);
    EXPECT_EQ(queue.pop(), 30);
    EXPECT_TRUE(queue.ifEmpty());
}

// Проверка на возврат индекса из начала очереди
TEST(TestTQueueLib, getFront) {
    TQueue<int> queue;
    queue.push(10);
    queue.push(20);
    EXPECT_EQ(queue.get_front(), 0);
    queue.pop();
    EXPECT_EQ(queue.get_front(), 1);
}

// Проверка на возврат индекса из конца очереди
TEST(TestTQueueLib, getBack) {
    TQueue<int> queue;
    queue.push(10);
    EXPECT_EQ(queue.get_back(), 0);
    queue.push(20);
    EXPECT_EQ(queue.get_back(), 1);
}

// Проверка на возврат размера очереди
TEST(TestTQueueLib, size) {
    TQueue<int> queue;
    EXPECT_EQ(queue.size(), 0);
    queue.push(10);
    EXPECT_EQ(queue.size(), 1);
    queue.pop();
    EXPECT_EQ(queue.size(), 0);
}

// Проверка на возврат вместимости очереди
TEST(TestTQueueLib, capacity) {
    TQueue<int> queue(15);
    EXPECT_EQ(queue.capacity(), 15);
}

// Проверка на очистку очереди
TEST(TestTQueueLib, clear) {
    TQueue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.clear();
    EXPECT_TRUE(queue.ifEmpty());
    EXPECT_EQ(queue.size(), 0);
}

// Проверка на вывод содержимого очереди
TEST(TestTQueueLib, print) {
    TQueue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    testing::internal::CaptureStdout();
    queue.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 30 \n");
}
*/