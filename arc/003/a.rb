n=gets.strip.to_f
points = gets.strip.split('')

converter = {
  'A' => 4,
  'B' => 3,
  'C' => 2,
  'D' => 1,
  'F' => 0
}

p points.map {|p| converter[p] }.inject(:+).to_f/n
