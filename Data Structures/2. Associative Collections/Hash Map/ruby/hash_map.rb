require_relative 'p02_hashing'
require_relative 'p04_linked_list'

class HashMap
  include Enumerable
  attr_reader :count

  def initialize(num_buckets = 8)
    @count = 0
    @store = Array.new(num_buckets) { LinkedList.new }
  end

  # O(1)
  def include?(key)
    bucket = bucket(key)
    bucket.include?(key)
  end

  # O(1)
  def [](key)
    bucket = bucket(key)
    bucket.get(key)
  end

  # O(1) ammortized
  def []=(key, val)
    bucket = bucket(key)
    if bucket.include?(key)
      bucket.update(key, val)
    else
      resize! if @count == num_buckets
      bucket.append(key, val)
      @count += 1
    end
  end

  # O(1)
  def delete(key)
    bucket = bucket(key)
    bucket.remove(key)
    @count -= 1
  end

  def each
    @store.each do |bucket|
      bucket.each do |node|
        yield(node.key, node.val)
      end
    end
  end

  # uncomment when you have Enumerable included
  def to_s
    pairs = inject([]) do |strs, (k, v)|
      strs << "#{k.to_s} => #{v.to_s}"
    end
    "{\n" + pairs.join(",\n") + "\n}"
  end

  alias_method :get, :[]
  alias_method :set, :[]=

  private

  def num_buckets
    @store.length
  end

  # O(n)
  def resize!
    new_num_buckets = num_buckets * 2
    new_store = Array.new(new_num_buckets) { LinkedList.new }
    each do |key, val|
      new_bucket = new_store[key.hash % new_num_buckets]
      new_bucket.append(key, val)
    end
    @store = new_store
  end

  def bucket(key)
    @store[key.hash % num_buckets]
  end
end