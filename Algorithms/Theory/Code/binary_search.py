# Write your code here :-)

# Function that it takes an ordered list and the item that we want to find
def binary_search(list, item):
    low = 0             # Low element of the list
    high = len(list)-1  # Highest value of the list

    while low <= high:  # While you get the last element of the list
        mid = (low + high) // 2
        guess = list[mid]           # Check the middle element
        if guess == item:
            return mid
        if guess > item:             # Guess to high
            high = mid - 1
        else:                         # Guess to low
            low = mid + 1
    return none


my_list = [1, 3, 5, 7, 9]

print(binary_search(my_list, 3))# Write your code here :-)
