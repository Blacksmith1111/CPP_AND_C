#include <iostream>
#include <fstream>

enum Level:int{
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Singleton{
public:
    template <typename T> static const T& self() {
        static T v; 
        return v; 
    }
};

class Logger{
private:
    mutable Level c_level;
    mutable std::ofstream mes;
public: 
    Logger():c_level(TRACE){
        mes.open("my_logger.txt");
    }
    ~Logger(){
        mes.close();
    }
    void log(Level p_level, const std::string& p_message) const {
        if (p_level < c_level){
            return;
        } 
        else{
            mes << p_message << std::endl;
        }
    }
    void loglevel(Level p_level) const {
        c_level = p_level;
    }
    Level loglevel() const { 
        return c_level;
    }
};
