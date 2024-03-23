# 2024 - 03 - 24
# 2개 용액문제에 linear하게 한번더 추가한 정도의 문제
n = int(input())
arr = list(map(int, input().split()))

smallest = 3_000_000_000
answer = [0, 1, 2]

arr.sort()
for i in range(n - 2):
    left = i + 1
    right = n - 1
    while left < right:
        total = arr[i] + arr[left] + arr[right]
        if abs(total) < smallest:
            smallest = abs(total)
            answer = [i, left, right]
        if total < 0:
            left += 1
        elif total > 0:
            right -= 1
        else:
            break

print(arr[answer[0]], arr[answer[1]], arr[answer[2]])
