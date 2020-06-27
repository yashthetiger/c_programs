#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<winbase.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
FILE *fnew;
HANDLE rHnd, wHnd;
//int current,extrarunsA,extrarunsB,bowlingcurrent,wicketnumber,teamAtotalruns=0,teamBtotalruns=0,teamAtotalovers=0,teamBtotalovers=0;
char input;
FILE *newfile,*filelist;
char filenamewithdirectory[50];//to pass the filename with its directory location//
char output[100];

//List of functions used//
int initializeconsolehandles();//for initializing handles//
void file();//for file IO//
void locate(int,int);//for locating the cursor position//
void tab1(); //for updating the game records//
void tab2();//for how out input//
void tab3();//for new bowler input//
void tab4();//for new batsbaninput//
void tab5();//for end of innings//
void date();//for storing todays date//
/*void timestart();//for  timestart input//
void timestop();//for timestop input//*/

//data structures used in the program//
struct team//for the record of batting team//
{
    char timein[9];
    char timeout[9];
    char batsmanname[50];
    int _4s;
    int _6s;
    int ballsfaced;
    char timeplayed[9];
    char howout[20];
    char fielder[30];
    char bowler[30];
    int totalruns;
    int mtsplayed;
} teamA[11],teamB[11];

struct bowlingteam//for the record of bowling team//
{
    char bowler[30];
    int ballthrownincurrentover;
    int overs;
    int maidens;
    int runs;
    int wickets;
    int noballs;
    int wides;
    float average;
} bowlingteamA[8],bowlingteamB[8];

struct gamedetails//for the records of game details//
{
    char competition[20];
    char playedAt[50];
    char venue[30];
    char matchbetween[30];
    char versus[30];
    char tosswonby[30];
    char electedto[20];
    int inningsof;
    char date[30];
    char input;
    int overs;
} gamedetailA,gamedetailB;

struct wickets
{
    int atruns;
    int overnumber;
} wicketsA[8],wicketsB[8];


struct undo
{
    struct team teamArecord[11];
    struct team teamBrecord[11];
    struct bowlingteam bowlingteamArecord[8];
    struct bowlingteam bowlingteamBrecord[8];
    struct wickets wicketsArecord[8];
    struct wickets wicketsBrecord[8];
} steps[10];

void welcome()
{
    system("color f1");
    int i,y;
    locate(26,5);
    printf(" _ _ _ _ _ _ _ _ _ _  _ _ _ _ ");
    locate(27,7);
    printf("*****************************");
    locate(27,9);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3);
    locate(27,11);
    printf(" %c%c%c!!! YOU ARE WELCOME !!!%c%c%c",2,2,2,2,2,2);
    locate(39,13);
    printf("TO");
    locate(27,15);
    printf(" %c%c%c%c Cricket score sheet %c%c%c%c",3,3,3,3,3,3,3,3);
    locate(27,17);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%",3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3);
    locate(27,19);
    printf("*****************************");
    locate(27,21);
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
    Sleep(250);
    locate(27,23);
    Sleep(250);
    locate(27,25);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE );
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE );
    locate(27,29);
    for(y=35;y<=58;y++)
    {
    	locate(27,y);
    	Sleep(400);
    }
    printf("\n");
	system("color ff");
}

void menu()
{
    printf("\n\n\t\t\t\t\tMENU:\n");
    printf("\n\n\n\t\t\t\t1.New scoresheet:\n");
    printf("\t\t\t\t2.View scoresheet:\n");
    printf("\t\t\t\t3.Exit:\n\t\t");
}

void printt()
{

    int j,l,i;
    locate(0,0);
    printf("%ccompetition:%s",179,gamedetailA.competition);
    locate(35,0);
    printf("%cVenue:%s",179,gamedetailA.venue);
    locate(0,1);
    for(i=0; i<79; i++)
        printf("%c",205);
    locate(0,2);
    printf("%cMatch Between:%s",179,gamedetailA.matchbetween);
    locate(35,2);
    printf("%cVersus:%s",179,gamedetailA.versus);
    locate(0,3);
    for(i=0; i<79; i++)
        printf("%c",205);
    locate(0,4);
    printf("%cToss won by:%s",179,gamedetailA.tosswonby);
    locate(35,4);
    printf("%cElected To:%s",179,gamedetailA.electedto);
    locate(0,5);
    for(i=0; i<79; i++)
        printf("%c",205);
    locate(35,0);
    for (i=0; i<33; i++)
    {
        locate(34,i);
        printf("%c",182);
    }
    locate(0,6);
    printf("%cInning Of:%d",179,gamedetailA.inningsof);
    locate(35,6);
    printf("%cDate:%s",179,gamedetailA.date);
    locate(0,7);
    for(i=0; i<79; i++)
        printf("%c",205);
    locate(0,21);
    for(i=0; i<79; i++)
        printf("%c",205);
    locate(0,9);
    for(i=0; i<79; i++)
        printf("%c",205);
    locate(5,8);
    printf("Batsmanname");
    locate(0,10);
    for(i=0; i<11; i++)
        printf("%cBatsman %d:%s\n",179,i+1,teamA[i].batsmanname);
    locate(36,8);
    printf("%cTotoal runs",179);
    for(i=0; i<11; i++)
    {
        locate(40,9+(i+1));
        printf("%d\n",teamA[i].totalruns);
    }

    locate(5,22);
    printf("Bowlers");
    locate(0,23);
    for (i=0; i<79; i++)
        printf("%c",205);
    for(i=0; i<8; i++)
    {
        locate(0,23+(i+1));
        printf("%cBowler %d:%s\n",179,i+1,teamA[i].bowler);
    }

    locate(35,22);
    printf("overs");
    locate(42,22);
    printf("Maidens");
    locate(50,22);
    printf("Economy");
    locate(58,22);
    printf("No balls");
    locate(68,22);
    printf("BTICO");
    locate(75,22);
    printf("Runs");
    locate(62,8);
    printf("_4s");
    locate(72,8);
    printf("_6s");
    locate(0,32);
    for (i=0; i<79; i++)
        printf("%c",205);
    locate(61,10);
    for(i=0; i<11; i++)
    {
        printf("%c",179);
        locate(61,10+(i+1));
    }
    locate(63,9);
    for(i=0;i<11;i++)
    {
        locate(63,9+(i+1));
    printf("%d",teamA[i]._4s);
    }
    locate(73,9);
    for(i=0;i<11;i++)
    {
        locate(73,9+(i+1));
    printf("%d",teamA[i]._6s);
    }
    locate(71,10);
    for(i=0; i<11; i++)
    {
        printf("%c",179);
        locate(71,10+(i+1));
    }
    locate(49,10);
    for(i=0; i<11; i++)
    {
        printf("%c",179);
        locate(49,10+(i+1));
    }
    locate(38,23);
    for(i=0; i<8; i++)
    {
        locate(38,23+(i+1));
        printf("%d\n",bowlingteamA[i].overs);
    }
    locate(47,23);
    for(i=0; i<8; i++)
    {
        locate(47,23+(i+1));
        printf("%d\n",bowlingteamA[i].maidens);
    }
    locate(55,23);
    for(i=0; i<8; i++)
    {
        locate(55,23+(i+1));
        printf("%.2f\n",bowlingteamA[i].average);
    }
    locate(62,23);
    for(i=0; i<8; i++)
    {
        locate(62,23+(i+1));
        printf("%d\n",bowlingteamA[i].noballs);
    }
    locate(70,23);
    for(i=0; i<8; i++)
    {
        locate(70,23+(i+1));
        printf("%d\n",bowlingteamA[i].ballthrownincurrentover);
    }
    locate(78,23);
    for(i=0; i<8; i++)
    {
        locate(78,23+(i+1));
        printf("%d\n",bowlingteamA[i].runs);
    }
    locate(0,40);
    for(i=0;i<79;i++)
    {
        printf("%c",205);
    }

}

void final()//Function to give the input//
{
    int a,key;
    char b;
    char lastinput;
    input='0';
    while(input!=27)//to end the input loop//
    {
        printt();
        while(1)
        {
             locate(0,33);
                printf("Enter runs made |1|2|3|4|5|6|");
                locate(30,33);
           // locate(40,33);
            fflush(stdin);
            if ((input=getche()) == -32)//for arrow key switching//
                input = getche();

            fflush(stdin);
            if(input==75||input==77)
            {
                printf("\b  ");
                if(input==75);
                    //tab5();
                else
                    tab2();
            }
            else  if(input=='\b')
            {
                printf("  ");
                continue;
            }
            else if (input == '\r')//processes the input only when pressed enter//
            {
                input=toupper(lastinput);
                // undoupdate();//excluded in the output//
                tab1();
                break;
            }
            else    if (input=='0'||input=='1'||input=='2'||input=='3'||input=='4'||input=='6'||toupper(input)=='W'||toupper(input)=='N')
                lastinput = input;
            else if(input==27)
            {
                printf("\b ");
                break;
            }
            else
                printf("\a\b ");
            continue;
        }
    }

}

void filewrite()
{
    fwrite(&gamedetailA,sizeof(gamedetailA),1,newfile);
    fwrite(&teamA,sizeof(teamA),11,newfile);
    fwrite(&bowlingteamA,sizeof(bowlingteamA),8,newfile);

}

void limitinput(int n)
{
    int i,j;
    char array[100];
    for(i=0;; i++)
    {
        if(i>=n)
            array[i]=getch();
        else
            array[i]=getche();
        if(array[i]=='\b')
        {
            if(i>(n-1))
                printf("\b \b");
            else
                printf(" \b");
            if(i>=n)
                i=n-1-1;
            else
            {
                for(j=1;; j++)
                {
                    if(i==n-j)
                    {
                        if(i==0)
                            i=-1;
                        else
                            i=n-(j+1)-1;
                        break;
                    }
                }
            }
        }
        if(array[i]=='\r')
            break;
    }
    int number=0;
    for(i=0; i!=n; i++)
    {
        if(array[i]=='\r')
        {
            output[i]='\0';
            break;
        }
        output[i]=array[i];
    }
}
int limitedinput(int n)
{
    int a,i,j,array[100];
start:
locate(11,6);
    for(i=0;; i++)
    {
        if(i>=n)
            array[i]=getch();
        else
            array[i]=getche();
        if(array[i]=='\b')
        {
            if(i>(n-1))
                printf("\b \b");
            else
                printf(" \b");
            if(i>=n)
                i=n-1-1;
            else
            {
                for(j=1;; j++)
                {
                    if(i==n-j)
                    {
                        if(i==0)
                            i=-1;
                        else
                            i=n-(j+1)-1;
                        break;
                    }
                }
            }
        }
        if(array[i]=='\r')
            break;
    }
    int number=0;
    for(i=0; i!=n; i++)
    {
        if(array[i]=='\r')
            break;
        if(isdigit(array[i])!=0)
        {
            (int) array[i];
            number=number*10+(array[i]-48);
        }
        else
        {
            locate(15,6);
            printf("  Invalid input.");
            goto start;
        }
    }
    locate(15,6);
    printf("                  ");
    return number;
}

FILE *newfile,*filelist;
char filenamewithdirectory[50];//to pass the filename with its directory location//
char output[100];
void newscoresheet()
{
    system("color f4");
    int j,ln,number;
    char text[50],ch;
    system("cls");
    locate(20,8);
    char filename[20],array[100];
    char extension[]=".txt";
    char filenamewithdirectory[]="Files//";
    char filenamecheck[20];
    char filenamecheckvar;
    int i=0,flag=1,n=15;
    system("cls");
    initializeconsolehandles();
    printt();
    flag=0;
    while(1)
    {
        if(flag==0)
        {
            fflush(stdin);
            locate(13,0);
            fflush(stdin);
            limitinput(n);
            strcpy(output,gamedetailA.competition);
            flag=1;
            n=20;
        }
        if (flag==1)
        {
            locate(42,0);
            limitinput(n);
            strcpy(output,gamedetailA.venue);
            fflush(stdin);
            flag=2;
            n=10;
        }
        if(flag==2)
        {
            locate(15,2);
            limitinput(n);
            strcpy(output,gamedetailA.matchbetween);
            fflush(stdin);
            flag=3;
            n=10;
        }
        if(flag==3)
        {
            locate(44,2);
            limitinput(n);
            strcpy(output,gamedetailA.versus);
            fflush(stdin);
            flag=4;
            n=10;
        }
        if(flag==4)
        {
            locate(13,4);
            limitinput(n);
            strcpy(output,gamedetailA.tosswonby);
            fflush(stdin);
            flag=5;
            n=7;
        }
        if(flag==5)
        {
            locate(47,4);
            limitinput(n);
            strcpy(output,gamedetailA.electedto);
            fflush(stdin);
            flag=6;
            n=3;
        }
        if(flag==6)
        {
            locate(11,6);
            number=limitedinput(n);
            gamedetailA.inningsof=number;
            fflush(stdin);
            flag=7;
            n=10;
        }
        if(flag==7)
        {
            locate(53,6);
            printf(" T to enter today's date");
            locate(43,6);
            limitinput(n);
            if(output[0]=='t'||output[0]=='T')
            {
                date();
                locate(43,6);
                printf("         %s              ",gamedetailA.date);
            }
            else
            {
                strcpy(gamedetailA.date,output);
                locate(43,6);
                if(strlen(gamedetailA.date)<2)
                printf("                                       ");
                else
                printf("         %s                  ",gamedetailA.date);

            }
            fflush(stdin);
            flag=8;
            n=15;
        }
        if(flag==8)
        {
            locate(12,10);
            for (i=0; i<11; i++)
            {
                limitinput(n);
                strcpy(teamA[i].batsmanname,output);
                locate(12,11+i);
            }
            flag=9;
        }
        if(flag==9)
        {
            locate(12,24);
            for (i=0; i<8; i++)
            {
                limitinput(n);
                strcpy(teamA[i].bowler,output);
                locate(12,25+i);
            }
            flag=80;
        }
        if (flag==80)
        {
            locate(36,33);
            skip:
            printf("Enter e to edit or c to continue");
            ch=getch();
            if(ch=='e'||ch=='E')
            {
                flag=0;
                 locate(36,33);
                printf("                                                                                                    ");

            }
            else if(ch=='c'||ch=='C')
            {
                locate(36,33);
                printf("                                                                                                    ");
                locate(14,20);
                final();
                filewrite();
            }
            else
            {
              locate(36,33);
               printf("                                                                                                    ");
                flag=80;
            }
        }
    }
}

void fileopen(char ch1)
{
    int j,ln;
    char text[50],ch;
    system("cls");
    locate(20,8);
    char filename[20],array[50];
    char extension[]=".txt";
    char filenamewithdirectory[]="Files//";
    char filenamecheck[20];
    char filenamecheckvar;
    int i=0,flag=1,n=15;
    if(ch1=='1')
    {
        filelist=fopen("Files//filelist.txt","a+");
        if(filelist==NULL)
        {
            printf(" File Listing Error...");
            exit(1);
        }
        while(flag==1)
        {
            if (flag==1)
            {
                printf("\nPlease enter the new file name:");
                scanf(" %[^\n]",filename);
                i=0;
            }
            rewind(filelist);
            while(filenamecheckvar!=EOF)
            {
                filenamecheckvar=fgetc(filelist);
                filenamecheck[i]=filenamecheckvar;
                if(filenamecheckvar=='\n')
                {
                    filenamecheck[i]='\0';
                    i=-1;
                    if(strcmp(filenamecheck,filename)==0)
                    {
                        printf("Filename already exists.Please give new filename:");
                        flag=1;
                        break;
                    }
                }
                i++;
                flag=0;
            }
        }
        fseek(filelist,0,SEEK_END);
        fprintf(filelist,"%s",filename);
        fprintf(filelist,"\n");
        fclose(filelist);
        strcat(filename,extension);
        strcat(filenamewithdirectory,filename);
        newfile=fopen(filenamewithdirectory,"w");
        if(newfile==NULL)
            printf("Error...");
        printf("Creating file...\n");
        Sleep(3000);
        printf("File Created.");
        Sleep(1000);
        newscoresheet();
    }
    if(ch1=='2')
    {
        printf("Enter the name of the existing file to open");
        scanf(" %[^\n]",filename);
        strcat(filename,extension);
        strcat(filenamewithdirectory,filename);
        newfile=fopen(filenamewithdirectory,"r");
        if(newfile==NULL)
        {
            system("cls");
            printf("Error...no such existing file");
            exit(0);
        }
        system("cls");
        fread(&gamedetailA,sizeof(gamedetailA),1,newfile);
        fread(&teamA,sizeof(teamA),11,newfile);
        fread(&bowlingteamA,sizeof(bowlingteamA),8,newfile);
        printt();
        getch();
        system("cls");
        main();
    }

}

void date ( )
{
    time_t now;
    struct tm *tm_now;
    char buff[BUFSIZ];
    now = time ( NULL );
    tm_now = localtime ( &now );
    strftime ( buff, sizeof buff, "%a %d %m %Y", tm_now );
    strcpy(gamedetailA.date,buff);

}

void filing()
{
    system("cls");
    locate(20,8);
    FILE *newfile,*filelist;
    char filename[20];
    char extension[]=".dat";
    char filenamewithdirectory[]="Files//";
    char filenamecheck[20];
    char filenamecheckvar;
    int i=0,flag=1;
    filelist=fopen("Files//filelist.txt","a+");
    if(filelist==NULL)
    {
        printf(" File Listing Error...");
        exit(1);
    }
    while(flag==1)
    {
        if (flag==1)
        {
            printf("\nPlease enter the new file name:");
            scanf(" %[^\n]",filename);
            i=0;
        }
        rewind(filelist);
        while(filenamecheckvar!=EOF)
        {
            filenamecheckvar=fgetc(filelist);
            filenamecheck[i]=filenamecheckvar;
            if(filenamecheckvar=='\n')
            {
                filenamecheck[i]='\0';
                i=-1;
                if(strcmp(filenamecheck,filename)==0)
                {
                    printf("Filename already exists.Please give new filename:");
                    flag=1;
                    break;
                }
            }
            i++;
            flag=0;
        }
    }
    fseek(filelist,0,SEEK_END);
    fprintf(filelist,"%s",filename);
    fprintf(filelist,"\n");
    fclose(filelist);
    strcat(filename,extension);
    strcat(filenamewithdirectory,filename);
    strcpy(file,filenamewithdirectory);
    newfile=fopen(filenamewithdirectory,"w");
    if(newfile==NULL)
    {
        printf("File opening Error...");
    	exit(1);
    }
    printf("Creating file...\n");
    Sleep(3000);
    printf("File Created.");
    Sleep(1000); 
} 

int initializeconsolehandles();
void locate(int,int);
void print();
void initialize();
int runsinoneover[50],runsinprevover=0,flagg=0;
int position=1,undoupdatevariable=0,newbatsmancounter[11],newbatsmanincrement=0,current,extrarunsA,extrarunsB,bowlingcurrent,wicketnumber,teamAtotalruns=0,teamBtotalruns=0,teamAtotalovers=0,teamBtotalovers=0;



void tab1()
{
    int calledfromwide=0,T;
    char a;

start:
    if(input=='0')
    {
        if(calledfromwide==1)
        {
            teamA[current].totalruns=0;
            extrarunsA+=0;
        }
        else
        {
            teamA[current].ballsfaced++;
            bowlingteamA[bowlingcurrent].ballthrownincurrentover++;
            if(bowlingteamA[bowlingcurrent].ballthrownincurrentover==6)
            {
                bowlingteamA[bowlingcurrent].overs++;
                bowlingteamA[bowlingcurrent].ballthrownincurrentover=0;
                ovatglance(bowlingteamA[bowlingcurrent].overs,teamA[current].totalruns);
            }
        }
    }
    if(input=='1')
    {
        if(calledfromwide==1)
        {
            bowlingteamA[bowlingcurrent].runs+=1;
            teamA[current].totalruns++;
            extrarunsA+=1;
        }
        else
        {
            bowlingteamA[bowlingcurrent].runs+=1;
            teamA[current].totalruns+=1;
            teamA[current].ballsfaced++;
            bowlingteamA[bowlingcurrent].ballthrownincurrentover++;
            if(bowlingteamA[bowlingcurrent].ballthrownincurrentover==6)
            {
                bowlingteamA[bowlingcurrent].overs++;
                bowlingteamA[bowlingcurrent].ballthrownincurrentover=0;
                ovatglance(bowlingteamA[bowlingcurrent].overs,teamA[current].totalruns);
            }
        }
    }
    if(input=='2')
    {
        if(calledfromwide==1)
        {
            bowlingteamA[bowlingcurrent].runs+=2;
            teamA[current].totalruns+=2;
            extrarunsA+=2;
        }
        else
        {
            bowlingteamA[bowlingcurrent].runs+=2;
            teamA[current].totalruns+=2;
            teamA[current].ballsfaced++;
            bowlingteamA[bowlingcurrent].ballthrownincurrentover++;
            if(bowlingteamA[bowlingcurrent].ballthrownincurrentover==6)
            {
                bowlingteamA[bowlingcurrent].overs++;
                bowlingteamA[bowlingcurrent].ballthrownincurrentover=0;
                ovatglance(bowlingteamA[bowlingcurrent].overs,teamA[current].totalruns);
            }
        }
    }
    if(input=='3')
    {
        if(calledfromwide==1)
        {
            bowlingteamA[bowlingcurrent].runs+=3;
            teamA[current].totalruns+=3;
            extrarunsA+=3;
        }
        else
        {
            bowlingteamA[bowlingcurrent].runs+=3;
            teamA[current].totalruns+=3;
            teamA[current].ballsfaced++;
            bowlingteamA[bowlingcurrent].ballthrownincurrentover++;
            if(bowlingteamA[bowlingcurrent].ballthrownincurrentover==6)
            {
                bowlingteamA[bowlingcurrent].overs++;
                bowlingteamA[bowlingcurrent].ballthrownincurrentover=0;
                ovatglance(bowlingteamA[bowlingcurrent].overs,teamA[current].totalruns);
            }
        }
    }
    if(input=='4')
    {
        if(calledfromwide==1)
        {
            bowlingteamA[bowlingcurrent].runs+=4;
            teamA[current].totalruns+=4;
            extrarunsA+=4;
            teamA[current]._4s++;
        }
        else
        {
            bowlingteamA[bowlingcurrent].runs+=4;
            teamA[current].totalruns+=4;
            teamA[current].ballsfaced++;
            teamA[current]._4s++;
            bowlingteamA[bowlingcurrent].ballthrownincurrentover++;
            if(bowlingteamA[bowlingcurrent].ballthrownincurrentover==6)
            {
                bowlingteamA[bowlingcurrent].overs++;
                bowlingteamA[bowlingcurrent].ballthrownincurrentover=0;
                ovatglance(bowlingteamA[bowlingcurrent].overs,teamA[current].totalruns);
            }
        }
    }
    if(input=='6')
    {
        if(calledfromwide==1)
        {
            bowlingteamA[bowlingcurrent].runs+=6;
            teamA[current].totalruns+=6;
            extrarunsA+=6;
            teamA[current]._6s++;
        }
        else
        {
            bowlingteamA[bowlingcurrent].runs+=6;
            teamA[current].totalruns+=6;
            teamA[current].ballsfaced++;
            teamA[current]._6s++;
            bowlingteamA[bowlingcurrent].ballthrownincurrentover++;
            if(bowlingteamA[bowlingcurrent].ballthrownincurrentover==6)
            {
                bowlingteamA[bowlingcurrent].overs++;
                bowlingteamA[bowlingcurrent].ballthrownincurrentover=0;
                ovatglance(bowlingteamA[bowlingcurrent].overs,teamA[current].totalruns);
            }
        }
    }
    if(input=='N')//for noballs
    {
        bowlingteamA[bowlingcurrent].runs+=1;
        bowlingteamA[bowlingcurrent].noballs++;
        teamA[current].totalruns++;
        calledfromwide=1;
        locate(0,34);
        printf("Enter the runs made:0/1/2/3/4/6");
        T=0;
        while(T==0)
        {
            scanf(" %c",&input);
            if(input=='0'||input=='1'||input=='2'||input=='3'||input=='4'||input=='5'||input=='6')
            {
                T=1;
                goto start;
            }
            else
            {
                T=0;
                printf("Invalid Input.Input:0/1/2/3/4/6");
            }
        }
    }
    if(input=='W')//for noballs
    {
        bowlingteamA[bowlingcurrent].runs+=1;
        bowlingteamA[bowlingcurrent].wides++;
        teamA[current].totalruns++;
        calledfromwide=1;
        locate(0,34);
        printf("Enter the runs made:0/1/2/3/4/6:");
        T=0;
        while(T==0)
        {
            scanf(" %c",&input);
            if(input=='0'||input=='1'||input=='2'||input=='3'||input=='4'||input=='5'||input=='6')
            {
                T=1;
                goto start;
            }
            else
            {
                T=0;
                locate(0,34);
                printf("Invalid Input.Input:0/1/2/3/4/6 :");
            }
        }
    }

    float overs=bowlingteamA[bowlingcurrent].overs+((bowlingteamA[bowlingcurrent].ballthrownincurrentover)/6.);
   // if(overs==0&&bowlingteamA[bowlingcurrent].ballthrownincurrentover==0)
  //      bowlingteamA[bowlingcurrent].average=0;
  //  else
        bowlingteamA[bowlingcurrent].average=
            bowlingteamA[bowlingcurrent].runs/overs;
    calledfromwide=0;

}

void tab2()
{
    int a;

    while(1)
    {
    locate(28,34);
    printf("How out?");
    locate(28,35);
    printf("Fielding='F'");
    locate(28,36);
    printf("Catch-Out='C'");
    locate(28,37);
    printf("Wicket='W'");
    locate(28,33);
    char temp;

        fflush(stdin);
        if ((input = getche()) == -32)
            input = getche();
        fflush(stdin);
        if(input==75||input==77)
        {
            printf("\b ");
            locate(28,34);
            printf("           ");
            locate(28,35);
            printf("              ");
            locate(28,36);
            printf("               ");
            locate(28,37);
            printf("                ");
            locate(28,33);
            if(input==77)
            {
                tab3();
                //return ;
            }
            else if(input==75)
            {
                fflush(stdin);
                return;

            }
        }
        else  if(input=='\b')
        {
            printf("  ");
            continue;
        }
        else if (input == '\r')
        {
            input=toupper(temp);
            break;
        }

        else if(input=='F'||input=='C'||input=='W'||input=='f'||input=='c'||input=='w')
        {
            temp=input;
            continue;
        }
        else
        {
            printf("\a\b\b  \b");
        }
    }
    locate(28,34);
    printf("           ");
    locate(28,35);
    printf("              ");
    locate(28,36);
    printf("               ");
    locate(28,37);
    printf("                ");
    input=toupper(input);
    if(toupper(input)=='W')
    {
        strcpy(teamA[current].howout,"Wicket");
        wicketnumber++;
        wicketsA[wicketnumber].atruns = teamAtotalruns;
        wicketsA[wicketnumber].overnumber = teamAtotalovers+1;
        locate(28,34);
        printf("Enter the fielder's name:");
        gets(teamA[current].fielder);
        locate(28,34);
        printf("                                     ");
        tab4();
    }
    if(toupper(input)=='C')
    {
        strcpy(teamA[current].howout,"Catchout");
        wicketnumber++;
        wicketsA[wicketnumber].atruns = teamAtotalruns;
        wicketsA[wicketnumber].overnumber = teamAtotalovers+1;
        locate(28,34);
        printf("Enter the fielder's name:");
        gets(teamA[current].fielder);
        locate(28,34);
        printf("                                     ");
        tab4();
    }
    if(toupper(input)=='F')
    {
        strcpy(teamA[current].howout,"Fielding");
        wicketnumber++;
        tab1(input);
        wicketsA[wicketnumber].atruns = teamAtotalruns;
        wicketsA[wicketnumber].overnumber = teamAtotalovers+1;
        locate(28,34);
        printf("Enter the fielder's name:");
        gets(teamA[current].fielder);
        locate(28,34);
        printf("                                     ");
        tab4();
    }
}

void tab3()
{
    while(1)
    {

    char temp;
    fflush(stdin);
    locate(37,34);
    printf("Select the bowler no.");
        fflush(stdin);
        locate(37,33);
        if ((input=getche()) ==-32)
            input = getche();
        fflush(stdin);
        if(input==75||input==77)
        {
            printf("\b ");
            locate(37,34);
            printf("                       ");
            if(input==75)
                //tab2();
                return;
            if (input==77)
                tab4();
        }
        else  if(input=='\b')
        {
            printf("  ");
            continue;
        }
        else if (input == '\r')
        {
            input=temp;
            break;
        }
        else if(input=='1'||input=='2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8')
        {
            temp=input;
            continue;
        }
        else
        {
            printf("\a\b\b  \b");
        }
    }
    bowlingcurrent = input-49;
    locate(37,33);
    printf("   ");
    locate(37,34);
    printf("                                      ");
    return;
}

void tab4()
{
    int currentinput = -1,number = 0;
    fflush(stdin);

    while (1){
    locate(52,34);
    printf("Select the new ");
    locate(52,35);
    printf("batsman no.from ");
    locate(52,36);
    printf("above list.");
    if (currentinput == -1) locate(52,33) ; else locate (53,33);
    if ((input=getch()) == -32)
        input = getch();
    fflush(stdin);

    if(input==75||input==77)
    {
        printf("\b\b   ");
        locate(52,34);
        printf("                 ");
        locate(52,35);
        printf("                 ");
        locate(52,36);
        printf("              ");
        if(input==75)
            //tab3();
            return;
        if (input==77)
        {
            tab5();
            //return;
        }
    }
    else if(input >= '0' && input <='9' && number !=1)

    {
            if (currentinput == -1)
            {
                    printf ("%c",input);
                    currentinput= input - '0';
                    currentinput *= 10;
            }
            else{
                if ((currentinput <10) || ( (input =='0' || input == '1') && currentinput>9))
                {printf ("%c",input);
                                currentinput += input - '0';
                number = 1;     //Two numbers entered
            }}
    }


    else if (input == '\b')
    {
        if (number ==1 )printf ("\b  \b\b"); else printf ("\b \b");
        currentinput = -1;
        number = 0;
    }
    else if (input == '\r')
    {current=currentinput -1;
    //printf("%d",current);
    fflush(stdin);

    }
    }
}
void tab5()
{
    while(1)
    {

    char ch;
    fflush(stdin);
    locate(68,34);
    printf("Do you want ");
    locate(68,35);
    printf("to  end the ");
    locate(68,36);
    printf("inning?");
        locate(68,33);
        if ((input=getch()) == -32)
            input = getch();
        ch=input;
        fflush(stdin);
        if(input==75||input==77)
        {
            printf("\b ");
            locate(68,34);
            printf("             ");
            locate(68,35);
            printf("              ");
            locate(68,36);
            printf("            ");
            if(input==75)
                //tab4();
                return;
            if (input==77)
            {
                fflush(stdin);
                //tab1();
                //return;
            }
        }
        if(toupper(input)=='Y')
        {
            locate(68,34);
            printf("             ");
            locate(68,35);
            printf("              ");
            locate(68,36);
            printf("            ");
            return;
        }
        else
            printf("\a\b ");
    }
    fflush(stdin);
    return;
}

int initializeconsolehandles()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    if (rHnd && wHnd)
        return TRUE;
    else
        return FALSE;
}

void locate(int x, int y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition (wHnd,pos);

}

int ovatglance(int overs,int runs)
{

    int i=1;
    runsinoneover[overs]=runs-runsinprevover;
    runsinprevover=runs;
    if(runsinoneover[overs]==0)
        bowlingteamA[bowlingcurrent].maidens++;
    return;
}
	           
int main()
{
    system("color f1");
    int a,key;
    char b,ch;
    FILE *fnew;

    char lastinput;
    while (TRUE)
    {
        initializeconsolehandles();
        welcome();
        system("cls");
        menu();
        locate(32,9);
        ch=getch();
        switch(ch)
        {
            case '1':
            fileopen(ch);
            case '2':
            fileopen(ch);
            getch();
            case '3':
            system ("cls");
            exit(0);
        }
    }
}

