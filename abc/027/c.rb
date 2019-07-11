n = gets.strip.to_i

rank = Math.log2(n).to_i

x=1

coin = if rank.odd?
         0
       else
         1
       end

(rank+1).times do |index|
  if (index+1).odd?
    x = x*2 + coin
    if n<x
      puts 'Aoki'
      exit
    end
  else
    x = x*2 + (coin+1)%2
    if n<x
      puts 'Takahashi'
      exit
    end
  end
end
