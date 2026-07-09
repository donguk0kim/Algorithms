# nlog(n)
def merge_sort(nums: list[int], start: int, end: int) -> list[int]:
    length = end - start + 1
    if length <= 1: return nums

    mid = length // 2

    merge_sort(nums, start, mid)
    merge_sort(nums, mid + 1, end)

    merge(nums, start, mid, end)

    return nums

# helper function
def merge(nums: list[int], start: int, mid: int, end: int):

    start2 = mid + 1

    if nums[mid] <= nums[start2]: return

    while start <= mid and start2 <= end:
        
        if nums[start] > nums[start2]:
            temp = nums[start2]
            index = start2

            while index != start:
                nums[index] = nums[index - 1]
                index -= 1

            nums[start] = temp

            start += 1
            mid += 1
            start2 += 1
        else:
            start += 1



print(merge_sort([], 0 , 0))
print(merge_sort([1], 0, 0))
print(merge_sort([1, 2, 3, 4], 0, 3))
print(merge_sort([4, 3, 2, 1], 0, 3))
print(merge_sort([1, 2, 3, 4, 5], 0, 4))
print(merge_sort([5, 4, 3, 2, 1], 0, 4))
print(merge_sort([5, 4, 3, 2, 1, 9, 8, 7, 6, 0], 0, 9))
