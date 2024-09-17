def count_words(text):
    # Split the text by spaces (and remove extra spaces) to get the words
    words = text.split()
    
    # Return the length of the resulting list which represents the word count
    return len(words)

# Example usage
if __name__ == "__main__":
    # Input from user
    text = input("Enter a string: ")

    # Get the word count
    word_count = count_words(text)

    # Output the result
    print(f"Number of words: {word_count}")
