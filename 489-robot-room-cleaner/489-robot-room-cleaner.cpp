/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    set<pair<int, int> > v;
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
    
    bool dfs(Robot& robot, int x, int y, int dir) {
        if(v.count({x, y}))return false;
        v.insert({x, y});
        robot.clean();
        
        for(int i = 0; i < 4; ++i) {
            int j = (dir + i ) % 4;
            if(robot.move()){
                dfs(robot, x + d[j], y + d[j + 1], j);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnLeft();
        }
        return true;
    }
};