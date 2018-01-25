#ifndef _LOG_H_
#define _LOG_H_

#define LOG_SUCCESS	0
#define LOG_FAILED	-1

#define RUN_LEVEL (0)    /*���м���0ȫ�����1����澯�ʹ���2�������3ȫ�����*/

#define MAX_FILE_SIZE (1024*1024*2)    /*��־�ļ���С�������*/

#define MBUF_MAX 160    /*��������ַ�������*/

#define RUN_LOG_PATH "run_log.log"    /*��־�ļ�·��*/

#define RUN_LOG_BAK_PATH "run_log_bak.log"    /*������־�ļ�·��*/

#define END ""    /*�ɱ��ĩβ��ʶ*/

#define IOBUF_SIZE	1024	/*����дIO�����С*/

/*���м���*/
#define LOG_RUN        0
#define LOG_WARNING    1
#define LOG_ERROR	   2

/*���˴�ӡ,level:���м���{0��1��2}*/
#define WRITE_LOG(level, ...) do{ \
    if (level - RUN_LEVEL < 0) \
        break; \
    run_log(__FILE__, __LINE__, __VA_ARGS__, END); \
    } while(0)

/*��־��ӡ*/
extern void run_log(const char* file_name, int line_num, ...);

/* ��ʱ������=TIMEKEEPER_NUM-2 */
#define TIMEKEEPER_NUM	20

/* ��ʱ���������ȡn - [1��TIMEKEEPER_NUM-1] */
extern void timekeeper_set(int n);
extern double timekeeper_get(int n);

#endif	/*!_LOG_H_*/