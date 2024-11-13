package niski.csc;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        // Processes Array
        List<Process> processes = new ArrayList<>();
        processes.add(new Process(1, 2, 2));
        processes.add(new Process(2, 1, 1));
        processes.add(new Process(3, 8, 4));
        processes.add(new Process(4, 4, 2));
        processes.add(new Process(5, 5, 3));
        fcfs(processes);
        // We need to sort the processes by shortest job to longest job
        // The method will print each process id in order
        processes = new ArrayList<>();
        processes.add(new Process(2, 1, 1));
        processes.add(new Process(1, 2, 2));
        processes.add(new Process(4, 4, 2));
        processes.add(new Process(5, 5, 3));
        processes.add(new Process(3, 8, 4));
        sjf(processes);
    }

    /**
     * Implementation of First Come, First Served Scheduling Algorithm
     */
    private static void fcfs(List<Process> processes) {
        System.out.println("--------------------FCFS--------------------------");
        System.out.println("Process Id\t|\tWaiting Time\t|\tTurnaround Time");
        int[] waitingTimeArray = new int[processes.size()];
        int[] turnaroundTimeArray = new int[processes.size()];
        // Fill arrays with -1 so it doesn't crash
        for (int i = 0; i < waitingTimeArray.length; i++) {
            waitingTimeArray[i] = -1;
        }
        for (int i = 0; i < turnaroundTimeArray.length; i++) {
            turnaroundTimeArray[i] = -1;
        }
        // Calculate Wait Time and Turnaround Time
        // Turnaround Time
        for (int i = 0; i < processes.size(); i++) {
            // the first process
            if (i == 0) {
                turnaroundTimeArray[i] = processes.get(i).burstTime;
            } else {
                turnaroundTimeArray[i] = processes.get(i).burstTime + turnaroundTimeArray[i - 1];
            }
        }
        // Waiting Time (Turnaround time - burst time)
        for (int i = 0; i < waitingTimeArray.length; i++) {
            waitingTimeArray[i] = turnaroundTimeArray[i] - processes.get(i).burstTime;
        }
        // Print
        for (int i = 0; i < processes.size(); i++) {
            System.out.println("P" + processes.get(i).pid + "\t\t\t|\t" + waitingTimeArray[i] + "\t\t\t\t|\t" + turnaroundTimeArray[i]);
        }
        System.out.println();
    }

    /**
     * Implemenation of Shortest Job First Scheduling Algorithm
     */
    private static void sjf(List<Process> processes) {
        System.out.println("--------------------SJF----------------------");
        System.out.println("Process Id\t| Waiting Time\t| Turnaround Time");
        int[] waitingTimeArray = new int[processes.size()];
        int[] turnaroundTimeArray = new int[processes.size()];
        // Fill arrays with -1 so it doesn't crash
        for (int i = 0; i < waitingTimeArray.length; i++) {
            waitingTimeArray[i] = -1;
        }
        for (int i = 0; i < turnaroundTimeArray.length; i++) {
            turnaroundTimeArray[i] = -1;
        }
        // Calculate Wait Time and Turnaround Time
        // Turnaround Time
        for (int i = 0; i < processes.size(); i++) {
            // the first process
            if (i == 0) {
                turnaroundTimeArray[i] = processes.get(i).burstTime;
            } else {
                turnaroundTimeArray[i] = processes.get(i).burstTime + turnaroundTimeArray[i - 1];
            }
        }
        // Waiting Time (Turnaround time - burst time)
        for (int i = 0; i < waitingTimeArray.length; i++) {
            waitingTimeArray[i] = turnaroundTimeArray[i] - processes.get(i).burstTime;
        }
        // Print
        int j = 1;
        while (j <= processes.size()) {
            for (int i = 0; i < processes.size(); i++) {
                if(j == processes.get(i).pid) {
                    System.out.println("P" + processes.get(i).pid + "\t\t\t|\t" + waitingTimeArray[i] + "\t\t\t|\t" + turnaroundTimeArray[i]);
                }
            }
            j++;
        }
        System.out.println();
    }

    /**
     * Process Class
     * The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0
     */
    private static class Process {
        private int pid;
        private int burstTime;
        private int priority;

        public Process(int pid, int burstTime, int priority) {
            this.pid = pid;
            this.burstTime = burstTime;
            this.priority = priority;
        }

        public int getPid() {
            return pid;
        }

        public int getBurstTime() {
            return burstTime;
        }

        public int getPriority() {
            return priority;
        }

    }

}