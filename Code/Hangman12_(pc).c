#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


static int score=0;
static int end=0;
static int skip=3;
static int round=0;

void word_file(int i);
void word(char wrd[10],char hint[30]);
void draw(int w);

int main() {
    
    char c;
    int i;
 
    
    
    system("cls");
    
    
    printf("\n\t\t*********************"); 
    printf("\n\t\t*                   *");   
    printf("\n\t\t*      HANGMAN      *");  
    printf("\n\t\t*                   *");  
    printf("\n\t\t*********************");
    printf("\n\t\t                 v_12");
    
    
   printf("\n\n\n Game Rules : "); 
    
   printf("\n\n\t 1.You have to guess the letter of the word one by one.");  
    printf("\n\t 2.You will get 6 wrong chances for every word.");  
    printf("\n\t 3.You can skip a word by typing 'skip' only 3 times.");  
    
    printf("\n\t 4.If you complete 10 words, you'll win.");  
    printf("\n\t 5.If you want to kill the man,just type 'kill' \n\t and game will end. (But your earned score will be 0)");  
    
    
    
    
    printf("\n\n\n\t\t\t Press [..ENTER..]");
            
        getchar();   
    
    
    
    
    
    
    
    
    start:
    
    
   
    srand(time(0));
 
    
    
    
   for(i=1;i<=20;i++) {
        

          
        word_file(i);
    
            
       
 
       if(round==10){
            
       
        system("cls");
          
        printf("\n\n\t\t Yahooo...!!...You win");
        printf("\n\n\t\t Thank you for saving me :) ");
         
    
   if(score==10) {       
  
    printf("\n\n\n");    
    printf("\n\t\t ************************"); 
    printf("\n\t\t *                      *");   
    printf("\n\t\t *    Your SCORE : %d   *",score);  
    printf("\n\t\t *                      *");  
    printf("\n\t\t ************************");   
              
     
     }              
        
            
      else {
                
               
    printf("\n\n\n");    
    printf("\n\t\t ************************"); 
    printf("\n\t\t *                      *");   
    printf("\n\t\t *    Your SCORE : %d    *",score);  
    printf("\n\t\t *                      *");  
    printf("\n\t\t ************************");   
                         
                             
            }      
            
            
            
            
                
                 
        score=0;
            
        printf("\n\n\n\t\t\t Press [..ENTER..]");
            
        getchar();   
            
            break;
     }
        
        if(end==1) {
            
            score=0;
            
         
            break;
        }
    
  }
      
        system("cls");
    
    printf("\n\n\t\t Do you want to play again?(Y/N)");
    printf("\n\n\t\t Type 'Y'..or..'N' : ");
    scanf(" %c",&c); 
  
    getchar();
    
    if(c=='y'||c=='Y') {
        
        end=0;
        round=0;
        skip=3;
        
        goto start;
    }
    
    if(c=='n'||c=='N')  {
        
       
        system("cls");
        
  printf("\n\n\n\t\t Thank you for playing our game");
        
 
    printf("\n\n\n");    
    printf("\n\t\t   *************************");
    printf("\n\t\t   *                       *");    
    printf("\n\t\t   *       Developed       *");   
    printf("\n\t\t   *           by          *");  
    printf("\n\t\t   *     Mehedi & Ashik    *"); 
    printf("\n\t\t   *                       *");     
    printf("\n\t\t   *************************");   
    
    printf("\n\n\n\n");          
         
        return 0;
    }
    
    
    
    
    
  
}

void word_file(int i){
    
    int wi=0;
    char word_list[100][50];
    
    FILE *w;
    


     /* You have to put all text file in the same folder with "Hangman.c" file 
	    
		 --OR--  
		 
		 Copy the file path and write like this way,
		 w=fopen("F:/DEV-C/Hangman/Word_file/1_season.txt","r"); 
		 
	     [NOTE : This is just a example ]
		 
		     */ 
    
    
    switch(i) {
        
        case 1:
        
        w=fopen("1_season.txt","r");
         
        break;
        
         case 2:
        
        w=fopen("2_month.txt","r");
        
        break;
        
        
         case 3:
        
        w=fopen("3_river.txt","r");
        
        break;
        
         case 4:
        
        w=fopen("4_flower.txt","r");
        
        break;
        
        
         case 5:
        
        w=fopen("5_fruits.txt","r");
        
        break;
        
         case 6:
        
        w=fopen("6_sports.txt","r");
        
        break;
        
        case 7:
        
        w=fopen("7_animals.txt","r");
        
        break;
        
         case 8:
        
        w=fopen("8_ethnic.txt","r");
        
        break;
        
        
         case 9:
        
        w=fopen("9_birds.txt","r");
        
        break;
        
         case 10:
        
        w=fopen("10_city.txt","r");
        
        break;        
        
        
                           
             
        
    }
    
    
       if(w==NULL) {
        
       printf("Error....File not opened");
       exit(0);
    }
   
      fscanf(w,"%s",word_list[wi]); 
    
    while(!feof(w)) {
       
        wi++;   
        
        fscanf(w,"%s",word_list[wi]);                  
        
    }
    
    
    fclose(w);
    
    int rand_wrd=1+rand()%wi;
    
   
    
    word(word_list[rand_wrd],word_list[0]);
        
    
}








void word(char wrd[10],char hint[30]) {
    
    int letter=strlen(wrd);
     
    char guess[10];  
    int ltr_gsd[10]= { 0,0,0,0,0,0,0,0,0,0 };  
    
    int correct=0;
    int hold=0; 
    int again;
   
    int live=6;
    int i;
    
    char ltr_enter;
    
    
      
        system("cls");
   
    
    while(correct<letter) {
        
        printf("\n\t\t-------------------------- ");
        
        printf("\n\t\t Round : %d  ||  SCORE : %d  ",round+1,score);
        printf("\n\t\t-------------------------- ");
        //printf("\n");
        printf("\n\t\t Skip_Chances : %d",skip);
        printf("\n\t\t Wrong_Chances : %d\n\n",live);      
        
        
        
        draw(live);
   
              
        printf("\n\n\t\t >> %s << ",hint);
        
        printf("\n\t\t Word : %s ",wrd);   // remove this line during gameplay 
        /* This line will show the actual word in game; Use only for developing the game */
        
        printf("\n\t\t Letter : %d ",letter);
        
        printf("\n\n\t\t");
        
         for(i=0;i<letter;i++) {
            
            if(ltr_gsd[i]==1) {
                
               printf("%c ",wrd[i]);
            }
            
            else {
                
                printf("_ ");
            }
            
        }
        
        
        
        
        printf("\n\n\t\tGuess a letter : ");
     
        
        gets(guess);
    
    if(strncmp(guess,"kill",4)==0||strncmp(guess,"KILL",4)==0) {
            
            end=1;
            
            system("cls");
            
            printf("\n\n\n\n\n");
            
            draw(0);
            
        printf("\n\t\t You killed me");
        printf("\n\n\t\t You will not get any points");
        
        score=0;
                             
        printf("\n\n\t\t Your SCORE : %d",score);
            
        printf("\n\n\n\t\t\t Press [..ENTER..]");
            getchar();
            
            
          
            break;
        }
        
        ltr_enter=guess[0];
        
        
        
        if(ltr_enter>='a' && ltr_enter<='z') {
            
           ltr_enter-=32;
        }
      
               
      if((strncmp(guess,"skip",4)==0||strncmp(guess,"SKIP",4)==0) && skip>0) {
                  
            skip--;
            round++;
            
            
            system("cls");
       
      printf("\n\n\t\t Correct word is : %s",wrd);        
    
      printf("\n\n\t\t You skiped the word");
      printf("\n\t\t You won't get point for this");
    
    
    printf("\n\n\n");    
    printf("\n\t\t ************************"); 
    printf("\n\t\t *                      *");   
    printf("\n\t\t *       SCORE : %d      *",score);  
    printf("\n\t\t *                      *");  
    printf("\n\t\t ************************");        
                
            
            
            
      printf("\n\n\n\t\t You have skip chances : %d",skip);
            
       
            
    
            
              
            
            
        printf("\n\n\n\t\t\t Press [..ENTER..]");
          
          getchar();
                       
               
                break;
            
               } 
        
      
        again=0;
      
        hold=correct;
        
        for(i=0;i<letter;i++) {
            
          if(ltr_gsd[i]==1) {
                
              if(wrd[i]==ltr_enter) {
                    
                    again=1;
                    break;
                    
                }
                  
                continue;
            }
            
            
            
            if(ltr_enter==wrd[i]) {
                
                ltr_gsd[i]=1;   
                correct++;    
                      
            } 
            
                
        } 
        
        
    if((strncmp(guess,"skip",4)==0||strncmp(guess,"SKIP",4)==0) && skip==0)   {
            
     printf("\n\n\n\t\t You don't have any skip chances\n");
    printf("\n\n\t\t\t Press [..ENTER..]");
            
           getchar();
               
            
               } 
      
        
        
         
        else if(hold==correct && again==0){
           
            /* These are the comments whenever player lose a chance */
            
            
             
            live--;
            
            printf("\n\t\t Wrong guess :( ");
            
            
            
            if(live==5) {
        
            printf("\n\n\t\t You lose a chance");
                
                     }
            
            if(live==4) {
        
            printf("\n\n\t\t Try again");
                
                     }
            
             if(live==3) {
        
            printf("\n\n\t\t Think again");     
                  
                     }
            
             if(live==2) {
        
            printf("\n\n\t\t You don't have too many chances ");
           
                     }
            
            if(live==1) {
        
            printf("\n\n\t\t Be Carefull.....!!! ");
            printf("\n\t\t You have only one chance ");
           
                     }
      
            
            printf("\n\n\n\t\t\t Press [..ENTER..]");
            
            getchar();  
            
            
            
                            
            
            if(live==0) {
        
            
             break;
                     }
                          
          
        } 
        
       
        
        
        
        else if(again==1) {
        	
        /* These are the comments whenever player guessed the same letter  */
                             
          printf("\n\n\t\t You have already guessed it.. ");
          printf("\n\n\t\t Try different letter ");       
          printf("\n\n\n\t\t\t Press [..ENTER..]");
            
           getchar();
        }
        
              
    
    
        system("cls");
         
                
    } 
    
    
    if(live==0) {
        
   
        system("cls");
        
        printf("\n\n\n\n\n");
        
        draw(0);
       
         
        printf("\n\t\t I am dead");
        printf("\n\t\t You couldn't save me");
        printf("\n\n\t\t Correct word is : %s",wrd);
        printf("\n\n\n\t\t YOU LOST....!!");
      
        end=1;
        
  
        
    printf("\n\n\n\t\t\t Press [..ENTER..]");
        
        getchar();    
        
        system("cls");
    
    printf("\n\n\n");
    printf("\n\t\t     [...GAME OVER...]     ");
     
    printf("\n\n\n");    
    printf("\n\t\t ************************"); 
    printf("\n\t\t *                      *");   
    printf("\n\t\t *    Your SCORE : %d    *",score);  
    printf("\n\t\t *                      *");  
    printf("\n\t\t ************************");   
        
       printf("\n\n\n\t\t\t Press [..ENTER..]");
        
        getchar();
    }
    
    
      if(letter==correct){
     
        system("cls");
        
        printf("\n\n\t\t Correct...guess...!! \n");
        printf("\n\n\t\t The Word was : %s",wrd);
        score++;
        round++;
        
      
        
   if(round>=1 && round<10) {   
 
    printf("\n\n\n");    
    printf("\n\t\t *********************"); 
    printf("\n\t\t *                   *");   
    printf("\n\t\t *     SCORE : %d     *",score);  
    printf("\n\t\t *                   *");  
    printf("\n\t\t *********************");     
  
       }
          
        /* These are the comments when player proceed to next round */
          
         
        if(round==1) {
       
        printf("\n\n\n\t\t Easy....huh..?? "); 
        printf("\n\t\t Let's try next one..."); 
            
       } 
        
        if(round==2) {
       
        printf("\n\n\n\t\t That's easy too... "); 
        printf("\n\t\t Let's try next word..."); 
            
       } 
        
        
        
        if(round>=3 && round<7) {
            
            
        printf("\n\n\n\t\t You have completed %d words",round); 
        printf("\n\t\t Let's try next one"); 
            
       } 
        
        if(round==7) {
       
        printf("\n\n\n\t\t Next one's not quite easy"); 
        printf("\n\t\t Best of luck "); 
       } 
        
        
        
        if(round==8) {
       
        printf("\n\n\n\t\t Only Two more to win"); 
        printf("\n\t\t Let's try......! "); 
            
       } 
        
        if(round==9) {
       
        printf("\n\n\n\t\t You have one word left"); 
        printf("\n\t\t Let's try last one..."); 
            
       } 
        
        if(round==10) {
       
        printf("\n\n\n\t\t You have completed 10 words"); 
            
       } 
        
        
            
        
        
        
        printf("\n\n\n\n\t\t\t Press [..ENTER..]");
        
        getchar();
        
        
       } 
    

         
}



// These 6 cases draw the man while hanging

void draw(int w) {
    
    
     switch(w) {  
 
 case 6:
            
    printf("\t\t	_____\n");
    printf("\t\t	|   |\n");
    printf("\t\t	    |\n");
    printf("\t\t	    |\n");
    printf("\t\t	    |\n");
    printf("\t\t	    |\n");
    printf("\t\t	   ===\n");

   	break;
            
 	case 5:
            
    	printf("\t\t	_____\n");
    printf("\t\t	|   |\n");
    printf("\t\t       ( )  |\n");
    printf("\t\t	    |\n");
    printf("\t\t	    |\n");
    printf("\t\t	    |\n");
    printf("\t\t	   ===\n");

   	break;
            
 	case 4:
            
	   printf("\t\t	_____\n");
    printf("\t\t	|   |\n");
    printf("\t\t       ( )  |\n");
    printf("\t\t	|   |\n");
    printf("\t\t	|   |\n");
    printf("\t\t	    |\n");
    printf("\t\t	   ===\n");

       	break;
	
	 case 3:
            
    	printf("\t\t	_____\n");
    printf("\t\t	|   |\n");
    printf("\t\t       ( )  |\n");
    printf("\t\t       /|   |\n");
    printf("\t\t	|   |\n");
    printf("\t\t	    |\n");
    printf("\t\t	   ===\n");
 
    break;

  case 2:
           
    	printf("\t\t	_____\n");
    printf("\t\t	|   |\n");
    printf("\t\t       ( )  |\n");
    printf("\t\t       /|\\  |\n");
    printf("\t\t	|   |\n");
    printf("\t\t	    |\n");
    printf("\t\t	   ===\n");
   
    	break;
            
 case 1:
            
	   printf("\t\t	_____\n");
    printf("\t\t	|   |\n");
    printf("\t\t       ( )  |\n");
    printf("\t\t       /|\\  |\n");
    printf("\t\t	|   |\n");
    printf("\t\t       /    |\n");
    printf("\t\t	   ===\n");
    
    	break;
 
 case 0:
            
	   printf("\t\t	_____\n");
    printf("\t\t	|   |\n");
    printf("\t\t        X   |\n");
    printf("\t\t       /|\\  |\n");
    printf("\t\t	|   |\n");
    printf("\t\t       / \\  |\n");
    printf("\t\t	   ===\n");
     
  	break;
}
    
    
    
    
    
}
