# nlog(n) but worst case n^2
def insertion_sort(nums: list[int]) -> list[int]:
    for k in range(1, len(nums)):
        for j in range(k, 0, - 1):
            if nums[j] < nums[j - 1]:
                nums[j], nums[j - 1] = nums[j - 1], nums[j]
            else:
                break
    return nums
