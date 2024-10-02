/*Niski Programming Assignment 1 - Memory Management Simulator*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int memorySize = 16000;
const int numberOfPages = 100;
const int pageSize = memorySize / numberOfPages;
const int startingMemoryAddress = 2000;
const int processNumberSize = 80;

void userMemoryAllocation(int processorNumberArray[]) {
	printf("Process Id\tStarting Memory Address\t\tSize of the Process MB\t\tUnused Space MB\n");
	int usedSpace = 0;
	int currentProcessorNumber = 0;
	int processCount = 0;
	while(currentProcessorNumber < numberOfPages) {
		/*printf("Process Count: %d\n", processCount);
		printf("Current Processor Number: %d\n", currentProcessorNumber);*/
		int random = rand() % (30 + 1);
		/*printf("Random Number Generated: %d\n", random);*/
		
		int calculatedProcessSize = random * processNumberSize;
		/*printf("Process Size: %d\n", calculatedProcessSize);*/
		
		int neededPages = ceil(calculatedProcessSize / pageSize);
		/*printf("Number of pages this process needs: %d\n", neededPages);*/
		
		int memorySizeNeeded = neededPages * pageSize;
		/*printf("Calculated memory size for process: %d\n", memorySizeNeeded);*/
			if((usedSpace + memorySizeNeeded) < memorySize) {
				int unusedSpace = calculatedProcessSize - memorySizeNeeded;
				/*printf("Unused space for this process: %d\n", unusedSpace);*/
				
				usedSpace = usedSpace + calculatedProcessSize;
				/*printf("Total used space so far: %d\n", usedSpace);*/
				
				int nextProcessorNumber = currentProcessorNumber + neededPages;
				
				/*Fill in processor array with process number and check available memory space*/
				if((startingMemoryAddress + usedSpace) < memorySize) {
					for(int i = currentProcessorNumber; i < nextProcessorNumber; i++) {
					processorNumberArray[i] = processCount;
				}
				printf("%d\t\t%d\t\t\t\t%d\t\t\t\t%d\n", processCount, (startingMemoryAddress + usedSpace - memorySizeNeeded - unusedSpace), memorySizeNeeded, unusedSpace);
				
				currentProcessorNumber = nextProcessorNumber;
				processCount = processCount + 1;
			} else {
				break;
			}
		} else {
			break;
		}
	}
}

int main() {
	/*Initialize Array and fill empty spaces with -1*/
	int processorNumberArray[numberOfPages];
	for(int i = 0; i < numberOfPages; i++) {
		processorNumberArray[i] = -1;
	}
	/*Run userMemoryAllocation function*/
	userMemoryAllocation(processorNumberArray);	
	return 0;
}