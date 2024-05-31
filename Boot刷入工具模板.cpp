#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <sstream>

using namespace std;
int s;
string deviceName = "input";
string projectName = "input";
string bootVer = "input";
string patchVer = "input";
string toolAuth = "input";
string buildDate = "input";
string bootImg = "input";
string apkFile = "input";
string Group = "input";

void MENU(); 
void FLASH_OVER();
void FLASH_FAILED();
void FLASHING();
void REBOOT_BOOTLOADER();
void IN_SYSTEM();
void FASTBOOT_MODE();
void INSTALL_APK();
void OTHERS(); 
bool CheckADBDevices();

int main()
{
    system("color 3f");
    system(("TITLE " + deviceName + "一键刷入Boot工具 --By " + toolAuth).c_str());
    cout << endl;
    cout << "     " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "           Rec基本信息" << endl;
    cout << "      Boot名称 ：" << projectName << endl;
    cout << "      Boot版本 ：" << bootVer << endl;
    cout << "      Patch版本：" << patchVer << endl;
    cout << "      适配机型：" << deviceName << endl;
    cout << "      工具作者：" << toolAuth << endl;
    cout << "      编译时间：" << buildDate << endl;
    cout << "      刷机交流群：" << Group << endl;
    cout << "***********************************************" << endl;
    cout << "" << endl;
    cout << "按回车键继续..." << endl;
    cin.get();
    system("cls");
    MENU();
    system("pause");
    return 0;
}

void MENU()
{
    cout << endl;
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "	请选择功能：" << endl;
    cout << "	1. 在开机状态下刷入" << endl;
    cout << "	2. 在fastboot模式下刷入" << endl;
    cout << "	3. 安装KernelSU应用" << endl;
    cout << "	4. 其他状态" << endl;
    cout << "***********************************************" << endl;
    int choice;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "您选择了开机状态，现在执行重启至Bootloader操作.." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            IN_SYSTEM();
            return;
        case 2:
            cout << "您选择了fastboot模式，现在执行刷入操作..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            FASTBOOT_MODE();
            return;
        case 3:
            cout << "您选择了安装KernelSU应用，现在执行安装操作..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            INSTALL_APK(); 
            return;
        case 4:
            cout << "您选择了其他状态，请将手机切换到开机状态或fastboot模式。" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            this_thread::sleep_for(chrono::seconds(1));
            OTHERS();
            this_thread::sleep_for(chrono::seconds(6));
            system("cls");
            MENU();
            return;
        default:
            cout << "无效的选择，请重新选择。" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            MENU();
            return;
        }

        cout << "按任意键返回菜单" << endl;
        cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

    } while (choice != 0);
    cout << "感谢使用，再见！" << endl;
    cout << "******************************" << endl;
}

void FLASH_OVER()
{
    system("cls");
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "             刷写Boot完成" << endl;
    cout << endl;
    cout << "            手机将重启进入系统" << endl;
    cout << endl;
    cout << "           " << toolAuth << "感谢您使用本工具" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "           （按任意键关闭此窗口）" << endl;
    cout << endl;
    system("fastboot reboot");
    cin.get();
    return;
}

void FLASH_FAILED()
{
    system("cls");
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
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
    cout << "***********************************************" << endl;
    cin.get();
    return;
}

void FLASHING()
{
    system("cls");
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          正在进行刷入Boot操作" << endl
         << endl;
    cout << "      （如果长时间停留在此界面，请检查：）" << endl;
    cout << endl;
    cout << "      【1.USB线是否正确连接】" << endl;
    cout << "      【2.电脑驱动是否正确安装并识别】" << endl;
    cout << "      【3.手机是否进入fastboot模式】" << endl;
    cout << endl;
    cout << "             （并重启该工具）" << endl;
    cout << "***********************************************" << endl;
    int result = system(("fastboot flash boot " + bootImg).c_str());
    if (result == 0)
    {
        FLASH_OVER();
    }
    else
    {
        FLASH_FAILED();
    }
    return;
}

void REBOOT_BOOTLOADER()
{
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "             手机重启中..." << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "   （若长时间停留在此界面，请重启该工具）" << endl;
    int result = system("adb reboot bootloader");
    if (result == 0)
    {
        FLASHING();
    }
    return;
}

void IN_SYSTEM()
{
	system("cls");
    cout << endl;
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          请您将手机正确连接到电脑：" << endl;
    cout << endl;
    cout << "            请确保：" << endl;
    cout << "       【1.手机bootloader未锁】" << endl;
    cout << "       【2.手机处于开机状态】" << endl;
    cout << "       【3.手机开启USB调试】" << endl;
    cout << "       【4.电脑上已经正确安装驱动】" << endl;
    cout << "       【5.手机提示USB调试授权时勾选始终点击授权】" << endl;
    cout << endl;
    cout << "***********************************************" << endl;
    cout << endl;
    cout << "  " << "正在检查设备是否正常连接..." << endl;
    cout << endl;
    cout << "   （若长时间停留在此界面，请检查上述几项）" << endl;
    cout << "***********************************************" << endl;
    char choice;  
    bool shouldContinue = true;
    while (shouldContinue) {  
        if (CheckADBDevices()) {  
            std::cout << "ADB设备检查成功，已发现已连接的设备。" << std::endl;
            std::cout << "设备将在两秒后重启至Bootloader..." << std::endl;
			this_thread::sleep_for(chrono::seconds(2));   
            return REBOOT_BOOTLOADER();  
        } else {  
            std::cerr << "ADB设备检查失败，请检查连接！" << std::endl;  
            char choice;  
            do {  
                std::cout << "按 r 重新检查，或输入 q 退出: ";  
                std::cin >> choice;   
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            } while (choice != 'r' && choice != 'R' && choice != 'q' && choice != 'Q');  
  
            if (choice == 'r' || choice == 'R') {    
            } else if (choice == 'q' || choice == 'Q') {   
                shouldContinue = false;  
            }  
        }  
    }
}

void FASTBOOT_MODE()
{
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          请您将手机正确连接到电脑：" << endl;
    cout << endl;
    cout << "          请确保：" << endl;
    cout << "        【1.手机bootloader未锁】" << endl;
    cout << "        【2.手机处于fastboot模式】" << endl;
    cout << "        【3.电脑上已经正确安装驱动】" << endl;
    cout << endl;
    cout << "            （按下任意键继续）" << endl;
    cout << "***********************************************" << endl;
    cin.get();
    FLASHING();
    return;
}

void OTHERS()
{
    cout << endl;
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "             请先将手机处于" << endl;
    cout << endl;
    cout << "               【开机状态】" << endl;
    cout << "                  或者" << endl;
    cout << "             【fastboot模式】" << endl;
    cout << endl;
    cout << "          (无操作则6秒后自动返回)" << endl;
    cout << "***********************************************" << endl;
}

void INSTALL_APK()
{
    system("cls");
    cout << endl;
    cout << "   " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By " << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          请您将手机正确连接到电脑：" << endl;
    cout << endl;
    cout << "          请确保：" << endl;
    cout << "        【1.手机开启了USB调试】" << endl;
    cout << "        【2.电脑已安装ADB驱动】" << endl;
    cout << "        【3.手机上已授权此电脑的调试权限】" << endl;
    cout << "          若出现授权，请手动授权" << endl;
    cout << endl;
    cout << "            （按下任意键继续）" << endl;
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
    this_thread::sleep_for(chrono::seconds(2));
	system("cls");  
    return MENU();  
}  
bool CheckADBDevices() {  
    std::string adbOutput = "";  
    FILE* pipe = popen("adb devices", "r");  
    if (!pipe) {  
        std::cerr << "Failed to execute adb devices" << std::endl;  
        return false;  
    }  
  
    char buffer[128];  
    while (fgets(buffer, sizeof(buffer), pipe)) {  
        adbOutput += buffer;  
    }  
    pclose(pipe);  
  
    // 跳过列表标题行  
    std::istringstream iss(adbOutput);  
    std::string line;  
    std::getline(iss, line); // 读取并丢弃列表标题行，例如 "List of devices attached"  
  
    // 检查后续行中是否包含 "device"  
    bool foundDevice = false;  
    while (std::getline(iss, line)) {  
        if (line.find("device") != std::string::npos) {  
            foundDevice = true;  
            break;  
        }  
        // 也可以检查是否包含 "offline" 或其他不需要的状态  
    }  
  
    // 如果adbOutput中没有设备信息（可能只有标题行和空行），则视为没有设备  
    if (adbOutput.find("device") == std::string::npos &&  
        adbOutput.find("offline") == std::string::npos) {  
        // 这里可以添加额外的逻辑来处理只有标题行和空行的情况  
        foundDevice = false;  
    }  
  
    return foundDevice;  
} 
