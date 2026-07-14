#pragma once

#include <iostream>
#include <stdexcept>

class RingBuffer {
  // member variables
  int start_;
  int count_;
  int capacity_;
  int* store_;

public:
  // constructor & destructor
  RingBuffer();
  ~RingBuffer();

  // accessors
  int& operator[] (int index);

  // basic operations
  int Pop();
  int Shift();
  void Push(int value);
  void Unshift(int value);

  // debugger
  void Print() const;

private:
  // internal member functions
  void Fill();
  void Resize();
  int Wrap(int index) const;
  int Intern(int index) const;
  bool IsInvalid(int index) const;
  void CheckIndex(int index) const;
};
