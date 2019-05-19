lines = readlines.map(&:strip)
N = lines[0].to_i
A = lines[1].split.map(&:to_i)
A.unshift(0)
A.push(0)

D = []
(0..A.length-2).each do|index|
  diff = A[index+1] - A[index]
  diff = diff*-1 if diff<0
  D.push(diff)
end

drawn_D = []
(0..A.length-3).each do|index|
  diff = A[index+2] - A[index]
  diff = diff*-1 if diff<0
  drawn_D.push(diff)
end

sum_D = D.inject(0){|memo, elem|memo+elem}

#puts D.inspect
#puts drawn_D.inspect
#puts sum_D
#puts('---')

(0..N-1).each do |index|
  puts sum_D -(D[index] + D[index+1]) + drawn_D[index]
end

