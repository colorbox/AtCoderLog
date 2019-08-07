n, m, r = gets.strip.split.map(&:to_i)
r = gets.strip.split.map(&:to_i)
abc = readlines.map {|line| line.strip.split.map(&:to_i) }

roads = Array.new(n+1) { [10**8]*(n+1) }

abc.each do |a, b, c|
  roads[a][b]=roads[b][a]=c
end

(n+1).times do |via|
  (n+1).times do |s|
    s_via = roads[s][via]
    (n+1).times do |g|
      via_center = s_via + roads[via][g]
      roads[g][s] = roads[s][g] = via_center if roads[s][g] > via_center
    end
  end
end

def recursive_roads_check(current, cost, remains, roads)
  return cost if remains.empty?

  remains.map {|next_town|
    next_remains = remains.dup - [next_town]
    next_cost = 0
    next_cost = cost + roads[current][next_town] if current
    recursive_roads_check(next_town, next_cost, next_remains, roads)
  }.min
end

#roads.each {|r|p r}

p recursive_roads_check(nil, 0, r, roads)
