// Copyright 2025 Dergynov Sergey

#include <gtest.h>
#include "../lib_dsu/dsu.h"
/*
// Проверка конструктора с корректным параметром
TEST(TestDSULib, ConstructorValid) {
	DSU dsu(10);
	EXPECT_EQ(dsu.find_pro(1), 0);
	EXPECT_EQ(dsu.find_pro(10), 9);
}

// Проверка конструктора с некорректным параметром
TEST(TestDSULib, ConstructorInvalid) {
	EXPECT_THROW(DSU dsu(-1), std::invalid_argument);
	EXPECT_THROW(DSU dsu(-5), std::invalid_argument);
}

// Проверка make_set с корректным элементом
TEST(TestDSULib, MakeSetValid) {
	DSU dsu(10);
	dsu.make_set(5);
	EXPECT_EQ(dsu.find_pro(5), 4);
}

// Проверка make_set с некорректным элементом
TEST(TestDSULib, MakeSetInvalid) {
	DSU dsu(10);
	EXPECT_THROW(DSU dsu(-1), std::logic_error);
	EXPECT_THROW(DSU dsu(11), std::logic_error);
}

// Проверка find_noob с корректным элементом
TEST(TestDSULib, FindNoobValid) {
	DSU dsu(10);
	EXPECT_EQ(dsu.find_noob(3), 2);
}

// Проверка find_noob с некорректным элементом
TEST(TestDSULib, FindNoobInvalid) {
	DSU dsu(10);
	EXPECT_THROW(dsu.find_noob(11), std::logic_error);
}

// Проверка find_pro с корректным элементом
TEST(TestDSULib, FindProValid) {
	DSU dsu(10);
	EXPECT_EQ(dsu.find_pro(3), 2);
}

// Проверка find_pro с некорректным элементом
TEST(TestDSULib, FindProInvalid) {
	DSU dsu(10);
	EXPECT_THROW(dsu.find_pro(11), std::logic_error);
}

// Проверка union_noob с корректным элементом
TEST(TestDSULib, UnionNoobValid) {
	DSU dsu(10);
	dsu.union_noob(1, 2);
	EXPECT_EQ(dsu.find_noob(1), dsu.find_noob(2));
}

// Проверка union_noob с некорректным элементом
TEST(TestDSULib, UnionNoobInvalid) {
	DSU dsu(10);
	EXPECT_THROW(dsu.union_noob(1, 11), std::logic_error);
}

// Проверка union_pro с корректным элементом
TEST(TestDSULib, UnionProValid) {
	DSU dsu(10);
	dsu.union_pro(1, 2);
	EXPECT_EQ(dsu.find_pro(1), dsu.find_pro(2));
}

// Проверка union_pro с некорректным элементом
TEST(TestDSULib, UnionProInvalid) {
	DSU dsu(10);
	EXPECT_THROW(dsu.union_pro(1, 11), std::logic_error);
}

// Проверка clear
TEST(TestDSULib, Clear) {
	DSU dsu(3);
	dsu.union_pro(1, 2);
	dsu.clear();
	EXPECT_EQ(dsu.find_pro(1), dsu.find_pro(2));
}

// Проверка объединения и поиск (noob)
TEST(TestDSULib, UnionFindNoob) {
	DSU dsu(10);
	dsu.union_noob(1, 2);
	dsu.union_noob(3, 4);
	dsu.union_noob(2, 4);
	EXPECT_EQ(dsu.find_noob(1), dsu.find_noob(3));
}

// Проверка объединения и поиск (pro)
TEST(TestDSULib, UnionFindPro) {
	DSU dsu(10);
	dsu.union_pro(1, 2);
	dsu.union_pro(3, 4);
	dsu.union_pro(2, 4);
	EXPECT_EQ(dsu.find_pro(1), dsu.find_pro(3));
}
*/