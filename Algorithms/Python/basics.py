# Write your code here :-)

command = ""

# Loop until user put quit
# Dot operator is used to acces the methods of the class object
while command.lower() != "quit":
    command = input("> ").lower()
    if command == "start":
        print("Car started...")
    elif command == "stop":
        print("Car stopped")
    elif command == "help":
        print("start - to start the car")
        print("stop - to stop the car")
        print("quit - quit the game")
    elif  command == "quit":
        break    # Jump out loop
    else:
        # if command doesnt match anything, this will prints
        print("Sorry, I didn't understand what you said")
