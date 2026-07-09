# nlog(n)
def merge_sort(nums: list[int]) -> list[int]:
    if len(nums) <= 1: return nums
    mid = len(nums) // 2
    
    left = merge_sort(nums[0:mid])
    rite = merge_sort(nums[mid:len(nums)])

    return merge(left, rite)

# helper function
def merge(left: list[int], rite: list[int]) -> list[int]:
    result = []
    l = 0
    r = 0

    while l < len(left) and r < len(rite):
        if left[l] <= rite[r]:
            result.append(left[l])
            l += 1
        else:
            result.append(rite[r])
            r += 1
    
    for k in range(l, len(left)):
        result.append(left[k])

    for k in range(r, len(rite)):
        result.append(rite[k])

    return result


print(merge_sort([]))
print(merge_sort([1]))
print(merge_sort([1, 2, 3, 4]))
print(merge_sort([4, 3, 2, 1]))
print(merge_sort([1, 2, 3, 4, 5]))
print(merge_sort([5, 4, 3, 2, 1]))
print(merge_sort([5, 4, 3, 2, 1, 9, 8, 7, 6, 0]))
