n = gets.strip.to_i
xrs = readlines.map {|l| l.strip.split.map(&:to_i) }.map {|x, r| [x-r, x+r] }.sort.reverse

result = [xrs.shift]

xrs.each do |cl, cr|
  i=result.bsearch_index {|_, r| r>=cr }

  if i.nil?
    result.push([cl,cr])
  else
    result[i]=[cl, cr]
  end
end

p result.length
