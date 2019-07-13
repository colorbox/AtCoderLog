R, C, K = gets.strip.split.map(&:to_i)
N=gets.to_i
RC=readlines.map {|line| line.strip.split.map(&:to_i) }

row_count=[0]*R
column_count=[0]*C

N.times do |index|
  current_r, current_c = RC[index]
  row_count[current_r-1]+=1
  column_count[current_c-1]+=1
end

rs = [0]*(C+1)
row_count.each do |count|
  rs[count]+=1
end

cs = [0]*(R+1)
column_count.each do |count|
  cs[count]+=1
end

#p rs
#p cs
#p row_count
#p column_count

result=0

(K+1).times do |kindex|
  result+=rs[kindex].to_i * cs[K-kindex].to_i
end

RC.each do |r, c|
  result -= 1 if row_count[r-1]+column_count[c-1]==K
  result += 1 if row_count[r-1]+column_count[c-1]==K+1
end

p result
