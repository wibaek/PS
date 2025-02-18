# 2025.02.18


def add_server(players, i, k, n):
    for j in range(i, min(24, i + k)):
        players[j] -= n


def solution(players, m, k):
    answer = 0

    for i in range(24):
        if players[i] >= m:
            server_count = players[i] // m
            answer += server_count
            add_server(players, i, k, server_count * m)

    return answer
