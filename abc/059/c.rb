n = gets.strip.to_i
a = gets.strip.split.map(&:to_i)

cum_a = [a.first]
(1..n-1).to_a.each do |index|
  cum_a[index] = cum_a[index-1]+a[index]
end

minus_first_result = 0
minus_first_base = 0

(0..n-1).to_a.each do |index|
  current = cum_a[index]
  if index.even? && (revised = current+minus_first_base) >= 0
    minus_first_result += (revised+1)
    minus_first_base -= (revised+1)
  elsif index.odd? && (revised = current+minus_first_base) <= 0
    minus_first_result += (-1*revised+1)
    minus_first_base += (-1*revised+1)
  end
end


plus_first_result = 0
plus_first_base=0

(0..n-1).to_a.each do |index|
  current = cum_a[index]
  if index.even? && (revised = current+plus_first_base) <= 0
    plus_first_result += (-1*revised+1)
    plus_first_base += (-1*revised+1)
  elsif index.odd? && (revised = current+plus_first_base) >= 0
    plus_first_result += (revised+1)
    plus_first_base -= (revised+1)
  end
end

p [plus_first_result, minus_first_result].min
