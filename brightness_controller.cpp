#define BATT_NOW        "/sys/class/power_supply/BAT0/charge_now"
#define BATT_FULL       "/sys/class/power_supply/BAT0/charge_full"
#define BATT_STATUS       "/sys/class/power_supply/BAT0/status"
#define BATT_PERCENT       "/sys/class/power_supply/BAT0/capacity"

#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
using namespace std;
int main(){

 time_t now;
 tm *gmtm;
 char *date_time;
 stringstream ss;
 FILE *fp;
 char bat_buf[]="ERR\0";
 while(true){
 ss<<"";
 now=time(0);
 gmtm= gmtime(&now);
 date_time= asctime(gmtm);
 strtok(date_time,"\n");
 fp = popen("cat /sys/class/power_supply/BAT0/capacity","r"); 
 if (fp != NULL)
 {
	 fgets(bat_buf,3,fp);
         pclose(fp);
 }
 ss << "xsetroot -name 'Bat:"<<bat_buf<<"<"<<date_time<<"'";
 //cout<< ss.str().c_str()[41];
 //cout<< strlen(ss.str().c_str());
 system(ss.str().c_str());
 sleep(1);
 }


}
