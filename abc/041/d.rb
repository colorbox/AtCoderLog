n, m = gets.split.map(&:to_i)

graph = [0]*(n)
m.times {
  x, y = gets.split.map(&:to_i)
  graph[x-1] |= 1 << (y-1)
}

#p graph

dp = [0]*(2**n)
dp[0]=1

(2**n).times do |bit|
  (0...n).each do |node|
    c = 1 << node
#p [bit, c, node, graph[node]]
    if((bit&c).zero? && (bit & graph[node]).zero?)
#p [dp[bit|c], bit|c]
      dp[bit|c] += dp[bit]
    end
  end
end

#p dp
p dp[2**n-1]



