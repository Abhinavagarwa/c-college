def count_vowels_and_consonants(text):
    # Define the vowels
    vowels = "aeiouAEIOU"
    
    # Initialize counts for vowels and consonants
    vowel_count = 0
    consonant_count = 0
    
    # Traverse each character in the input text
    for char in text:
        # Check if the character is a letter
        if char.isalpha():
            # If the character is a vowel, increase the vowel count
            if char in vowels:
                vowel_count += 1
            else:
                consonant_count += 1
    return vowel_count, consonant_count

if __name__ == "__main__":
    # Input from user
    text = input("Enter a string: ")

    # Get the counts
    vowels, consonants = count_vowels_and_consonants(text)

    # Output the result
    print(f"Number of vowels: {vowels}")
    print(f"Number of consonants: {consonants}")
