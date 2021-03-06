class PriorityQueue
  attr_accessor :data

  def initialize(arr=[])
    @data = arr
  end

  def push(e)
    @data.push(e)

    current_index = @data.size-1
    parent_index = parent(current_index)

    while current_index > 0 && @data[parent_index] > @data[current_index]
      @data[current_index] = @data[parent_index]
      @data[parent_index] = e
      current_index = parent_index
      parent_index = parent(current_index)
    end
  end

  def pop
    ret = @data.first
    last = @data.last
    current_index = 0

    while have_child?(current_index)
      li = left_child_index(current_index)
      ri = right_child_index(current_index)

      ni = li
      ni = ri if ri < @data.size && @data[ri] < @data[li]

      break if @data[ni] >= last

      @data[current_index] = @data[ni]
      current_index = ni
    end
    @data[current_index] = last
    @data.pop

    ret
  end

  def size
    @data.length
  end

  def parent(index)
    (index-1)/2
  end

  def left_child_index(index)
    2*index+1
  end

  def right_child_index(index)
    2*index+2
  end

  def have_child?(index)
    left_child_index(index) < @data.size
  end
end

class BigPQ < PriorityQueue
  def push(e)
    @data.push(e)

    current_index = @data.size-1
    parent_index = parent(current_index)

    while current_index > 0 && @data[parent_index] < @data[current_index]
      @data[current_index] = @data[parent_index]
      @data[parent_index] = e
      current_index = parent_index
      parent_index = parent(current_index)
    end
  end

  def pop
    ret = @data.first
    last = @data.last
    current_index = 0

    while have_child?(current_index)
      li = left_child_index(current_index)
      ri = right_child_index(current_index)

      ni = li
      ni = ri if ri < @data.size && @data[ri] > @data[li]

      break if @data[ni] <= last

      @data[current_index] = @data[ni]
      current_index = ni
    end
    @data[current_index] = last
    @data.pop

    ret
  end
end


n=gets.strip.to_i
aa = gets.strip.split.map(&:to_i)

bpq = BigPQ.new
pq = PriorityQueue.new

n.times do |i|
  pq.push(aa[i])
  bpq.push(aa[3*n-1-i])
end

left_score = pq.data.inject(:+)
left_scores = [left_score]

right_score = bpq.data.inject(:+)
right_scores = [right_score]

n.times do |i|
  c = aa[n+i]
  if c >= pq.data.first
    pq.push(c)
    left_score -= pq.pop
    left_score += c
  end
  left_scores.push(left_score)

  c = aa[2*n-1-i]
  if c <= bpq.data.first
    bpq.push(c)
    right_score -= bpq.pop
    right_score += c
  end
  right_scores.unshift(right_score)
end

result = left_scores.zip(right_scores).map {|l, r| l-r }.max

#p left_scores
#p right_scores
p result
