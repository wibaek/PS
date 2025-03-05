# 2025.03.05

from collections import deque


def solution(bridge_length, weight, truck_weights):
    truck_count = len(truck_weights)
    deq = deque([0 for _ in range(bridge_length)])

    arrived_truck_count = 0
    curr_weight = 0
    truck_cur = 0
    answer = 0
    while arrived_truck_count < truck_count:
        answer += 1
        popl = deq.popleft()
        curr_weight -= popl
        if popl != 0:
            arrived_truck_count += 1

        if truck_cur < truck_count:
            if truck_weights[truck_cur] + curr_weight <= weight:
                deq.append(truck_weights[truck_cur])
                curr_weight += truck_weights[truck_cur]
                truck_cur += 1

            else:
                deq.append(0)
        else:
            deq.append(0)

    return answer
