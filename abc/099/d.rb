n, c = gets.strip.split.map(&:to_i)
ds = c.times.map { gets.strip.split.map(&:to_i) }
cs = n.times.map { gets.strip.split.map(&:to_i) }

numbered_groups = Array.new(3) { [] }
#p numbered_groups

n.times do |i|
  n.times do |j|
    k = ( (i+1)+(j+1) )%3
    numbered_groups[k] << cs[i][j]
  end
end

color_count_with_group = numbered_groups.map {|group|
  group.group_by(&:itself).to_a.inject( [0]*(c+1) ) {|memo, e|
    memo[e.first] = e.last.count
    memo
  }
}

#p numbered_groups
#p color_count_with_group

result = Float::INFINITY

(1..c).each do |c1|
  (1..c).each do |c2|
    next if c1==c2
    (1..c).each do |c3|
      next if c1==c3 || c2==c3
      tmp=0
      tmp+=(1..c).map {|i| color_count_with_group[0][i] * ds[i-1][c1-1] }.inject(:+)
      tmp+=(1..c).map {|i| color_count_with_group[1][i] * ds[i-1][c2-1] }.inject(:+)
      tmp+=(1..c).map {|i| color_count_with_group[2][i] * ds[i-1][c3-1] }.inject(:+)

      result = tmp if tmp < result
    end
  end
end

p result
