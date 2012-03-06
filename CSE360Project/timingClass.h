
#include <ctime>

using namespace std;

typedef enum computation_type {
	cpu = 1,
	elapsed = 2
} computation_type_t;

struct elapsed_time_t {
	time_t elapsed_time;
	time_t elapsed_time_saved;

	clock_t cpu_time;
	clock_t cpu_time_saved;

	bool saved;
};

class timingClass
{
public:
	timingClass();

	//Benchmarking Functions
	int startNewTimer(); //returns index of timer
	double getElapsedTime(int); //int is index of timer.
	double getCPUTime(int);
	void saveCurrentTime(int);
	void resetTimer(int);
	void tic();
	double toc();

	//Time Functions
	char formatHumanProcessedTime(double totalSeconds);


protected:
	int numOfTimers;
	int ticValue;

	elapsed_time_t *savedTimers;

};
