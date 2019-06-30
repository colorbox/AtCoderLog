N = gets.strip.to_i
a = gets.strip.split.map(&:to_i)

number_parted_a = a.map {|x| (x/400).to_i }.sort
legends, without_legends = number_parted_a.partition {|x| x>7 }

colored_count = without_legends.group_by {|x| x }.length
legend_count = legends.length

min = [colored_count, 1].max
max = colored_count + legend_count

puts [min, max].join(' ')
