from collections import defaultdict

# Function to compute the FIRST set of a grammar
def compute_first(grammar):
    # Initialize FIRST dictionary
    first = defaultdict(set)
    
    # Helper function to recursively find FIRST of a non-terminal
    def find_first(symbol):
        # If symbol is a terminal, FIRST(symbol) = {symbol}
        if not symbol.isupper():
            return {symbol}
        
        # If already computed, return it
        if first[symbol]:
            return first[symbol]
        
        # Compute FIRST set for each production of the non-terminal
        for production in grammar[symbol]:
            for char in production:
                # Get FIRST of the current symbol in the production
                char_first = find_first(char)
                
                # Add everything except epsilon to FIRST(symbol)
                first[symbol].update(char_first - {'ε'})
                
                # If char does not produce epsilon, stop
                if 'ε' not in char_first:
                    break
            else:
                # If all characters in the production can be epsilon
                first[symbol].add('ε')
        
        return first[symbol]

    # Compute FIRST set for each non-terminal in the grammar
    for non_terminal in grammar:
        find_first(non_terminal)
    
    return first

# Sample grammar input as a dictionary
# Grammar format: { Non-terminal : [Productions] }
grammar = {
    'S': ['AB', 'bC'],
    'A': ['ε', 'b'],
    'B': ['aA', 'b'],
    'C': ['AB', 'a']
}

# Compute FIRST sets
first_sets = compute_first(grammar)

# Display the FIRST sets
print("FIRST sets:")
for non_terminal, first_set in first_sets.items():
    print(f"FIRST({non_terminal}) = {{ {', '.join(first_set)} }}")
