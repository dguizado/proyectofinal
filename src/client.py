def get_menu_choice():
    def print_menu():       # Your menu design here
        
        print("1. List Use Device  ")
        print("2. Write USB Device  ")
        print("3. Read USB Device  ")
   

    loop = True
    int_choice = -1

    while loop:          
        print_menu()    # Displays menu
        choice = input("Enter your choice [1-3]: ")

        if choice == '1':
            int_choice = 1
            loop = False
        elif choice == '2':
            choice = ''
            while len(choice) == 0:
                name  = raw_input("Enter name of the device and name of the file ")
            
			int_choice = 2	
            loop = False
        elif choice == '3':
            choice = ''
            while len(choice) == 0:
                name_and_content  = raw_input(" enter the name of the device and the name of the file you want to write and and the contents of the file ")
            int_choice = 3
            loop = False
        else:
         
            input("Wrong menu selection. Enter any key to try again..")
    return [int_choice, choice]


print(get_menu_choice())


