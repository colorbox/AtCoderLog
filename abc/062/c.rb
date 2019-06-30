H,W = gets.split.map(&:to_i)

if H%3==0 || H%3==0
  p 0
  exit
end

# first
short_height = (H.to_f/3.to_f).round
rest_height = (H-short_height)

# cut different directions
short_width = (W.to_f/2.to_f).round
rest_width = (W-short_width)
a = W * short_height
b = rest_height*short_width
c = rest_height*rest_width

# cut same directions
second_short_height = ((H-short_height).to_f/2.to_f).round
b2 = second_short_height*W
c2 = (rest_height-second_short_height)*W

pattern1 = [a,b,c].max - [a,b,c].min
pattern2 = [a,b2,c2].max - [a,b2,c2].min

result1 = [pattern1, pattern2].min

#second
short_width = (W.to_f/3.to_f).round
rest_width = (W-short_width)

# cut different directions
short_height = (H.to_f/2.to_f).round
rest_height = (H-short_height)
a = H * short_width
b = rest_width*short_height
c = rest_width*rest_height

# cut same directions
second_short_width = ((W-short_width).to_f/2.to_f).round
b2 = second_short_width*H
c2 = (rest_width-second_short_width)*H

pattern1 = [a,b,c].max - [a,b,c].min
pattern2 = [a,b2,c2].max - [a,b2,c2].min

result2 = [pattern1, pattern2].min

result = [result1, result2].min
p result
