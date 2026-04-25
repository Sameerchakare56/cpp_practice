
# Code


# Testcase
# Testcase
# Test Result
# 557. Reverse Words in a String III
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

# Example 1:

# Input: s = "Let's take LeetCode contest"
# Output: "s'teL ekat edoCteeL tsetnoc"
# Example 2:

# Input: s = "Mr Ding"
# Output: "rM gniD"
 

# Constraints:

# 1 <= s.length <= 5 * 104
# s contains printable ASCII characters.
# s does not contain any leading or trailing spaces.
# There is at least one word in s.
# All the words in s are separated by a single space.

class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(word[::-1] for word in s.split())


# 🔹 Test Cases
def run_tests():
    sol = Solution()
    
    test_cases = [
        "hello world",
        "I love coding",
        "Python is fun",
        "  multiple   spaces here  ",
        "a",
        "",
        "OpenAI GPT"
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = sol.reverseWords(test)
        print(f"Test Case {i}:")
        print(f"Input : '{test}'")
        print(f"Output: '{result}'")
        print("-" * 40)


# Run tests
run_tests()



# class Solution:
#     def reverseWords(self, s: str) -> str:
#         string = ""
#         for word in s.split():
#             word = word[::-1]
#             string += word + " "
#         return string[:-1]