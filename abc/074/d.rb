n = gets.strip.to_i
a = readlines.map {|line| line.strip.split.map(&:to_i) }

# 1. 本当に最短距離の行列かどうかを判定する
# 2. どこかを経由している道は消す

# 1
n.times do |via|
  n.times do |from|
    a_from_via = a[from][via]
    next if a_from_via.zero?
    (from+1...n).each do |to|
      next if (a_from_to = a[from][to]).zero? || (a_via_to = a[via][to]).zero?
      if a_from_to == a_from_via + a_via_to
        a[from][to]=a[to][from]=0
      end
      if a_from_to > a_from_via + a_via_to
        p -1
        exit
      end
    end
  end
end

p a.flatten.inject(:+)/2
