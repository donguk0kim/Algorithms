#pragma once

class DynamicArray {
  // member variables
  int count_;
  int capacity_;
  int* store_;

public:
  // constructor & destructor
  DynamicArray();
  ~DynamicArray();

  // accessors
  int& operator[] (int index);

  // basic operations
  int Pop();
  int Shift();
  void Push(int val);
  void Unshift(int val);

  // debugger
  void Print();

private:
  // internal members
  void Fill();
  void Resize();
  bool IsInvalid(int index);
  void CheckIndex(int index);
};
