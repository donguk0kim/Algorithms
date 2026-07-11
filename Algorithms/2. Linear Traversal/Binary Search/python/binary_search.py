# log(n)
def binary_search(nums: list[int], target: int) -> int:
    if not nums: return None

    mid_index = len(nums) // 2
    mid_value = nums[mid_index]

    if mid_value < target:
        index = binary_search(nums[mid_index:-1], target)
        if index is not None: return mid_index + index
    elif mid_value > target:
        return binary_search(nums[0:mid_index], target)
    else:
        return mid_index


# test cases
print(binary_search([1, 5, 7, 9, 15], 5))
print(binary_search([1, 5, 7, 9, 15], 9))
print(binary_search([1, 5, 7, 9, 15], 10))
print(binary_search([1, 5, 7, 9, 15], -10))
