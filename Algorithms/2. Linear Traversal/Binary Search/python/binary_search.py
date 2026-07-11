# log(n)
def binary_search(nums: list[int], target: int) -> int:
    if not nums: return None

    mid = len(nums) // 2

    if nums[mid] > target:
        return binary_search(nums[0:mid], target)
    elif nums[mid] < target:
        index = binary_search(nums[mid + 1:], target)
        if index is not None: return mid + index + 1
    else:
        return mid


# test cases
print(binary_search([1, 5, 7, 9, 15], 5))
print(binary_search([1, 5, 7, 9, 15], 9))
print(binary_search([1, 5, 7, 9, 15], 1))
print(binary_search([1, 5, 7, 9, 15], 15))
print(binary_search([1, 5, 7, 9, 15], 10))
print(binary_search([1, 5, 7, 9, 15], -10))
