def lbs_toKg(weight):
    return weight * 0.45
def kg_toLbs(weight):
    return weight/0.45
def find_max(numbers):
    max=numbers[0]
    for i in numbers:
        if i>max:
            max=i
    return max
    