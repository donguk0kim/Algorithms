# log(n)
def binary_search(nums: list[int], target: int, start: int, end: int) -> int:
    if start > end: return None
    
    mid = start + (end - start) // 2

    if nums[mid] > target:
        return binary_search(nums, target, start, mid - 1)
    elif nums[mid] < target:
        return binary_search(nums, target, mid + 1, end)
    else:
        return mid


# test cases
print(binary_search([1, 5, 7, 9, 15], 5, 0, 4))
print(binary_search([1, 5, 7, 9, 15], 9, 0, 4))
print(binary_search([1, 5, 7, 9, 15], 1, 0, 4))
print(binary_search([1, 5, 7, 9, 15], 15, 0, 4))
print(binary_search([1, 5, 7, 9, 15], 10, 0, 4))
print(binary_search([1, 5, 7, 9, 15], -10, 0, 4))
