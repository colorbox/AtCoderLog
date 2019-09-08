n, k = gets.strip.split.map(&:to_i)
s = gets.strip.split('')

rl = s.inject([]) {|memo, c|
  if memo.last.nil?
    memo << [c]
  elsif memo.last.last == c
    memo.last << c
  else
    memo << [c]
  end
  memo
}

counted_rl = rl.map(&:length)

if counted_rl.length-1 < k*2
  p counted_rl.inject(:+)-1
  exit
end

#p rl
#p counted_rl

result = counted_rl.inject(:+) - counted_rl.length+k*2
p result
