all:
	gcc  -o semaphore semaphore.c
	gcc  -pthread -o atomic_mutex atomic_mutex.c
