n = gets.strip.to_i
a = gets.strip.split.map(&:to_i)


numbers_length_count=[]
current_numbers=[]

a.each_with_index do |num, index|
  if current_numbers.empty? || current_numbers.last < num
    current_numbers.push(num)
    numbers_length_count.push(current_numbers.length) if index==n-1
    next
  end

  if current_numbers.last >= num
    numbers_length_count.push(current_numbers.length)
    current_numbers=[num]
  end
end


increase = numbers_length_count.map {|count| (1..count-1).to_a }.flatten.inject(:+) if !numbers_length_count.empty?

result = increase.to_i + n

p result
