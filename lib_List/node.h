// Copyright 2025 Dergynov Sergey

#ifndef LIB_LIST_NODE_H_
#define LIB_LIST_NODE_H_

#include <iostream>

template <class T>
class TNode {
private:
	T _value;			// Значение в звене
	TNode<T>* _pnext;	// Указатель на следующее звено
public:
	explicit TNode(const T& value, TNode<T>* pnext = nullptr);	// Конструктор с параметрами
	TNode(const TNode<T>& node);								// Конструктор копирования

	T& get_value();									// Вернуть значение из звена
	void set_value(const T& value);					// Установить значение в звено
	TNode<T>* get_next() const;						// Вернуть указатель на следующее звено
	void set_next(TNode<T>* pnext);					// Установить указатель на следующее звено

	TNode<T>& operator=(const TNode<T>& node);	// Оператор присваивания
	bool operator==(const TNode<T>& node) const;	// Оператор сравнения

	template <class U>
	friend std::istream& operator>>(std::istream& is, TNode<U>& node);		// Ввод значения

	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const TNode<U>& node); // Вывод значения
};

template <class T>
TNode<T>::TNode(const T& value, TNode<T>* pnext): _value(value), _pnext(pnext) {}

template <class T>
TNode<T>::TNode(const TNode<T>& node): _value(node._value), _pnext(node._pnext) {}

template <class T>
T& TNode<T>::get_value() {
	return _value;
}

template <class T>
void TNode<T>::set_value(const T& value) {
	_value = value;
}

template <class T>
TNode<T>* TNode<T>::get_next() const {
	return _pnext;
}

template <class T>
void TNode<T>::set_next(TNode<T>* pnext) {
	_pnext = pnext;
}

template <class T>
TNode<T>& TNode<T>::operator=(const TNode<T>& node) {
	if (this != &node) {
		_value = node._value;
		_pnext = node._pnext;
	}
	return *this;
}

template <class T>
bool TNode<T>::operator==(const TNode<T>& node) const {
	return _value == node._value;
}

template <class U>
std::ostream& operator<<(std::ostream& os, const TNode<U>& node) {
	os << node._value;
	return os;
}

template <class U>
std::istream& operator>>(std::istream& is, TNode<U>& node) {
	is >> node._value;
	return is;
}

#endif  LIB_LIST_NODE_H_