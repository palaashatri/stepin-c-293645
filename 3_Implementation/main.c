/**
 * @file main.c
 * @author Palaash Atri
 * @brief Main business logic. Input file, encrypt, decrypt or read data from the file.
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "fun.h"

int main()
{
    FILE *fp;
    char data[100],ch,ch1,name[10];
    int i,j=0,k,key=0,eof;
    int password,varInput;

    
    system("cls||clear");

    /**
     * @brief Access screen to the Program
     * 
     */

    printf("Welcome to the Program! \nPlease input password :  ");
    scanf("%d",&password);
    
    if(password == 1234)
    {
        /**
         * @brief Main menu to the program
         * 
         */
        system("cls||clear");
        label1:
        printf("Welcome!\nInput Your Choice : ");
        /**
         * @brief Enter input :
         *                  1 - Encrypt a file
         *                  2 - Decrypt a file
         *                  3 - Read data from a file
         *                  Any other integer - Exit the program
         * 
         */
        printf("\n1.Encryption\n2.Decryption\n3.View Contents of the file\n\nPress any other key to exit!\nEnter : ");
        scanf("%d",&varInput);

        if(varInput==1)
        {
            // ENCRYPTION


            /**
             * @brief Basic encryption logic : Input the file, 
             *                                 Add data to the file, 
             *                                 Input the encryption key,
             *                                 Encrypt the data,                                              
             *                                 Close the file
             * 
             */

            
            system("cls||clear");
            printf("Welcome to Encryption Block!\n");
            while ((getchar()) != '\n'); // clear buffer for ENTER

            // input file
            printf("Enter name of file : ");            
            scanf("%s",name);

            // Append .txt to filename
            strcat(name,".txt");

            // Open the file in write mode
            fp = fopen(name,"w");

            // Input data to the file
            printf("\nEnter data to the file : ");
            while ((getchar()) != '\n'); // clear buffer for ENTER
            fgets(data,sizeof(data),stdin);

            // Enter the encryption passkey
            printf("\nEnter the passkey : ");
            scanf("%d",&key);

            //Encrypt data & add to file
            fprintf(fp,"%s",encryptFile(data,key));

            // Close the file after operations
            fclose(fp);

            printf("Data has been successfully encrypted. Going back to main screen!\n");
            // Jump to main menu
            goto label1;
        } 
        else if(varInput==2)
        {

            // DECRYPTION

            /**
             * @brief Basic encryption logic : Input the file, 
             *                                 Add data to the file, 
             *                                 Input the decryption key,
             *                                 Decrypt the data,                                              
             *                                 Close the file
             * 
             */

            
            system("cls||clear");
            printf("\nWelcome to Decryption Block!\n");
            while ((getchar()) != '\n'); // clear buffer for ENTER

            //input file
            printf("Enter name of file : ");            
            scanf("%s",name);

            // Append .txt to filename
            strcat(name,".txt");

            // Open the file in read/write mode
            fp = fopen(name,"w+");

            // Enter the decryption passkey
            printf("\nEnter the passkey : ");
            scanf("%d",&key);

            // Read data from the file
            fscanf(fp,"%s",data);  

            // Set seek to first position in the file
            fseek(fp,0,SEEK_SET);
            
            // Overwrite the data in the file with decrypted data
            fprintf(fp,"%s",decryptFile(data,key));

            // Close the file after operations
            fclose(fp);

            printf("\nData has been successfully decrypted. Going back to main screen! \n");
            // Jump to main menu
            goto label1;
        } 
        else if(varInput == 3)
        {

            /**
             * @brief Read current data in the file.
             * 
             */
            
            system("cls||clear");
            while ((getchar()) != '\n'); // clear buffer for ENTER

            // input file
            printf("Enter name of file : ");            
            scanf("%s",name);

            // Append .txt to filename
            strcat(name,".txt");

            // Open file in read-only mode
            fp = fopen(name,"r");

            // display file data                
            printf("\nCurrent data in the file : ");
            fscanf(fp,"%s",data);
            printf("%s",data);

            // Close the file after operations
            fclose(fp);
            
            // Wait for user input to go back to main menu
            printf("\nEnter any key to go back to main menu : ");
            getchar();
            goto label1;          
                    
        } 
        else 
        {
            /**
             * @brief When user inputs any other number : Terminate the program
             * 
             */
            system("cls||clear");
            printf("Thank You!\n");
        }
    } 

    else 
    {
        /**
         * @brief Terminate the program if wrong password is entered.
         * 
         */
        printf("\nInvalid password entered. Program will terminate now...");
    }

    return 0;
}