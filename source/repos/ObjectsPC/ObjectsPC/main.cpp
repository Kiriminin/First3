#include <iostream>
#include "Hardware.h"
#include "Components.h"

using namespace std;

class PC {
    Cpu cpu;
    SSD ssd;
    RAM ram;

    Keyboard* keyboard;
    Mouse* mouse;
    Headphones* headphones;
    Monitor* monitor;

public:
    PC(Cpu c, SSD s, RAM r, Keyboard* kb = nullptr, Mouse* ms = nullptr, Headphones* hp = nullptr, Monitor* mn = nullptr)
        : cpu(c), ssd(s), ram(r), keyboard(kb), mouse(ms), headphones(hp), monitor(mn) {}

    void Output() {
        cout << "-- PC Configs --" << endl;
        cpu.Output();
        ssd.Output();
        ram.Output();

        if (keyboard) {
            cout << "-- Keyboard --" << endl;
            keyboard->Output();
        }
        else cout << "No keyboard" << endl;

        if (mouse) {
            cout << "-- Mouse --" << endl;
            mouse->Output();
        }
        else cout << "No mouse" << endl;

        if (headphones) {
            cout << "-- Headphones --" << endl;
            headphones->Output();
        }
        else cout << "No headphones" << endl;

        if (monitor) {
            cout << "-- Monitor --" << endl;
            monitor->Output();
        }
        else cout << "No monitor" << endl;

        cout << "--------------------" << endl;
    }
};

int main() {
    Cpu cpu;
    cpu.setPrice(350);
    cpu.setCapacity(8);
    cpu.setName("Intel i9");

    SSD ssd;
    ssd.setPrice(200);
    ssd.setCapacity(512);
    ssd.setBrand("Apple");

    RAM ram;
    ram.setPrice(95);
    ram.setSize(16);
    ram.setType("DDR5");

    Keyboard keyboard;
    keyboard.setPrice(75);
    keyboard.setLayout("ZXCVB");
    keyboard.setIsMechanical(true);

    Mouse mouse;
    mouse.setPrice(15);
    mouse.setDPI(1650);
    mouse.setIsWireless(false);

    Headphones headphones;
    headphones.setPrice(200);
    headphones.setIsWireless(true);
    headphones.setType("Cool");

    Monitor monitor;
    monitor.setPrice(350);
    monitor.setSize(28);
    monitor.setResolution("1700x1080");

    PC myPC(cpu, ssd, ram, &keyboard, &mouse, &headphones, nullptr);
    myPC.Output();

    return 0;
}