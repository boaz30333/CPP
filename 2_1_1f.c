#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include <unistd.h>

#define N 5 
#define THINKING 2 
#define HUNGRY 1 
#define EATING 0 
#define LEFT (phnum + 4) % N 
#define RIGHT (phnum + 1) % N 

int state[N]; 
int phil[N] = { 0, 1, 2, 3, 4 }; 

sem_t mutex; 
sem_t Chopstick[N]; 

 

// take up chopsticks 
void take_fork(int phnum) 
{ 

	//  sem_wait(&mutex); 

	// state that hungry 
	// state[phnum] = HUNGRY; 
    sem_wait(&Chopstick[phnum]);
	printf("Philosopher %d is take %d fork \n", phnum,phnum); 
    sleep(2);
    sem_wait(&Chopstick[phnum+1]);
	printf("Philosopher %d is take %d fork \n", phnum,phnum+1); 
	// eat if neighbours are not eating 
	// test(phnum); 
    printf("Philosopher %d eating... \n", phnum);
    sleep(8);
    printf("Philosopher %d finish eating... \n", phnum);
	//  sem_post(&mutex); 

	// if unable to eat wait to be signalled 
	// sem_wait(&S[phnum]); 

	sleep(1); 
} 

// put down chopsticks 
void put_fork(int phnum) 
{ 
     
	//  sem_wait(&mutex); 

	// // state that thinking 
	// state[phnum] = THINKING; 
    sem_post(&Chopstick[phnum]);
    sem_post(&Chopstick[phnum+1]);
	// printf("Philosopher %d putting fork %d and %d down\n", 
	// 	phnum + 1, LEFT + 1, phnum + 1); 
	// printf("Philosopher %d is thinking\n", phnum + 1); 

	// test(LEFT); 
	// test(RIGHT); 

	//  sem_post(&mutex); 
} 

void* philospher(void* num) 
{ 

	while (1) { 

		int* i = num; 

		sleep(1); 
printf("Philosopher %d is hungry\n", *(int*)num); 
		take_fork(*i); 

		sleep(0); 

		put_fork(*i); 
	} 
} 

int main() 
{ 

	int i; 
	pthread_t thread_id[N]; 

	// initialize the mutexes 
	sem_init(&mutex, 0, 1); 

	for (i = 0; i < N; i++) 

		sem_init(&Chopstick[i], 0, 1); 

	for (i = 0; i < N; i++) { 

		// create philosopher processes 
		pthread_create(&thread_id[i], NULL, 
					philospher, &phil[i]); 

		printf("Philosopher %d is thinking\n", i + 1); 
	} 

	for (i = 0; i < N; i++) 

		pthread_join(thread_id[i], NULL); 
} 

