def check_keyword_in_string(string, keyword):
    if keyword in string:
        print(f"The keyword '{keyword}' is present in the string.")
    else:
        print(f"The keyword '{keyword}' is not present in the string.")

def main():
    string = input("Enter a string: ")
    keyword = input("Enter the keyword to search for: ")
    check_keyword_in_string(string, keyword)

if __name__ == "__main__":
    main()
