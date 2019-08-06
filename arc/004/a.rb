n = gets.strip.to_i
xy = readlines.map {|line| line.strip.split.map(&:to_i) }

def line_length(s, g)
  Math.sqrt( ((s.first - g.first)**2).abs + ((s.last - g.last)**2).abs )
end

result = 0.0
xy.each do |s|
  xy.each do |g|
    result = [line_length(s, g), result].max
  end
end

puts result
