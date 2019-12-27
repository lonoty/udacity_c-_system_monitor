#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <string>
#include<vector>
#include "linux_parser.h"
using std::string;
using std::vector;
class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
  void store();
  float percent();
  void readfile();
  float debug();
  long debug1();
  // TODO: Declare any necessary private members
 private:
 string cpu;
 long cpu_data[10] = {0};
 long prev_cpu_data[10] = {0};
 long idles_waits_;
long prev_idles_waits_;
long nonidle_;
long prev_nonidle_;
long total_;
long prev_total_;
long totald_;
long idled_;
};
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
#endif