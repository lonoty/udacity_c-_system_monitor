#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  Process(int pid);
      //cpu_ = CpuUtilization();
  //}
  // TODO: Declare any necessary private members
 private:
 int pid_;
 float cpu_;
 //pid
enum pidjiff {
  kutime_ = 0,
  kstime_,
  kcutime_,
  kcstime_,
  kstarttime_
};
};


#endif