t = int(input())
for _ in range(t):
    p = input()
    _ = input()
    qr = input()
    qr = qr[1:-1]
    arr = list(map(int, qr.split(","))) if qr != "" else []

    is_reverse = False
    tail_pop_stack = 0
    head_pop_stack = 0
    is_error = False
    for q in list(p):
        if q == "R":
            is_reverse = not is_reverse
        elif q == "D":
            if is_reverse:
                tail_pop_stack += 1
            else:
                head_pop_stack += 1
    if is_error or len(arr) - tail_pop_stack - head_pop_stack < 0:
        print("error")
    else:
        arr = arr[head_pop_stack : len(arr) - tail_pop_stack]
        if is_reverse:
            arr.reverse()
        print("[" + ",".join(list(map(str, arr))) + "]")
