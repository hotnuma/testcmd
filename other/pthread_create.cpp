#include <stdio.h>
#include <pthread.h>

void *exec(void *param)
{
    pthread_t id = *((pthread_t *) param);
    int count = 10;

    while (count)
    {
        --count;

        fprintf(stdout, "%li  = %i\n", id, count);
        fflush(stdout);

        sleep(1);
    }
}

int main()
{
    pthread_t thread0;
    pthread_t thread1;

    if (pthread_create(&thread0, NULL, exec, &thread0))
    {
        printf("Error creating thread\n");
        return 1;
    }

    if (pthread_create(&thread1, NULL, exec, &thread1))
    {
        printf("Error creating thread\n");
        return 1;
    }

    printf("join thread %li\n", thread0);
    if (pthread_join(thread0, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    printf("join thread %li\n", thread1);
    if (pthread_join(thread1, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    return 0;
}

