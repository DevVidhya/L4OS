#include <stdlib.h>			
#include <stdio.h>			//For Input and Output
#include <semaphore.h>		//For creating semaphores
#include <pthread.h>		//For Create POSIX threads.
#include <time.h>			//Waiting for a random time.
#include <unistd.h>			//Thread calls sleep for specified number of seconds.

//Declaration of Semaphores and Mutex Lock.
sem_t TA_Sleep;             
sem_t Student_Sem;
sem_t ChairsSem[3];
pthread_mutex_t ChairAccess;

//Declaration of N threads for running as Students.
pthread_t *Students;		
//Declaration of a Separate Thread for TA.
pthread_t TA;	

//Number of chairs occupied is 0 initially.			
int ChairsCount = 0;        
//Chair number in which next student can wait.
int CurrentIndex = 0;       

//Declaration of Functions.
void *TA_Activity();        
void *Student_Activity(void *threadID);

void *TA_Activity()
{
	while(1)
	{
		//TA is currently sleeping.
		sem_wait(&TA_Sleep);
		printf("~~~~~~~~~~~~~~~~~~~~~TA has been awakened by a student.~~~~~~~~~~~~~~~~~~~~~\n");

		while(1)
		{
			//lock
			
			pthread_mutex_lock(&ChairAccess);          
			if(ChairsCount == 0) 
			{
				//if chairs are empty, break the loop and the teaching assistant can continue sleeping.
				pthread_mutex_unlock(&ChairAccess);
				break; 
			}	
			//When students are waiting.
			//TA gets next student on chair by signalling.	
			sem_post(&ChairsSem[CurrentIndex]);
			//Decrease the chair count as number of students waiting gets reduced by one.
			ChairsCount--;
			//Remaining chairs is total - number of chairs occupied.
			printf("Student left his/her chair. Remaining Chairs %d\n", 3 - ChairsCount);
			//Update the chair number where next student can sit.
			CurrentIndex = (CurrentIndex + 1) % 3;
			pthread_mutex_unlock(&ChairAccess);
			
			// unlock

			printf("\t TA is currently helping the student.\n");
			sleep(5);
			sem_post(&Student_Sem);
			usleep(1000);
		}
	}
}

void *Student_Activity(void *threadID) 
{
	int ProgrammingTime;

	while(1)
	{
		printf("Student %ld is doing programming assignment.\n", (long)threadID);
		ProgrammingTime = rand() % 10 + 1;
		//Sleep for a random time period.
		sleep(ProgrammingTime);		

		printf("Student %ld needs help from the TA\n", (long)threadID);
		
		pthread_mutex_lock(&ChairAccess);
		int count = ChairsCount;
		pthread_mutex_unlock(&ChairAccess);

        //Student is trying to sit on a chair.
		if(count < 3)		
		{
			//If student sits on first empty chair, wake up the TA.
			if(count == 0)		
				sem_post(&TA_Sleep);
			else
				printf("Student %ld sat on a chair waiting for the TA to finish. \n", (long)threadID);

			// lock
			
			pthread_mutex_lock(&ChairAccess);
			int index = (CurrentIndex + ChairsCount) % 3;
			//Number of chairs occupied is increased by one.
			ChairsCount++;
			printf("Student sat on chair.Chairs Remaining: %d\n", 3 - ChairsCount);
			pthread_mutex_unlock(&ChairAccess);
			
			// unlock

            //Student leaves his/her chair.
			sem_wait(&ChairsSem[index]);		
			printf("\t Student %ld is getting help from the TA. \n", (long)threadID);
			//Student waits to go next.
			sem_wait(&Student_Sem);		
			printf("Student %ld left TA room.\n",(long)threadID);
		}
		else 
			printf("Student %ld will return at another time. \n", (long)threadID);
			//If student didn't find any chair to sit on.
	}
}

int main(int argc, char* argv[])
{
	//a variable taken from the user to create student threads.	Default is 5 student threads.
	int number_of_students;		
	int id;
	srand(time(NULL));

	//Initializing Mutex Lock and Semaphores.
	sem_init(&TA_Sleep, 0, 0);
	sem_init(&Student_Sem, 0, 0);
	//Chairs array of 3 semaphores.
	for(id = 0; id < 3; ++id)			
		sem_init(&ChairsSem[id], 0, 0);

	pthread_mutex_init(&ChairAccess, NULL);
	
	if(argc<2)
	{
		printf("Number of Students not specified. Using default (5) students.\n");
		number_of_students = 5;
	}
	else
	{
		printf("Number of Students specified. Creating %d threads.\n", number_of_students);
		number_of_students = atoi(argv[1]);
	}
		
	//Allocate memory for Students
	Students = (pthread_t*) malloc(sizeof(pthread_t)*number_of_students);

	//Creating TA thread and N Student threads.
	pthread_create(&TA, NULL, TA_Activity, NULL);	
	for(id = 0; id < number_of_students; id++)
		pthread_create(&Students[id], NULL, Student_Activity,(void*) (long)id);

	//Waiting for TA thread and N Student threads.
	pthread_join(TA, NULL);
	for(id = 0; id < number_of_students; id++)
		pthread_join(Students[id], NULL);

	//Free allocated memory
	free(Students); 
	return 0;
}


