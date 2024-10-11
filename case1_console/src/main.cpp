#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>

bool myled = false;
bool isOpen = false;
char PASSWORD[4] = {'A', 'C', 'D', 'B'};
char input[4];

using namespace std;

void showIsOpen();

int main()
{
    while(1) 
    {
        if(isOpen){
            showIsOpen();
            isOpen = false;
            myled = false;
        }
        
        char btnPressed;
        for(int btn = 0; btn < 4; btn++){
            cout << "Press " << btn + 1 << " button\n";
            cin >> btnPressed;
            input[btn] = btnPressed;
        }
        
        isOpen = true;

        for(int i = 0; i < sizeof(PASSWORD); i++){
            if(input[i] != PASSWORD[i]){
                isOpen=false;
                break;
            }
        }
                
        cout << "Is open: " << isOpen << "\n";

        cout << "\r" << flush;
        
    }

    return 0;

}

void showIsOpen(){
    for(int sec = 0; sec < 10; sec++){
        if(myled){
            cout << "FLASHBANG\n";
            cout << "\r" << flush;
        }
        myled = !myled;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
