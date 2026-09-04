dictdata=[
    {"id":101,"name":"priya","address":"hisar"},
    
    {"id":102,"name":"ruhi","address":"jind"},

    {"id":103,"name":"pihu","address":"chandigarh"}
    ]
\
user_name = input("enter your name : ")
found = False

for data in dictdata:
    for key,value in data.items():
        if user_name == value:
            print("record found")
            print(data)
            found = True
            break 
if not found:       
            print("record not found!")    
            
           
