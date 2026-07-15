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
  int length() const;
  void insert(int value);
  void remove(int value);
  bool includes(int value) const;

  // debugger
  void print() const;

private:
  // internal members
  void fill();
  void resize();
  int hash(int value) const;
  int bucketIndex(int value, int n_buckets) const;
  int indexAt(std::vector<int> bucket, int value) const;
};
