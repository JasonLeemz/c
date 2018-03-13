//
// Created by 李明泽 on 2018/3/13.
//

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

using namespace std;

typedef int sem_t;
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
} arg;


//struct semmbuf {
//    ushort sem_num;
//    short sem_op;
//    short sem_flg;
//};

sem_t CreateSem(key_t key, int value);

int GetvalueSem(sem_t semid);

int Sem_P(sem_t semid);

int Sem_V(sem_t semid);

void DestorySem(sem_t semid);


int main() {
    int sem_id;
    key_t key;
//    char i;
    int value = 0;

    key = ftok(".", 1);
    cout<<key;
    sem_id = CreateSem(key, 100);

    for (int i = 0; i <= 3; i++) {
        Sem_P(sem_id);
        Sem_V(sem_id);
    }

    value = GetvalueSem(sem_id);
    cout << "信号量为：" << value << endl;

    DestorySem(sem_id);

    return 0;
}

sem_t CreateSem(key_t key, int value) {

    sem_t sem_id;

    //获取信号量id
//    cout<<key<<endl;
    sem_id = semget(key, 1, IPC_CREAT);
    if (sem_id == -1) {
        cout << "信号量创建失败" << endl;
        return -1;
    }
    //建立value个初始值的信号量
    union semun sem;
    sem.val = value;
    semctl(sem_id, 0, SETVAL, sem);
    return sem_id;
}

int GetvalueSem(sem_t semid) {
    union semun sem;
    return semctl(semid, 0, GETVAL, sem);
}

int Sem_P(sem_t semid) {
    struct sembuf sops = {0, +1, IPC_NOWAIT};
    return (semop(semid, &sops, 1));
}

int Sem_V(sem_t semid) {
    struct sembuf sops = {0, -1, IPC_NOWAIT};
    return (semop(semid, &sops, 1));
}

void DestorySem(sem_t semid) {
    union semun sem;
    sem.val = 0;

    //IPC_RMID将制定信号量销毁
    semctl(semid, 0, IPC_RMID, sem);
}