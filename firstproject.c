#include <stdio.h>
#include <string.h>
#include <ctype.h>


char reg_name[30];
char reg_email[40];
char reg_password[20];
char reg_mobile[11];
struct Bus
{
    int bus_number;
    char source[20];
    char destination[20];
    int total_seats;
    int available_seats;
    int fare;
};
struct Bus buses[4]=
 {
    {101, "Delhi", "Jind", 50, 50, 500},
    {102, "Hisar", "Chandigarh", 40, 40, 600},
    {103,"kaithal", "Gurugram", 45, 45, 550},
    {104, "Ambala", "Jaipur" , 30, 30, 450}
};
int valid_name(char name[])
{
    for (int i = 0; name[i] != '\0'; i++)
        if ((isalpha(name[i]) && name[i] == ' '))
            return 0;
    return 1;
}

int valid_mobile(char mob[])
{
    if (strlen(mob) != 10)
        return 0;

    int allZero = 1;
    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(mob[i]))
            return 0;
        if (mob[i] != '0')
            allZero = 0;
    }
    if (allZero)
        return 0;

    return 1;
}

int validEmail(char email[])
{
    int at = 0, dot = 0;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@') at = 1;
        if (email[i] == '.') dot = 1;
    }
    return (at && dot);
}

int validPassword(char pass[])
{
    int len = strlen(pass);
    return (len >= 8 && len <= 15);
}

void registration()
{
    printf("\n--- REGISTRATION ---\n");

    do {
        printf("Enter your name: ");
        scanf(" %[^\n]", reg_name);
        if (!valid_name(reg_name))
            printf("Invalid name! Only alphabets allowed\n");
    } while (!valid_name(reg_name));

    do {
        printf("Enter mobile number: ");
        scanf("%s", reg_mobile);
        if (!valid_mobile(reg_mobile))
            printf("Invalid mobile number! Number should be 10 digits\n");
    } while (!valid_mobile(reg_mobile));

    do {
        printf("Enter email: ");
        scanf("%s", reg_email);
        if (!validEmail(reg_email))
            printf("Invalid email format!\n");
    } while (!validEmail(reg_email));

    do {
        printf("Enter password (8 - 15 chars): ");
        scanf("%s", reg_password);
        if (!validPassword(reg_password))
            printf("Password must be 8 - 15 characters!\n");
    } while (!validPassword(reg_password));

    printf("\nRegistration Successful!\n");
}

int login()
{
    char email[40], pass[20];

    printf("\n--- LOGIN ---\n");
    printf("\nLogin with your email & password");
    printf("Enter email: ");
    scanf("%s", email);
if (strcmp(reg_email, email)==0)
{
    printf("Enter password: ");
    scanf("%s", pass);
    return 1;
}
printf("\ninvalid email!");
return 0;
     if(strcmp(reg_password, pass) == 0)
    {
        printf("\nLogin Successful! Welcome ");
        return 1;
    }

    printf("\nInvalid Password!\n");
    return 0;
}

int find_bus(int bus_number)
{
    for (int i = 0; i < 4; i++)
        if (buses[i].bus_number == bus_number)
            return i;

    return -1;
}

void menu()
{
    int choice;

    while (1)
    {
        printf("\n==== USER MENU ====\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Bus Status\n");
        printf("4. Logout\n");
        printf("please select your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        { 
            int bus_number, seats;
            printf("Enter bus number: ");
            scanf("%d", &bus_number);

            int i = find_bus(bus_number);
            if (i == -1)
            {
                printf("Invalid Bus Number!\n");
                continue;
            }

            printf("Enter seats to book: ");
            scanf("%d", &seats);

            if (seats > buses[i].available_seats)
            {
                printf("Not enough seats!\n");
            }
            else
            {
                buses[i].available_seats -= seats;
                printf("Booking successful!\n");
                printf("Total Amount = Rs%d\n", seats * buses[i].fare);
            }
        }

        else if (choice == 2)
        {
            int bus_number, seats;
            printf("Enter bus number: ");
            scanf("%d", &bus_number);

            int i = find_bus(bus_number);
            if (i == -1)
            {
                printf("Invalid Bus Number!\n");
                continue;
            }

            printf("Enter seats to cancel: ");
            scanf("%d", &seats);

            buses[i].available_seats += seats;
            if (buses[i].available_seats > buses[i].total_seats)
                buses[i].available_seats = buses[i].total_seats;

            printf("Cancellation successful!\n");
        }

        else if (choice == 3)
        {
            int bus_number;
            printf("Enter bus number: ");
            scanf("%d", &bus_number);

            int i = find_bus(bus_number);
            if (i == -1)
            {
                printf("Invalid Bus Number!\n");
                continue;
            }

            printf("\n--- BUS STATUS ---\n" );
            printf("Bus No: %d\n", buses[i].bus_number);
            printf("Route: %s to %s\n", buses[i].source, buses[i].destination);
            printf("Total Seats: %d\n", buses[i].total_seats);
            printf("Available Seats: %d\n", buses[i].available_seats);
            printf("Fare: Rs= %d\n", buses[i].fare);
        }

        else if (choice == 4)
        {
            printf("Logout successful!\n");
            break;
        }

        else
            printf("Invalid choice!\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n**** BUS RESERVATION SYSTEM ****\n");
        printf("1. Registration\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("please select your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            registration();

        else if (choice == 2)
        {
            if (login())
                menu();
        }

        else if (choice == 3)
        {
            printf("Exit!\n");
            break;
        }

        else
            printf("Invalid choice!\n");
    }

    return 0;
}