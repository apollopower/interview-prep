# Two Sum, classic problem

# SOLUTION

def can_two_movies_fill_flight(movie_lengths, flight_length):
  remaining_times = set()
  for length in movie_lengths:
    if length in remaining_times:
      return True
    else:
      remaining_times.add(flight_length - length)
  return False

# COMPLEXITY 
# Time => O(N)
# Space => O(N)