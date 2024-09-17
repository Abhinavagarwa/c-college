class Grammar:
    def __init__(self, rules):
        self.rules = rules  # The input grammar in the form of rules
        self.non_terminals = list(rules.keys())

    def remove_left_recursion(self):
        new_rules = {}  # To store the modified grammar without left recursion

        for nt in self.non_terminals:  # For each non-terminal
            alpha = []  # Productions of the form A -> Aα (left-recursive)
            beta = []   # Productions of the form A -> β (non-left-recursive)

            # Split into left-recursive and non-left-recursive
            for prod in self.rules[nt]:
                if prod[0] == nt:  # If left-recursive
                    alpha.append(prod[1:])
                else:
                    beta.append(prod)

            if alpha:  # If there are left-recursive productions
                new_nt = nt + "'"  # Create a new non-terminal

                # Apply the transformation rules
                new_rules[nt] = [b + new_nt for b in beta]  # A → βA'
                new_rules[new_nt] = [a + new_nt for a in alpha] + ['ε']  # A' → αA' | ε
            else:
                new_rules[nt] = self.rules[nt]  # If no left recursion, keep the rule as is

        return new_rules

    def display_grammar(self, grammar):
        for nt, prods in grammar.items():
            prod_str = " | ".join(prods)
            print(f"{nt} → {prod_str}")

# Example Usage
if __name__ == "__main__":
    # Input grammar with left recursion
    rules = {
        'A': ['Aa', 'b']
    }

    grammar = Grammar(rules)
    print("Original Grammar:")
    grammar.display_grammar(rules)

    # Remove left recursion
    new_grammar = grammar.remove_left_recursion()

    print("\nGrammar after removing left recursion:")
    grammar.display_grammar(new_grammar)

