import re

# Function to check if an expression is valid
def is_valid_arithmetic_expression(expression):
    # Regular expression to match valid arithmetic expressions
    pattern = r'^\s*[\d\w]+(\s*[-+/*]\s*[\d\w]+\s*)*$'

    # Check if parentheses are balanced
    if not balanced_parentheses(expression):
        return False
    
    # Check if the expression matches the pattern
    return bool(re.match(pattern, expression))

# Function to check if parentheses are balanced
def balanced_parentheses(expression):
    stack = []
    for char in expression:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if not stack or stack.pop() != '(':
                return False
    return not stack

# Example usage
if __name__ == "__main__":
    # Input arithmetic expression from user
    expression = input("Enter an arithmetic expression: ")

    # Validate the expression
    if is_valid_arithmetic_expression(expression):
        print("The expression is valid.")
    else:
        print("The expression is not valid.")
