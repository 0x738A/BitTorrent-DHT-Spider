#ifndef HEADER_P2SP_API
#define HEADER_P2SP_API

typedef unsigned int DWORD;
typedef DWORD UINT;
typedef unsigned long long UINT64;
typedef DWORD HANDLE;
typedef char CHAR;
typedef unsigned int BOOL;
typedef int INT;
typedef void VOID;
#define TRUE true
#define FALSE false
#define INVALID_HANDLE_VALUE -1
#define DUPLICATE_TASK_HANDLE -2
#define MAX_PATH 260
#define WINAPI
#include <stdarg.h>
#define SLEEP usleep

struct TASK_INFO
{
    UINT status;
    UINT64 size_total;
    UINT64 size_done;
    float percent;
    UINT speed_down;
    UINT speed_up;
    UINT peers_all;
    UINT seeds_all;
    UINT peers_conn;
    UINT seeds_conn;
};

struct TASK_FILE_INFO
{
    char szName[MAX_PATH];
    char szPathName[MAX_PATH];
    UINT priority;
    unsigned long long file_size;
    unsigned long long file_down;
};

enum state_t
{
    queued_for_checking,    //�ȴ�����ļ�����
    checking_files,         //����Ѿ����ص��ļ�����
    downloading_metadata,   //���ش���������
    downloading,            //������
    finished,               //���������δ��ʼ����
    seeding,                //������ɿ�ʼ����
    allocating,             //������̿ռ�
    checking_resume_data,   //�����ٻָ��ļ�
    pause_s,                  //��������ͣ
    error,                  //���ع��̳�����ͣ
    pending                 //������ͣ������ֹͣ
};