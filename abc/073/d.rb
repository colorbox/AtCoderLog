n, m, r = gets.strip.split.map(&:to_i)
r = gets.strip.split.map(&:to_i)

roads = Array.new(n+1) { [10**8]*(n+1) }

readlines.each do |line|
  a, b, c = line.strip.split.map(&:to_i)
  roads[b][a] = roads[a][b] = c
end


(n+1).times do |via|
  (n+1).times do |s|
    s_via = roads[s][via]
    (n+1).times do |g|
      via_center = s_via + roads[via][g]
#      roads[g][s] = roads[s][g] = [roads[s][g], via_center].min
      roads[g][s] = roads[s][g] = via_center if roads[s][g] > via_center
    end
  end
end

result = 10**9
r.permutation.each do |arr|
  tmp = 0
  arr.each_cons(2) do |from, to|
    tmp += roads[from][to]
  end
  result = tmp if result > tmp
end

p result
