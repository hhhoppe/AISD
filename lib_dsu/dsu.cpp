// Copyright 2025 Dergynov Sergey

#include "../lib_dsu/dsu.h"
#include <iostream>

DSU::DSU(int size) : _size(size) {
	if (_size > 0) {
		_parent = new int[_size];
		_rank = new int[_size];
		for (int i = 0; i < _size; i++) {
			_parent[i] = i;
			_rank[i] = 1;
		}
	}
	else {
		throw std::invalid_argument("Size < 0!");
	}
}

DSU::~DSU() {
	delete[] _parent;
	delete[] _rank;
}

void DSU::make_set(int elem) {
	if (elem <= 0 || elem > _size) {
		throw std::logic_error("Elem <= 0 or Elem > Size!");
	}
	else {
		_parent[elem] = elem;
		_rank[elem] = 1;
	}
}

int DSU::find_noob(int elem) {
	if (elem <= 0 || elem > _size) {
		throw std::logic_error("Elem <= 0 or Elem > Size!");
	}
	elem--;
	if (_parent[elem] == elem) { 
		return elem; 
	}
	return find_noob(_parent[elem]);
}

int DSU::find_pro(int elem) {
	if (elem <= 0 || elem > _size) {
		throw std::logic_error("Elem <= 0 or Elem > Size!");
	}
	elem--;
	if (_parent[elem] != elem) {
		_parent[elem] = find_pro(_parent[elem]);
	}
	return _parent[elem];
}

void DSU::union_noob(int first, int second) {
	int _first = find_noob(first);
	int _second = find_noob(second);
	if (_first == _second) {
		return;
	}
	_parent[_second] = _first;
}

void DSU::clear() {
	for (int i = 0; i < _size; ++i) {
		_parent[i] = i;
	}
}