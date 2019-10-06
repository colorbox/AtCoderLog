n = gets.strip.to_i
ss = readlines.map {|line| line.strip.split('').map(&:to_i) }

graph = Array.new(n) { [] }

n.times do |i|
  n.times do |j|
    graph[i] << j if ss[i][j]==1
  end
end

color = []
color[0]=true
s = [0]

until s.empty?
  c = s.pop
  pc = color[c]
  graph[c].each do |t|
    if !color[t].nil? && color[t]==pc
      p -1; exit
    end
    next unless color[t].nil?

    color[t] = !pc
    s.push(t)
  end
end

INF=10**5
n.times do |i|
  n.times do |j|
    ss[i][j] = INF if ss[i][j]==0
    ss[i][j]=0 if i==j
  end
end

n.times do |via|
  n.times do |from|
    n.times do |to|
      ss[from][to] = ss[from][via] + ss[via][to] if ss[from][to] > ss[from][via] + ss[via][to]
    end
  end
end
#ss.each {|l|p l}

p ss.map{|l|l.max}.max+1
