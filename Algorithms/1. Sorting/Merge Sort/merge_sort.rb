def merge_sort! (&prc)
  prc ||= Proc.new { |a, b| a <=> b }
  return self if self.length <= 1
  mid_index = self.length / 2
  left = self.take(mid_index).merge_sort!(&prc)
  rite = self.drop(mid_index).merge_sort!(&prc)
  return merge(left, rite, &prc)
end

def merge (left, rite, &prc)
    merged_array = []
    until left.empty? || rite.empty?
      case prc.call(left.first, rite.first)
      when  0; merged_array << left.shift
      when  1; merged_array << rite.shift
      when -1; merged_array << left.shift
      end
    end
    merged_array + left + rite
end