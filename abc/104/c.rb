lines = readlines.map(&:strip)

n, d = lines.shift.split.map(&:to_i)

problems = lines.map{|line|line.split.map(&:to_i)}

#p [n, d, problems].inspect

# I need calculate rest count with biggest problems after current point
def count_problems_in_rest(complete_solving_arr, problems, goal)
  diff = goal - points_with_solved(complete_solving_arr, problems)
  return 0 if diff<0

  last_index = complete_solving_arr.zip((1..complete_solving_arr.count).to_a).keep_if{|e|e[0]==0}.last&.last.to_i
  max_points_in_rest = last_index*100
  return 0 if last_index == 0

  require_count = (diff.to_f/max_points_in_rest.to_f).ceil
  return Float::INFINITY if require_count > problems[last_index-1][0]
  require_count
end

# calculate point with current solving array
def points_with_solved(complete_solving_arr, problems)
  complete_solving_arr.zip(problems).map.with_index {|solve_problem, index|
    solve= solve_problem[0]
    problem = solve_problem[1]
    if(solve==1)
      100*(index+1)*problem[0]+problem[1]
    else
      0
    end
  }.inject(:+)
end

def count_with_solved(solvings, problems)
  solvings.zip(problems).keep_if{|e|e[0]==1}.map{|e|e[1][0]}.inject(:+).to_i
end

def recursive_count(solvings, problems, goal)
  # end condition
  if solvings.length==problems.length
    current_points = points_with_solved(solvings, problems)
    count = count_with_solved(solvings, problems)
    additional_count = count_problems_in_rest(solvings, problems, goal)

#p [count+additional_count, solvings]

    return count+additional_count
  end

  # recursive condition
  return [
    recursive_count(solvings.dup.push(0), problems, goal),
    recursive_count(solvings.dup.push(1), problems, goal)
  ].min
end


#puts points_with_solved([0,1], problems)
#puts count_problems_in_rest([0,1], problems, 7000).inspect

p recursive_count([], problems, d)
