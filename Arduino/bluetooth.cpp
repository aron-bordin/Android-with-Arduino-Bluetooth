#include "bluetooth.h"

int Bluetooth::getrxPin(){
    return rxPin;
}

void Bluetooth::setrxPin(int rx){
    rxPin = rx;
}

int Bluetooth::gettxPin(){
    return txPin;
}

void Bluetooth::settxPin(int tx){
    txPin = tx;
}

void Bluetooth::setupBluetooth(){
    btSerial = new SoftwareSerial(rxPin, txPin);
    pinMode(txPin, OUTPUT);
    pinMode(rxPin, INPUT);

    btSerial->begin(9600);

    Serial.println("Bluetooth with 9600");
    btSerial->write("AT+BAUD4");
    delay(1100);
    while (btSerial->available()) 
    Serial.write(btSerial->read());

    btSerial->write(Name);
    delay(1100);
    while (btSerial->available()) 
    Serial.write(btSerial->read());

    Serial.println("\nAjusting PIN - 6666");
    btSerial->write("AT+PIN6666");
    delay(1100);
    while (btSerial->available()) 
    Serial.write(btSerial->read());

    Serial.println("\nBluetooth version");
    btSerial->write("AT+VERSION");
    delay(1100);
    while (btSerial->available()) 
    Serial.write(btSerial->read());
}

Bluetooth::Bluetooth(char name[]){
    setName(name);
    setrxPin(2);
    settxPin(3);
}

Bluetooth::Bluetooth(char name[], int r, int t){
    setName(name);
    setrxPin(r);
    settxPin(t);
    setupBluetooth();
}

void Bluetooth::setName(char c[]){
    strcpy(Name, "AT+NAME");
    strcat(Name, c);
}
char * Bluetooth::getName(){
    return &Name[0];
}


String Bluetooth::Read(){
    char c;
    String retorno = "";
    if(btSerial->available())
        while(1){
            c = btSerial->read();
            retorno += c;
            if(c == '#')
              break;
        }
    return retorno;
}

void Bluetooth::Send(char c[]){
    btSerial->print(c);
}