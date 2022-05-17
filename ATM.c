// ATM //

#include<stdio.h>

int  login();
void CheckBalance();
void Cashwithdrawl();
void Cashdeposit(); 

int id[6]={0,1,2,3,4,5};
int pin[6]={0,111,222,333,444,555};
int balance[6]={0,1000,2000,3000,4000,5000};

void main()
{
     int p;
     int u = login();
     
     if(u > 0)
     {
        printf("user %d logged in succesfully\n", u);
        
        do 
        {
               printf("What you want to do ?\n Enter 1 for Balance enquiry\n Enter 2 for Cash withdrawl\n Enter 3 for Cash   deposit\n Enter 4 to quit\n");
               scanf("%d", &p);
               
               switch(p)
               { 
                        case 1:
                        CheckBalance(u);
                        break;
                 
                        case 2:
                        Cashwithdrawl(u);
                        break;
                 
                        case 3:
                        Cashdeposit(u);
                        break;
                 
                        case 4:
                        printf("Thank you for visiting our bank !\n");
                        break;
                 
                        default:
                        printf("Invalid input\n");
               }
        }        
        while(p != 4); 
       
      }
      else
      {
         printf("Card Blocked");
      }
}  

      int login()
      {
         int i,q,chance = 3;
         printf("Enter your account id\n");
         scanf("%d",&i);
         do 
         {
                 printf("Enter pin no: \n");
                 scanf("%d" , &q);
                 if(q!=pin[i])
                 chance--;
         }  
         while(q != pin[i] && chance > 0);
         
         if(chance == 0)
         {
                 return - 1;
         }
         else
         {
                 return i;
         } 
      }

void CheckBalance(int a)
{
      printf("Balance of user %d is %d\n",a,balance[a]);
}

void Cashwithdrawl(int a)
{
      int amount;
      printf("Enter the amount:\n");
      scanf("%d", &amount);
      if(balance[a] >= amount)
      {
          balance[a]=balance[a]-amount;
      }
      else
          printf("Insufficiant balance\n");
}

void Cashdeposit(int a)
{
      int amount;
      printf("Enter the amount:\n");
      scanf("%d", &amount);
      balance[a]=balance[a]+amount;

}                    
                  
                                            
                 
