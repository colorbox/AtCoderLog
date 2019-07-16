n = gets.strip.to_i
a = gets.strip.split.map(&:to_i)

p a.uniq.map {|num|
  alter = num
  while alter.even?
    alter = (alter/2).to_i
  end
  alter
}.uniq.length
