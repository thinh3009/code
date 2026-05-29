import os

#doc file

# file_obj=open("myfile.txt")
# content=file_obj.read()
# print(content)
# file_obj.close()

#file context manager
# with open("myfile.txt") as file_obj:
#     content=file_obj.read()
#     print(content)

# with open("new_file.txt","w") as f:
#     f.write("xin chao cac ban nhe")


with open("new_file.txt","a") as f:
    f.write("\ntoi la bdt")