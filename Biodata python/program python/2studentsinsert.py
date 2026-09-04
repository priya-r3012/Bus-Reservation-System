listdata = []
for i in range(1,3):
    student_data={
         "name" : input("Enter student name: "),
         "id": int(input("Enter student id: "))
                 }

    listdata.append(student_data)

print(listdata)

