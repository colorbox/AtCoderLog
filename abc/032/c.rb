n, k = gets.strip.split(' ').map(&:to_i)
s = readlines.map {|line| line.strip.to_i }

if s.sort.first.zero?
  p n
  exit
end

if s.sort.first>k
  p 0
  exit
end

maxlength = 0
current_numbers = []
current = 1
s.each do |num|
  (current_numbers.length).times do |_|
    if current*num > k
      shifted_num = current_numbers.shift
      current /= shifted_num
    else
      break
    end
  end

  if current*num <= k
    current *= num
    current_numbers.push(num)
  end

  maxlength = [maxlength, current_numbers.length].max
end

p maxlength
