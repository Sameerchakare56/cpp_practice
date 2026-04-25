# A self-dividing number is a number that is divisible by every digit it contains.

# For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
# A self-dividing number is not allowed to contain the digit zero.

# Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).

 

# Example 1:

# Input: left = 1, right = 22
# Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
# Example 2:

# Input: left = 47, right = 85
# Output: [48,55,66,77]
 

# Constraints:

# 1 <= left <= right <= 104


class Solution:
    def selfDividingNumbers(self, left: int, right: int):
        result = []

        for num in range(left, right + 1):
            temp = num
            is_valid = True

            while temp > 0:
                digit = temp % 10

                # If digit is 0 or not divisible
                if digit == 0 or num % digit != 0:
                    is_valid = False
                    break

                temp //= 10

            if is_valid:
                result.append(num)

        return result


# ------------------ TEST CASES ------------------

if __name__ == "__main__":
    sol = Solution()

    # Test Case 1
    left1, right1 = 1, 22
    print("Input:", left1, right1)
    print("Output:", sol.selfDividingNumbers(left1, right1))
    print("Expected: [1,2,3,4,5,6,7,8,9,11,12,15,22]\n")

    # Test Case 2
    left2, right2 = 47, 85
    print("Input:", left2, right2)
    print("Output:", sol.selfDividingNumbers(left2, right2))
    print("Expected: [48,55,66,77]\n")

    # Test Case 3 (Edge Case)
    left3, right3 = 10, 15
    print("Input:", left3, right3)
    print("Output:", sol.selfDividingNumbers(left3, right3))
    print("Expected: [11,12,15]\n")
