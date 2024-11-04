from collections import defaultdict

def left_factoring(grammar):
    factored_grammar = {}
    for non_terminal, productions in grammar.items():
        # Group productions by common prefix
        prefix_dict = defaultdict(list)
        
        for prod in productions:
            # Find the first symbol (prefix) of each production
            prefix = prod.split()[0]
            prefix_dict[prefix].append(prod)
        
        # Factoring process
        factored_productions = []
        extra_productions = {}
        
        for prefix, prods in prefix_dict.items():
            if len(prods) > 1:
                # Left factoring is needed
                new_non_terminal = f"{non_terminal}'"
                while new_non_terminal in grammar or new_non_terminal in extra_productions:
                    new_non_terminal += "'"
                
                # Create new productions for the factored prefix
                factored_productions.append(f"{prefix} {new_non_terminal}")
                new_prods = [' '.join(prod.split()[1:]) if len(prod.split()) > 1 else 'ε' for prod in prods]
                extra_productions[new_non_terminal] = new_prods
            else:
                # No factoring needed, keep the production as it is
                factored_productions.append(prods[0])
        
        factored_grammar[non_terminal] = factored_productions
        factored_grammar.update(extra_productions)

    return factored_grammar

# Define a sample grammar
grammar = {
    "A": ["a b", "a c", "b d"]
}

# Perform left factoring
factored_grammar = left_factoring(grammar)

# Print the factored grammar
print("Factored Grammar:")
for non_terminal, productions in factored_grammar.items():
    print(f"{non_terminal} -> {' | '.join(productions)}")
