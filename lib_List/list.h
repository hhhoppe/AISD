// Copyright 2025 Dergynov Sergey

#ifndef LIB_LIST_LIST_H_
#define LIB_LIST_LIST_H_

#include <iostream>
#include "../lib_List/node.h"

template <class T>
class TList {
private:
	TNode<T>* _head;				// Указатель на начало списка
	TNode<T>* _tail;				// Указатель на конец списка
public:
	TList();						// Конструктор по умолчанию
	TList(const TList<T>& list);	// Конструктор копирования
	~TList();						// Деструктор

	void push_back(const T& value);						// Вставка в конец списка
	void push_front(const T& value);					// Вставка в начало списка
	void insert_after(TNode<T>* node, const T& value);	// Вставка после указанного звена
	void insert_to(size_t position, const T& value);	// Вставка на указанную позицию

	TNode<T>* find(const T& value) const;				// Поиск звена по значению
	T front() const;									// Вернуть значение первого элемента
	TNode<T>* get_node_to(size_t position) const;		// Вернуть указатель на звено по индексу

	void pop_back();				// Удалить из конца списка
	void pop_front();				// Удалить из начала списка
	void remove(TNode<T>* node);	// Удалить указанное звено
	void remove_to(size_t position);// Удалить по указанной позиции

	void replace(TNode<T>* node, const T& new_value);	// Заменить значение в указанном звене
	void replace_to(size_t position, const T& new_value);// Заменить значение по указанной позиции

	bool ifEmpty() const;			// Постой ли список

	TNode<T>* get_head() const;		// Вернуть указатель на первое звено
	TNode<T>* get_tail() const;		// Вернуть указатель на второе звено

	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const TList<U>& list);// Вывод списка

	template <class U>
	friend std::istream& operator>>(std::istream& is, TList<U>& list);		// Ввод списка

	// Итератор для обхода списка
	class Iterator {
	private:
		TNode<T>* current;			// Текущее звено
	public:
		Iterator(): current(nullptr) {}
		explicit Iterator(TNode<T>* node): current(node) {}

		T& operator*() const {
			return current->get_value();
		}
		Iterator& operator++() {
			if (current) {
				current = current->get_next();
			}
			return *this;
		}
		Iterator& operator++() const {
			if (current) {
				current = current->get_next();
			}
			return *this;
		}
		Iterator operator++(int) {
			Iterator iterator = *this;
			if (current) {
				current = current->get_next();
			}
			return iterator;
		}
		Iterator operator++(int) const {
			Iterator iterator = *this;
			if (current) {
				current = current->get_next();
			}
			return iterator;
		}
		
		bool operator==(const Iterator& iterator) const {
			return current == iterator.current;
		}
		bool operator!=(const Iterator& iterator) const {
			return current != iterator.current;
		}
	};

	Iterator begin() {
		return Iterator(_head);
	}
	Iterator begin() const {
		return Iterator(_head);
	}
	Iterator end() {
		return Iterator(nullptr);
	}
	Iterator end() const {
		return Iterator(nullptr);
	}
};

template <class T>
TList<T>::TList(): _head(nullptr), _tail(nullptr) {}

template <class T>
TList<T>::TList(const TList<T>& list): _head(nullptr), _tail(nullptr) {
	TNode<T>* current = list._head;
	while (current != nullptr) {
		push_back(current->get_value());
		current = current->get_next();
	}
}

template <class T>
TList<T>::~TList() {
	while (!ifEmpty()) {
		pop_front();
	}
}

template <class T>
void TList<T>::push_back(const T& value) {
	TNode<T>* node = new TNode<T>(value);
	if (ifEmpty()) {
		_head = node;
		_tail = node;
	} else {
		_tail->set_next(node);
		_tail = node;
	}
}

template <class T>
void TList<T>::push_front(const T& value) {
	TNode<T>* node = new TNode<T>(value, _head);
	if (ifEmpty()) {
		_tail = node;
	}
	_head = node;
}

template <class T>
void TList<T>::insert_after(TNode<T>* node, const T& value) {
	if (node == nullptr) {
		throw std::invalid_argument("Node = null");
	}
	TNode<T>* _node = new TNode<T>(value, node->get_next());
	node->set_next(_node);
	if (node == _tail) {
		_tail = _node;
	}
}

template <class T>
void TList<T>::insert_to(size_t position, const T& value) {
	if (position == 0) {
		push_front(value);
		return;
	}
	TNode<T>* current = _head;
	for (size_t i = 0; i < position - 1; ++i) {
		if (current == nullptr) {
			throw std::out_of_range("Position out of range");
		}
		current = current->get_next();
	}
	if (current == nullptr) {
		throw std::out_of_range("Position out of range");
	}
	insert_after(current, value);
}

template <class T>
TNode<T>* TList<T>::find(const T& value) const {
	TNode<T>* current = _head;
	while (current != nullptr) {
		if (current->get_value() == value) {
			return current;
		}
		current = current->get_next();
	}
	return nullptr;
}

template <class T>
T TList<T>::front() const {
	if (ifEmpty()) {
		throw std::out_of_range("List is empty");
	}
	return _head->get_value();
}

template <class T>
TNode<T>* TList<T>::get_node_to(size_t position) const {
	TNode<T>* current = _head;
	size_t index = 0;
	while (current != nullptr) {
		if (index == position) {
			return current;
		}
		current = current->get_next();
		++index;
	}
	throw std::out_of_range("Position out of range");
}

template <class T>
void TList<T>::pop_back() {
	if (ifEmpty()) {
		throw std::out_of_range("List is empty");
	}
	if (_head == _tail) {
		delete _head;
		_head = nullptr;
		_tail = nullptr;
	}
	else {
		TNode<T>* current = _head;
		while (current->get_next() != _tail) {
			current = current->get_next();
		}
		delete _tail;
		_tail = current;
		_tail->set_next(nullptr);
	}
}

template <class T>
void TList<T>::pop_front() {
	if (ifEmpty()) {
		throw std::out_of_range("List is empty");
	}
	TNode<T>* tmp = _head;
	_head = _head->get_next();
	delete tmp;
	if (_head == nullptr) {
		_tail = nullptr;
	}
}

template <class T>
void TList<T>::remove(TNode<T>* node) {
	if (ifEmpty() || node == nullptr) {
		throw std::invalid_argument("Node = null or list is empty");
	}
	if (node == _head) {
		pop_front();
		return;
	}
	TNode<T>* current = _head;
	while (current->get_next() != nullptr && current->get_next() != node) {
		current = current->get_next();
	}
	if (current->get_next() == nullptr) {
		throw std::invalid_argument("Node not found");
	}
	current->set_next(node->get_next());
	if (node == _tail) {
		_tail = current;
	}
	delete node;
}

template <class T>
void TList<T>::remove_to (size_t position) {
	if (ifEmpty()) {
		throw std::out_of_range("List is empty");
	}
	if (position == 0) {
		pop_front();
		return;
	}
	TNode<T>* current = _head;
	for (size_t i = 0; i < position - 1; ++i) {
		if (current == nullptr || current->get_next() == nullptr) {
			throw std::out_of_range("Position out of range");
		}
		current = current->get_next();
	}
	TNode<T>* node = current->get_next();
	if (node == nullptr) {
		throw std::out_of_range("Position out of range");
	}
	current->set_next(node->get_next());
	if (node == _tail) {
		_tail = current;
	}
	delete node;
}

template <class T>
void TList<T>::replace(TNode<T>* node, const T& new_value) {
	if (node == nullptr) {
		throw std::invalid_argument("Node = null");
	}
	node->set_value(new_value);
}

template <class T>
void TList<T>::replace_to(size_t position, const T& new_value) {
	TNode<T>* current = _head;
	for (size_t i = 0; i < position; ++i) {
		if (current == nullptr) {
			throw std::out_of_range("Position out of range");
		}
		current = current->get_next();
	}
	if (current == nullptr) {
		throw std::out_of_range("Position out of range");
	}
	current->set_value(new_value);
}

template <class T>
bool TList<T>::ifEmpty() const {
	return _head == nullptr;
}

template <class T>
TNode<T>* TList<T>::get_head() const {
	return _head;
}

template <class T>
TNode<T>* TList<T>::get_tail() const {
	return _tail;
}

template <class U>
std::ostream& operator<<(std::ostream& os, const TList<U>& list) {
	TNode<U>* current = list._head;
	while (current != nullptr) {
		os << current->get_value() << " -> ";
		current = current->get_next();
	}
	os << "nullptr";
	return os;
}

template <class U>
std::istream& operator>>(std::istream& is, TList<U>& list) {
	U value;
	while (is >> value) {
		list.push_back(value);
	}
	return is;
}

#endif  LIB_LIST_LIST_H_