#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int q1 ( int argc , char * argv[] ) {

	printf("Je suis: %s \n", argv[0]);
	printf("Je vais créer %s fils \n", argv[1]);
	int pid=0;
	int n=1;
	int nb = atoi(argv[1]);
	while (pid==0 && n<=nb){
		printf("Je suis le %i e fils\n", n);
		n++;
		pid=fork();

	}
	sleep(5);

}

int q2 ( int argc , char * argv[] ) {
	printf("Je suis: %s \n", argv[0]);
	printf("Je vais créer %s fils \n", argv[1]);
	printf("Chacun de mes fils va créer %s fils \n", argv[2]);
	int id=getpid(); // papa pid
	int pid=id;
	int ppid=0;
	int nb = atoi(argv[1]); // représente le nombre de fils à créer
	int nbChild = atoi(argv[2]);  // représente le nombre de petit fils à créer


	// Je suis le pere, alors je crée mes fils
	for(int i=0;i<nb;i++){

        printf("Je suis le père (%i), je crée mon %ie fils\n", getpid(),i+1);
        pid=fork();


		//Je suis un fils, alors je crée mes petits fils
		if(pid==0){
			for(int j=0;j<nbChild;j++){
				printf("Je suis le %ie (%i) fils et je crée mon %ie fils\n", i+1, getpid(), j+1);
				ppid=fork();
				// je suis le petit fils
				if (ppid==0){
                    sleep(5);
                    exit(EXIT_SUCCESS);
				}
			}

			sleep(5);
			exit(EXIT_SUCCESS);
		}
	}
	sleep(5);

}

void q3() {
    int pid = fork();
    if (pid != 0) {
        sleep(10);
        wait(&pid);
    }
}

int q4(){
    int n, pid;
    pid = fork();
    if(pid == 0){
        printf("L'enfant écrit : ");
        scanf("%d",&n);
        exit(n);
    }
    else{
        wait(&n);
        printf("Le père lit : %d\n", WEXITSTATUS(n));
        return WEXITSTATUS(n);
    }
}


int main ( int argc , char * argv[] ) {
	return q1(argc, argv);

	//return q2(argc, argv);

	//q3();

	//return q4();

}
