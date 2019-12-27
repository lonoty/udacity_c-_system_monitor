#include "processor.h"
#include "linux_parser.h"
#include <string>
#include <algorithm>

using std::string;
using std::to_string;
using std::copy;
// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
readfile();
return percent();
}

void Processor::store() {
copy(cpu_data, cpu_data + 10, prev_cpu_data);


}
float Processor::percent(){
idles_waits_ = cpu_data[LinuxParser::kIdle_] + cpu_data[LinuxParser::kIOwait_];
prev_idles_waits_ = prev_cpu_data[LinuxParser::kIdle_] + prev_cpu_data[LinuxParser::kIOwait_];

nonidle_ = cpu_data[LinuxParser::kUser_] + cpu_data[LinuxParser::kNice_] + cpu_data[LinuxParser::kSystem_] + cpu_data[LinuxParser::kIRQ_] + cpu_data[LinuxParser::kSoftIRQ_] + cpu_data[LinuxParser::kSteal_];
prev_nonidle_ = prev_cpu_data[LinuxParser::kUser_] + prev_cpu_data[LinuxParser::kNice_] + prev_cpu_data[LinuxParser::kSystem_] + prev_cpu_data[LinuxParser::kIRQ_] + prev_cpu_data[LinuxParser::kSoftIRQ_] + prev_cpu_data[LinuxParser::kSteal_];


total_ = idles_waits_ + nonidle_;
prev_total_ = prev_idles_waits_ + prev_nonidle_;

totald_ = total_ + prev_total_;
idled_ = idles_waits_ + prev_idles_waits_;

store();

return (float)(totald_ - idled_)/(float)totald_;
}
void Processor::readfile(){
string line;
std::ifstream filestream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
if (filestream.is_open()) {
  while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      int i = 0;
      linestream >> cpu;
      if(cpu == "cpu"){
        while(linestream >> cpu_data[i]){
        i++;
        }
      return;
      }
    }
  }
}
//for debugging porpuses only
/*
float Processor::debug(){
  long a = totald_-idled_;
  float b = (float)a/(float)totald_;

  return b;
}
long Processor::debug1(){
  return prev_cpu_data[1];
}
*/

/*PrevIdle = previdle + previowait
Idle = idle + iowait

PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal
NonIdle = user + nice + system + irq + softirq + steal

PrevTotal = PrevIdle + PrevNonIdle
Total = Idle + NonIdle

# differentiate: actual value minus the previous one
totald = Total - PrevTotal
idled = Idle - PrevIdle

CPU_Percentage = (totald - idled)/totald
*/
