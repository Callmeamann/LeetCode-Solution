class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> temperature;
        temperature.push_back(celsius + 273.15);
        temperature.push_back( celsius * 1.80 + 32.00);
        return temperature;
    }
};