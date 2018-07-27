#include<stdio.h>
void printHorLine(int);
void printHVerLine(int);
void printTab(int);
void printTwoVer(int,int);

int main()
{
int tabCount;
    /*printHorLine(100);
    printf("\n\r");
    printfTab(100);
    printVerLine(20);
    printHorLine(100);
    */
printTwoVer(10,100);

}

void printHorLine(int count) {
    int hrCount;
    for(hrCount=0;hrCount !=100 ; hrCount++) {
           printf("-");
    }
}

void printVerLine(int count){
    int vrCount;
    for(vrCount=0;vrCount !=count ; vrCount++) {
           printf("|\v\r");
    }
}
void printTab(int count) {
    int loopCnt;
    for(loopCnt; loopCnt<=count;loopCnt++);
        printf("\t");
        
}

void printTwoVer(int lineCount,int horSpace){
    int vrCount;
    for(vrCount=0;vrCount !=lineCount ; vrCount++) {
           printf("|\r");
           printTab(horSpace);
           printf("|\r\n");
    }

}
