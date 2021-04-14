#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    char data[100],ch,ch1,name[10];
    int i,j=0,k,key=0,eof;
    int password,varInput;

    system("cls||clear");

    printf("Welcome to the Program! \nPlease input password :  ");
    scanf("%d",&password);
    
    if(password == 1234)
    {
        system("cls||clear");
        printf("Welcome!\nInput Your Choice : ");
        label1:
        system("cls||clear");
        printf("\n1.Encryption\n2.Decryption\n3.View Contents of the file\n\nPress any other key to exit!\nEnter : ");
        scanf("%d",&varInput);

        if(varInput==1)
        {
            // input file
            system("cls||clear");
            printf("Welcome to Encryption Block!\n");
            while ((getchar()) != '\n'); // clear buffer for ENTER
            printf("Enter name of file : ");
            // fgets(name,sizeof(name),stdin);
            scanf("%s",name);
            strcat(name,".txt");
            fp = fopen(name,"w");
            printf("\nEnter data to the file : ");
            while ((getchar()) != '\n'); // clear buffer for ENTER
            fgets(data,sizeof(data),stdin);
            printf("\nEnter the passkey : ");
            scanf("%d",&key);
            // encryption code here
            for(i=0;i<strlen(data);i++)
            {
                data[i] = data[i]+key;
            }

            //add to file
            fprintf(fp,"%s",data);
            fclose(fp);
            printf("Data has been successfully encrypted. Going back to main screen!\n");
                // if success
                    goto label1;
        } 
        else if(varInput==2)
        {
            //input file
            system("cls||clear");
            printf("\nWelcome to Decryption Block!\n");
            while ((getchar()) != '\n'); // clear buffer for ENTER
            printf("Enter name of file : ");
            // fgets(name,sizeof(name),stdin);
            scanf("%s",name);
            strcat(name,".txt");
            fp = fopen(name,"w+");
            printf("\nEnter the passkey : ");
            scanf("%d",&key);

            // read data from the file
            // while(eof!=EOF)
            // {
            //     fscanf(fp,"%s",data);                
            //     //decryption code here
            //     for(i=0;i<strlen(data);i++)
            //     {
            //         data[i] = data[i]-key;
            //     }
            // }

            fscanf(fp,"%s",data);
            
                for(i=0;i<strlen(data);i++)
                {
                    data[i] = data[i]-key;
                }
            

            // overwrite existing data
            fseek(fp,0,SEEK_SET);
            // for(i=0;i<strlen(data);i++)
            // {
            //     fprintf(fp,"%s",data);
            // }

            fprintf(fp,"%s",data);

            fclose(fp);

            printf("\nData has been successfully decrypted. Going back to main screen! \n");
            
                // if success
                    goto label1;
        } 
        else if(varInput == 3)
        {
            // input file
            system("cls||clear");
            while ((getchar()) != '\n'); // clear buffer for ENTER
            printf("Enter name of file : ");
            // fgets(name,sizeof(name),stdin);
            scanf("%s",name);
            strcat(name,".txt");
            fp = fopen(name,"r");
            // display file data
                
            printf("\nCurrent data in the file : ");
            fscanf(fp,"%s",data);
            printf("%s",data);

            fclose(fp);
            //if success
            printf("\nEnter 1 to go back to main menu : ");
            scanf("%d",&k);
            if(k==1)
            {
                goto label1;
            }
            
                    
        } 
        else 
        {
            system("cls||clear");
            printf("Thank You!\n");
        }
    } 

    else 
    {
        printf("\nInvalid password entered. Program will terminate now...");
    }

    return 0;
}