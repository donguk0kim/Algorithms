#pragma once

class MaxIntSet {
  // member variables
  int capacity_;
  bool* store_;

public:
  // constructor
  MaxIntSet(int max);

  // basic operations
  void Insert(int value);
  void Remove(int value);
  bool Includes(int value) const;

  // debugger
  void Print() const;

private:
  // internal members
  void Fill();
  bool IsInvalid(int index) const;
  void CheckIndex(int index) const;
};
