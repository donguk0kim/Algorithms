  def bsearch (target_value, &prc)
      prc ||= Proc.new { |a, b| a <=> b }

      mid_index = self.length / 2
      mid_value = self[mid_index]
      return mid_index if mid_value == target_value

      return nil if self.length <= 1
      left = self.take(mid_index)
      rite = self.drop(mid_index)

      case prc.call(target_value, mid_value)
      when  1
        index = rite.bsearch(target_value, &prc)
        return mid_index + index if index
      when -1
        return left.bsearch(target_value, &prc)
      end
  end