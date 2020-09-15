#include <stdio.h>
#include <fcntl.h>
#include <string.h> 
#include <unistd.h> 
#include <stdlib.h> 
 
#define REPORT_FILE "packages_report.txt"
#define PACKAGES 1000

struct pkg {
	char *action;
	char *install;
	char *removed;
	char *update;
	int updates;
	
};

void analizeLog(char *logFile, char *report);

int main(int argc, char **argv) {

    if (argc < 2) {
	printf("Usage:./pacman-analizer.o \n");
	return 1;
    }
	/*
	printf("%s",argv[2]);
	printf("%s",argv[4]);}
	*/
    analizeLog(argv[2], argv[4]);
    return 0;
}
char ** readL(int fr){


	//we create a string array to save each of the sections of the line
	char **sects;
	sects = malloc(200*sizeof(char*));
	for (int i = 0; i < 200; i++)
	{
		sects[i] = malloc(200*sizeof(int*));
	}

	int sec = 0;
	int word = 0;
	int p = 0;
	int key = 0;
	char curr[1];

	while (read(fr,curr,1) != 0)
	{
		
		if(curr[0] == '['){
			key = 1;
		}else if(curr[0] == ']'){
			key = 0;
		}
		//we separate words by spaces
		if(curr[0] == ' '){
			//if there are spaces between keys, we ignore them
			if (!key)
			{
				word++;
				sects[sec][p] = curr[0];
				sec++;
				p=0;
			}
			
		}else{
			//if not, we add the char to the string we are currently at and at char p
			sects[sec][p] = curr[0];
			p++;
		}
		//if the char we are reading is the new line char, we ignore it
		if(curr[0] == '\n'){
			return sects;
		}
	}
	
}

int checkInstall( char* action,int installed_pkgs, struct pkg* pkgs){
	//We search pkgs using the amount of packages installed
	for(int i = 0; i<installed_pkgs; i++){
		if (pkgs[i].action != NULL)
		{
			//if it matches, we return the index of the package
			if(strcmp(action,pkgs[i].action) == 0){
			return i;
		}
		}
		
		//printf("%s",);
		/*

		*/
	}
	return -1;
}

char * keyRemove(char * d){
	int i;
	//We replace each char with the one in front of it
	for (i = 0; i < strlen(d); i++)
	{
		d[i] = d[i+1];
	}
	//and we replace the last one with string end
	d[i-3] = '\0';
	return d;
}

void analizeLog(char *logFile, char *report) {
    

    // Implement your solution here.
	//Se abre el archivo y verificamos que exista
	printf("%s",logFile);
	int fr = open(logFile,O_RDONLY);
	if(fr == -1){
		printf("File does not exist \n");
		return;
	}else{
		printf("Generating Report from: [%s] log file\n", logFile);
	}
	//Se considera que vamos a usar menos de mil paquetes
	struct pkg pkgs[PACKAGES];

	int ix = 0;
	int pkg_installed = 0;
	int pkg_rmv = 0;
	int pkg_updates = 0;
	int pkg_curr = 0;

	char **line;	
	
	//We read the file line by line
	while(line = readL(fr)){

		//We check what the action was done
		if(strcmp(line[2],"installed ") == 0){

			int installedPos = checkInstall(line[3],pkg_installed,pkgs);
			//If not installed 
			if(installedPos == -1){
				pkg_curr++;
				pkg_installed++;
				pkgs[ix].action = line[3];
				pkgs[ix].install = keyRemove(line[0]);
				pkgs[ix].removed = "-";
				pkgs[ix].update = "-";
				pkgs[ix].updates = 0;
				ix++;
			}
			else{
				if ((strcmp(pkgs[installedPos].removed,"-") != 0))
				{
					pkg_installed++;
					pkg_curr++;
					//pkg_rmv--;
					pkgs[installedPos].removed = "-";
					pkgs[installedPos].install = keyRemove(line[0]);
					pkgs[installedPos].update = "-";
					pkgs[installedPos].updates = 0;
				}
			}
			
		
		}else if((strcmp(line[2],"removed ") == 0)){
			
			//printf("%s\n",line[2]); 
			//We check if it is installed
			int searchInstall = checkInstall(line[3],pkg_installed,pkgs);
			//printf("%d %s\n",searchInstall,pkgs[searchInstall].removed);
			if((searchInstall>=0)&&(strcmp(pkgs[searchInstall].removed,"-")==0)){
				pkgs[searchInstall].removed = keyRemove(line[0]);
				pkg_rmv++;
				pkg_curr--;
			}
			
			
		}else if((strcmp(line[2],"upgraded ") == 0)){
			//We check if it is installed
			int searchInstall = checkInstall(line[3],pkg_installed,pkgs);
			if((searchInstall>=0)&&(strcmp(pkgs[searchInstall].update,"-")==0)){
				pkgs[searchInstall].update = keyRemove(line[0]);
				pkgs[searchInstall].updates++;
				//printf("%s",line[0]);
				pkg_updates++;
			}else{
				pkgs[searchInstall].update = keyRemove(line[0]);
			}
			//printf("%s\n",line[2]); 
			
		}
	}
	
	close(fr);
	//opening report file
	int reportFile = open(report, O_WRONLY | O_CREAT, 0640);
	char msg [500];
	char * title = "Pacman Packages Report\n-----------------------\n";
	write(reportFile,title,strlen(title));
	sprintf(msg,"%s%d\n"," - Installed packages\t: ",pkg_installed);
	write(reportFile,msg,strlen(msg));
	sprintf(msg,"%s%d\n"," - Removed packages\t: ",pkg_rmv);
	write(reportFile,msg,strlen(msg));
	sprintf(msg,"%s%d\n"," - Upgraded packages\t: ",pkg_updates);
	write(reportFile,msg,strlen(msg));
	sprintf(msg,"%s%d\n\n"," - Current Installed\t: ",pkg_curr);
	write(reportFile,msg,strlen(msg));
	
	for(int i = 0; i<ix; i++){
		sprintf(msg,"- Package Name \t\t: %s\n",pkgs[i].action);
		write(reportFile,msg,strlen(msg));
		sprintf(msg," - Install date\t\t: %s\n",pkgs[i].install);
		write(reportFile,msg,strlen(msg));
		sprintf(msg," - Last update date\t: %s\n",pkgs[i].update);
		write(reportFile,msg,strlen(msg));
		sprintf(msg," - How many updates\t: %d\n",pkgs[i].updates);
		write(reportFile,msg,strlen(msg));
		sprintf(msg," - Removal date\t\t: %s\n",pkgs[i].removed);
		write(reportFile,msg,strlen(msg));
	}
	
	close(reportFile);
	
}
