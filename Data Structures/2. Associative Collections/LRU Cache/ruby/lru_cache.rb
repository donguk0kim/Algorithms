require_relative 'p05_hash_map'
require_relative 'p04_linked_list'

class LRUCache
  attr_reader :store, :map
  def initialize(max, prc)
    @max = max
    @prc = prc
    @map = HashMap.new
    @store = LinkedList.new
  end

  def count
    @map.count
  end

  # O()
  def [](key)
    node = @map[key]
    if node
      update_node!(node)
      node.val
    else
      calc!(key)
    end
  end

  def to_s
    "Map: " + @map.to_s + "\n" + "Store: " + @store.to_s
  end

  alias_method :get, :[]

  private
  # O()
  def calc!(key)
    eject! if count == @max
    val = @prc.call(key)
    node = @store.append(key, val)
    @map[key] = node
    val
  end

  # O()
  def update_node!(node)
    @store.remove(node.key)
    new_node = @store.append(node.key, node.val)
    @map[node.key] = new_node
  end

  # O()
  def eject!
    least = @store.first
    @store.remove(least.key)
    @map.delete(least.key)
  end
end