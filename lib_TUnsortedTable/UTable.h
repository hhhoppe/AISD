// Copyright 2025 Dergynov Sergey

#ifndef LIB_TUNSORTEDTABLE_UTABLE_H_
#define LIB_TUNSORTEDTABLE_UTABLE_H_

#include <iostream>
#include <stdexcept>
#include "../lib_Pair/pair.h"
#include "../lib_List/list.h"

template <class TKey, class TVal>
class UTable : ITable <TPair <TKey, TVal>> {
    TList <TPair <TKey, TVal>> _data;
    size_t _size;

public:
    UTable() {}
    UTable(const TList <TPair <TKey, TVal>>& data) : _data(data) {
        _size = _data.size();
    }
    UTable(const UTable& tab) : _data(tab._data), _size(tab._size) {}
    TKey insert(TVal value) {
        TPair <TKey, TVal> new_row(generate_key(), value);
        _data.push_back(new_row);
        _size++;
        return new_row
    }
    void insert(TKey key, TVal val) {
        if (find(key)) { throw std::logic_error("labadabdab") }
        TPair <TKey, TVal> new_row(key, val);
        _data push_back(new_row);
        _size++;
    }
};

#endif  //LIB_TUNSORTEDTABLE_UTABLE_H_