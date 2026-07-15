#pragma once

#include <vector>

class Bucket {
    // member variables
    std::vector<int> store_;

public:
    // constructor
    Bucket();

    // accessors
    int& operator[](int index);

    // basic operations
    int length() const;
    void push(int value);
    void remove(int value);
    bool includes(int value) const;
};
