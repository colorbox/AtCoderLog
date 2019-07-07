s = gets.strip

piano = 'WBWBWWBWBWBW'*3

#p piano
#p s

index = piano.index(s)

#index -= 12 if index >= 12

result = if index < 2
           'Do'
         elsif index < 4
           'Re'
         elsif index < 5
           'Mi'
         elsif index < 7
           'Fa'
         elsif index < 9
           'So'
         elsif index < 11
           'La'
         else
           'Si'
         end

puts result
