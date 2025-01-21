class Solution {
public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        long long firstRowSum = std::accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long secondRowSum = 0;
        long long minimizeRobot2Sum = LLONG_MAX;

        for (int robot1Col = 0; robot1Col < grid[0].size(); ++robot1Col) {
           
            firstRowSum -= grid[0][robot1Col];
            
            
            long long bestOfRobot2 = std::max(firstRowSum, secondRowSum);
            
         
            minimizeRobot2Sum = std::min(minimizeRobot2Sum, bestOfRobot2);
            
            
            secondRowSum += grid[1][robot1Col];
        }
        
        return minimizeRobot2Sum;
    }
};
