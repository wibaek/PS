# 2025.03.05


def solution(phone_book):

    dic = {}
    for phone in phone_book:
        dic[phone] = True

    for phone in phone_book:
        number = ""
        for p in phone[:-1]:
            number += p

            if number in dic:
                return False

    return True
