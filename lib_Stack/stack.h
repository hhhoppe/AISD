// Copyright 2025 Dergynov Sergey

#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_

#include <iostream>
#include <stdexcept>
#include "../lib_DMassive/dmassive.h"

template <typename T>
class Stack {
private:
	TDmassive<T> _data;			// Кондейнер для хранения элементов
public:
	Stack();					// Конструктор по умолчанию
	Stack(const Stack<T>& stack);// Конструктор копирования
	~Stack();					// Деструктор
	
	Stack<T>& operator=(const Stack<T>& stack);	// Оператор присваивания

	void push(const T& value);	// Добавить элемент на вершину стека
	void pop();					// Удалить элемент с вершины стека
	T& top();					// Получить элемент с вершины стека
	const T& top() const;		// Получить элемент с вершины стека (const)

	bool empty() const noexcept;// Пуст ли стек
	size_t size() const noexcept;// Кол-во элементов в стеке

	void clear();				// Очистить стек
	void print() const;			// Вывод стека
};

template <typename T>
Stack<T>:: Stack(): _data() {}

template <typename T>
Stack<T>::Stack(const Stack<T>& stack) : _data(stack._data) {}

template <typename T>
Stack<T>::~Stack() {
	_data.clear();
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack) {
	if (this != &stack) {
		_data = stack._data;
	}
	return *this;
}

template <typename T>
void Stack<T>::push(const T& value) {
	_data.push_back(value);
}

template <typename T>
void Stack<T>::pop() {
	if (empty()) {
		throw std::logic_error("Stack is empty");
	}
	_data.pop_back();
}

template <typename T>
T& Stack<T>::top() {
	if (empty()) {
		throw std::logic_error("Stack is empty");
	}
	return _data[_data.size() - 1];
}

template <typename T>
const T& Stack<T>::top() const {
	if (empty()) {
		throw std::logic_error("Stack is empty");
	}
	return _data[_data.size() - 1];
}

template <typename T>
bool Stack<T>::empty() const noexcept {
	return _data.empty();
}

template <typename T>
size_t Stack<T>::size() const noexcept {
	return _data.size();
}

template <typename T>
void Stack<T>::clear() {
	_data.clear();
}

template <typename T>
void Stack<T>::print() const {
	_data.print();
}

#endif  // LIB_STACK_STACK_H_