class Solution {
public:
    int minSensors(int n, int m, int k) {
        
        int sensor_coverage=k*2+1;
        return ceil((float)n/sensor_coverage) * ceil((float)m/sensor_coverage);
    }
};