lines = readlines.map(&:strip)

n, m = lines.shift.split.map(&:to_i)
p = lines.pop.split.map(&:to_i)
k = lines.map{|line| line.split.map(&:to_i)}

#puts [n, m].inspect
result=0
(2**n).times do |number|
  current_switches = ("%0#{n}b" % number).split('').map(&:to_i)

#  puts '='
#  puts current_switches.inspect
#  puts '-'

  all_on=true
  m.times do |index|
    k_condition_switches = k[index][1..-1]

#  puts k_condition_switches.inspect
#  puts k_condition_switches.map{|k_switch|current_switches[k_switch-1]}.inspect
#  puts '---'

    on_count = k_condition_switches.map{|k_switch|current_switches[k_switch-1]}.inject(:+)
    unless p[index] == on_count % 2
      all_on=false
      break
    end
  end
  result += 1 if all_on
end

puts result
