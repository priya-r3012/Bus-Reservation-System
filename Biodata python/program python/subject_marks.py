print("\nMarks obtained :-")

english = float(input("\nEnter marks in English : "))
hindi = float(input("Enter marks in Hindi : "))
maths = float(input("Enter marks in Maths : "))
ss = float(input("Enter marks in SS : "))
science = float(input("Enter marks in Science : "))

total_marks = english + hindi + maths + ss + science

percentage = (total_marks/500)*100

print(f"\nTotal marks = {total_marks}")
print(f"\nPercentage = {percentage:.2f}%")