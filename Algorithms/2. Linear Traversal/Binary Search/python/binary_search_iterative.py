# log(n)
def binary_search(nums: list[int], target: int) -> int:
    start = 0
    end = len(nums) - 1

    while start <= end:
        mid = start + (end - start) // 2

        if nums[mid] > target:
            end = mid - 1
        elif nums[mid] < target:
            start = mid + 1
        else:
            return mid
    
    return None


# test cases
print(binary_search([1, 5, 7, 9, 15], 5))
print(binary_search([1, 5, 7, 9, 15], 9))
print(binary_search([1, 5, 7, 9, 15], 10))
print(binary_search([1, 5, 7, 9, 15], -10))
