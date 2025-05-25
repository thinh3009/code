with open(r"C:\Users\Asus\Desktop\thiscode\PYthon_only\Beatifulsoup\0.txt", "r") as f:
    files = f.readlines()

# Remove \t and \n characters
cleaned_files = [line.replace('\t', '').replace('\n', '').strip() for line in files]

print(cleaned_files)
