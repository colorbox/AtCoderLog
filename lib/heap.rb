require 'byebug'

class Heap
  attr_accessor :data, :size

  def initialize
    @data=[]
  end

  def comp(l, r)
    l > r
  end

  def push(e)
    @data.push(e)

    cur = @data.size-1
    return if cur.zero?
    parent_i = parent(cur)

    while cur > 0 && comp(@data[parent_i], e)
      parent = @data[parent_i]
      @data[parent_i] = e
      @data[cur] = parent
      cur = parent_i
      parent_i = parent(cur)
    end
  end

  def pop
    ret = @data.first
    last = data.last

    cur = 0
    while left_i(cur)<data.size
      li = left_i(cur)
      ri = right_i(cur)
      l=data[li]
      r=data[ri]
      ni=li
      ni=ri if r && comp(l, r)

      break if @data[ni] >= last

      @data[cur] = @data[ni]
      cur = ni
    end

    data[cur]=last
    data.pop

    ret
  end

  def left_i(i)
    2*i+1
  end

  def right_i(i)
    2*i+2
  end

  def parent(i)
    return 0 if i.zero?
    (i-1)/2
  end
end

h = Heap.new
arr = %w(10 1 5 3 8 12 13 43 54 65).map(&:to_i)
expected = arr.sort
p "push #{arr}"
arr.each {|e| h.push(e) }
p h.data
p"---"
p h.data
target = []
h.data.size.times do
  target.push(h.pop)
  p h.data
end
p "---"
p expected
p target
p expected == target
p h.data
