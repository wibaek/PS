""" 복잡도
    재료: 200,000
    유통기한: 1b
"""


def calc_important(important_materials, day):
    sum = 0
    for material in important_materials:
        sum += max(1, (day - material["expire_date"])) * material["rotten_speed"]
    return sum


def calc_unimportant(unimportant_materials, day, remove_limit):
    for material in unimportant_materials:
        material["rotten_level"] = material["rotten_speed"] * max(
            1, (day - material["expire_date"])
        )
    unimportant_materials.sort(key=lambda x: (x["rotten_level"]))
    sum = 0
    for i in range(len(unimportant_materials) - remove_limit):
        sum += unimportant_materials[i]["rotten_level"]
    return sum


material_count, germ_limit, remove_limit = map(int, input().split())
important_materials = []
unimportant_materials = []
for i in range(material_count):
    rotten_speed, expire_date, is_not_important = map(int, input().split())
    if is_not_important:
        unimportant_materials.append(
            {
                "rotten_speed": rotten_speed,
                "expire_date": expire_date,
            }
        )
    else:
        important_materials.append(
            {
                "rotten_speed": rotten_speed,
                "expire_date": expire_date,
            }
        )

# 1 ~ 2000000000 사이 이분탐색
left = 0
right = 2000000000

while left < right:
    mid = (left + right + 1) // 2
    sum = calc_important(important_materials, mid) + calc_unimportant(
        unimportant_materials, mid, remove_limit
    )
    if sum > germ_limit:
        right = mid - 1
    else:
        left = mid
print(left)
