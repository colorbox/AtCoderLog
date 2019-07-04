n=gets.strip.to_i
a = gets.strip.split.map(&:to_i)

sorted = a.sort
grouped = sorted.group_by {|x| x }
counted = grouped.map {|_,v| v.count }

if n.odd? && counted.shift!=1
  p 0
  exit
end

if n==1 && counted.empty?
  p 1
  exit
end

if counted.uniq!=[2]
  p 0
  exit
end

div=10**9+7

result = 1
(n/2).floor.times do |num|
  result = result*2%div
end

p result

#Other payttern
n=gets.strip.to_i
a = gets.strip.split.map(&:to_i)

sorted = a.sort
grouped = sorted.group_by {|x| x }
counted = grouped.map {|_,v| v.count }

if n==1 && counted==[1]
  p 1
  exit
end

if n.odd? && counted.shift!=1 || counted.uniq!=[2]
  p 0
  exit
end

div=10**9+7

result = 1
(n/2).floor.times do |num|
  result = result*2%div
end

p result
