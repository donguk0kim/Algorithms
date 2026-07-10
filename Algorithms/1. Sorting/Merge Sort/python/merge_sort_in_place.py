# nlog(n)
def merge_sort(nums: list[int], start: int, end: int) -> list[int]:
    length = end - start + 1
    if length <= 1: return nums

    mid = start + (length - 1) // 2

    merge_sort(nums, start, mid)
    merge_sort(nums, mid + 1, end)

    merge(nums, start, mid, end)

    return nums


# helper function
def merge(nums: list[int], leftStart: int, leftEnd: int, riteEnd: int):

    riteStart = leftEnd + 1
    index = riteStart

    while riteStart <= riteEnd:

        while index > leftStart and nums[index] < nums[index - 1]:
            nums[index], nums[index - 1] = nums[index - 1], nums[index]
            index -= 1

        riteStart += 1
        index = riteStart


# test cases
print(merge_sort([], 0 , 0))
print(merge_sort([1], 0, 0))
print(merge_sort([1, 2, 3, 4], 0, 3))
print(merge_sort([4, 3, 2, 1], 0, 3))
print(merge_sort([1, 2, 3, 4, 5], 0, 4))
print(merge_sort([5, 4, 3, 2, 1], 0, 4))
print(merge_sort([5, 4, 3, 2, 1, 9, 8, 7, 6, 0], 0, 9))
