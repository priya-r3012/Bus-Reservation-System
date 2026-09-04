students = {} 

while True:
        print("\n----STUDENT RECORD----")
        print("\n1. Registration")
        print("2. Student record")
        print("3. Exit")
        
        choice = int(input("\nEnter your choice: "))

        if choice==1:
        
                student_id = input("\nEnter student ID: ")
                name = input("Enter student name: ")
                address = input("Enter student address: ")
                students[student_id] = {'name': name, 'address': address}
                print(f"Student: {name} (ID: {student_id})")
                print("REGISTERED SUCCESSFULL!")
                
        elif choice==2:
            
            student_id = int(input("Enter the student ID to search: "))
            for student_details in students:
               if student_id in students:
                record = students[student_id]
                print(f"\n--- STUDENT DETAIL Found ---")
                print(f"\ndetails found for ID = {student_id}")
                print(f"{record}")
            else:
                print(f"\nError: No student ID = {student_id}")

        elif choice==3:
            
            print("\nExit!")
            break
        
        else:
            print("Invalid choice. Please enter valid choice.")

