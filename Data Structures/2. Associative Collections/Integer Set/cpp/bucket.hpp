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
    int Length() const;
    void Push(int value);
    void Remove(int value);
    bool Includes(int value) const;
};
