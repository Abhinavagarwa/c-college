from collections import defaultdict
import re

# Function to check if a grammar is operator-precedence
def is_operator_precedence_grammar(grammar):
    # Check each production rule for consecutive non-terminals
    for non_terminal, productions in grammar.items():
        for production in productions:
            # Search for consecutive non-terminals (e.g., "AB")
            if re.search(r'[A-Z]{2}', production):
                # If two uppercase letters (non-terminals) are found consecutively
                print(f"Grammar is NOT operator-precedence due to consecutive non-terminals in production: {non_terminal} -> {production}")
                return False
    
    # If no consecutive non-terminals are found, it's potentially an operator-precedence grammar
    print("Grammar satisfies operator-precedence conditions (no consecutive non-terminals).")
    return True

# Sample grammar input as a dictionary
# Grammar format: { Non-terminal : [Productions] }
grammar = {
    'E': ['E+T', 'T'],
    'T': ['T*F', 'F'],
    'F': ['(E)', 'id']
}

# Check if grammar is operator-precedence
result = is_operator_precedence_grammar(grammar)

# Display result
if result:
    print("The grammar can be an operator-precedence grammar.")
else:
    print("The grammar cannot be an operator-precedence grammar.")
