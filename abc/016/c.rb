n, m = gets.strip.split.map(&:to_i)
ab = readlines.map {|line| line.strip.split.map {|n| n.to_i-1 } }

relations = []
n.times do
  relations.push([100]*n)
end


ab.each do |l, r|
  relations[l][r] = relations[r][l] = 1
end

n.times do|via|
  n.times do|from|
    next if via==from
    (from+1...n).each do|to|
      relations[from][to] = relations[to][from] = [relations[from][to], relations[from][via] + relations[via][to]].min
    end
  end
end


relations.each {|r| p r.select{|n|n==2}.length }
