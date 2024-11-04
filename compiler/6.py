class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        """Add an item to the top of the stack."""
        self.stack.append(item)
        print(f"Pushed {item} to stack")

    def pop(self):
        """Remove the item from the top of the stack."""
        if self.is_empty():
            print("Stack is empty. Cannot pop.")
            return None
        item = self.stack.pop()
        print(f"Popped {item} from stack")
        return item

    def peek(self):
        """View the item at the top of the stack without removing it."""
        if self.is_empty():
            print("Stack is empty. Nothing to peek.")
            return None
        return self.stack[-1]

    def is_empty(self):
        """Check if the stack is empty."""
        return len(self.stack) == 0

    def display(self):
        """Display all items in the stack."""
        if self.is_empty():
            print("Stack is empty.")
        else:
            print("Stack contents:", self.stack)

# Usage Example
stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)
stack.display()      # Display current stack

print("Top element:", stack.peek())  # Peek at the top element
stack.pop()          # Pop the top element
stack.display()      # Display stack after pop
print("Is stack empty?", stack.is_empty())  # Check if stack is empty

stack.pop()
stack.pop()
stack.pop()          # Attempt to pop from an empty stack
stack.display()
print("Is stack empty?", stack.is_empty())
