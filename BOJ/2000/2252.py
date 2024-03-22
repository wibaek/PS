# 2024 - 03 - 22
import sys

input = sys.stdin.readline

# 입력
student_count, compare_count = map(int, input().split())
students = []
for student in range(student_count):
    students.append({"id": student, "required": [], "required_by": [], "done": False})

for i in range(compare_count):
    a, b = map(int, input().split())
    students[b - 1]["required"].append(a - 1)
    students[a - 1]["required_by"].append(b - 1)


# 풀이
stack = [i for i in range(student_count)]
while stack:
    student_id = stack.pop()
    if students[student_id]["done"]:
        continue
    if not students[student_id]["required"]:
        print(student_id + 1, end=" ")
        students[student_id]["done"] = True
        for s in students[student_id]["required_by"]:
            students[s]["required"].remove(student_id)
    else:
        stack.append(student_id)
        for s in students[student_id]["required"]:
            stack.append(s)
