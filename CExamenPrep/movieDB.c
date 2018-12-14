#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	int hours;
	int minutes;
}time;
typedef struct 
{
	char title[20];
	int relese_year;
	float imdb_rate;
	time duration; 
}movie;

int database_add(char *moviestxt_filename, char *database_filename)
{
	FILE *txt = fopen(moviestxt_filename,"r");
	FILE *bin = fopen(database_filename,"wb");
	if(bin == NULL) { printf("Binary file open error\n"); return 0;}
	if(txt == NULL) {printf("txt file open error\n"); return 0;}
	movie m; int i=1;
	while(1)
	{
		fscanf(txt,"%s",&m.title);
		fscanf(txt,"%d",&m.relese_year);
		fscanf(txt,"%f",&m.imdb_rate);
		fscanf(txt,"%d",&m.duration.hours);
		fscanf(txt,"%d",&m.duration.minutes);
		fseek(bin, 0 , SEEK_END);
		fwrite(&m, sizeof(m), 1, bin); 
		if(fwrite == NULL) printf("NUBUN\n");
		if(feof(txt)) break;
		
	} 
	fclose(bin);
	return 1;
}
int*  database_read(char *database_filename)
{
	FILE *bin = fopen(database_filename,"rb");
	if(bin == NULL){printf("Binary file open error\n"); return 0;}
	fseek(bin, 0, SEEK_END);
	int size = ftell(bin); //Here I get the wrong size
	printf("%d\n",size); 

	rewind(bin);
	movie *movie_list;
	int movie_count = (size / sizeof(movie))+1;
	movie_list = malloc(movie_count * sizeof(movie));
	fread(movie_list,sizeof(movie),movie_count,bin);
	printf("%s\n",movie_list[3].title);
	
}
int main()
{	
	movie *v;
	database_add("movies.txt","db");
	database_read("db");
	return 0;
}