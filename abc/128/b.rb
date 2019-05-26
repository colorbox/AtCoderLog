lines = readlines.map(&:strip)

n = lines.shift.to_i

sp = lines.map{|line| [line.split[0].to_s, line.split[1].to_i] }

#puts n
#puts sp.inspect

sp.each_with_index do |_, index|
  sp[index].push(index+1)
end

#puts sp.group_by{|l|l[0]}.sort.inspect

sp.group_by{|l|l[0]}.sort.each do |city, values|
  values.sort{|l,r|l[1] - r[1]}.reverse.each do |line|
    puts line.last
  end
end
