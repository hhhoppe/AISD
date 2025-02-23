// Copyright 2025 Dergynov Sergey

#include <gtest.h>
#include "../lib_TVector/tvector.h"
#include "../lib_DMassive/dmassive.h"

// ѕроверка конструктора по умолчанию
TEST(TestTVectorLib, DefaultConstructor) {
    TVector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_start_index(), 0);
}

// ѕроверка конструктора с размером и начальным индексом
TEST(TestTVectorLib, SizeStartIndexConstructor) {
    TVector<int> vec(5, 2);
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec.get_start_index(), 2);
}

// ѕроверка конструктора из массива
TEST(TestTVectorLib, MassiveConstructor) {
    int mass[] = { 1, 2, 3, 4, 5 };
    TVector<int> vec(mass, 5, 1);
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec.get_start_index(), 1);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], 2);
    EXPECT_EQ(vec[5], 5);
}

// ѕроверка конструктора копировани¤
TEST(TestTVectorLib, CopyConstructor) {
    TVector<int> vec1(3, 1);
    vec1[1] = 10;
    vec1[2] = 20;
    vec1[3] = 30;

    TVector<int> vec2(vec1);
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2.get_start_index(), 1);
    EXPECT_EQ(vec2[1], 10);
    EXPECT_EQ(vec2[2], 20);
    EXPECT_EQ(vec2[3], 30);
}

// ѕроверка оператора присваивани¤
TEST(TestTVectorLib, AssignOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 10;
    vec1[2] = 20;
    vec1[3] = 30;

    TVector<int> vec2;
    vec2 = vec1;
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2.get_start_index(), 1);
    EXPECT_EQ(vec2[1], 10);
    EXPECT_EQ(vec2[2], 20);
    EXPECT_EQ(vec2[3], 30);
}

// ѕроверка оператора доступа по индексу
TEST(TestTVectorLib, IndexOperator) {
    TVector<int> vec(3, 1);
    vec[1] = 10;
    vec[2] = 20;
    vec[3] = 30;

    EXPECT_EQ(vec[1], 10);
    EXPECT_EQ(vec[2], 20);
    EXPECT_EQ(vec[3], 30);
}

// ѕроверка оператора сложени¤
TEST(TestTVectorLib, AddOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 10;
    vec1[2] = 20;
    vec1[3] = 30;

    TVector<int> vec2(3, 1);
    vec2[1] = 1;
    vec2[2] = 2;
    vec2[3] = 3;

    TVector<int> result = vec1 + vec2;
    EXPECT_EQ(result[1], 11);
    EXPECT_EQ(result[2], 22);
    EXPECT_EQ(result[3], 33);
}

// ѕроверка оператора вычитани¤
TEST(TestTVectorLib, SubOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 10;
    vec1[2] = 20;
    vec1[3] = 30;

    TVector<int> vec2(3, 1);
    vec2[1] = 1;
    vec2[2] = 2;
    vec2[3] = 3;

    TVector<int> result = vec1 - vec2;
    EXPECT_EQ(result[1], 9);
    EXPECT_EQ(result[2], 18);
    EXPECT_EQ(result[3], 27);
}

// ѕроверка оператора скал¤рного произведени¤
TEST(TestTVectorLib, MultScalarOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 1;
    vec1[2] = 2;
    vec1[3] = 3;

    TVector<int> vec2(3, 1);
    vec2[1] = 4;
    vec2[2] = 5;
    vec2[3] = 6;

    int result = vec1 * vec2;
    EXPECT_EQ(result, 32);
}

// ѕроверка оператора сложени¤ с присваиванием
TEST(TestTVectorLib, AddAssignOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 10;
    vec1[2] = 20;
    vec1[3] = 30;

    TVector<int> vec2(3, 1);
    vec2[1] = 1;
    vec2[2] = 2;
    vec2[3] = 3;

    vec1 += vec2;
    EXPECT_EQ(vec1[1], 11);
    EXPECT_EQ(vec1[2], 22);
    EXPECT_EQ(vec1[3], 33);
}

// ѕроверка оператора вычитани¤ с присваиванием
TEST(TestTVectorLib, SubAssignOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 10;
    vec1[2] = 20;
    vec1[3] = 30;

    TVector<int> vec2(3, 1);
    vec2[1] = 1;
    vec2[2] = 2;
    vec2[3] = 3;

    vec1 -= vec2;
    EXPECT_EQ(vec1[1], 9);
    EXPECT_EQ(vec1[2], 18);
    EXPECT_EQ(vec1[3], 27);
}

// ѕроверка оператора умножени¤ на скал¤р
TEST(TestTVectorLib, ScalarMultOperator) {
    TVector<int> vec(3, 1);
    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 3;

    TVector<int> result = vec * 2;
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 6);
}

// ѕроверка оператора умножени¤ на скал¤р с присваиванием
TEST(TestTVectorLib, ScalarMultnAssignOperator) {
    TVector<int> vec(3, 1);
    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 3;

    vec *= 2;
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 4);
    EXPECT_EQ(vec[3], 6);
}

// ѕроверка оператора сравнени¤
TEST(TestTVectorLib, EqualityOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 1;
    vec1[2] = 2;
    vec1[3] = 3;

    TVector<int> vec2(3, 1);
    vec2[1] = 1;
    vec2[2] = 2;
    vec2[3] = 3;

    EXPECT_TRUE(vec1 == vec2);
}

// ѕроверка оператора неравенства
TEST(TestTVectorLib, InequalityOperator) {
    TVector<int> vec1(3, 1);
    vec1[1] = 1;
    vec1[2] = 2;
    vec1[3] = 3;

    TVector<int> vec2(3, 1);
    vec2[1] = 4;
    vec2[2] = 5;
    vec2[3] = 6;

    EXPECT_TRUE(vec1 != vec2);
}

// ѕроверка метода изменени¤ размера
TEST(TestTVectorLib, SetSize) {
    TVector<int> vec(3, 1);
    vec.set_size(5);
    EXPECT_EQ(vec.size(), 5);
}

// ѕроверка метода очистки
TEST(TestTVectorLib, Clear) {
    TVector<int> vec(3, 1);
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.get_start_index(), 0);
}

// ѕроверка метода вывода
TEST(TestTVectorLib, Print) {
    TVector<int> vec(3, 1);
    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 3;

    std::stringstream ss;
    vec.print(ss);
    EXPECT_EQ(ss.str(), "{ 1, 2, 3 }");
}