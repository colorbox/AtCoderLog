N, T = gets.strip.split.map(&:to_i)
t = gets.strip.split.map(&:to_i)

result = 0;

(1..N-1).to_a.each do |index|
  current_diff = t[index]-t[index-1]
  if current_diff > T
    result += T
  else
    result += current_diff
  end
end

result += T

p result
