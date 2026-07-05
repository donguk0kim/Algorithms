class Array
  def quicksort(&prc)
    prc ||= Proc.new { |a, b| a <=> b }
    return self if self.length <= 1
    pivot_element = self[0]
    pivs = self.select { |el| prc.call(pivot_element, el) ==  0 }
    left = self.select { |el| prc.call(pivot_element, el) ==  1 }
    rite = self.select { |el| prc.call(pivot_element, el) == -1 }
    return left.quicksort(&prc) + pivs + rite.quicksort(&prc)
  end

  def quicksort!(first, last)
    return if (last <= first)
    wall = self.partition!(first, last)
    self.quicksort!(first, wall - 1)
    self.quicksort!(wall + 1, last)
  end

  def partition!(first, last)
    wall = first
    pivot = self[first]

    for k in (first + 1)..last
      if self[k] <= pivot
        wall += 1
        self[k], self[wall] = self[wall], self[k]
      end
    end

    self[first], self[wall] = self[wall], self[first]
    wall
  end
end