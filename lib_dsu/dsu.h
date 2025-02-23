// Copyright 2025 Dergynov Sergey

#ifndef LIB_DSU_DSU_H_
#define LIB_DSU_DSU_H_

class DSU {
	int _size;
	int* _parent;
	int* _rank;
public:
	DSU(int size = 0);
	~DSU();
	void make_set(int elem);
	int find_noob(int elem);
	void union_noob(int first, int second);
	void clear();
};

#endif  // LIB_DSU_DSU_H_