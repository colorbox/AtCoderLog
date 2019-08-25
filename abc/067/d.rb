n = gets.strip.to_i
ab = readlines.map {|line| line.strip.split.map(&:to_i) }

graph = Array.new(n+1) { [] }
ab.each do |a, b|
  graph[a] << b
  graph[b] << a
end

checked = [false]*(n+1)
checked[1] = checked[n] = true
fq = [1]
sq = [n]
fp=sp=0

until fq.empty? && sq.empty?

  cq = fq.dup
  fq=[]
  until cq.empty?
    cf = cq.shift
    graph[cf].each do |to|
      next if checked[to]
      fq.push(to)
      fp+=1
      checked[to]=true
    end
  end

  cq = sq.dup
  sq=[]
  until cq.empty?
    cs = cq.shift
    graph[cs].each do |to|
      next if checked[to]
      sq.push(to)
      sp+=1
      checked[to]=true
    end
  end

end

#p [sp, fp]

if sp >= fp
  puts 'Snuke'
else
  puts 'Fennec'
end
