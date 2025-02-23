// Copyright 2025 Dergynov Sergey

#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H_

#include <iostream>
#include <stdexcept>
#include "../lib_DMassive/dmassive.h"

template <typename T>
class TQueue {
private:
	TDmassive<T> _data;		// Кондейнер для хранения элементов
	size_t _front;			// Начало очереди
	size_t _back;			// Конец очереди
	size_t _size;			// Кол-во элементов
	size_t _capacity;		// Максимальный размер очереди
public:
	TQueue();									// Конструктор по умолчанию
	explicit TQueue(size_t capacity);			// Конструктор с параметром
	TQueue(const TQueue<T>& queue);				// Конструктор копирования
	explicit TQueue(const TDmassive<T>& mass);	// Конструктор из массива
	~TQueue();									// Деструктор
	
	bool ifFull() const;		// Полна ли очередь
	bool ifEmpty() const;		// Пуста ли очередь

	void push(const T& value);	// Добавить элемент в конец
	T pop();					// Удалить и вернуть элемент из начала
	size_t get_front() const;	// Получить индекс начала очереди
	size_t get_back() const;	// Получить индекс конца очереди
	size_t size() const;		// Получить размер очереди
	size_t capacity() const;	// Получить вместимость очереди

	void clear();				// Очистить содержимое очереди
	void print() const;			// Вывести содержимое очереди
};

template <typename T>
TQueue<T>::TQueue(): _data(new T[_capacity]), _front(-1), _back(), _size(0), _capacity(10) {}

template <typename T>
TQueue<T>::TQueue(size_t capacity): _data(nullptr), _front(-1), _back(-1), _size(0), _capacity(capacity) {
	if (_capacity <= 0) {
		throw std::invalid_argument("Capacity <= 0");
	}
	_data = new T[_capacity];
}

template <typename T>
TQueue<T>::TQueue(const TQueue<T>& queue): _data(new T[queue._capatity]), _front(queue._front), _back(queue._back), _size(queue._size), _capacity(_capacity) {
	if (!queue.ifEmpty()) {
		size_t i = queue._front;
		while (true) {
			_data[i] = queue._data[i];
			if (i == queue._back) {
				break;
			}
			i = (i + 1) % _capacity;
		}
	}
}

template <typename T>
TQueue<T>::TQueue(const TDmassive<T>& mass): _data(new T[_capacity]), _front(-1), _back(-1), _size(0), _capacity(mass.size()) {
	for (size_t i = 0; i < mass.size(); ++i) {
		push(mass[i]);
	}
}

template <typename T>
TQueue<T>::~TQueue() {
	delete[] _data;
}

template <typename T>
bool TQueue<T>::ifFull() const {
	return _size == _capacity;
}

template <typename T>
bool TQueue<T>::ifEmpty() const {
	return _size == 0;
}

template <typename T>
void TQueue<T>::push(const T& value) {
	if (ifFull()) {
		throw std::overflow_error("Queue is full");
	} else if (ifEmpty()) {
		_front = 0;
		_back = 0;
	} else {
		_back = (_back + 1) % _capacity;
	}
	_data[_back] = value;
	++_size;
}

template <typename T>
T TQueue<T>::pop() {
	if (ifEmpty()) {
		throw std::underflow_error("Queue is empty");
	}
	T value = _data[_front];
	if (_front == _back) {
		_front = -1;
		_back = -1;
	} else {
		_front = (_front + 1) % _capacity;
	}
	--_size;
	return value;
}

template <typename T>
size_t TQueue<T>::get_front() const {
	return _front;
}

template <typename T>
size_t TQueue<T>::get_back() const {
	return _back;
}

template <typename T>
size_t TQueue<T>::size() const {
	return _size;
}

template <typename T>
size_t TQueue<T>::capacity() const {
	return _capacity;
}

template <typename T>
void TQueue<T>::clear() {
	_front = -1;
	_back = -1;
	_size = 0;
}

template <typename T>
void TQueue<T>::print() const {
	if (ifEmpty()) {
		throw std::overflow_error("Queue is empty");
	}
	size_t i = _front;
	while (true) {
		std::cout << _data[i] << " ";
		if (i == _back) {
			break;
		}
		i = (i + 1) % _capacity;
	}
	std::cout << std::endl;
}

#endif  // LIB_QUEUE_QUEUE_H_