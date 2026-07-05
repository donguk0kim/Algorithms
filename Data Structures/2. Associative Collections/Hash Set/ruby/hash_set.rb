require_relative 'p02_hashing'

class HashSet
  attr_reader :count
  
  def initialize(num_buckets = 8)
    @count = 0
    @store = Array.new(num_buckets) { Array.new }
  end

  # O(1) ammortized
  def insert(key)
    resize! if @count == num_buckets
    bucket = self[key]
    bucket.push(key)
    @count += 1
  end

  # O(1)
  def remove(key)
    bucket = self[key]
    bucket.delete(key)
    @count -= 1
  end

  # O(1)
  def include?(key)
    bucket = self[key]
    bucket.include?(key)
  end

  private
  def [](num)
    @store[num.hash % num_buckets]
  end

  def num_buckets
    @store.length
  end

  # O(n)
  def resize!
    new_num_buckets = num_buckets * 2
    new_store = Array.new(new_num_buckets) { Array.new }
    @store.each do |bucket|
      bucket.each do |element|
        new_bucket = new_store[element.hash % num_buckets]
        new_bucket.push(element)
      end
    end
    @store = new_store
  end
end