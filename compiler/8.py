class ShiftReduceParser:
    def __init__(self, grammar):
        self.grammar = grammar  # Dictionary of production rules
        self.start_symbol = list(grammar.keys())[0]  # Assume first non-terminal is the start symbol
    def parse(self, input_string):
        stack = []  # Stack for parsing
        input_buffer = list(input_string)  
        steps = []  
        while True:
            if stack == [self.start_symbol] and not input_buffer:
                steps.append("Accepted: Input matches the grammar.")
                break
            if input_buffer:
                action = "Shift"
                stack.append(input_buffer.pop(0))  # Shift the next symbol from input to stack
                steps.append(f"{action}: Stack = {stack}, Input = {input_buffer}")
            else:
                action = None
            reduced = False
            for lhs, rhs_list in self.grammar.items():
                for rhs in rhs_list:
                    rhs_symbols = rhs.split()  # Split RHS into symbols for easy comparison
                    if stack[-len(rhs_symbols):] == rhs_symbols:
                        # Apply reduction
                        stack = stack[:-len(rhs_symbols)]  # Remove RHS symbols from stack
                        stack.append(lhs)  # Push LHS onto stack
                        action = f"Reduce by {lhs} -> {' '.join(rhs_symbols)}"
                        steps.append(f"{action}: Stack = {stack}, Input = {input_buffer}")
                        reduced = True
                        break
                if reduced:
                    break
            if action == "Shift" and not reduced and not input_buffer:
                steps.append("Error: Parsing failed.")
                break
        for step in steps:
            print(step)
grammar = {
    "S": ["A A"],
    "A": ["a"]
}
input_string = "aa"
parser = ShiftReduceParser(grammar)
parser.parse(input_string)

