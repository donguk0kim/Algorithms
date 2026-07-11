# nlog(n) but worst case n^2
def quicksort(nums: list[int]) -> list[int]:
    if len(nums) <= 1: return nums

    pivot = nums[0]

    left, pivs, rite = [], [], []

    for num in nums:
        if num < pivot: left.append(num)
        elif num > pivot: rite.append(num)
        else: pivs.append(num)

    left = quicksort(left)
    rite = quicksort(rite)

    return left + pivs + rite


# test cases
print(quicksort([]))
print(quicksort([1]))
print(quicksort([1, 2, 3, 4]))
print(quicksort([4, 3, 2, 1]))
print(quicksort([1, 2, 3, 4, 5]))
print(quicksort([5, 4, 3, 2, 1]))
print(quicksort([5, 4, 3, 2, 1, 9, 8, 7, 6, 0]))
