#ifndef __LOGGING__
#define __LOGGING__

struct {
    tBoolean LogOn;
    static enum eLogLevel outputLevel[NUM_LOG_SUBSYSTEMS];
} sLogStruct;
static struct sLogStruct gLogData;
struct sLogStruct* LogInternalState(){
#if PRODUCTION
    #error "Internal state of logging protected!"
#else
    return &gLogData;
#endif /* PRODUCTION */
}

struct sLogStruct* LogInit(){
    int i;
    struct sLogStruct *logData=malloc(sizeof(*logData));
    logData->logOn=FALSE;
    for(i=0;i<NUM_LOG_SUBSYSTEMS;i++){
        logData->outputLevel=eNoLogging;
    }
    return logData;
}



void Log(enum eLogSubSystem sys, enum eLogLevel level, char *msg);
void LogWithNum(enum eLogSubSystem sys, enum eLogLevel level, char *msg,int number);
void LogSetOutputLevel(enum eLogSubSystem sys, enum eLogLevel level);
void LogGlobalOn();
void LogGlobalOff();
void LogVersion(struct sFirmwareVersion *v);
#endif /* ifndef __LOGGING__ */
