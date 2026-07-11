# log(n)
def binary_search(nums: list[int], target: int, start: int, end: int) -> int:
    if start > end: return None
    
    size = end - start + 1
    mid_index = start + size // 2
    mid_value = nums[mid_index]

    if mid_value > target:
        return binary_search(nums, target, start, mid_index - 1)
    elif mid_value < target:
        index = binary_search(nums, target, mid_index + 1, end)
        if index: return mid_index + index - 1
    else:
        return mid_index



# test cases
print(binary_search([1, 5, 7, 9, 15], 5, 0, 4))
print(binary_search([1, 5, 7, 9, 15], 9, 0, 4))
print(binary_search([1, 5, 7, 9, 15], 10, 0, 4))
print(binary_search([1, 5, 7, 9, 15], -10, 0, 4))
