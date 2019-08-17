n, m = gets.strip.split.map(&:to_i)

(m/n).downto(1) do |current|
  if (m%current).zero?
    p current
    exit
  end
end
