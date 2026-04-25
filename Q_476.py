# // 476. Number Complement
# // Solved
# // Easy
# // Topics
# // premium lock icon
# // Companies
# // The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

# // For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
# // Given an integer num, return its complement.

 

# // Example 1:

# // Input: num = 5
# // Output: 2
# // Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
# // Example 2:

# // Input: num = 1
# // Output: 0
# // Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

# // Constraints:

# // 1 <= num < 231

class Solution:
    def findComplement(self, num: int) -> int:
        if num == 0:
            return 1
        
        power = 0
        result = 0
        
        while num > 0:
            remainder = num % 2
            
            if remainder == 0:
                result += 2 ** power
            
            power += 1
            num = num // 2
        
        return result


# 🔹 Test Cases
sol = Solution()

print(sol.findComplement(5))   # 2
print(sol.findComplement(1))   # 0
print(sol.findComplement(10))  # 5
print(sol.findComplement(0))   # 1