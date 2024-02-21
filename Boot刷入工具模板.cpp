#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;
int s;
string deviceName = "input";
string projectName = "input";
string bootVer = "input";
string patchVer = "input";
string toolAuth = "input";
string buildDate = "input";
string bootImg = "input";
string Group = "input";
void FLASH_OVER()
{
    system("cls");
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By" << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "             刷写Recovery完成" << endl;
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
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By" << toolAuth << endl;
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
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By" << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "          正在进行刷入Recovery操作" << endl
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
    cin.get();
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
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By" << toolAuth << endl;
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
    cin.get();
    cout << "正在检查设备是否正常连接..." << endl;
    cout << endl;
    cout << "   （若长时间停留在此界面，请检查上述几项）" << endl;
    cout << "***********************************************" << endl;
    int result = system("adb devices");
    cout << "出现手机序列号后，按回车键重启到Bootloader模式..." << endl;
    if (result == 0)
    {
        REBOOT_BOOTLOADER();
    }
    else
    {
        IN_SYSTEM();
    }
}
void FASTBOOT_MODE()
{
    system("cls");
    cout << endl;
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By" << toolAuth << endl;
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
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By" << toolAuth << endl;
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
void MENU()
{
    cout << endl;
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
    cout << "                                --By" << toolAuth << endl;
    cout << "***********************************************" << endl;
    cout << "	请选择您手机的当前状态：" << endl;
    cout << "	1. 开机状态" << endl;
    cout << "	2. fastboot模式" << endl;
    cout << "	3. 其他状态" << endl;
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
int main()
{
    system("color 3f");
    system(("TITLE " + deviceName + "一键刷入Boot工具 --By " + toolAuth).c_str());
    cout << endl;
    cout << "  " << deviceName << " 一键刷入Boot工具" << endl;
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
