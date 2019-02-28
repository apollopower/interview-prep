# Given a list of meeting times, return a list of merged meeting times

def merge_meetings(meetings):
    sorted_meetings = sorted(meetings)
    merged_meetings = [sorted_meetings[0]]

    for current_start, current_end in sorted_meetings[1:]:
        last_merged_start, last_merged_end = merged_meetings[-1]
        
        if current_start <= last_merged_end:
            merged_meetings[-1] = (
                last_merged_start,
                max(current_end, last_merged_end)
            )
        else:
            merged_meetings.append((current_start, current_end))
    
    return merged_meetings



test_times = [(0, 1), (3, 5), (4, 8), (10, 12), (9, 10)]

assert(merge_meetings(test_times) == [(0, 1), (3, 8), (9, 12)])

# Completixy:
# O(lgN) time
# O(N) space