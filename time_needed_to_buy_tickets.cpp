class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // tracks the line order
        queue<int> line;

        // track people's time
        vector<int> times;
        
        // populate the line
        for (int i=0; i < tickets.size(); ++i) {
            line.push(i);
            times.push_back(0);
        }

        // total time to serve everyone
        int time = 0;

        while (!line.empty()) {
            // get the first person in line
            int i = line.front();

            // decrement ticket count 
            tickets[i]--;

            // increment time count
            times[i] = time + 1;

            time++;

            // move from the front of line
            line.pop();

            if (tickets[i] > 0) {
                // send the person back to the line if more tickets
                line.push(i);
            }
        }
        return times[k];
    }
};
