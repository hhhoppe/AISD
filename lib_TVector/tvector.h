// Copyright 2024 Dergynov Sergey

#ifndef LIB_TVECTOR_TVECTOR_H_
#define LIB_TVECTOR_TVECTOR_H_

#include <iostream>
#include <stdexcept>
#include "../lib_DMassive/dmassive.h"

template <typename T>
class TVector {
protected:
	TDmassive<T> _data;		// Кондейнер для хранения элементов
	size_t _start_index;	// Начальный индекс вектора
public:
	TVector();														// Конструктор по умолчанию
	explicit TVector(size_t size, size_t start_index = 0);			// Конструктор с размером и начальным индексом
	TVector(const T* mass, size_t size, size_t start_index = 0);	// Конструктор из массива
	TVector(const TVector<T>& vector);								// Конструктор копирования

	~TVector();				// Деструктор

	TVector<T>& operator=(const TVector<T>& vector);		// Оператор присваивания
	T& operator[](size_t index);							// Операторы доступа
	const T& operator[](size_t index) const;

	TVector<T> operator+(const TVector<T>& vector) const;	// Оператор сложения
	TVector<T> operator-(const TVector<T>& vector) const;	// Оператор вычитания
	T operator*(const TVector<T>& vector) const;			// Оператор произведения
	
	TVector<T>& operator+=(const TVector<T>& vector);		// Оператор сложения (присваивание)
	TVector<T>& operator-=(const TVector<T>& vector);		// Оператор вычитания (присваивание)

	bool operator==(const TVector<T>& vector) const;		// Операторы сравнения
	bool operator!=(const TVector<T>& vector) const;
	
	TVector<T> operator*(const T& scalar) const;			// Оператор умножения на скаляр
	TVector<T>& operator*=(const T& scalar);				// Оператор умножения на скаляр (присваивание)

	size_t size() const;									// Получение размера вектора
	size_t get_start_index() const;							// Геттер (начальный индекс)
	void set_start_index(size_t start_index);				// Сеттер (начальный индекс)

	void set_size(size_t new_size);							// Изменение размера вектора
	void clear();											// Очистка вектора

	void print(std::ostream& out = std::cout) const;		// Вывод вектора

	class Iterator {										// Вложенный класс для обхода элементов вектора
	private:
		TVector<T>& _vector;								// Ссылка на вектор
		size_t _index;										// Текущий индекс
	public:
		explicit Iterator(TVector<T>& vector): _vector(vector), _index(0) {}

		void FirstIterator() { _index = 0; }				// Установить итератор на начало
		void NextIterator() { ++_index; }					// Переместить итератор на след элемент
		bool IfEnd() const { return _index >= _vector.size(); } // Конец ли вектора

		T& CurrentElem() {									// Текущий элемент
			if (IfEnd()) {
				throw std::out_of_range("Iterator out of range of vector");
			}
			return _vector._data[_index];
		}
	};

	Iterator GetIterator() {								// Получить итератор
		return Iterator(*this);
	}
};

template <typename T>
TVector<T>::TVector(): _data(), _start_index(0) {}

template <typename T>
TVector<T>::TVector(size_t size, size_t start_index) : _data(), _start_index(start_index) {
	_data.resize(size);
}

template <typename T>
TVector<T>::TVector(const T* mass, size_t size, size_t start_index) : _data(), _start_index(start_index) {
	_data.insert(mass, size, 0);
}

template <typename T>
TVector<T>::TVector(const TVector<T>& vector): _data(vector._data), _start_index(vector._start_index) {}

template <typename T>
TVector<T>::~TVector() {}

template <typename T>
TVector<T>& TVector<T>::operator=(const TVector<T>& vector) {
	if (this != &vector) {
		_data = vector._data;
		_start_index = vector._start_index;
	}
	return *this;
}

template <typename T>
T& TVector<T>::operator[](size_t index) {
	if (index < _start_index || index >= _start_index + _data.size()) {
		throw std::out_of_range("Index out of range");
	}
	return _data[index - _start_index];
}

template <typename T>
const T& TVector<T>::operator[](size_t index) const {
	if (index < _start_index || index >= _start_index + _data.size()) {
		throw std::out_of_range("Index out of range");
	}
	return _data[index - _start_index];
}

template <typename T>
TVector<T> TVector<T>::operator+(const TVector<T>& vector) const {
	TVector<T> result(*this);
	result += vector;
	return result;
}

template <typename T>
TVector<T> TVector<T>::operator-(const TVector<T>& vector) const {
	TVector<T> result(*this);
	result -= vector;
	return result;
}

template <typename T>
T TVector<T>::operator*(const TVector<T>& vector) const {
	if (size() != vector.size() || _start_index != vector._start_index) {
		throw std::logic_error("Different vector sizes");
	}
	T result = T();
	for (size_t i = 0; i < size(); ++i) {
		result += _data[i] * vector._data[i];
	}
	return result;
}

template <typename T>
TVector<T>& TVector<T>::operator+=(const TVector<T>& vector) {
	if (size() != vector.size() || _start_index != vector._start_index) {
		throw std::logic_error("Different vector sizes");
	}
	for (size_t i = 0; i < size(); ++i) {
		_data[i] += vector._data[i];
	}
	return *this;
}

template <typename T>
TVector<T>& TVector<T>::operator-=(const TVector<T>& vector) {
	if (size() != vector.size() || _start_index != vector._start_index) {
		throw std::logic_error("Different vector sizes");
	}
	for (size_t i = 0; i < size(); ++i) {
		_data[i] -= vector._data[i];
	}
	return *this;
}

template <typename T>
bool TVector<T>::operator==(const TVector<T>& vector) const {
	if (size() != vector.size() || _start_index != vector._start_index) {
		return false;
	}
	for (size_t i = 0; i < size(); ++i) {
		if (_data[i] != vector._data[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool TVector<T>::operator!=(const TVector<T>& vector) const {
	return !(*this == vector);
}

template <typename T>
TVector<T> TVector<T>::operator*(const T& scalar) const {
	TVector<T> result(*this);
	result *= scalar;
	return result;
}

template <typename T>
TVector<T>& TVector<T>::operator*=(const T& scalar) {
	for (size_t i = 0; i < size(); ++i) {
		_data[i] *= scalar;
	}
	return *this;
}

template <typename T>
size_t TVector<T>::size() const {
	return _data.size();
}

template <typename T>
size_t TVector<T>::get_start_index() const {
	return _start_index;
}

template <typename T>
void TVector<T>::set_start_index(size_t start_index) {
	_start_index = start_index;
}

template <typename T>
void TVector<T>::set_size(size_t new_size) {
	_data.resize(new_size);
}

template <typename T>
void TVector<T>::clear() {
	_data.clear();
	_start_index = 0;
}

template <typename T>
void TVector<T>::print(std::ostream& out) const {
	out << "{ ";
	for (size_t i = 0; i < size(); ++i) {
		out << _data[i];
		if (i < size() - 1) { out << ", "; }
	}
	out << " }";
}

#endif  // LIB_TVECTOR_TVECTOR_H_