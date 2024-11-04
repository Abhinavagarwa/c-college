from collections import defaultdict

def compute_leading(grammar):
    leading = defaultdict(set)

    def find_leading(symbol):
        # If symbol is terminal, return it as leading set
        if not symbol.isupper():  # Assumes non-terminals are uppercase
            return {symbol}

        # If already computed, return it to avoid re-calculating
        if leading[symbol]:
            return leading[symbol]

        for production in grammar[symbol]:
            # Iterate over each symbol in the production
            for sym in production:
                if sym == 'ε':  # Epsilon case
                    leading[symbol].add(sym)
                    continue

                # Add leading of current symbol
                leading[symbol].update(find_leading(sym))

                # If sym does not derive epsilon, stop here
                if 'ε' not in find_leading(sym):
                    break

        return leading[symbol]

    # Compute leading for each non-terminal
    for non_terminal in grammar:
        find_leading(non_terminal)

    return leading

# Define a sample grammar as dictionary where keys are non-terminals
# and values are lists of productions.
grammar = {
    "A": ["B C", "a D", "ε"],
    "B": ["b", "ε"],
    "C": ["c", "d"],
    "D": ["d", "A"]
}

# Compute leading sets
leading = compute_leading(grammar)

# Display leading sets
print("Leading Sets of Non-Terminals:")
for non_terminal, leads in leading.items():
    print(f"{non_terminal}: {leads}")
