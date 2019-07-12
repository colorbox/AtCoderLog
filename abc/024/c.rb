def overwrap?(minmax, minmax2)
  minmax.last >= minmax2.first && minmax.first <= minmax2.last
end

n, d, k = gets.strip.split.map(&:to_i)
lr = []
d.times do
  lr.push(gets.strip.split.map(&:to_i))
end

st = []
k.times do
  st.push(gets.strip.split.map(&:to_i))
end

results = [0]*k

moving = []
k.times do |j|
  s=st[j].first
  moving.push([s,s])
end


d.times do |day|
  l=lr[day].first
  r=lr[day].last
  targets = [l,r]
  k.times do |j|
    current=moving[j]
    sum = (targets+current).minmax
    goal=st[j].last
    if overwrap?(targets, current) && overwrap?(sum, [goal, goal])
      results[j]=day+1 if results[j].zero?
    elsif overwrap?(targets, current)
      moving[j] = sum
    end
  end
end

results.each do |result|
  p result
end

