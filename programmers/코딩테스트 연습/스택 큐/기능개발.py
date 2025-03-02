# 2025.03.03


class Task:
    def __init__(self, value, speed):
        self.value = value
        self.speed = speed

    def do(self):
        self.value += self.speed

    def is_completed(self):
        return self.value >= 100


def do_work(tasks):
    for task in tasks:
        task.do()


def solution(progs, speeds):
    answer = []

    task_list = []
    for i in range(len(speeds) - 1, -1, -1):
        task_list.append(Task(progs[i], speeds[i]))

    while True:
        if len(task_list) == 0:
            break

        do_work(task_list)

        count = 0
        while True:
            if len(task_list) > 0 and task_list[-1].is_completed():
                count += 1
                task_list.pop()
            else:
                break

        if count != 0:
            answer.append(count)

    return answer
