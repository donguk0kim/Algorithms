#pragma once

#include <vector>

class HashSet {
  // member variables
  int count_;
  int num_buckets_;
  std::vector<int>* store_;

public:
  // constructor
  HashSet();

  // basic operations
  int Length() const;
  void Insert(int value);
  void Remove(int value);
  bool Includes(int value) const;

  // debugger
  void Print() const;

private:
  // internal members
  void Fill();
  void Resize();
  int Hash(int value) const;
  int BucketIndex(int value, int n_buckets) const;
  int IndexAt(std::vector<int> bucket, int value) const;
};
