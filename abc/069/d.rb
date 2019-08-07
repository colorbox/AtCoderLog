h, w = gets.strip.split.map(&:to_i)
n = gets.strip.to_i
a = gets.strip.split.map(&:to_i)

colors = a.map.with_index(1) {|count, color| [color]*count }.flatten

colors = colors.each_slice(w).to_a
colors.map.with_index {|column, index| index.odd? ? column.reverse : column }.each do |column|
  puts column.join(' ')
end
