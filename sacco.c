
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int i, j;
//Used to exit the banking system
int main_exit;
//Structures that hold all the variables needed in the program
struct date
{
    int month, day, year;

};

struct
{

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

//Calculating the Interest for Clients with Saving, Fixed1, Fixed2, Fixed3.
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
//the Menu function with all available options to run this program. Using the Switch Statement
void menu(void)
{   int choice;
    printf("\033[H\033[J");
    printf("\n\n\t KARUGUTU SAVINGS AND CREDIT COOPERATIVE SOCIETY");
    printf("\n\n\n\t\t Account Management System");
    printf("\n\n\n\t\t\t Main Menu");
    printf("\n\n\t\t1. Open New Account\n\t\t2. Update Info of Existing Account\n\t\t3. Make Transactions\n\t\t4. Details of Existing Account\n\t\t5. Delete Existing Account\n\t\t6. View Client List\n\t\t7. Exit\n\n\n\n\n\t\t Enter Your Choice: ");
    scanf("%d", &choice);

    printf("\033[H\033[J");
    switch(choice)
    {
        case 1:new_acc(); //Opening a New Account
        break;
        case 2:edit(); //Modifying an Existing Account
        break;
        case 3:transact(); //Make Transactions
        break;
        case 4:see(); //View Details of a Client
        break;
        case 5:erase(); //Delete An Existing Account
        break;
        case 6:view_list(); //View List of All Clients
        break;
        case 7:close(); //Exit the program
        break;

    }

}

// Function to close the program
void close(void)
{
    printf("\n\n\t\tThank you for using Karugutu SACCO Banking System!\n\n");
    exit(0);
}

/*Opening New Accounts with information being stored using a File Pointer *ptr to record.dat
The User is required to feed in all the information needed to Open an  Account*/
void new_acc()
{
    int choice;
    FILE *ptr;
    int is_account_no_unique;

    ptr=fopen("record.dat","a+");
    do {
        is_account_no_unique = 1; // Assume unique until proven otherwise
        printf("\033[H\033[J");
        printf("\t\t\tCreate a New Sacco Account");
        printf("\n\n\nEnter Current Date (MM/DD/YYYY): ");
        scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
        printf("\nEnter Account Number: ");
        scanf("%d",&check.acc_no);
        // Reset file pointer to the beginning of the file for each check
        rewind(ptr);
        while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if (check.acc_no==add.acc_no)
            {
                printf("Account No. Already in Use!\n");
                is_account_no_unique = 0;
                // Consume the rest of the line if any, to prevent issues with next scanf
                char c;
                while ((c = getchar()) != '\n' && c != EOF);
                break; // No need to check further
            }
        }
    } while (!is_account_no_unique);
    add.acc_no=check.acc_no;
        printf("\nEnter Name: ");
    scanf("%s",add.name);
    printf("\nEnter Date of Birth (MM/DD/YYYY): ");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter Age: ");
    scanf("%d",&add.age);
    printf("\nEnter Address: ");
    scanf("%s",add.address);
    printf("\nEnter Citizenship Number: ");
    scanf("%s",add.citizenship);
    printf("\nEnter Phone Number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter Amount to Deposit (UGX): ");
    scanf("%f",&add.amt);
    printf("\nType of Account:\n\t Saving\n\t Current\n\t Fixed1 (for 1 Year)\n\t Fixed2 (for 2 Years)\n\t Fixed3 (for 3 Years)\n\n\tEnter Your Choice: ");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount Created Successfully!");
    while(1)
    {
        printf("\n\n\n\t\tEnter 1 to go to Main Menu and 0 to Exit: ");
        scanf("%d",&main_exit);
        printf("\033[H\033[J");
        if (main_exit==1)
        {
            menu();
            break;
        }
        else if(main_exit==0)
        {
            close();
            break;
        }
        else
        {
            printf("\nInvalid!\a");
        }
    }
}
/*Modifying of Existing Accounts. Only the Address or Phone Number of an Existing Account can be Updated.
The updated Information is stored in  a new file called new.dat*/
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the Account No. of the Client whose Info you want to change: ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich Information do you want to Change? \n1. Address\n2. Phone Number \n\nEnter Your Choice: ");
            scanf("%d",&choice);
            printf("\033[H\033[J");
            if(choice==1)
                {printf("Enter New Address: ");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\033[H\033[J");
                printf("Changes Saved!");
                }
            else if(choice==2)
                {
                    printf("Enter New Phone Number: ");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\033[H\033[J");
                printf("Changes Saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   printf("\033[H\033[J");
            printf("\nRecord not Found!\a\a\a");
            while(1)
            {
                printf("\nEnter 0 to Try Again, 1 to return to Main Menu and 2 to Exit: ");
                scanf("%d",&main_exit);
                printf("\033[H\033[J");
                if (main_exit==1)
                {
                    menu();
                    break;
                }
                else if (main_exit==2)
                {
                    close();
                    break;
                }
                else if(main_exit==0)
                {
                    edit();
                    break;
                }
                else
                {
                    printf("\nInvalid!\a");
                }
            }
        }
    else
        {printf("\n\n\nEnter 1 to go to Main Menu and 0 to Exit: ");
        scanf("%d",&main_exit);
        printf("\033[H\033[J");
        if (main_exit==1)
            menu();
        else
            close();
        }
}
/*Make transactions 
Deposit and Withdraw from Saving and Current Accounts.
Can't withdraw from fixed accounts*/
void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the Account No. of the Client: ");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcasecmp(add.acc_type,"Fixed1")==0||strcasecmp(add.acc_type,"Fixed2")==0||strcasecmp(add.acc_type,"Fixed3")==0)
                {
                    printf("\a\a\a\n\nYou Cannot Deposit or Withdraw Cash on Fixed Accounts!");
                    printf("\033[H\033[J");
                    menu();

                }
                printf("\n\nDo you want to\n1. Deposit\n2. Withdraw \n\nEnter Your Choice: ");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the Amount you want to Deposit (UGX): ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited Successful");
                }
                else
                {
                    printf("Enter the Amount you want to Withdraw (UGX): ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdraw Successful!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       while(1)
       {
           printf("\n\n\nEnter 0 to try again, 1 to return to Main Menu and 2 to Exit: ");
           scanf("%d",&main_exit);
           printf("\033[H\033[J");
           if (main_exit==0)
           {
               transact();
               break;
           }
           else if (main_exit==1)
           {
               menu();
               break;
           }
           else if (main_exit==2)
           {
               close();
               break;
           }
           else
           {
               printf("\nInvalid!");
           }
       }
   }
   else
   {
       printf("\nEnter 1 to go to the Main Menu and 0 to Exit: ");
        scanf("%d",&main_exit);
        printf("\033[H\033[J");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
//Function to view the details of an individual client. You can check using an Account Number or Name
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1. Account No.\n2. Name\nEnter Your Choice: ");
    scanf("%d", &choice);
    if (choice==1)
    {   printf("Enter the Account No.: ");
        scanf("%d", &check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   printf("\033[H\033[J");
                test=1;

                printf("\nAccount No.: %d\nName: %s\nDate of Birth: %d/%d/%d\nAge: %d\nAddress: %s\nCitizenship No: %s\nPhone Number: %.0lf\nType Of Account: %s\nAmount deposited(UGX): %.2f\nDate Of Deposit: %d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcasecmp(add.acc_type,"Fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get (UGX) %.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcasecmp(add.acc_type,"Fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get (UGX) %.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcasecmp(add.acc_type,"Fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get UGX %.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcasecmp(add.acc_type,"Saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get UGX %.2f as Interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcasecmp(add.acc_type,"Current")==0)
                     {

                        printf("\n\nYou will get no Interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter Name: ");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcasecmp(add.name,check.name)==0)
            {   printf("\033[H\033[J");
                test=1;
                printf("\nAccount No.: %d\nName: %s\nDate of Birth: %d/%d/%d \nAge:%d \nAddress: %s \nCitizenship No: %s \nPhone Number: %.0lf \nType Of Account: %s \nAmount deposited (UGX): %.2f \nDate Of Deposit: %d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcasecmp(add.acc_type,"Fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get (UGX) %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcasecmp(add.acc_type,"Fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get (UGX) %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcasecmp(add.acc_type,"Fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get (UGX) %.2f as Interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcasecmp(add.acc_type,"Saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get (UGX) %.2f as Interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcasecmp(add.acc_type,"Current")==0)
                    {

                        printf("\n\nYou will get no Interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   printf("\033[H\033[J");
            printf("\nRecord not Found!!\a\a\a");
            while(1)
            {
                printf("\nEnter 0 to Try Again, 1 to return to Main Menu and 2 to Exit: ");
                scanf("%d",&main_exit);
                printf("\033[H\033[J");
                if (main_exit==1)
                {
                    menu();
                    break;
                }
                else if (main_exit==2)
                {
                    close();
                    break;
                }
                else if(main_exit==0)
                {
                    see();
                    break;
                }
                else
                {
                    printf("\033[H\033[J");
                    printf("\nInvalid!\a");
                }
            }
        }
    else
        {printf("\nEnter 1 to go to Main Menu and 0 to Exit: ");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            printf("\033[H\033[J");
            menu();
        }

        else
           {

             printf("\033[H\033[J");
            close();
            }

}
//Function to Delete an Account from the program that is stored in files
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the Account No. of the Client you want to Delete: ");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
                test++;
                printf("\nRecord Deleted Successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not Found!\a\a\a");
            while(1)
            {
                printf("\nEnter 0 to Try Again, 1 to return to Main Menu and 2 to Exit: ");
                scanf("%d",&main_exit);

                if (main_exit==1)
                {
                    menu();
                    break;
                }
                else if (main_exit==2)
                {
                    close();
                    break;
                }
                else if(main_exit==0)
                {
                    erase();
                    break;
                }
                else
                {
                    printf("\nInvalid!\a");
                }
            }
        }
    else
        {
            printf("\nEnter 1 to go to the Main Menu and 0 to Exit: ");
            scanf("%d",&main_exit);
            printf("\033[H\033[J");
        if (main_exit==1)
            menu();
        else
            close();
        }

}
//Function to View the list of clients at the Sacco
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    printf("\033[H\033[J");
    printf("\nAccount No. \t\tName \t\tAddress \t\tPhone \n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t\t %10s\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   printf("\033[H\033[J");
            printf("\nNo Records!\n");}

    while(1)
    {
        printf("\n\nEnter 1 to go to the Main Menu and 0 to Exit: ");
        scanf("%d",&main_exit);
        printf("\033[H\033[J");
        if (main_exit==1)
        {
            menu();
            break;
        }
        else if(main_exit==0)
        {
            close();
            break;
        }
        else
        {
            printf("\nInvalid!\a");
        }
    }
}
//Main function that has the Welcome page to the program.
int main()
{
    char pass[20], password[20]; // Increased size for safety
    int i=0;
    FILE *password_file;

    // Try to open record.dat to see if it's the first run
    FILE *record_file = fopen("record.dat", "r");
    if (record_file == NULL) {
        // record.dat does not exist, so it's likely the first run or data was cleared.
        printf("\n\n\t\t Welcome to Karugutu SACCO Setup\n\n");
        printf("\n\tThis appears to be the first time running the program or data has been cleared.");
        printf("\n\tPlease set a new password for the system (max 19 characters): ");
        scanf("%19s", password);
        // Consume newline character left by scanf
        while(getchar() != '\n');

        password_file = fopen("password.dat", "w");
        if (password_file == NULL) {
            perror("Error creating password file");
            return 1;
        }
        fprintf(password_file, "%s", password);
        fclose(password_file);
        printf("\n\tPassword set successfully. Please restart the program to login.\n");
        // Create an empty record.dat so next time it doesn't ask to set password
        record_file = fopen("record.dat", "w");
        if (record_file != NULL) fclose(record_file);
        else perror("Error creating record.dat");
        return 0; // Exit after setting password
    } else {
        // record.dat exists, proceed to load password
        fclose(record_file); // Close record.dat, it was just for checking existence
        password_file = fopen("password.dat", "r");
        if (password_file == NULL) {
            // This case should ideally not happen if record.dat exists and setup was complete.
            // It implies password.dat was deleted manually or setup was interrupted.
            printf("\n\n\t\tPassword file not found!\n");
            printf("\tPlease run setup by deleting 'record.dat' or ensure 'password.dat' exists.\n");
            // As a fallback, or for recovery, one might prompt to set a new password here too.
            // For now, exiting.
            // Alternative: Default to a known password or prompt for a new one.
            strcpy(password, "kasacco"); // Fallback to original hardcoded if password.dat missing
            printf("\tUsing default password. Consider resetting if this is unexpected.\n");
            // return 1; // Or exit
        } else {
            if (fscanf(password_file, "%19s", password) != 1) {
                printf("\n\n\t\tError reading password from file!\n");
                fclose(password_file);
                // Fallback or error handling
                 strcpy(password, "kasacco"); // Fallback
                 printf("\tUsing default password due to read error.\n");
                // return 1;
            } else {
                fclose(password_file);
            }
        }
    }

    printf("\n\n\t\t Welcome to Karugutu SACCO\n\n");
    printf("\n\n\t\t Enter Password to Login: ");
    scanf("%19s", pass);
    // Consume newline character left by scanf
    while(getchar() != '\n');

    // Using strcmp for password check as before
    if (strcmp(pass, password) == 0)
        {printf("\n\n\n\t\tPlease Wait");
        for(i=0;i<=5;i++)
        {
            printf(".");
        }
                printf("\033[H\033[J");
            menu();
        }
    else
        {   printf("\n\n\t\tYou Entered a Wrong Password!\a\a\a\n");
            while(1)
            {
                printf("\n\n\t\tEnter 1 to Try Again and 0 to Exit: ");
                scanf("%d", &main_exit);
                if (main_exit==1)
                {
                    printf("\033[H\033[J");
                    // Instead of calling main() recursively, we can just let the loop continue
                    // and the password check will happen again at the beginning of main().
                    // However, this will re-print the welcome message.
                    // A better approach would be to loop just the password part.
                    // For now, to match original logic as closely as possible while removing goto:
                    main(); // This is still a recursive call.
                    return 0; // Exit after the recursive call returns.
                }
                else if (main_exit==0)
                {
                    printf("\033[H\033[J");
                    close();
                    return 0; // Exit after closing.
                }
                else
                {
                    printf("\nInvalid Choice!");
                    printf("\033[H\033[J");
                }
            }
        }
        return 0;
}
