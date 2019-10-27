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

n = gets.strip.to_i
stops = n.times.map { gets.strip.split.map(&:to_i) }
car = gets.strip.split.map(&:to_i)

stops.map! {|l,r| [l, -r] }

current = car.first - car.last

pq = PriorityQueue.new()
ans=0;
while (current>0)
  stops.select {|l, _| l >= current }.each do |_,r|
    pq.push(r)
  end
  stops.reject! {|l, _| l >= current }
  if pq.size.zero?
    p -1
    exit
  end


  cs = pq.pop
  p [current, cs]
  current += cs
  ans+=1

end
 p ans
