#include "STL_data.h"

using namespace std;


int getPidNumberList(int * pid_numbers){
    int pid_count = getPidList(pid_numbers) ; 
    return pid_count;
}

/* get max pid number limit */
int getPidLimit(){
    int max_pid=0;
    ifstream f_mpid;
    f_mpid.open("/proc/sys/kernel/pid_max");
    if (!f_mpid) {
        cout << "failed to read proc entry " << endl;
        return max_pid;
    }
    f_mpid >> max_pid;
return max_pid;
}

/* Get pid number list */
int getPidList(int * pid_numbers) {
    FILE * cmd_stream = NULL;
    char pid_string[6];
    int index = 0;
    int pid_count = 0;
    
    cmd_stream = popen(PROCESS_CMD,"r");
    assert(cmd_stream != NULL);
    
    while(!feof(cmd_stream)){
        if(fgets(pid_string,BUF_SIZE,cmd_stream) != NULL) {
            pid_numbers[index] = atoi(pid_string);
            pid_count++;
            index++;
        }
    }
    pclose(cmd_stream);
    return pid_count;
}
