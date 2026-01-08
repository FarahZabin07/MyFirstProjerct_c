#include<stdio.h>
#include<string.h>

struct LogIn {
  char name[20];
  char Password[20];
};

struct Cricketer{
 char Name[50];
 int Age;
 int Runs;
 int Wickets;
 int Rating;
};

struct Cricketer Team1[11];
struct Cricketer Team2[11];
struct Cricketer score[2];

void login();
void menu();
void DisplayTeam1();
void DisplayTeam2();
void updateRun(char team);
void youngerPlayer(char team);
void MostRatedPlayerTeam1();
void MostRatedPlayerTeam2();
void ManofTheMatch();

int main() {

login();

FILE *file1;
file1=fopen("Team1.txt","r");
if(file1==NULL){
    printf("Error opening Team1.txt file.\n");
    return 0;
}

for(int i=0;i<11;i++){
    fscanf(file1,"%s %d %d %d",Team1[i].Name, &Team1[i].Age, &Team1[i].Runs, &Team1[i].Wickets);

    int rating=0;
    rating+=Team1[i].Wickets*8;

    if(Team1[i].Runs<20){
        rating+=4;
    }else if(Team1[i].Runs>=20 && Team1[i].Runs<=50){
        rating+=12;
    }else if(Team1[i].Runs>50 && Team1[i].Runs<=75){
        rating+=20;
    }else{
        rating+=24;
    }
    Team1[i].Rating=rating;
}
fclose(file1);

FILE *file2;
file2=fopen("Team2.txt","r");
if(file2==NULL){
    printf("Error opening Team2.txt file.\n");
    return 0;
}

for(int i=0;i<11;i++){
    fscanf(file2,"%s %d %d %d",Team2[i].Name, &Team2[i].Age, &Team2[i].Runs, &Team2[i].Wickets);
    int rating=0;
    rating+=Team2[i].Wickets*8;

    if(Team2[i].Runs<20){
        rating+=4;
    }else if(Team2[i].Runs>=20 && Team2[i].Runs<=50){
        rating+=12;
    }else if(Team2[i].Runs>50 && Team2[i].Runs<=75){
        rating+=20;
    }else{
        rating+=24;
    }
    Team2[i].Rating=rating;
}
fclose(file2);

menu();
return 0;
}

void login(){

struct LogIn log;
char inputname[20];
char inputpassword[20];

FILE *file;
file=fopen("LogIn.txt","r");
if(file==NULL){
    printf("Error opening LogIn.txt file.\n");
}

fscanf(file,"%s %s",log.name, log.Password);
fclose(file);

printf("Enter name: ");
scanf("%s",inputname);
printf("Enter password:");
scanf("%s",inputpassword);

if(strcmp(inputname,log.name)==0 && strcmp(inputpassword,log.Password)==0){
    printf("Login successfully");
}else{
    printf("Invalid information");
}

}

void menu(){

char choice;


  printf("Menu: \n");
  printf("1.Display the Team1�s information along with the rating score.\n");
  printf("2.Display the team2�s information along with the rating score.\n");
  printf("3.Update player's runs.\n");
  printf("4.Display younger player's information.\n");
  printf("5.Display the Most Rated Player among Team1.\n");
  printf("6.Display the Most Rated Player among Team2.\n");
  printf("7.Display the Man of the Match.\n");
  printf("8.Enter (Q/q) to quit. \n");

  do{
    printf("Enter your choice: ");
    scanf("%c",&choice);
    if(choice=='1'){

      DisplayTeam1();

  }else if(choice=='2'){

      DisplayTeam2();

  }else if(choice=='3'){

      updateRun('a');
      updateRun('b');

  }else if(choice=='4'){

      youngerPlayer('a');
      youngerPlayer('b');


  }else if(choice=='5'){

    MostRatedPlayerTeam1();

  }else if(choice=='6'){

      MostRatedPlayerTeam2();

  }else if(choice=='7'){

     ManofTheMatch();

  }else if(choice=='q' || choice=='Q'){

      printf("Thank You!");

  }


  }while(choice!='q' && choice!='Q');


}

void DisplayTeam1(){

 int i;
 printf("Team 1 information: \n");
 printf("Name\tAge\tRuns\tWickets\tRating\n");
 for(i=0;i<11;i++){
    printf("%s\t %d\t %d\t %d\t %d\n",Team1[i].Name,Team1[i].Age,Team1[i].Runs,Team1[i].Wickets,Team1[i].Rating);
 }

}

void DisplayTeam2(){

 int i;
 printf("Team 2 information: \n");
 printf("Name\tAge\tRuns\tWickets\tRating\n");
 for(i=0;i<11;i++){
    printf("%s\t %d\t %d\t %d\t %d\n",Team2[i].Name,Team2[i].Age,Team2[i].Runs,Team2[i].Wickets,Team2[i].Rating);
 }

}

void youngerPlayer(char team){

 int i;
 int youngage=100;
 int index=0;
 printf("Enter choice(a for Team1 & b for Team2): ");
 scanf("%c",&team);
 if(team=='a'){
 for(i=0;i<11;i++){
    if(Team1[i].Age<youngage){
        youngage=Team1[i].Age;
        index=i;
    }
 }
  printf("\nYounger player in Team 1:\n");
  printf("Name:%s  Age:%d  Runs:%d  Wickets:%d  Rating:%d\n",Team1[index].Name,Team1[index].Age,Team1[index].Runs,Team1[index].Wickets,Team1[index].Rating);


 }else if(team=='b'){
 for(i=0;i<11;i++){
    if(Team2[i].Age<youngage){
        youngage=Team2[i].Age;
        index=i;
    }
 }
  printf("\nYounger player in Team 2:\n");
  printf("Name:%s  Age:%d  Runs:%d  Wickets:%d  Rating:%d\n",Team2[index].Name,Team2[index].Age,Team2[index].Runs,Team2[index].Wickets,Team2[index].Rating);
 }
}

void MostRatedPlayerTeam1(){

  int i;
  int mostrate=0;
  int index=0;
  for(i=0;i<11;i++){
    if(Team1[i].Rating>mostrate){
      mostrate=Team1[i].Rating;
      index=i;
    }
  }
    printf("\nThe Most Rated Player among Team1:\n");
     printf("Name:%s  Age:%d  Runs:%d  Wickets:%d  Rating:%d\n",Team1[index].Name,Team1[index].Age,Team1[index].Runs,Team1[index].Wickets,Team1[index].Rating);
    FILE *file3=fopen("score.txt","w");
    if(file3==NULL){
    printf("Error opening score.txt file.\n");
  }
   // fprintf(file3,"The Most Rated Player among Team1:\n");
    fprintf(file3,"%s %d %d %d %d\n",Team1[index].Name,Team1[index].Age,Team1[index].Runs,Team1[index].Wickets,Team1[index].Rating);
    fclose(file3);
}

void MostRatedPlayerTeam2(){

  int i;
  int mostrate=0;
  int index=0;
  for(i=0;i<11;i++){
    if(Team2[i].Rating>mostrate){
      mostrate=Team1[i].Rating;
      index=i;
    }
  }
    printf("\nThe Most Rated Player among Team2:\n");
     printf("Name:%s  Age:%d  Runs:%d  Wickets:%d  Rating:%d\n",Team2[index].Name,Team2[index].Age,Team2[index].Runs,Team2[index].Wickets,Team2[index].Rating);
    FILE *file3=fopen("score.txt","w");
    if(file3==NULL){
    printf("Error opening score.txt file.\n");
  }
    //fprintf(file3,"The Most Rated Player among Team1:\n");
    fprintf(file3,"%s %d %d %d %d\n",Team2[index].Name,Team2[index].Age,Team2[index].Runs,Team2[index].Wickets,Team2[index].Rating);
    fclose(file3);
}

void ManofTheMatch(){


FILE *file3=fopen("score.txt","r");
    if(file3==NULL){
    printf("Error opening score.txt file.\n");
  }

int motm=0;
int i;
int index=0;


for(int i=0;i<2;i++){
    fscanf(file3,"%s %d %d %d",score[i].Name, &score[i].Age, &score[i].Runs, &score[i].Wickets,&score[i].Rating);
    if(score[i].Rating>0){
    motm=score[i].Rating;
    index=i;
    }
}
printf("The Man of The Match is %s ",score[index].Name);
}

void updateRun(char team){
    int i;
    char playername[20];
    int run;
   printf("Enter choice(a for Team1 & b for Team2): ");
 scanf("%c",&team);
if(team=='a'){
    printf("Enter player's name: ");
    scanf("%s", playername);
    for(i=0;i<11;i++){
    if(strcmp(Team1[i].Name,playername)==0){
        printf("Enter updated runs: ");
            scanf("%d", &run);
    Team1[i].Runs=Team1[i].Runs+run;
    if(Team1[i].Runs<20){
       Team1[i].Rating+=4;
    }else if(Team1[i].Runs>=20 && Team1[i].Runs<=50){
        Team1[i].Rating+=12;
    }else if(Team1[i].Runs>50 && Team1[i].Runs<=75){
        Team1[i].Rating+=20;
    }else{
        Team1[i].Rating+=24;
    }
    }
}
}
if(team=='b'){
    printf("Enter player's name: ");
    scanf("%s", playername);
    for(i=0;i<11;i++){
    if(strcmp(Team2[i].Name,playername)==0){
        printf("Enter updated runs: ");
            scanf("%d", &run);
    Team2[i].Runs=Team2[i].Runs+run;
    if(Team2[i].Runs<20){
       Team2[i].Rating+=4;
    }else if(Team2[i].Runs>=20 && Team2[i].Runs<=50){
        Team2[i].Rating+=12;
    }else if(Team2[i].Runs>50 && Team2[i].Runs<=75){
        Team2[i].Rating+=20;
    }else{
        Team2[i].Rating+=24;
    }
    }
}
}
}
