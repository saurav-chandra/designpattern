//before
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    return false;
  } else if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    return false;
  } else if(chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

observation:
code is violating SRP
could be broken into 3 functions
in case of multiple failures in battery, we will rcv just one msg which came earlier in the fn

//after refactoring
bool batteryTempIsOk(float temperature) {
    if(temperature < 0 || temperature > 45) {
        cout << "Temperature out of range!\n";
        return false;
    }
    return true;
}

bool batterySocIsOk(float soc) {
    if(soc < 20 || soc > 80) {
        cout << "State of Charge out of range!\n";
        return false;
    }
    return true;
}

bool batteryChargeRateIsOk(float chargeRate) {
    if(chargeRate > 0.8) {
        cout << "Charge Rate out of range!\n";
        return false;
    }
    return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  if(batteryTempIsOk && batterySocIsOk && batteryChargeRateIsOk)
    return true;
}
