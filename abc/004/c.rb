n=gets.strip.to_i

array = [1,2,3,4,5,6]

normalized_n = n%30
turn_counts = normalized_n/5

array.rotate!(turn_counts)

(normalized_n%5).times do |index|
  array[index], array[index+1] = array[index+1], array[index]
end

puts array.join
