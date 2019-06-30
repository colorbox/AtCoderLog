N,M = gets.strip.split.map(&:to_i)
div=1_000_000_007
div=(10e8+7).to_i

diff = (N-M).abs
if diff>1
  p 0
  exit
end

fanctors = [1]
(1..[N,M].max).to_a.map do|num|
  fanctors[num] = ((fanctors[num-1]*(num+1))%div)
end

result = (fanctors[N-1]*fanctors[M-1])%div
result *= 2 if (N==M)

#p fanctors
p (result%div)
