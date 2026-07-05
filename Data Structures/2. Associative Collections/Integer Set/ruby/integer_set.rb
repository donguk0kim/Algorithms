class Set
  def initialize
    @store = []
  end
  
  # O(n)
  def insert(val)
    @store.push(val) unless include?(val)
  end

  # O(n)
  def remove(val)
    @store.delete(val) if include?(val)
  end
  
  # O(n)
  def include?(val)
    @store.any? { |element| element == val }
  end
end

class MaxIntSet
  def initialize(max)
    @max = max
    @store = (0...max).map { |index| false }
  end

  # O(1)
  def insert(num)
    validate!(num)
    @store[num] = true
  end

  # O(1)
  def remove(num)
    validate!(num)
    @store[num] = false
  end

  # O(1)
  def include?(num)
    @store[num]
  end

  private
  def is_valid?(num)
    (num >= 0) && (num < @max)
  end

  def validate!(num)
    raise 'Out of bounds' unless is_valid?(num)
  end
end


class IntSet
  def initialize(num_buckets = 20)
    @num_buckets = num_buckets
    @store = Array.new(num_buckets) { Array.new }
  end

  # O(1)
  def insert(num)
    bucket = self[num]
    bucket.push(num)
  end

  # O(k)
  def remove(num)
    bucket = self[num]
    bucket.delete(num)
  end

  # O(k)
  def include?(num)
    bucket = self[num]
    bucket.include?(num)
  end

  private
  def [](num)
    @store[num % num_buckets]
  end

  def num_buckets
    @num_buckets
  end
end

class ResizingIntSet
  attr_reader :count

  def initialize(num_buckets = 20)
    @count = 0
    @store = Array.new(num_buckets) { Array.new }
  end

  # O(1) ammortized
  def insert(num)
    resize! if @count == num_buckets
    bucket = self[num]
    bucket.push(num)
    @count += 1
  end
  
  # O(1) but O(k) worst case
  def remove(num)
    bucket = self[num]
    bucket.delete(num)
    @count -= 1
  end
  
  # O(1) but O(k) worst case
  def include?(num)
    bucket = self[num]
    bucket.include?(num)
  end

  private
  def [](num)
    @store[num % num_buckets]
  end

  def num_buckets
    @store.length
  end

  # O(n) but O(nk) worst case
  def resize!
    new_num_buckets = num_buckets * 2
    new_store = Array.new(new_num_buckets) { Array.new }
    @store.each do |bucket|
      bucket.each do |element|
        new_bucket = new_store[element % new_num_buckets]
        new_bucket.push(element)
      end
    end
    @store = new_store
  end
end