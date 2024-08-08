def is_palindrome(s):
    return s == s[::-1]

a = "Hello"
print(f"{a} is palindrome? {is_palindrome(a)}")

a = "level"
print(f"{a} is palindrome? {is_palindrome(a)}")