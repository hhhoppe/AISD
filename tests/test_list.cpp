// Copyright 2025 Dergynov Sergey

#include <gtest.h>
#include "../lib_List/list.h"

// Тест конструктора по умолчанию
TEST(TestTListLib, defaultConstructor) {
    TList<int> list;
    EXPECT_TRUE(list.ifEmpty());
    EXPECT_EQ(list.get_head(), nullptr);
    EXPECT_EQ(list.get_tail(), nullptr);
}

// Тест конструктора копирования
TEST(TestTListLib, copyConstructor) {
    TList<int> list1;
    list1.push_back(10);
    list1.push_back(20);

    TList<int> list2(list1);
    EXPECT_EQ(list2.front(), 10);
    EXPECT_EQ(list2.get_tail()->get_value(), 20);
}

// Тест деструктора
TEST(TestTListLib, destructor) {
    TList<int>* list = new TList<int>();
    list->push_back(10);
    list->push_back(20);
    delete list;
}

// Тест push_back
TEST(TestTListLib, pushBack) {
    TList<int> list;
    list.push_back(10);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.get_tail()->get_value(), 10);

    list.push_back(20);
    EXPECT_EQ(list.get_tail()->get_value(), 20);
}

// Тест push_front
TEST(TestTListLib, pushFront) {
    TList<int> list;
    list.push_front(10);
    EXPECT_EQ(list.front(), 10);

    list.push_front(20);
    EXPECT_EQ(list.front(), 20);
}

// Тест insert_after
TEST(TestTListLib, insertAfter) {
    TList<int> list;
    list.push_back(10);
    list.push_back(30);

    TNode<int>* node = list.find(10);
    list.insert_after(node, 20);

    EXPECT_EQ(list.get_head()->get_next()->get_value(), 20);
}

// Тест insert_to
TEST(TestTListLib, insertTo) {
    TList<int> list;
    list.push_back(10);
    list.push_back(30);

    list.insert_to(1, 20);
    EXPECT_EQ(list.get_head()->get_next()->get_value(), 20);
}

// Тест find
TEST(TestTListLib, find) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    TNode<int>* node = list.find(20);
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->get_value(), 20);
}

// Тест front
TEST(TestTListLib, front) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    EXPECT_EQ(list.front(), 10);
}

// Тест get_node_to
TEST(TestTListLib, getNodeTo) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    TNode<int>* node = list.get_node_to(1);
    EXPECT_EQ(node->get_value(), 20);
}

// Тест pop_back
TEST(TestTListLib, popBack) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    list.pop_back();
    EXPECT_EQ(list.get_tail()->get_value(), 10);
}

// Тест pop_front
TEST(TestTListLib, popFront) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    list.pop_front();
    EXPECT_EQ(list.front(), 20);
}

// Тест remove
TEST(TestTListLib, remove) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    TNode<int>* node = list.find(10);
    list.remove(node);
    EXPECT_EQ(list.front(), 20);
}

// Тест remove_to
TEST(TestTListLib, removeTo) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    list.remove_to(1);
    EXPECT_EQ(list.get_tail()->get_value(), 10);
}

// Тест replace
TEST(TestTListLib, replace) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    TNode<int>* node = list.find(10);
    list.replace(node, 30);
    EXPECT_EQ(list.front(), 30);
}

// Тест replace_to
TEST(TestTListLib, replaceTo) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    list.replace_to(1, 30);
    EXPECT_EQ(list.get_tail()->get_value(), 30);
}

// Тест ifEmpty
TEST(TestTListLib, ifEmpty) {
    TList<int> list;
    EXPECT_TRUE(list.ifEmpty());

    list.push_back(10);
    EXPECT_FALSE(list.ifEmpty());
}

// Тест get_head
TEST(TestTListLib, getHead) {
    TList<int> list;
    list.push_back(10);

    EXPECT_EQ(list.get_head()->get_value(), 10);
}

// Тест get_tail
TEST(TestTListLib, getTail) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    EXPECT_EQ(list.get_tail()->get_value(), 20);
}

// Тест оператора вывода
TEST(TestTListLib, outputStream) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    std::stringstream ss;
    ss << list;
    EXPECT_EQ(ss.str(), "10 -> 20 -> nullptr");
}

// Тест оператора ввода
TEST(TestTListLib, inputStream) {
    TList<int> list;
    std::stringstream ss("10 20");
    ss >> list;

    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.get_tail()->get_value(), 20);
}

// Тест итератора
TEST(TestTListLib, iterator) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
}

// Тест итератора на пустом списке
TEST(TestTListLib, iteratorEmptyList) {
    TList<int> list;
    auto it = list.begin();
    EXPECT_EQ(it, list.end());
}

// Тест итератора с постфиксным инкрементом
TEST(TestTListLib, iteratorPostIncrement) {
    TList<int> list;
    list.push_back(10);
    list.push_back(20);

    auto it = list.begin();
    EXPECT_EQ(*it++, 10);
    EXPECT_EQ(*it, 20);
}