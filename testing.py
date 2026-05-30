import random
import time

def greedy(events):
    events.sort(key=lambda x: x[1])
    count = 0
    last_end = -1

    for s, e in events:
        if s >= last_end:
            count += 1
            last_end = e

    return count

# Generate random events
def generate_events(n):
    events = []
    for _ in range(n):
        s = random.randint(0, 100000)
        e = s + random.randint(1, 100)
        events.append((s, e))
    return events

# Testing
sizes = [1000, 5000, 10000, 50000]

for n in sizes:
    events = generate_events(n)

    start_time = time.time()
    result = greedy(events)
    end_time = time.time()

    print(f"n = {n}, selected = {result}, time = {end_time - start_time:.6f} sec")