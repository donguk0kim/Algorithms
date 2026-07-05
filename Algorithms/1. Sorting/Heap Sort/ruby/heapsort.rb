require_relative 'heap'

class Array
  def heapsort
    result = []
    heap = BinaryMinHeap.new
    self.each { |el| heap.push(el) }
    result.push(heap.extract) until heap.empty?
    result
  end

  def heapsort!
    numel = self.length
    prc = Proc.new { |parent, child| child <=> parent }
    0.upto(numel - 1) { |k| BinaryMinHeap.heapify_up(self, k, numel, &prc) }

    until numel == 0
      numel -= 1
      self[0], self[numel] = self[numel], self[0]
      BinaryMinHeap.heapify_down(self, 0, numel, &prc)
    end
  end
end