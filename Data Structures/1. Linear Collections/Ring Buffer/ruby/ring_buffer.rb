require_relative "static_array"

class RingBuffer
  attr_reader :length, :capacity, :store

  def initialize
    @start = 0
    @length = 0
    @capacity = 8
    @store = StaticArray.new(@capacity)
  end

  # O(1)
  def [](index)
    check_index_get(index)
    @store[store_index(index)]
  end

  # O(1)
  def []=(index, val)
    check_index_set(index)
    @store[store_index(index)] = val
  end

  # O(1)
  def pop
    last_value = self[@length - 1]
    self[@length - 1] = nil
    @length -= 1
    last_value
  end

  # O(1) ammortized
  def push(val)
    resize! if @length == @capacity
    self[@length] = val
    @length += 1
  end

  # O(1)
  def shift
    first_value = self[0]
    self[0] = nil
    @start += 1
    @length -= 1
    first_value
  end

  # O(1) ammortized
  def unshift(val)
    resize! if @length == @capacity
    self[-1] = val
    @start -= 1
    @length += 1
  end

  protected
  def check_index_get(index)
    raise 'index out of bounds' if index >= @length
    raise 'index out of bounds' if index < 0
  end

  def check_index_set(index)
    raise 'index out of bounds' if index > @length
  end

  def resize!
    new_capacity = @capacity * 2
    new_store = StaticArray.new(new_capacity)
    @length.times { |index| new_store[index] = self[index] }
    @start = 0
    @store = new_store
    @capacity = new_capacity
  end

  def store_index(user_index)
    (user_index + @start) % @capacity
  end
end