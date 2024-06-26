#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <sstream>
#include <windows.h>

using namespace std;
int s;
string deviceName = "红米 Note 12 Turbo";
string deviceCode = "marble";
string projectName = "OrangeFox Recovery Project";
string recVer = "R11.1_6 Beta";
string recAuth = "Ctapchuk";
string toolAuth = "AviderMin";
string buildDate = "2024.04.18";
string recImg = "OFRP-R11.1_6_RECOVERY-Beta-marble.img";
string apkFile = "KernelSU_v0.9.4_11838-release.apk";
string Group = "749222815";

void MENU();
void INF();
void IN_SYSTEM();
bool CheckADBDevice();
void FASTBOOT_MODE();
void INSTALL_APK();
void REBOOT_BOOTLOADER();
void FLASHING();
void FLASH_OVER();
void FLASH_FAILED();

int main() {
    system("color 3f");
    system(("TITLE " + deviceName + "一键刷入工具 --By " + toolAuth).c_str());
    INF();
    cout << "按回车键继续..." << endl;
    cin.get();
    system("cls");
    MENU();
    system("pause");
    return 0;
}

void INF() {
    cout << endl;
    cout << "     " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "           Rec基本信息" << endl;
    cout << "      Rec名称 ：" << projectName << endl;
    cout << "      Rec版本 ：" << recVer << endl;
    cout << "      Rec作者：" << recAuth << endl;
    cout << "      适配机型：" << deviceName << endl;
    cout << "      机型代号：" << deviceCode << endl;
    cout << "      工具作者：" << toolAuth << endl;
    cout << "      编译时间：" << buildDate << endl;
    cout << "      刷机交流群：" << Group << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
}

void MENU() {
    cout << endl;
    cout << "   " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "	     请选择功能：" << endl;
    cout << "" << endl;
    cout << "   1. 在开机状态下刷入（带机型检查，推荐）" << endl;
    cout << "" << endl;
    cout << "   2. 在fastboot模式下刷入" << endl;
    cout << "" << endl;
    cout << "   3. 安装KernelSU应用" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    int choice;
    do {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "您选择了开机状态，现在执行重启至Bootloader操作.." << endl;
                Sleep(2);
                IN_SYSTEM();
                return;
            case 2:
                cout << "您选择了fastboot模式，现在执行刷入操作..." << endl;
                Sleep(2);
                system("cls");
                FASTBOOT_MODE();
                return;
            case 3:
                cout << "您选择了安装KernelSU应用，现在执行安装操作..." << endl;
                Sleep(2);
                system("cls");
                INSTALL_APK();
                return;
            default:
                cout << "无效的选择，请重新选择。" << endl;
                Sleep(1);
                system("cls");
                MENU();
                return;
        }

        cout << "按任意键返回菜单" << endl;
        cin.get();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << endl;

    } while (choice != 0);
    cout << "感谢使用，再见！" << endl;
    cout << "******************************" << endl;
}

void FLASH_OVER() {
    system("cls");
    cout << "   " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "             刷写Recovery完成" << endl;
    cout << endl;
    cout << "            手机将重启进入Recovery" << endl;
    cout << endl;
    cout << "           " << toolAuth << "感谢您使用本工具" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "           （按任意键关闭此窗口）" << endl;
    cout << endl;
    system("fastboot reboot recovery");
    cin.get();
    return;
}

void FLASH_FAILED() {
    system("cls");
    cout << "   " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "                   刷入失败！" << endl;
    cout << endl;
    cout << "           1.请检查手机型号是否正确" << endl;
    cout << "           2.请确认fastboot是否正常" << endl;
    cout << "           3.解压后重新运行本程序，" << endl;
    cout << "             若还不成功，请联系作者" << endl;
    cout << endl;
    cout << "           " << toolAuth << "感谢您使用本工具" << endl;
    cout << endl;
    cout << "            （按任意键退出程序）" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    return;
}

void FLASHING() {
    system("cls");
    cout << "   " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "          正在进行刷入Recovery操作" << endl <<
    cout << "      （如果长时间停留在此界面，请检查：）" << endl;
    cout << endl;
    cout << "      【1.USB线是否正确连接】" << endl;
    cout << "      【2.电脑驱动是否正确安装并识别】" << endl;
    cout << "      【3.手机是否进入fastboot模式】" << endl;
    cout << endl;
    cout << "             （并重启该工具）" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    int result = system(("fastboot flash recovery_ab " + recImg).c_str());
    if (result == 0) {
        FLASH_OVER();
    } else {
        FLASH_FAILED();
    }
    return;
}

void REBOOT_BOOTLOADER() {
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "             手机重启中..." << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "   （若长时间停留在此界面，请重启该工具）" << endl;
    int result = system("adb reboot bootloader");
    if (result == 0) {
        FLASHING();
    }
    return;
}

void IN_SYSTEM() {
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "         请您将手机正确连接到电脑：" << endl;
    cout << endl;
    cout << "           请确保：" << endl;
    cout << "      【1.手机bootloader未锁】" << endl;
    cout << "      【2.手机处于开机状态】" << endl;
    cout << "      【3.手机开启USB调试】" << endl;
    cout << "      【4.电脑上已经正确安装驱动】" << endl;
    cout << "      【5.手机提示USB调试授权时勾选始终点击授权】" << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "     " << "正在检查设备是否正常连接..." << endl;
    cout << endl;
    cout << "   （若长时间停留在此界面，请检查上述几项）" << endl;
    cout << "***********************************************" << endl;
    char choice;
    bool shouldContinue = true;
    while (shouldContinue) {
        if (CheckADBDevice()) {
            std::cout << "设备检查成功，已发现已连接的设备。" << std::endl;
            std::cout << "设备将在两秒后重启至Bootloader..." << std::endl;
            Sleep(3);
            return REBOOT_BOOTLOADER();
        } else {
            std::cerr << "设备检查失败，请检查连接！" << std::endl;
            std::cerr << "如果连接正常，请检查是否为对应机型。" << std::endl;
            char choice;
            do {
                std::cout << "按 r 重新检查，或输入 q 退出: ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
            } while (choice != 'r' && choice != 'R' && choice != 'q' && choice != 'Q');

            if (choice == 'r' || choice == 'R') {} else if (choice == 'q' || choice == 'Q') {
                shouldContinue = false;
            }
        }
    }
}

void FASTBOOT_MODE() {
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "          请您将手机正确连接到电脑：" << endl;
    cout << endl;
    cout << "          请确保：" << endl;
    cout << "        【1.手机bootloader未锁】" << endl;
    cout << "        【2.手机处于fastboot模式】" << endl;
    cout << "        【3.电脑上已经正确安装驱动】" << endl;
    cout << endl;
    cout << "            （按下任意键继续）" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    FLASHING();
    return;
}

void INSTALL_APK() {
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " 一键刷入工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "          请您将手机正确连接到电脑：" << endl;
    cout << endl;
    cout << "          请确保：" << endl;
    cout << "        【1.手机开启了USB调试】" << endl;
    cout << "        【2.电脑已安装ADB驱动】" << endl;
    cout << "        【3.手机上已授权此电脑的调试权限】" << endl;
    cout << "          若出现授权，请手动授权" << endl;
    cout << endl;
    cout << "            （按下任意键继续）" << endl;
    cout << "" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    int adbDevicesResult = system("adb devices");
    if (adbDevicesResult != 0) {
        std::cerr << "ADB设备检查失败，请检查连接！" << std::endl;
        return;
    }
    std::string installCommand = "adb install " + apkFile;
    int installResult = system(installCommand.c_str());
    if (installResult != 0) {
        std::cerr << "APK安装失败，请检查文件路径或ADB连接！" << std::endl;
    } else {
        std::cout << "APK安装成功！" << std::endl;
    }
    Sleep(2);
    system("cls");
    return MENU();
}

bool CheckADBDevice() {
    std::string adbOutput = "";
    FILE * pipe = popen("adb shell getprop ro.product.vendor.name", "r");
    if (!pipe) {
        std::cerr << "Failed to execute adb shell getprop ro.product.vendor.name" << std::endl;
        return false;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe)) {
        adbOutput += buffer;
    }

    pclose(pipe);


    size_t pos;
    while ((pos = adbOutput.find_first_of("\n\r ")) != std::string::npos) {
        adbOutput.erase(pos, 1);
    }

    if (adbOutput == deviceCode) {
        return true;
    }

    return false;
}
