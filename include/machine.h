#ifndef MACHINE_H
#define MACHINE_H

#include <string>  // 引入string头文件
#include <map>

class Machine {
  public:
	virtual void powerOn(){
        if(isPoweredOn == 0){
            isPoweredOn = 1;
            // Turn on the machine
        }
        else{
            // Do nothing
        }
    }
    virtual void powerOff(){
        if(isPoweredOn == 1){
            isPoweredOn = 0;
            // Turn off the machine
        }
        else{
            // Do nothing
        }
    };
    virtual void reset() = 0;
    virtual bool isOn() const {
        return isPoweredOn;
    };

  private:
    bool isPoweredOn = false;
};

#endif