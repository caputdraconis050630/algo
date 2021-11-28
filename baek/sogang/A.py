s = input()

arr1 = ["B", "E", "H", "P", "C", "Y", "X"]
arr2 = ["v", "ye", "n", "r", "s", "u", "h"]

for i in range(7):
    s = s.replace(arr1[i], arr2[i])

print(s.lower())
