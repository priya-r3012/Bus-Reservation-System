print("\nMarks obtained :-")

english = float(input("\nEnter marks in English : "))
hindi = float(input("Enter marks in Hindi : "))
maths = float(input("Enter marks in Maths : "))
science = float(input("Enter marks in Science : "))

total_marks = english + hindi + maths + science

percentage = total_marks/4

print(f"\nTotal marks = {total_marks}")
print(f"\nPercentage = {percentage:.2f}%")

if percentage>=60:
    print("Excellent , You are pass with first division !")
else:
    print("you are fail !")    