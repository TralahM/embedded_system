#ifndef __CPP_LOGGING__
#define __CPP_LOGGING__ value

class Singleton{
    public:
        static Singleton* Instance(){
            if(mInstance==0){
                mInstance=new Singleton;
            }
            return mInstance;
        }
    protected:
        Singleton(); //no one can create this except itself
    private:
        static Singleton* mInstance=0;
}
#endif /* ifndef __CPP_LOGGING__ */
